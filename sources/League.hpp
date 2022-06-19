#ifndef LEAGUE_HPP_
#define LEAGUE_HPP_
#include "Team.hpp"
#include <string>
#include <vector>

namespace ex6
{
    #define LEAGUESIZE 20

    class League
    {
        private:
            std::vector<Team> * teams;
            double rand_value_generator();
            Team rand_team_generator(int i);
        public:
        /**
         * @brief Construct a new League object
         * 
         */
            League();
            /**
             * @brief Construct a new League object
             * This gets a vector of teams and initializes the league's teams array with the teams in the league
             * the rest gets randomized.
             * @param teams 
             */
            League(std::vector<Team> & teams);
            /**
             * @brief Get the teams object
             * 
             * @return Team* 
             */
            std::vector<Team> * get_teams();
    };
}



#endif




