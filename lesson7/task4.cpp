#include <iostream>
#include <string>
class Rangepair
{
private:
    int score;
public:
    void o_move(char f1,char f2,char s1,char s2){
        if((f1<=s1&&f2>=s2)||(f1>=s1&&f2<=s2))score++;
    }
    int result(){return this->score;}
    Rangepair()
    {
        this->score=0;
    }
};
int main()
{
    Rangepair pairs=Rangepair();
    std::string dual;
    while(!std::getline(std::cin,dual).eof()&&dual!="")
    {
        pairs.o_move(dual[0],dual[2],dual[4],dual[6]);
        //std::cout<<adam.result()<<"\n";
    }
    std::cout<<pairs.result()<<"\n";
}
