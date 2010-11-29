// =====================================================================================
// 
//       Filename:  magictable.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-11 12:04:29
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================


#include	"magicwindow.h"
#include	"preferences.h"
#include	"popwindow.h"
#include	"core/core.h"
#include	<vector>
#include	<QMessageBox>
#include	<QTimer>
#include	<QLabel>
#include	<functional>
#include	<algorithm>


using std::vector;

namespace Oi
{
    MagicWindow::MagicWindow(QWidget* parent) : QMainWindow(parent)
    {
        setupUi(this);
        
        setWindowIcon(QIcon(":/images/chimpLogo.gif"));
        grNumbers_ = new QButtonGroup;        
        const QObjectList objects = container->children();
        
        foreach(QObject* object, objects)
        {
            QPushButton* button = qobject_cast<QPushButton*>(object);
            if (!button)
                continue;
    
            grNumbers_->addButton(button); 
        }

        connect(actionNew, SIGNAL(triggered()), this, SLOT(newSession()));
        connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));
        connect(actionHelp, SIGNAL(triggered()), this, SLOT(help()));
        connect(actionAbout,SIGNAL(triggered()), this, SLOT(about()));
        connect(grNumbers_, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(fieldClicked(QAbstractButton*))); 
        
        preferences_ = new Preferences(this);
        preferences_->setModal(true);
        connect(actionPreferences, SIGNAL(triggered()), preferences_, SLOT(show()));

        countTimer_ = new QTimer(this);
        connect(countTimer_, SIGNAL(timeout()), this, SLOT(countDown()));

        statusLabel_ = new QLabel("Unlimited time");         
        secondsLabel_ = new QLabel;
        this->statusBar()->addWidget(statusLabel_);
        this->statusBar()->addWidget(secondsLabel_, 1);
       
        popWindow_ = new PopWindow;

        core_ = new Core;
        // once length is set(changed) it needs to reset numbers and 
        // generate new ones at specific length. 
        setLength(6);
    }
    
    MagicWindow::~MagicWindow()
    {
        if (core_)
        {
            delete core_;
            core_ = 0;
        }
    }
    
    void MagicWindow::setLength(int value)
    {
        core_->setLength(value);
        reset();
    }

    void MagicWindow::setTime(int value)
    {
        if (value == -1)
        {
            statusLabel_->setText("Unlimited time");
            secondsLabel_->setText("");
            timeLeft_ = -1;
            return;
        }

        timeLeft_ = value;
        QString sec;
        statusLabel_->setText("Time left:");
        secondsLabel_->setText(sec.setNum(value));
        countTimer_->start(1000);
    }
   
    void MagicWindow::countDown()
    {
        --timeLeft_;
        statusLabel_->setText("Time left:");
       
       QString sec;
       if (timeLeft_ == 0)
        {
            countTimer_->stop();       
            secondsLabel_->setText(sec.setNum(0));
            clearText();
            return;
        }

        // send message to status bar - how much time left.
        secondsLabel_->setText(sec.setNum(timeLeft_)); 
    }

    void MagicWindow::clearText()
    {
        QList<QAbstractButton*> buttons = grNumbers_->buttons();
         
        foreach(QAbstractButton* but, buttons)
            but->setText("");
    }

    void MagicWindow::reset()
    {
        QList<QAbstractButton*> buttons = grNumbers_->buttons();
        foreach(QAbstractButton* button, buttons)
        {
            QPushButton* push = qobject_cast<QPushButton*>(button);
            push->setText("");
            push->setFlat(true);
            push->setEnabled(false);
        }
        
        core_->start();
        vector<int> numbers = core_->getNumbers();
        
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            QString name = "field" + QString::number(numbers[i]);
            foreach(QAbstractButton* button, buttons)
            {
                QPushButton* push = qobject_cast<QPushButton*>(button);

                if (push->objectName() == name)
                {
                    push->setFlat(false);
                    push->setEnabled(true);
                    push->setDefault(true);
                    push->setText(QString::number(i+1));
//                    ->setPalette(QPalette(Qt::blue));
                    break;
                }
            }
        
        }
        

    }

    void MagicWindow::message(bool correct)
    {

        QLabel* imageLabel = popWindow_->getImage();
        if (correct) 
            imageLabel->setPixmap(QPixmap(":/images/happy.jpg"));
        else
            imageLabel->setPixmap(QPixmap(":/images/sad.jpg"));

        popWindow_->show();
    }

    // On Action

    void MagicWindow::fieldClicked(QAbstractButton* button)
    {
        QString name = button->objectName();
        QString text = button->text();
        // name will be fieldxx or fieldx - where x represent number.
        // so from 6th position to the right there is a number of a field.
        if (!core_->tap(name.remove("field").toInt()))             
        {
            message(false);
            newSession();
            return;
        }
       
        // if this is the first button clear numbers!
        if (text == "1")
            clearText();

        QPushButton* push = qobject_cast<QPushButton*>(button);
        push->setFlat(true);

        if (core_->isLast())
        {
            message(true);
            newSession();
        }
    }
    
    void MagicWindow::newSession()
    {
        setLength(preferences_->getLength());
        int time = preferences_->getTime();
        if (time != -1)
        {
            // set time in seconds. after time is expaired: program
            // clears all fileds with numbers.
            setTime(time);
        }
        else
        {
            statusLabel_->setText("Unlimited time");
            secondsLabel_->setText("");
        }

        reset();
    }
    
    void MagicWindow::help()
    {
        QMessageBox::about(this, tr("How to play"),
            tr("<h2>How to play</h2>"
               "<p>The objective of <it>Chimpanse</it> is to click on numbers in right sequence. "
               "Once you remeber positions of the numbers and start with number \"1\" - "
               "other numbers will be hidden. So, use your memory - guess right! " 
               "<p>Form preferences in menues, you can choose lenght of the sequence and(or) "
               "time how long (in seconds) numbers will be shown."));
    }

    void MagicWindow::about()
    {
        QMessageBox::about(this, tr("About Chimpanse"),
            tr("<h2> Chimpanse 1.0</h2>"
               "<p>Copyright &copy; 2010 sigidagi."
               "<p>Chimpanse is a cognitive (mind) game. Playing <i>Chimpanse</i> "
               "will improve your photographic memory skills. "
               "You will be suprised that "
               "Ayumu, a seven-year-old chimpanse male is a world chimpion " 
               "in such memory competition. "
               "<p> More about it: "
               "<a href=\"http://news.bbc.co.uk/2/hi/7124156.stm\">BBS News article</a> "));
    }


} // namesapce Oi 

