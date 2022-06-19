#include "Schedule.hpp"
#include <algorithm>
#include <vector>


using namespace ex6;
using namespace std;


ex6::Schedule::Schedule(League & league) : teams(league.get_teams()), init_teams(nullptr)
{
    set_initState();
}

std::vector<Team> * ex6::Schedule::get_teams()
{
    return this->teams;
}


bool ex6::Schedule::is_RoundEnded()
{
    if(this->init_teams == nullptr)
    {
        throw("cannot check if round ended if init_teams is null ptr.");
    }
    if(init_teams->at(1).getName() == teams->at(1).getName())
    {
        return true;
    }
    return false;
}


void ex6::Schedule::set_initState()
{
    if(init_teams != nullptr)
    {
        throw("cannot instantiate new intiState.");
    }
    init_teams = new std::vector<Team>;
    for(size_t i=0; i < LEAGUESIZE; i++)
    {
        init_teams->push_back(teams->at(i));
    }
}

void ex6::Schedule::set_next_state()
{
   std::rotate(teams->begin()+1, teams->begin() +2, teams->end());
}
