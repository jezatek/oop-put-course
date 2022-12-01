#include <iostream>
#include <cmath>
class Aritmetics{
private:
    int a,b;
public:
    Aritmetics(int in_a,int in_b)
    {
        this->a=in_a;
        this->b=in_b;
    }
    int min(){return a<b?a:b;}
    int max(){return a<b?b:a;}
    float avg(){return float(a+b)/2;}
};
int main()
{
    Aritmetics dodatnie=Aritmetics(1,74);
    std::cout<<dodatnie.avg()<<" "<<dodatnie.min()<<" "<<dodatnie.max()<<"\n";
    //I zadanie : Class +-avg dla 2 zmiennych
    //II zadanie: Class Logarithm dla 2 zmiennych (try-catch=throw)
    //logab=lnb/lna
}
