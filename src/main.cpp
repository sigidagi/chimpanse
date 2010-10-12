// =====================================================================================
// 
//       Filename:  main.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-04 14:45:43
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#include	"gui/magictable.h"
#include	<QApplication>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Oi::MagicTable table;

    table.show();

    return app.exec();
}

