#include <iostream>
#include <cassert>
class Game
{
public:
    int result();
};
class FakeFootballGame : public Game
{
public:
    int result()
    {
        return 4;
    }
};
int main()
{
    FakeFootballGame *fake=new FakeFootballGame;
    assert(fake->result()==4);
    std::cout<<"done\n";
    assert(fake->result()==3);
}
