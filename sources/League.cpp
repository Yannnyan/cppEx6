#include "League.hpp"
#include "Team.hpp"
#include <random>
#include <vector>

using namespace ex6;
using namespace std;
#define SEED 7
#define nameLength 5

ex6::League::League() 
{
    this->teams = new ex6::Team[20];
    srand(SEED);
    for(int i=0; i < LEAGUESIZE; i++)
    {
        this->teams[i] = rand_team_generator(i);
    }
}
ex6::League::League(vector<Team> teams)
{
    this->teams = new Team[20];
    size_t i=0;
    for(i=0; i< LEAGUESIZE && i < teams.size(); i++)
    {
        this->teams[i] = teams.at(i);
    }
    for(; i< LEAGUESIZE; i++)
    {
        this->teams[i] = rand_team_generator(i);
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


Team * ex6::League::get_teams()
{
    return this->teams;
}

