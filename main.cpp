#include "sources/Season.hpp"
#include "sources/League.hpp"
#include "sources/Game.hpp"
#include "sources/Statistics.hpp"

#include <iostream>
#include <stdlib.h>


using namespace ex6;
using namespace std;

int main()
{

    // League league;
    // Season season(league);
    // cout << "----------------     Season started!    --------------- " << "\n";
    // season.run_season();
    // cout << "----------------     Season ended!    --------------- " << "\n";
    // cout << "----------------     Statistical information:    ---------------" << "\n";
    // cout << season.get_statistics().get_summary() << endl;

    Team t1(1, "Best_team");
    Team t2(0.99, "Second_best_team");
    Team t3(0.98, "third_best_team");
    vector<Team> teams;
    teams.push_back(t1); teams.push_back(t1); teams.push_back(t3);
    for(int i=0; i< LEAGUESIZE - 3; i++)
    {
        teams.push_back(Team(0,"team " + to_string(i)));
    }
    League league(teams);
    Game g(t1,teams[3]);
    g.game_start();
    Game g1(t2, teams[3]);
    g1.game_start();
    Game g2(t3, teams[3]);
    g2.game_start();
    // cout << t1.getRecord().get_losses() + t1.getRecord().get_wins() << endl;
    Statistics stat(league);
    std::string ret = stat.get_leading_teams(5);
    
}



