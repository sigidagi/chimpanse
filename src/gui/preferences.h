// =====================================================================================
// 
//       Filename:  preferences.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-15 13:48:43
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#ifndef  PREFERENCES_INC
#define  PREFERENCES_INC


#include	"ui_preferences.h"
#include	<QButtonGroup>

namespace Oi
{
    class MagicWindow;

    class Preferences : public QDialog, public Ui::Preferences
    {
        Q_OBJECT
        
        MagicWindow* magic_;
        QButtonGroup* groupTime;
        QButtonGroup* groupLength;

        public:
            Preferences(QWidget* parent = 0);

            void changedTime();
            void changedLength();
        
        private slots:
            void accept();
    };


} // namespace Oi

#endif   // ----- #ifndef PREFERENCES_INC  -----
