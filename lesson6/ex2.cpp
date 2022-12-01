#include <iostream>
#include <cmath>
class Number
{
public:
    virtual double doubleValue()=0;
};
class Logarithm : public Number{
private:
    double base,argumet;
public:
    double doubleValue(){
        if(this->argumet<=0)
            throw std::logic_error("error: argument cant be negative\n");
        if(this->base==1)
            throw std::logic_error("error: base cant be equal 1\n");
        if(this->base<=0)
            throw std::logic_error("error: base cant be negative\n");
    return log(this->argumet)/log(this->base);
    }
    Logarithm(double in_base,double in_argumet)
    {
        this->argumet=in_argumet;
        this->base=in_base;
        //test a>0
        //test a!=0
        //test b>0
    }
};
int main()
{
        Logarithm dobry=Logarithm(2,16);
        Logarithm ujemny=Logarithm(2,-1);
        Logarithm jedynkowy=Logarithm(1,5);
    try
    {
        std::cout<<dobry.doubleValue()<<"\n";
    }
    catch(std::logic_error &e)
    {
        std::cout<<e.what();
    }
    try
    {
        std::cout<<ujemny.doubleValue()<<"\n";
    }
    catch(std::logic_error &e)
    {
        std::cout<<e.what();
    }
    try
    {
        std::cout<<jedynkowy.doubleValue()<<"\n";
    }
    catch(std::logic_error &e)
    {
        std::cout<<e.what();
    }
}
