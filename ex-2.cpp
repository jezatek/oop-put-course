#include <iostream>
#include <string>
class apple{
private:
    std::string colour;
    float sweetness;
public:
    apple(){this->colour="Red";this->sweetness=0;}
    apple(std::string c){this->colour=c;this->sweetness=0;}
    apple(float sweet){this->colour="Red";this->sweetness=sweet;}
    apple(int sweet){this->colour="Red";this->sweetness=sweet;}
    apple(std::string c,float sweet){this->colour=c;this->sweetness=sweet;}
    bool good(){return (colour=="Red"&&sweetness>1);}
};
class drawing{
public:
    int beauty;
    drawing(int k){this->beauty=k;}
};
class pencil{
private:
    int amount;
public:
    pencil(float p_a){this->amount=p_a;}
    pencil(int p_a){this->amount=p_a;}
    void put_into_box(int &nr_inbox){amount--;nr_inbox++;}
    drawing draw_sth()
    {
        if(amount>0){amount--; drawing k(1); return k;}
        else{drawing k(0); return k;}
    }
    drawing draw_sth(int usage)
    {
        if(usage<=amount){amount-=usage; drawing k(usage); return k;}
        else{drawing k(0); return k;}
    }
};
int main()
{
    apple *typical=new apple;
    apple sweet(int(13));
    apple weird("Blue");
    apple traitor("Orange",0.7);
    apple last("Red",2.1);
    std::cout<<typical->good()<<" "<<sweet.good()<<" "<<weird.good()<<" "<<traitor.good()<<" "<<last.good()<<"\n";
    int pencilbox=0;
    pencil blue(float(16));
    blue.put_into_box(pencilbox);
    std::cout<<pencilbox<<" in box\n";
    drawing sky=blue.draw_sth();
    drawing mona_lisa=blue.draw_sth(11);
    drawing bluh=blue.draw_sth(1539);
    std::cout<<"nice:"<<sky.beauty<<" very beutifull:"<<mona_lisa.beauty<<" not enough pencils:"<<bluh.beauty<<"\n";
}
