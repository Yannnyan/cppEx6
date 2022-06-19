#include "League.hpp"
#include "Team.hpp"
#include <random>
#include <vector>

using namespace ex6;
using namespace std;
#define SEED 7

ex6::League::League() 
{
    this->teams = new vector<Team>();
    srand(SEED);
    for(int i=0; i < LEAGUESIZE; i++)
    {
        this->teams->push_back(rand_team_generator(i));
    }
}
ex6::League::League(vector<Team> & teams)
{
    srand(SEED);
    this->teams = new vector<Team>;
    size_t i=0;
    for(i=0; i< LEAGUESIZE && i < teams.size(); i++)
    {
        this->teams->push_back(teams.at(i));
    }
    for(; i< LEAGUESIZE; i++)
    {
        this->teams->push_back(rand_team_generator(i));
    }
}

double ex6::League::rand_value_generator()
{
    int val = std::rand();
    return (val / RAND_MAX); 
}
Team ex6::League::rand_team_generator(int i)
{
    string str =  "random team " + to_string(i);
    return Team(rand_value_generator(), str);
}


vector<Team> * ex6::League::get_teams()
{
    return this->teams;
}

