// =====================================================================================
// 
//       Filename:  magictable.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-11 11:20:25
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================
#ifndef  MAGICTABLE_INC
#define  MAGICTABLE_INC

#include	"ui_magictable.h"
#include	<vector>

using std::vector;


namespace Oi
{
    class Core;

    class MagicTable : public QDialog
    {
        Q_OBJECT

        private:
            Ui::MagicTable ui;
            Core* core;
            vector<QPushButton*> buttons_; 

        public:
            MagicTable(QWidget* parent = 0);
            ~MagicTable();
            void reset();
            void update();

        private slots:
            void on_field01_clicked();
            void on_field02_clicked();
            void on_field03_clicked();
            void on_field04_clicked();
            void on_field05_clicked();
            void on_field06_clicked();
            void on_field07_clicked();
            void on_field08_clicked();
            void on_field09_clicked();
            void on_field10_clicked();
            void on_field11_clicked();
            void on_field12_clicked();
            void on_field13_clicked();
            void on_field14_clicked();
            void on_field15_clicked();
            void on_field16_clicked();
            void on_field17_clicked();
            void on_field18_clicked();
            void on_field19_clicked();
            void on_field20_clicked();
            void on_field21_clicked();
            void on_field22_clicked();
            void on_field23_clicked();
            void on_field24_clicked();
            void on_field25_clicked();
            void on_field26_clicked();
            void on_field27_clicked();
            void on_field28_clicked();
            void on_field29_clicked();
            void on_field30_clicked();
            void on_field31_clicked();
            void on_field32_clicked();
            void on_field33_clicked();
            void on_field34_clicked();
            void on_field35_clicked();
            void on_field36_clicked();
    };
    
} // namespace Oi

#endif   // ----- #ifndef MAGICTABLE_INC  -----
