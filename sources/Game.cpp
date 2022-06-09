#include "Game.hpp"
using namespace ex6;
using namespace std;

#include <random>

#define MAXPOINTS 10

std::default_random_engine ex6::Game::engine;


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
    std::normal_distribution<> h_d{75, 25};
    normal_distribution<> v_d{78, 22};
    this->points_home = h_d(engine);
    this->points_visitor = v_d(engine);
    // calc value points
    int add_home_points = (int)MAXPOINTS * this->home_team.getValue();
    int add_vis_points = (int) MAXPOINTS * this->visitor_team.getValue(); 
    // add extra value points
    this->points_home = points_home + add_home_points > 100 ? 100 : points_home + add_home_points;
    this->points_visitor = points_visitor + add_home_points > 100 ? 100 : points_visitor + add_vis_points;
    // add to the record the results
    if(this->points_home >= this->points_visitor) // home team wins if equal
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



