#include "sources/Season.hpp"
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/Schedule.hpp"
#include "sources/League.hpp"
#include "sources/Statistics.hpp"
#include "sources/Record.hpp"

#include "doctest.h"
#include <string>
#include <iostream>

using namespace ex6;
using namespace std;

TEST_CASE("Game start")
{
    // run enough games to know that the values are in range because the results are random
    for(int i=0; i< 100; i++)
    {
        Team A(0.5, "Team A");
        Team B(0.2, "Team B");
        Game g1(A, B);
        CHECK_NOTHROW(g1.game_start());
        cout << g1.get_homePoints() << endl << g1.get_visitorPoints() << endl;
        bool val = (g1.get_homePoints() >= 55 && g1.get_visitorPoints() >= 50);
        CHECK(val);
    }
   
}


