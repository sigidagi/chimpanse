// =====================================================================================
// 
//       Filename:  popwindow.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-23 17:01:47
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#include	"popwindow.h"
#include	"magicwindow.h"


static const int FADE_UNIT = 100; // in milliseconds
static const int FADE_COUNT = 10*FADE_UNIT;

namespace Oi
{
    PopWindow::PopWindow(QWidget* parent) : QScrollArea(parent)
    {
        magic_ = qobject_cast<MagicWindow*>(parent);

        setupUi(this);
    
        QPixmap pix(":/images/chimp.png");
        imageLabel_->setPixmap(pix);
        imageLabel_->adjustSize();

        this->adjustSize();
    }
   
    QLabel* PopWindow::getImage()
    {
        return imageLabel_;
    }

    void PopWindow::showEvent(QShowEvent* event)
    {
        isAppearing_ = true;
        timeElapsed_ = 0;

        setWindowOpacity(0.0);
        startTimer(FADE_UNIT);
        QScrollArea::showEvent(event);
    }

    void PopWindow::timerEvent(QTimerEvent* event)
    {
       if (isAppearing_ && (timeElapsed_ < FADE_COUNT))
       {
           timeElapsed_ += FADE_UNIT;
       }
       else
       {
           isAppearing_ = false;
           timeElapsed_ -= FADE_UNIT;
       }

       setWindowOpacity(double(timeElapsed_)/FADE_COUNT);

       if (timeElapsed_ <= 0)
       {
           killTimer(event->timerId());
           close();
       }

    }

} // namespace Oi
