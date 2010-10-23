// =====================================================================================
// 
//       Filename:  popwindow.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-23 16:50:26
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#include	"ui_popwindow.h"

namespace Oi
{
    class MagicWindow;

    class PopWindow : public QScrollArea, public Ui::popWindow
    {
        
        private:
           MagicWindow* magic_;
           bool isAppearing_;
           int timeElapsed_;

        public:
            PopWindow(QWidget* parent = 0);
            QLabel* getImage();
    
        protected:
            virtual void showEvent(QShowEvent* );
            virtual void timerEvent(QTimerEvent* );
    };

} // namespace

