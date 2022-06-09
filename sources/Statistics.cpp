#include "Statistics.hpp"
#include <stdlib.h>

ex6::Statistics::Statistics(League & league) : league(league), unique_team_win_counter(0)
{

}
int ex6::Statistics::get_unique_team_win_counter()
{
    this->unique_team_win_counter = 0;
    Team * teams = this->league.get_teams();
    for(int i=0; i< LEAGUESIZE; i++)
    {
        if( teams->getRecord().get_wins() > 0)
        {
            this->unique_team_win_counter +=1;
        }
    }
    return this->unique_team_win_counter;
}
std::string ex6::Statistics::get_leading_teams(int num)
{
    if(num > 20 || num < 0)
    {
        throw("invalid num");
    }
    Team * teams = this->league.get_teams();
    qsort(teams , sizeof(Team), LEAGUESIZE, team_comparator);
    std::string ret;
    for(int i=0; i< num; i++)
    {
        ret += teams[i].getName();
        ret += "  ";
    }
    return ret;
}

int ex6::Statistics::team_comparator(const void *  teamA, const void * teamB)
{
    Team * A = (Team *) teamA;
    Team * B = (Team *) teamB;
    if(A->getRecord().get_wins() > B->getRecord().get_wins())
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


int ex6::Statistics::get_longest_winStreak()
{
    int longest_param = 0;
    Team * teams = this->league.get_teams();
    for(int i=0; i< LEAGUESIZE; i++)
    {
        if(teams[i].getRecord().get_longest_win_streak() > longest_param)
        {
            longest_param = teams[i].getRecord().get_longest_win_streak();
        }
    }
    return longest_param;
}
int ex6::Statistics::get_longest_lossStreak()
{
    int longest_param = 0;
    Team * teams = this->league.get_teams();
    for(int i=0; i< LEAGUESIZE; i++)
    {
        if(teams[i].getRecord().get_longest_loss_streak() > longest_param)
        {
            longest_param = teams[i].getRecord().get_longest_loss_streak();
        }
    }
    return longest_param;
}

std::string ex6::Statistics::get_summary()
{
    std::string sum;
    sum += "Longest win streak : " + std::to_string(this->get_longest_winStreak()) + "\n";
    sum += "Longest loss streak : " + std::to_string(this->get_longest_lossStreak()) + "\n";
    sum += "The best 5 teams : " + this->get_leading_teams(5) + "\n";
    sum += "Number of teams that won a game : " + std::to_string(this->get_unique_team_win_counter()) + "\n";
    return sum;
}
