#include "Game.hpp"
using namespace ex6;
using namespace std;

#include <random>

ex6::Game::Game(Team & home_team, Team & visitor_team) : home_team(home_team), visitor_team(visitor_team), points_home(0), points_visitor(0)
{

}
void ex6::Game::game_start()
{
    generate_results();
}


int ex6::Game::get_homePoints()
{
    return this->points_home;
}

int ex6::Game::get_visitorPoints()
{
    return this->points_visitor;
}

void ex6::Game::generate_results()
{
    std::default_random_engine engine;
    std::normal_distribution<int> d{75, 25};
    normal_distribution<int> d1{78, 22};
    this->points_home = d(engine);
    this->points_visitor = d(engine);
    if(this->points_home >= this->points_visitor)
    {
        this->home_team.getRecord().team_won();
        this->visitor_team.getRecord().team_lost();
    }
    else
    {
        this->home_team.getRecord().team_lost();
        this->visitor_team.getRecord().team_won();
    }
}



