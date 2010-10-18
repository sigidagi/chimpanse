// =====================================================================================
// 
//       Filename:  preferences.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-15 13:59:33
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#include	"preferences.h"
#include	"magicwindow.h"


namespace Oi
{
    Preferences::Preferences(QWidget* parent) : QDialog(parent)
    {
        magic_ = qobject_cast<MagicWindow*>(parent);
        
        setupUi(this);
        
        groupTime = new QButtonGroup;
        groupTime->addButton(sec1);
        groupTime->addButton(sec2);
        groupTime->addButton(sec5);
        groupTime->addButton(sec8);
        groupTime->addButton(sec12);
        groupTime->addButton(sec20);

        groupLength = new QButtonGroup;
        groupLength->addButton(len4);
        groupLength->addButton(len5);
        groupLength->addButton(len6);
        groupLength->addButton(len7);
        groupLength->addButton(len8);
        groupLength->addButton(len9);
    
        len6->setChecked(true);
        sec5->setChecked(true);
        
        connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    }


    void Preferences::changedTime()
    {
        if ( grTime->isChecked())
        {
            QAbstractButton* button = groupTime->checkedButton();
            magic_->setTime( button->text().toInt() );
        }
    }

    void Preferences::changedLength()
    {
        QAbstractButton* button = groupLength->checkedButton();         
        magic_->setLength( button->text().toInt() );
    }

    void Preferences::accept()
    {
        changedTime();
        changedLength();
        this->close();
    }
    
    int Preferences::getTime()
    {
        if (!grTime->isChecked())
             return -1;
        
        QAbstractButton* button = groupTime->checkedButton();
        return button->text().toInt();
    }

    int Preferences::getLength()
    {
        QAbstractButton* button = groupLength->checkedButton();
        return button->text().toInt();
    }

} // namespace Oi
