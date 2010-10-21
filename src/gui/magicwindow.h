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

#include	"ui_magicwindow.h"
#include	<vector>

using std::vector;

class QLabel;

namespace Oi
{
    class Core;
    class Preferences;

    class MagicWindow : public QMainWindow, public Ui::MagicWindow
    {
        Q_OBJECT

        private:
            //Ui::MagicWindow ui;
            Core* core_;
            QTimer* countTimer_;
            QLabel* statusLabel_;
            QLabel* secondsLabel_;
            Preferences* preferences_;
            QButtonGroup* grNumbers_;
            int timeLeft_;

        public:
            MagicWindow(QWidget* parent = 0);
            ~MagicWindow();
            void setLength(int value);
            void setTime(int value);
            void reset();
            void message(const QString& message);
            void clearText();

        private slots:
            void newSession();
            void help();
            void about();
            void countDown();
            void fieldClicked(QAbstractButton* button);

    };
    
} // namespace Oi

#endif   // ----- #ifndef MAGICTABLE_INC  -----

