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

#include	<QApplication>
#include	"gui/magicwindow.h"


using namespace std;

#if defined(_MSC_VER)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
#else
int main(int argc, char* argv[])
#endif
{
    int c = 0;
    QApplication app(c, 0);
//    app.setStyle("cde");
    Oi::MagicWindow* magic = new Oi::MagicWindow;
    magic->show();

    return app.exec();
}

