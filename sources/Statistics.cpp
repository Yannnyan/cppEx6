#include "Statistics.hpp"
#include <stdlib.h>
#include <algorithm>
#include <vector>

ex6::Statistics::Statistics(League & league) : league(league), unique_team_win_counter(0)
{

}
int ex6::Statistics::get_unique_team_win_counter()
{
    this->unique_team_win_counter = 0;
    std::vector<Team> * teams = this->league.get_teams();
    for(size_t i=0; i< LEAGUESIZE; i++)
    {
        if( teams->at(i).getRecord().get_wins() > 0)
        {
            this->unique_team_win_counter +=1;
        }
    }
    return this->unique_team_win_counter;
}

void bublesort(std::vector<ex6::Team> * teams)
{
    for(size_t i=0; i< teams->size(); i++)
    {
        for(size_t j=0; j< teams->size(); j++)
        {
            // swap
            if(teams->at(i) < teams->at(j))
            {
                ex6::Team temp = teams->at(i);
                teams->at(i) = teams->at(j);
                teams->at(j) = temp;
            }
        }
    }
}
std::string ex6::Statistics::get_leading_teams(int num)
{
    if(num > 20 || num <= 0)
    {
        throw("invalid num");
    }
    std::vector<Team> * teams = this->league.get_teams();
    bublesort(teams);
    std::string ret;
    for(size_t i= 0; i  < num; i++)
    {
        ret += teams->at(i).getName();
        ret += " ";
    }
    return ret;
}

int ex6::Statistics::get_longest_winStreak()
{
    int longest_param = 0;
    std::vector<Team> * teams = this->league.get_teams();
    for(size_t i=0; i< LEAGUESIZE; i++)
    {
        if(teams->at(i).getRecord().get_longest_win_streak() > longest_param)
        {
            longest_param = teams->at(i).getRecord().get_longest_win_streak();
        }
    }
    return longest_param;
}
int ex6::Statistics::get_longest_lossStreak()
{
    int longest_param = 0;
    std::vector<Team> * teams = this->league.get_teams();
    for(size_t i=0; i< LEAGUESIZE; i++)
    {
        if(teams->at(i).getRecord().get_longest_loss_streak() > longest_param)
        {
            longest_param = teams->at(i).getRecord().get_longest_loss_streak();
        }
    }
    return longest_param;
}
std::string ex6::Statistics::get_worst_teams(int num)
{
    if(num > 20 || num <= 0)
    {
        throw("invalid num");
    }
    std::vector<Team> * teams = this->league.get_teams();
    bublesort(teams);
    std::string ret;
    for(size_t i= LEAGUESIZE -1; i >= LEAGUESIZE - num; i--)
    {
        ret += teams->at(i).getName();
        ret += " ";
    }
    return ret;

}
std::string ex6::Statistics::undefeated_teams()
{
    std::string ret;
    std::vector<Team> * teams = this->league.get_teams();
    for(size_t i = 0; i< LEAGUESIZE; i++)
    {
        if(teams->at(i).getRecord().get_losses() == 0)
        {
            ret += teams->at(i).getName();
            ret += " ";
        }
    }
    return ret;
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
