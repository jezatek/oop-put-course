#include <iostream>
#include <string>
class Match
{
private:
    int score;
public:
    void o_move(char my_move,char oponent_move){
        score+=(int(my_move)-'X'+1);
        score+=((my_move-oponent_move+'A'-'X'+4)%3)*3;
    }
    int result(){return this->score;}
    Match()
    {
        this->score=0;
    }
};
int main()
{
    Match tournament=Match();
    std::string duel;
    while(!std::getline(std::cin,duel).eof()&&duel!="")
    {
        tournament.o_move(duel[2],duel[0]);
        //std::cout<<adam.result()<<"\n";
    }
    std::cout<<tournament.result()<<"\n";
}
