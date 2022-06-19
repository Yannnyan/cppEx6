#include "Season.hpp"
#include "Schedule.hpp"
#include "Game.hpp"
#include "Team.hpp"


using namespace ex6;

ex6::Season::Season(League & league) : league(league), statistics(league)
{

}

void ex6::Season::run_season()
{
    std::vector<Team> *teams;
    Schedule sched(this->league);
    // run the shcedule for the teams to play against each other
     do
    {
        teams = league.get_teams();
        // play each matchup
        for(size_t i=0; i< LEAGUESIZE - 1; i++)
        {
            Game game(teams->at(i), teams->at(i+1));
            game.game_start();
        }
        sched.set_next_state();
    }while(sched.is_RoundEnded());

}
Statistics & ex6::Season::get_statistics()
{
    return this->statistics;
}



