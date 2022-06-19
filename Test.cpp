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
#include <regex>

using namespace ex6;
using namespace std;

TEST_CASE("Game start")
{
    bool val1;
    bool val2;
    // run enough games to know that the values are in range because the results are random
    for(int i=0; i< 100; i++)
    {
        Team A(0.5, "Team A");
        Team B(0.2, "Team B");
        Game g1(A, B);
        CHECK_NOTHROW(g1.game_start());
        // cout << g1.get_homePoints() << endl << g1.get_visitorPoints() << endl;
        val1 = (g1.get_homePoints() >= 55 && g1.get_visitorPoints() >= 50);
        val2 = (g1.get_homePoints() <= 100 && g1.get_visitorPoints() <= 100);
        CHECK(val1);
        CHECK(val2);
    }
}
TEST_CASE("Game- Constructor")
{
    //check that the points are 0 when constructed.
    Team A(0.5, "Team A");
    Team B(0.2, "Team B");
    Game g(A,B);
    CHECK(g.get_homePoints() == 0);
    CHECK(g.get_visitorPoints() == 0);
}

void print(std::vector<Team> * teams)
{
    for(size_t i=0; i< LEAGUESIZE; i++)
    {
        cout << teams->at(i).getName() << " ";
    }
    cout << endl;
}
TEST_CASE("Schedule rotate")
{
    League league;
    Schedule sched(league);
    for(int i=0; i< LEAGUESIZE -1 ; i++)
    {
        sched.set_next_state();
        if(i != LEAGUESIZE -2)
        {
            CHECK(!sched.is_RoundEnded());
        }
        // print(sched.get_teams());
    }
    CHECK(sched.is_RoundEnded());
}


TEST_CASE("Statistics - leading teams")
{
    Team t1(1, "Best_team");
    Team t2(0.99, "Second_best_team");
    Team t3(0.98, "third_best_team");
    vector<Team> teams;
    teams.push_back(t1); teams.push_back(t2); teams.push_back(t3);
    for(int i=0; i< LEAGUESIZE - 3; i++)
    {
        teams.push_back(Team(0,"team " + to_string(i)));
    }
    League league(teams);
    Team & t4 = league.get_teams()->at(0);
    Team & t5 = league.get_teams()->at(1);
    Team & t6 = league.get_teams()->at(2);
    Team lossing_team(0, "sldls");
    Game g(t4,lossing_team);
    while(t4.getRecord().get_wins() - t4.getRecord().get_losses() <= 0)
    {
        // cout << to_string(t4.getRecord().get_wins() - t4.getRecord().get_losses())  + " ";
        g.game_start();
    }
    // cout << endl;
    Game g1(t5, lossing_team);
    while(t5.getRecord().get_wins() - t5.getRecord().get_losses() <= 0)
    {
        // cout << to_string(t5.getRecord().get_wins() - t5.getRecord().get_losses())  + " ";
        g1.game_start();
    }
    // cout << en   dl;
    Game g2(t5, lossing_team);
    while(t6.getRecord().get_wins() - t6.getRecord().get_losses() <= 0)
    {
        // cout << to_string(t6.getRecord().get_wins() - t6.getRecord().get_losses())  + " ";
        g2.game_start();
    }
    
    // cout << t1.getRecord().get_losses() + t1.getRecord().get_wins() << endl;
    Statistics stat(league);
    // print(league.get_teams());
    CHECK_THROWS(stat.get_leading_teams(21));
    CHECK_THROWS(stat.get_leading_teams(-1));
    std::string ret = stat.get_leading_teams(5);
    // cout << ret << endl; 
    // cout << t1.getRecord().get_wins() << endl;  
    // print(league.get_teams());
    std::regex rgx("\\ ");
    std::vector<string> strings;
    std::sregex_token_iterator iter(ret.begin(),
        ret.end(),
        rgx,
        -1);
    std::sregex_token_iterator end;
    for ( ; iter != end; ++iter)
        strings.push_back(*iter );
    bool val1 = true;
    // cout << strings.at(0) + "." << endl << strings.at(1) + "." << endl << strings.at(2) + ".";
    for(size_t i=0; i< 3; i++)
    {
        val1 = val1 && (!(strings.at(i).compare("Best_team")) || !(strings.at(i).compare("Second_best_team")) || !(strings.at(i).compare("third_best_team")));
    }
    CHECK(val1);
    print(league.get_teams());
   
}


TEST_CASE("Statistics - win loss streaks")
{
    Team t1(1, "Best_team");
    Team t2(0, "Second_best_team");
    Team t3(0.98, "third_best_team");
    vector<Team> teams;
    teams.push_back(t1); teams.push_back(t2); teams.push_back(t3);
    for(int i=0; i< LEAGUESIZE - 3; i++)
    {
        teams.push_back(Team(0,"team " + to_string(i)));
    }
    League league(teams);
    int win_counter = 0;
    int last_wins = 0;
    // count 3 win streak
    Team & t4 = league.get_teams()->at(0);
    Team & t5 = league.get_teams()->at(1);
    while(win_counter != 3)
    {
        Game g(t4,t5);
        g.game_start();
        if(t4.getRecord().get_wins() > last_wins)
        {
            win_counter +=1;
        }
        else
        {
            win_counter = 0;
        }
        last_wins = t4.getRecord().get_wins();
    }
    
    Statistics stat(league);
    CHECK(stat.get_longest_winStreak() == 3);
    CHECK(stat.get_longest_lossStreak() == 3);
}

TEST_CASE("Statistics - unique winners")
{   
    Team t1(1, "Best_team");
    Team t2(0.99, "Second_best_team");
    Team t3(0.98, "third_best_team");
    vector<Team> teams;
    teams.push_back(t1); teams.push_back(t2); teams.push_back(t3);
    for(int i=0; i< LEAGUESIZE - 3; i++)
    {
        teams.push_back(Team(0,"team " + to_string(i)));
    }
    League league(teams);
    Team & t4 = league.get_teams()->at(0);
    Team & t5 = league.get_teams()->at(1);
    Team & t6 = league.get_teams()->at(2);
    while(t4.getRecord().get_wins() == 0)
    {
        Game g(t4,t5);
        g.game_start();
    }
    while(t5.getRecord().get_wins() == 0)
    {
        Game g(t5,t6);
        g.game_start();
    }
    while(t6.getRecord().get_wins() == 0)
    {
        Game g(t6,t5);
        g.game_start();
    }
    Statistics stat(league);
    CHECK(stat.get_unique_team_win_counter() == 3);
}


TEST_CASE("Statistics - worst teams")
{
    // winners
    Team t1(1, "Best_team");
    Team t2(0.99, "Second_best_team");
    Team t3(0.98, "third_best_team");
    Team tloss1(0, "worst_team");
    Team tloss2(0, "second_worst_team");
    Team tloss3(0, "third_worst_team");
    vector<Team> teams;
    teams.push_back(t1); teams.push_back(t2); teams.push_back(t3); teams.push_back(tloss1); teams.push_back(tloss2);
    teams.push_back(tloss3);
    for(int i=0; i< LEAGUESIZE - 6; i++)
    {
        teams.push_back(Team(0,"team " + to_string(i)));
    }
    League league(teams);
    print(league.get_teams());
    // lossers
    Team & t4 = league.get_teams()->at(3);
    Team & t5 = league.get_teams()->at(4);
    Team & t6 = league.get_teams()->at(5);
    while( (t4.getRecord().get_wins() - t4.getRecord().get_losses()) >= 0)
    {
        Game g(t4,t1);
        g.game_start();
    }
    while((t5.getRecord().get_wins() - t5.getRecord().get_losses()) >= 0)
    {
        Game g(t5,t1);
        g.game_start();
    }
    while((t6.getRecord().get_wins() - t6.getRecord().get_losses()) >= 0)
    {
        Game g(t6,t1);
        g.game_start();
    }

    Statistics stat(league);
    std::string ret = stat.get_worst_teams(3);
    std::regex rgx("\\ ");
    std::vector<string> strings;
    std::sregex_token_iterator iter(ret.begin(),
        ret.end(),
        rgx,
        -1);
    std::sregex_token_iterator end;
    for ( ; iter != end; ++iter)
        strings.push_back(*iter );
    bool val1 = true;
    // cout << ret << endl;
    print(league.get_teams());
    cout << t4.getRecord().get_wins() - t4.getRecord().get_losses() << endl;
    cout << t5.getRecord().get_wins() - t5.getRecord().get_losses() << endl;
    cout << t6.getRecord().get_wins() - t6.getRecord().get_losses() << endl;

    // cout << strings.at(0) + "." << endl << strings.at(1) + "." << endl << strings.at(2) + ".";
    for(size_t i=0; i< 3; i++)
    {
        val1 = val1 && (!(strings.at(i).compare("worst_team")) || !(strings.at(i).compare("second_worst_team")) || !(strings.at(i).compare("third_worst_team")));
    }
    CHECK(val1);

}
