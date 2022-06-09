#ifndef SEASON_HPP_
#define SEASON_HPP_

#include "League.hpp"
#include "Statistics.hpp"


namespace ex6
{
    class Season
    {
        private:
            League league;
            Statistics statistics;
        public:
            Season() = delete;
            Season(League & league);

            void run_season();
            Statistics & get_statistics();
            
    };
}





#endif


