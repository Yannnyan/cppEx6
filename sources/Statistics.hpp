#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_
#include "League.hpp"
#include <string>

namespace ex6
{
    class Statistics
    {
        private:
            int unique_team_win_counter;
            League & league;
        public:
            Statistics() = delete;
            Statistics(League & league);
            int get_unique_team_win_counter();
            std::string get_leading_teams(int num);             
            int get_longest_winStreak();
            int get_longest_lossStreak();
            /**
             * @brief Get the worst teams in league
             * 
             * @param num 
             * @return std::string 
             */
            std::string get_worst_teams(int num);
            /**
             * @brief get all the teams with 0 losses
             * 
             * @return std::string 
             */
            std::string undefeated_teams();
            std::string get_summary();
        public:
            static int team_comparator(const void * teamA, const void * teamB);
    };
}



#endif