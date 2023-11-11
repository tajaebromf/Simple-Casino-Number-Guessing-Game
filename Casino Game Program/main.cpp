#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
class user_info{
public:
    std::string user_first;
    std::string user_last;
    double user_balance;
    int wins=0;
    int loses =0;
    double cash_won=0;
    double cash_lost=0;
    void win_and_lose(int& a, int& b, double& c){
        class user_info p2;
        double holder=0;
        holder = c* .50;
        if( a == b){
            wins++;
            cash_won +=holder;
            std::cout<<"\nYou guessed correctly!"<<std::endl;
            c += holder;
            std::cout<<"\nThe amount you have won is: $"<<holder<<std::endl;

        }
        else{
            loses++;
            cash_lost+=holder;
            std::cout<<"\nYOU LOST :("<<std::endl;
            std::cout<<"\nAww try again"<<std::endl;
            c = c - holder;
            std::cout<<"\nThe amount you have lost is: $"<<std::fixed<<std::setprecision(2)<<holder<<std::endl;

        }
    }
};



enum position {left, right, center};

void format (position pos, std::string s, int linelen){
    int spaces = 0;
    center: spaces = (linelen -s.size())/2;

    if (spaces> 0){
        std::cout<<std::string (spaces, ' ');
        std::cout<<s<<std::endl;
    }

}
void header(){
    for (int i =0; i<240;i++){
        std::cout<<'*';
    }
    std::cout<<'\n';
}




int main() {
    std::string user_decision, user_decision2;
    user_info p1;
    int user_number=0;
    int guess;
    double extra_cash=0;
    std:: srand(time(0));
    const int linelength = 120;
    header();
    format(center, "Welcome to TJ'S CASINO NUMBER GUESSING GAME!!!!!!",linelength);
    format(center, "Here are the Rules:",linelength);
    format(center, "The player(you) enter how much money you will like to gamble with, it has to be more than a dollar!", linelength);
    format(center, "The player will guess a number from 1-10 to determine if they will increase there profits", linelength);
    format(center, "If your guess is correct you increase your cash by 50%!!",linelength);
    format(center, "If your guess is wrong you will lose 50% of the cash you bet with :(", linelength);
    format(center, "Of course you can add more cash in the middle of the game.", linelength);
    format(center, "Make sure to not go lower than 1 dollar or you will be kicked out of the program!",linelength);
    format(center, "WELL LET'S START!!",linelength);
    header();
    std::cout<<"Enter your first and last name:";
    std::cin>>p1.user_first>>p1.user_last;
    std::cout<<"Enter how much you want to bet has to be greater than a dollar: $";
    std::cin>>p1.user_balance;
    while(user_decision != "no"){
        if(p1.user_balance<=1){
            std::cout<<"\nError the amount you entered is less than or equal to one dollar!!Please Exit and Try again"<<std::endl;
            break;
        }
        user_number=0;
        guess = (rand()%10)+1;
        std::cout<<"\nGuess a number between 1-10 for the chance to win:";
        std::cin>>user_number;
        p1.win_and_lose(user_number,guess,p1.user_balance);
        std::cout<<"\nThe number was:"<<guess<<std::endl;
        if (p1.user_balance <= 1){
            std::cout<<"\nYou have less than a dollar that is it for today!"<<std::endl;
            user_decision="no";
            break;

        }
        std::cout<<"\nDo you want to continue yes or no:";
        std::cin>>user_decision;

        if(user_decision== "yes"){
            std::cout<<"\nYour current balance is: $"<<p1.user_balance<<std::endl;
            std::cout<<"\nDo you want to add more money? yes or no:";
            std::cin>>user_decision2;
            if(user_decision2 == "yes"){
                std::cout<<"\nHow much will you like to add: $";
                std:: cin>>extra_cash;
                p1.user_balance += extra_cash;
            }
            else{
                continue;
            }
        }


    }
    header();
    format(center, "Thank you for playing my casino game I hope you didn't lose too much money:)", linelength);
    format(center, "Here are your stats for your time playing:",linelength);
    std::cout<<"\t\t\t\t\t\tName: "<<p1.user_first<<" "<<p1.user_last<<std::endl;
    std::cout<<"\t\t\t\t\t\tWins: "<<p1.wins<<std::endl;
    std::cout<<"\t\t\t\t\t\tLoses: "<<p1.loses<<std::endl;
    std::cout<<"\t\t\t\t\t\tFinal Balance: $"<<p1.user_balance<<std::endl;
    std::cout<<"\t\t\t\t\t\tTotal money won: $"<<p1.cash_won<<std::endl;
    std::cout<<"\t\t\t\t\t\tTotal money lost: $"<<p1.cash_lost<<std::endl;
    header();



    return 0;
}
