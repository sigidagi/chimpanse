// =====================================================================================
// 
//       Filename:  OiCore.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-04 19:47:03
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================


#ifndef  OICORE_INC
#define  OICORE_INC

#include	<vector>

using std::vector;

namespace Oi
{
    class Core
    {
        private:
            vector<int> vec_;

        public:
            Core();
            void start();
            void setLength(unsigned int size);
            bool tap(unsigned int number);
            void getNumbers(vector<int>& vec);
    };

} //namespace

#endif   // ----- #ifndef OICORE_INC  -----
