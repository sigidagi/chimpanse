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
    }
    
    void Core::setLength(unsigned int length)
    {
        if (length >= (unsigned int)vec_.size() )
            return;
        
        length_ = length;
        vec_.erase(vec_.begin() + length, vec_.end());
    }

    int Core::getLength()
    {
        return length_;
    }
    
    void Core::start()
    {
        const int* array = Oi::Random<int, SIZE>::shuffle();
        vec_.clear();
        vec_.resize(length_);
        std::copy(array, array+length_, vec_.begin());
    }

    bool Core::tap(unsigned int number)
    {
        std::vector<int>::iterator it;
        it = std::find(vec_.begin(), vec_.end(), number);
        // if such number exist in a vector then it has to be first
        // otherwise wrong number was taped!
        if (it != vec_.end())
        {
            // corect guess - delete then first in the vector!
            if (number == (unsigned int)vec_[0])
            {
                vec_.erase(vec_.begin());
                return true;
            }
            // clear vector - session is over!
            else
            {
                vec_.clear();
                return false;
            }
        }
        
        // it was tapped accedent field - do nothing with vector. 
        return false;
    }
    
    void Core::getNumbers(std::vector<int>& vec)
    {
        vec.resize(vec_.size());
        std::copy(vec_.begin(), vec_.end(), vec.begin());
    }

} // namespace Oi
