#ifndef RECORD_HPP_
#define RECORD_HPP_ 



namespace ex6
{
    class Record
    {
        private:
            int num_wins;
            int num_losses;
            int longest_win_streak;
            int current_win_streak;
            int longest_loss_streak;
            int current_loss_streak;

        public:
            Record();
            void team_won();
            void team_lost();

            int get_longest_win_streak();   
            int get_longest_loss_streak();
            int get_wins();
            int get_losses();
        private:
            void update_streak();
    };
}

#endif


