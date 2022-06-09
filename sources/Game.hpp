#ifndef GAME_HPP_
#define GAME_HPP_

#include "Team.hpp"

namespace ex6
{
    class Game
    {
        private:
            Team home_team;
            Team visitor_team;
            int points_home;
            int points_visitor;
            void generate_results();
        
        public:
            Game(Team & home_team, Team & visitor_team);
            void game_start();
            int get_homePoints();
            int get_visitorPoints();
           
    };
}

#endif