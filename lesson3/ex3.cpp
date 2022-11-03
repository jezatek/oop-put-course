#include <iostream>
#include <string>
#include <cstdlib>
class Person{
private:
    std::string f_name;
    std::string l_name;
    std::string brth_date;
public:
    Person()
    {
        this->f_name="FAILed";
        this->l_name="FAILed";
    }
    Person(std::string wholename)
    {
        this->f_name=wholename.substr(0,wholename.find(' '));
        this->l_name=wholename.substr(wholename.find(' '),wholename.size()-wholename.find(' '));
        this->brth_date="";
    }
    Person(std::string wholename,std::string birth_date)
    {
        this->brth_date=birth_date;
        this->f_name=wholename.substr(0,wholename.find(' '));
        this->l_name=wholename.substr(wholename.find(' '),wholename.size()-wholename.find(' '));
    }
    void whenborn()
    {
        std::cout<<f_name<<" l "<<l_name;
        if(!brth_date.empty())
            std::cout<<" that was born "<<brth_date;
        std::cout<<"\n";
    }
};
class Movie{
private:
    std::string title;
    Person author;
    Person Main_actor;
    float revievs;
public:
    Movie(std::string Title,std::string author_name,std::string Main_actor_fname,float rev)
    {
        this->revievs=-1;
        this->title=Title;
        Person autor(author_name);
        this->author=autor;
        Person mac(Main_actor_fname);
        this->Main_actor=mac;
        this->revievs=rev;
    }
    Movie(std::string Title,std::string author_name,std::string author_birth,std::string Main_actor_fname,std::string Main_actor_birth,float rev)
    {
        this->revievs=-1;
        this->title=Title;
        Person autor(author_name,author_birth);
        this->author=autor;
        Person mac(Main_actor_fname,Main_actor_birth);
        this->Main_actor=mac;
        this->revievs=rev;
    }
    Movie(std::string Title,std::string author_name,std::string Main_actor_fname)
    {
        this->revievs=-1;
        this->title=Title;
        Person autor(author_name);
        this->author=autor;
        Person mac(Main_actor_fname);
        this->Main_actor=mac;
    }
    Movie(std::string Title,std::string author_name,std::string author_birth,std::string Main_actor_fname,std::string Main_actor_birth)
    {
        this->revievs=-1;
        this->title=Title;
        Person autor(author_name,author_birth);
        this->author=autor;
        Person mac(Main_actor_fname,Main_actor_birth);
        this->Main_actor=mac;
    }
    bool good_film(){
        return revievs>4;
    }
    void full_reviev(){
        std::cout<<"Movie: "<<title<<" was made by: ";
        author.whenborn();
        std::cout<<"The main acotr was:";
        author.whenborn();
        if(revievs!=-1){
        std::cout<<"revievs were ";
            if(good_film())
                std::cout<<"really good\n";
            else
                std::cout<<"bad\n";
        }
    }
};
int main()
{

}
