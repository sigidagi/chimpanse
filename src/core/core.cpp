// =====================================================================================
// 
//       Filename:  OiCore.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-04 19:51:18
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================

#include	"core.h"
#include	"random.h"
#include	<algorithm>

namespace Oi
{
    enum
    {
        SIZE = 36
    };

    Core::Core()
    {
        vec_.resize(SIZE);
        end_ = vec_.end();
    }
    
    void Core::setLength(unsigned int length)
    {
        if (length > SIZE )
            return;
       
        end_ = vec_.begin() + length;
       
        start();
    }

    int Core::getLength()
    {
        int len = (int)(end_ - vec_.begin());
        return len; 
    }
    

    void Core::start()
    {
        const int* array = Oi::Random<int, SIZE>::shuffle();
        vec_.clear();
        vec_.resize(SIZE);
        std::copy(array, array+SIZE, vec_.begin());
        pos_ = vec_.begin();
    }

    bool Core::tap(unsigned int number)
    {
        std::vector<int>::const_iterator it;
        it = std::find(vec_.begin(), end_, number);
        // if such number exist in a vector then it has to be first
        // otherwise wrong number was taped!
        if (it != end_)
        {
            if (number == (unsigned int)*pos_)
            {
                ++pos_;
                return true;
            }
            else
            {
                pos_ = end_;
                return false;
            }
        }
        
        // it was tapped accedent field - do nothing with vector. 
        return false;
    }

    bool Core::isLast()
    {
        if (pos_ == end_)
            return true;
        
        return false;
    }
    
    vector<int> Core::getNumbers()
    {
        int size = (end_ - pos_); 
        vector<int> numbers(size);
        std::copy(pos_, end_, numbers.begin());
        return numbers;
    }

} // namespace Oi
