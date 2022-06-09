#include "Schedule.hpp"




using namespace ex6;
using namespace std;


ex6::Schedule::Schedule(League & league) : teams(league.get_teams()), init_teams(nullptr)
{
    set_initState();
}

Team * ex6::Schedule::get_teams()
{
    return this->teams;
}


bool ex6::Schedule::is_RoundEnded()
{
    if(this->init_teams == nullptr)
    {
        throw("cannot check if round ended if init_teams is null ptr.");
    }
    if(this->init_teams[1].getName() == this->teams[1].getName())
    {
        return true;
    }
    return false;
}


void ex6::Schedule::set_initState()
{
    this->init_teams = new Team[LEAGUESIZE];
    for(int i=0; i < LEAGUESIZE; i++)
    {
        this->init_teams[i] = this->teams[i];
    }
}

void ex6::Schedule::set_next_state()
{
    Team * temp = &this->teams[1];
    Team * newtemp;
    // fix the first element
    for(int i=1; i< LEAGUESIZE - 1; i++)
    {
        newtemp = &this->teams[i+1];
        this->teams[i+1] = *temp;
        temp = newtemp;
    }
    this->teams[1] = *newtemp;
}
