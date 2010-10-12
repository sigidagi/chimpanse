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


#include	"magictable.h"
#include	"core/core.h"
#include	<vector>

using std::vector;

namespace Oi
{
    MagicTable::MagicTable(QWidget* parent) : QDialog(parent)
    {
        ui.setupUi(this);
        core = new Core;
        core->setLength(6);
        
        reset();
    }
    
    MagicTable::~MagicTable()
    {
        if (core)
        {
            delete core;
            core = 0;
        }
    }

    void MagicTable::update()
    {
        if (buttons_.empty())
            return;
    
        buttons_[0]->setFlat(true);
        buttons_[0]->setEnabled(false);
    }
  
    void MagicTable::reset()
    {
        const QObjectList objects  = ui.container->children();
        
        int size = objects.count();
        for (int j = 0; j < size; ++j)
        {
            QPushButton* button = qobject_cast<QPushButton*>(objects[j]);
            if (button)
            {
                button->setFlat(true);
                button->setEnabled(false);
            }
        }

        buttons_.clear();
        core->start();

        vector<int> numbers;
        core->getNumbers(numbers);
        
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            QPushButton* button = qobject_cast<QPushButton*>(objects[numbers[i]]);
            if (button)
            {
                button->setFlat(false);
                button->setEnabled(true);
                button->setText(QString::number(i+1));
                button->setPalette(QPalette(Qt::red));
                buttons_.push_back(button);
            }
        }

    }

    void MagicTable::on_field01_clicked()
    {
        if (!core->tap(1))             
            reset();

        update();                
    }
    void MagicTable::on_field02_clicked()
    {
        if (!core->tap(2))             
            reset();

        update();                

    }
    void MagicTable::on_field03_clicked()
    {
        if (!core->tap(3))             
            reset();

        update();                

    }
    void MagicTable::on_field04_clicked()
    {
        if (!core->tap(4))             
            reset();

        update();                

    }
    void MagicTable::on_field05_clicked()
    {
        if (!core->tap(5))             
            reset();

        update();                

    }
    void MagicTable::on_field06_clicked()
    {
        if (!core->tap(6))             
            reset();

        update();                

    }
    void MagicTable::on_field07_clicked()
    {
        if (!core->tap(7))             
            reset();

        update();                

    }
    void MagicTable::on_field08_clicked()
    {
        if (!core->tap(8))             
            reset();

        update();                

    }
    void MagicTable::on_field09_clicked()
    {
        if (!core->tap(9))             
            reset();

        update();                

    }
    void MagicTable::on_field10_clicked()
    {
        if (!core->tap(10))             
            reset();

        update();                

    }
    void MagicTable::on_field11_clicked()
    {
        if (!core->tap(11))             
            reset();

        update();                

    }
    void MagicTable::on_field12_clicked()
    {
        if (!core->tap(12))             
            reset();

        update();                

    }
    void MagicTable::on_field13_clicked()
    {
        if (!core->tap(13))             
            reset();

        update();                

    }
    void MagicTable::on_field14_clicked()
    {
        if (!core->tap(14))             
            reset();

        update();                

    }
    void MagicTable::on_field15_clicked()
    {
        if (!core->tap(15))             
            reset();

        update();                

    }
    void MagicTable::on_field16_clicked()
    {
        if (!core->tap(16))             
            reset();

        update();                

    }
    void MagicTable::on_field17_clicked()
    {
        if (!core->tap(17))             
            reset();

        update();                

    }
    void MagicTable::on_field18_clicked()
    {
        if (!core->tap(18))             
            reset();

        update();                

    }
    void MagicTable::on_field19_clicked()
    {
        if (!core->tap(19))             
            reset();

        update();                

    }
    void MagicTable::on_field20_clicked()
    {
        if (!core->tap(20))             
            reset();

        update();                

    }
    void MagicTable::on_field21_clicked()
    {
        if (!core->tap(21))             
            reset();

        update();                

    }
    void MagicTable::on_field22_clicked()
    {
        if (!core->tap(22))             
            reset();

        update();                

    }
    void MagicTable::on_field23_clicked()
    {
        if (!core->tap(23))             
            reset();

        update();                

    }
    void MagicTable::on_field24_clicked()
    {
        if (!core->tap(24))             
            reset();

        update();                

    }
    void MagicTable::on_field25_clicked()
    {
        if (!core->tap(25))             
            reset();

        update();                

    }
    void MagicTable::on_field26_clicked()
    {
        if (!core->tap(26))             
            reset();

        update();                

    }
    void MagicTable::on_field27_clicked()
    {
        if (!core->tap(27))             
            reset();

        update();                

    }
    void MagicTable::on_field28_clicked()
    {
        if (!core->tap(28))             
            reset();

        update();                

    }
    void MagicTable::on_field29_clicked()
    {
        if (!core->tap(29))             
            reset();

        update();                

    }
    void MagicTable::on_field30_clicked()
    {
        if (!core->tap(30))             
            reset();

        update();                

    }
    void MagicTable::on_field31_clicked()
    {
        if (!core->tap(31))             
            reset();

        update();                

    }
    void MagicTable::on_field32_clicked()
    {
        if (!core->tap(32))             
            reset();

        update();                

    }
    void MagicTable::on_field33_clicked()
    {
        if (!core->tap(33))             
            reset();

        update();                

    }
    void MagicTable::on_field34_clicked()
    {
        if (!core->tap(34))             
            reset();

        update();                

    }
    void MagicTable::on_field35_clicked()
    {
        if (!core->tap(35))             
            reset();

        update();                

    }
    void MagicTable::on_field36_clicked()
    {
        if (!core->tap(36))             
            reset();

        update();                

    }

} // namesapce Oi 

