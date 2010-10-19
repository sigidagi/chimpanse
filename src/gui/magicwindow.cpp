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
#include	"core/core.h"
#include	<vector>
#include	<QMessageBox>
#include	<QTimer>
#include	<functional>
#include	<algorithm>


using std::vector;

namespace Oi
{
    MagicWindow::MagicWindow(QWidget* parent) : QMainWindow(parent)
    {
        setupUi(this);
   
        grNumbers_ = new QButtonGroup;        
        const QObjectList objects = container->children();
        
        foreach(QObject* object, objects)
        {
            QPushButton* button = qobject_cast<QPushButton*>(object);
            if (!button)
                continue;
    
            grNumbers_->addButton(button); 
        }

        preferences_ = new Preferences(this);
        preferences_->setModal(true);
        
        connect(actionNew, SIGNAL(triggered()), this, SLOT(newSession()));
        connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));
        connect(actionPreferences, SIGNAL(triggered()), preferences_, SLOT(show()));
        connect(actionHelp, SIGNAL(triggered()), this, SLOT(help()));
        connect(actionAbout,SIGNAL(triggered()), this, SLOT(about()));
        connect(grNumbers_, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(fieldClicked(QAbstractButton*))); 

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
        QTimer::singleShot(1000*value, this, SLOT(clearText()));                 
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

    void MagicWindow::message(const QString& message)
    {
            QMessageBox box;
            box.setText(message);
            box.exec();
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
            message("Incorrect quess! Try again.");            
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
            message("Correct! Congratulations!");
            newSession();
        }
    }
    
    void MagicWindow::newSession()
    {
        setLength(preferences_->getLength());
        int time = preferences_->getTime();
        if (time != -1)
            setTime(time);

        reset();
    }
    
    void MagicWindow::help()
    {

    }

    void MagicWindow::about()
    {

    }


} // namesapce Oi 

