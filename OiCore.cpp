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

#include	"OiCore.h"
#include	"OiRandom.h"
#include	<algorithm>

#define	SIZE 36			//

namespace Oi
{
    Core::Core()
    {
        vec_.resize(SIZE);
    }
    
    void Core::setLength(unsigned int length)
    {
        if (length >= (unsigned int)vec_.size() )
            return;
        
        vec_.erase(vec_.begin() + length, vec_.end());
    }

    void Core::start()
    {
        int size = (int)vec_.size();
        const int* array = Oi::Random<int, SIZE>::shuffle();
        std::copy(array, array+size, vec_.begin());
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
