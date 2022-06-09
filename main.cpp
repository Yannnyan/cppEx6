#include "sources/Season.hpp"
#include "sources/League.hpp"
#include <iostream>
#include <stdlib.h>


using namespace ex6;
using namespace std;

int main()
{

    League league;
    Season season(league);
    cout << "----------------     Season started!    --------------- " << "\n";
    season.run_season();
    cout << "----------------     Season ended!    --------------- " << "\n";
    cout << "----------------     Statistical information:    ---------------" << "\n";
    cout << season.get_statistics().get_summary() << endl;
}



