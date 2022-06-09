#include "Record.hpp"




// ex6::Record::


ex6::Record::Record() : num_wins(0), num_losses(0), longest_win_streak(0) , current_win_streak(0)
{

}
void ex6::Record::team_won()
{
    this->num_wins +=1;
    this->current_win_streak +=1;
    this->current_loss_streak = 0;
    this->update_streak();
    
}
void ex6::Record::team_lost()
{
    this->num_losses +=1;
    this->current_loss_streak +=1;
    this->current_win_streak = 0;
}


int ex6::Record::get_longest_win_streak()
{
    return this->longest_win_streak;
}

int ex6::Record::get_longest_loss_streak()
{
    return this->longest_loss_streak;
}


void ex6::Record::update_streak()
{
    if(this->current_win_streak > this->longest_win_streak)
    {
        this->longest_win_streak = this->current_win_streak;
    }
    if(this->current_loss_streak > this->longest_loss_streak)
    {
        this->longest_loss_streak = this->current_loss_streak;
    }
}


int ex6::Record::get_wins()
{
    return this->num_wins;
}
int ex6::Record::get_losses()
{
    return this->num_losses;
}
