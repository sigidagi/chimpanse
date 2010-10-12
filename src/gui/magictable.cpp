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
           
//        QObjectList b = ui.MagicTable->children();      

        core = new Core;
        core->setLength(36);
        core->start();
        
        vector<int> numbers;
        core->getNumbers(numbers);
        
        
    }
    
    MagicTable::~MagicTable()
    {
        if (core)
        {
            delete core;
            core = 0;
        }
    }

    void MagicTable::reset()
    {

    }

    void MagicTable::on_field01_clicked()
    {

    }
    void MagicTable::on_field02_clicked()
    {

    }
    void MagicTable::on_field03_clicked()
    {

    }
    void MagicTable::on_field04_clicked()
    {

    }
    void MagicTable::on_field05_clicked()
    {

    }
    void MagicTable::on_field06_clicked()
    {

    }
    void MagicTable::on_field07_clicked()
    {

    }
    void MagicTable::on_field08_clicked()
    {

    }
    void MagicTable::on_field09_clicked()
    {

    }
    void MagicTable::on_field10_clicked()
    {

    }
    void MagicTable::on_field11_clicked()
    {

    }
    void MagicTable::on_field12_clicked()
    {

    }
    void MagicTable::on_field13_clicked()
    {

    }
    void MagicTable::on_field14_clicked()
    {

    }
    void MagicTable::on_field15_clicked()
    {

    }
    void MagicTable::on_field16_clicked()
    {

    }
    void MagicTable::on_field17_clicked()
    {

    }
    void MagicTable::on_field18_clicked()
    {

    }
    void MagicTable::on_field19_clicked()
    {

    }
    void MagicTable::on_field20_clicked()
    {

    }
    void MagicTable::on_field21_clicked()
    {

    }
    void MagicTable::on_field22_clicked()
    {

    }
    void MagicTable::on_field23_clicked()
    {

    }
    void MagicTable::on_field24_clicked()
    {

    }
    void MagicTable::on_field25_clicked()
    {

    }
    void MagicTable::on_field26_clicked()
    {

    }
    void MagicTable::on_field27_clicked()
    {

    }
    void MagicTable::on_field28_clicked()
    {

    }
    void MagicTable::on_field29_clicked()
    {

    }
    void MagicTable::on_field30_clicked()
    {

    }
    void MagicTable::on_field31_clicked()
    {

    }
    void MagicTable::on_field32_clicked()
    {

    }
    void MagicTable::on_field33_clicked()
    {

    }
    void MagicTable::on_field34_clicked()
    {

    }
    void MagicTable::on_field35_clicked()
    {

    }
    void MagicTable::on_field36_clicked()
    {

    }

} // namesapce Oi 

