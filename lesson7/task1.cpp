#include <iostream>
#include <string>
class Elf
{
private:
    int calories;
public:
    void dish(std::string cal){this->calories+=std::stoi(cal);}
    int result(){return this->calories;}
    Elf(int f_cal)
    {
        this->calories=f_cal;
    }
};
class Bestelf
{
private:
    int item;
public:
    int result(){return this->item;}
    Bestelf (int k){this->item=k;}
    void newelf(int k)
    {
        item=std::max(item,k);
    }
};
int main()
{
    std::string cal;
    Elf elf = Elf(0);
    Bestelf adam=Bestelf(0);
    while(!std::getline(std::cin,cal).eof()&&cal[0]!='-')
    {
        if(cal==""){
            adam.newelf(elf.result());
            elf=Elf(0);
        }
        else
            elf.dish(cal);
        //std::cout<<adam.result()<<"\n";
    }
    std::cout<<adam.result()<<"\n";
}
