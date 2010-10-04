// =====================================================================================
// 
//       Filename:  OiRandom.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-04 09:49:50
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================


#ifndef  OIRANDOM_INC
#define  OIRANDOM_INC

#include	<ctime>
#include	<algorithm>

namespace Oi
{
    template<class T, unsigned int N>
    class Random
    {
        private:
             static T vec_[N];
        public:
            Random()
            {
            }
            
            static const T* shuffle()
            {
                srand(unsigned (time(0)));
                for (unsigned int i = 0; i < N; ++i)
                   vec_[i] = i+1;
               
                std::random_shuffle(vec_, vec_+N);
                return vec_;
            }
    };

 } // namespace Oi   

template<class T, unsigned int N> T Oi::Random<T, N>::vec_[N];

#endif   // ----- #ifndef OIRANDOM_INC  -----
