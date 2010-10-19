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
        length_ = SIZE;
    }
    
    void Core::setLength(unsigned int length)
    {
        if (length > SIZE )
            return;
       
        length_ = length;
       
        start();
    }

    int Core::getLength()
    {
        return length_; 
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
        it = std::find(vec_.begin(), vec_.begin()+length_, number);
        // if such number exist in a vector then it has to be first
        // otherwise wrong number was taped!
        if (it != vec_.begin()+length_)
        {
            if (number == (unsigned int)*pos_)
            {
                ++pos_;
                return true;
            }
            else
            {
                pos_ = vec_.begin()+length_;
                return false;
            }
        }
        
        // it was tapped accedent field - do nothing with vector. 
        return false;
    }

    bool Core::isLast()
    {
        if (pos_ == vec_.begin()+length_)
            return true;
        
        return false;
    }
    
    vector<int> Core::getNumbers()
    {
        vector<int> numbers;
        if (pos_ >= vec_.begin()+length_)
            return numbers;
        
        int size = vec_.begin()+length_ - pos_;
        numbers.resize(size);
        std::copy(pos_, vec_.begin()+length_, numbers.begin());
        return numbers;

    }

} // namespace Oi
