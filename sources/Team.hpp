#ifndef TEAM_HPP_
#define TEAM_HPP_
#include <string>
#include "Record.hpp"

namespace ex6
{
    class Team
    {
        private:
        /**
         * @brief this is the name of the team
         * 
         */
            std::string name;
            /**
             * @brief this is how much the team is valued by a decimal value ranged from 0 to 1
             * 
             */
            double value;
            Record record;
            
        public:
            Team();
            Team(double value, const std::string & name);
            std::string & getName();
            double getValue();
            Record & getRecord();
            bool operator<( Team & teamB);

    };

}




#endif