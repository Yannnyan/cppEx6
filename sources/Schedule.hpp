#ifndef SCHEDULE_HPP_
#define SCHEDULE_HPP_
#include "Team.hpp"
#include "League.hpp"

namespace ex6
{
    class Schedule
    {
        private:
            Team * teams;
            Team * init_teams;
        
        public:
            Schedule() = delete;
            Schedule(League & league);
            /**
             * @brief Set the next matching
             * 
             */
            void set_next_state();
            /**
             * @brief 
             * 
             * @return true if the current teams equal to the initial state 
             * @return false 
             */
            bool is_RoundEnded();
            /**
             * @brief Get the current matching of the teams
             * 
             * @return Team* 
             */
            Team * get_teams();
        private:
            /**
             * @brief Set the initial state of the team matching
             * 
             */
            void set_initState();

    };
}



#endif




