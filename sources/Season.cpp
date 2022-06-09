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
    Team * teams;
    Schedule sched(this->league);
    // run the shcedule for the teams to play against each other
     do
    {
        teams = league.get_teams();
        // play each matchup
        for(int i=0; i< LEAGUESIZE - 1; i++)
        {
            Game game(teams[i], teams[i+1]);
            game.game_start();
        }
        sched.set_next_state();
    }while(sched.is_RoundEnded());

}
Statistics & ex6::Season::get_statistics()
{
    return this->statistics;
}



