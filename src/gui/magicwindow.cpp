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
#include	<functional>
#include	<algorithm>


using std::vector;

namespace Oi
{
    MagicWindow::MagicWindow(QWidget* parent) : QMainWindow(parent)
    {
        setupUi(this);
    
        connect(actionNew, SIGNAL(triggered()), this, SLOT(newSession()));
        connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));
        connect(actionPreferences, SIGNAL(triggered()), this, SLOT(preferences()));
        connect(actionHelp, SIGNAL(triggered()), this, SLOT(help()));
        connect(actionAbout,SIGNAL(triggered()), this, SLOT(about()));

        core_ = new Core;
        preferences_ = new Preferences(this);
        preferences_->setModal(true);
        
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

    void MagicWindow::update()
    {
        if (buttons_.empty())
            return;
        
        // if it is first update then loop through PushButtons and clear text
        if ((int)buttons_.size() == core_->getLength())
        {
            foreach(QPushButton* but, buttons_)
                but->setText("");
        }

        buttons_[0]->setFlat(true);
        buttons_[0]->setEnabled(false);
        buttons_.erase(buttons_.begin());

        if (buttons_.empty())
        {
            message("Correct! Congratulations!");
            reset();
        }
    }

/*
 *    struct ObjectName : public std::binary_function<QObject, QString, bool>
 *    {
 *        bool operator()(const QObject* object, const QString& name) const
 *        {
 *            const QPushButton* button = qobject_cast<QPushButton*>(object);
 *            if (!button)
 *                return false;
 *
 *            if (button->objectName() != name)
 *                return false; 
 *
 *            return true;
 *
 *        }
 *    };
 */

    void MagicWindow::reset()
    {
        const QObjectList objects  = container->children();
        
        int size = objects.count();
        for (int j = 0; j < size; ++j)
        {
            QPushButton* button = qobject_cast<QPushButton*>(objects[j]);
            if (button)
            {
                button->setText("");
                button->setFlat(true);
                button->setEnabled(false);
            }
        }

        buttons_.clear();
        core_->start();

        vector<int> numbers;
        core_->getNumbers(numbers);
        
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            QString name = "field" + QString::number(numbers[i]);
            foreach(QObject* obj, objects)
            {
                QPushButton* button = qobject_cast<QPushButton*>(obj);
                if (!button)
                    continue;

                if (button->objectName() == name)
                {
                    button->setFlat(false);
                    button->setEnabled(true);
                    button->setDefault(true);
                    button->setText(QString::number(i+1));
                    button->setPalette(QPalette(Qt::red));
                    buttons_.push_back(button);

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

    void MagicWindow::newSession()
    {
        reset();
    }
    
    void MagicWindow::preferences()
    {
        preferences_->show();
    }

    void MagicWindow::help()
    {

    }

    void MagicWindow::about()
    {

    }

    void MagicWindow::on_field1_clicked()
    {
        if (!core_->tap(1))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                
    }
    void MagicWindow::on_field2_clicked()
    {
        if (!core_->tap(2))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field3_clicked()
    {
        if (!core_->tap(3))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field4_clicked()
    {
        if (!core_->tap(4))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field5_clicked()
    {
        if (!core_->tap(5))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field6_clicked()
    {
        if (!core_->tap(6))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field7_clicked()
    {
        if (!core_->tap(7))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field8_clicked()
    {
        if (!core_->tap(8))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field9_clicked()
    {
        if (!core_->tap(9))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field10_clicked()
    {
        if (!core_->tap(10))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field11_clicked()
    {
        if (!core_->tap(11))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field12_clicked()
    {
        if (!core_->tap(12))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field13_clicked()
    {
        if (!core_->tap(13))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field14_clicked()
    {
        if (!core_->tap(14))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field15_clicked()
    {
        if (!core_->tap(15))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field16_clicked()
    {
        if (!core_->tap(16))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field17_clicked()
    {
        if (!core_->tap(17))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field18_clicked()
    {
        if (!core_->tap(18))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field19_clicked()
    {
        if (!core_->tap(19))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field20_clicked()
    {
        if (!core_->tap(20))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field21_clicked()
    {
        if (!core_->tap(21))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field22_clicked()
    {
        if (!core_->tap(22))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field23_clicked()
    {
        if (!core_->tap(23))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field24_clicked()
    {
        if (!core_->tap(24))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field25_clicked()
    {
        if (!core_->tap(25))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field26_clicked()
    {
        if (!core_->tap(26))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field27_clicked()
    {
        if (!core_->tap(27))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field28_clicked()
    {
        if (!core_->tap(28))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field29_clicked()
    {
        if (!core_->tap(29))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field30_clicked()
    {
        if (!core_->tap(30))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field31_clicked()
    {
        if (!core_->tap(31))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field32_clicked()
    {
        if (!core_->tap(32))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field33_clicked()
    {
        if (!core_->tap(33))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field34_clicked()
    {
        if (!core_->tap(34))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field35_clicked()
    {
        if (!core_->tap(35))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }
    void MagicWindow::on_field36_clicked()
    {
        if (!core_->tap(36))             
        {
            message("Incorrect quess! Try again.");            
            reset();
            return;
        }

        update();                

    }

} // namesapce Oi 

