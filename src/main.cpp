// =====================================================================================
// 
//       Filename:  main.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2010-10-04 14:45:43
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Sigitas Dagilis (), sigidagi@gmail.com
//        Company:  sigidagis
// 
// =====================================================================================


#include	"core/core.h"
#include	<iostream>
#include	<iterator>
#include	<algorithm>
#include	<vector>

using namespace std;

int main()
{
    Oi::Core co;
    co.setLength(9);
    co.start();

    vector<int> vec;
    co.getNumbers(vec); 

    ostream_iterator<int> out_it (cout, ", ");
    copy(vec.begin(), vec.end(), out_it);
    cout << endl;

    bool ret;
    ret = co.tap(100);
    if (ret)
        cout << "Correct!\n";
    else
    {
        co.getNumbers(vec);
        if (vec.empty())
        {
            cout << "Bad luck! Start new game!\n";
            return -1;
        }
        cout << "You tapped on empty field! Try again\n";   

    }

    return 0;
}

