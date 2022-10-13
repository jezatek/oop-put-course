#include <iostream>
#include <vector>
class room
{
    public:
        int nr;
        int nr_people=0;
};
class person
{
    public:
        bool student;
        std::string name;
        int age;
        bool isinroom=0;
        room &curr_room;
        void out_room()
        {
            if(!isinroom)
                std::cout<<"person "<<name<<" is not in room\n";
            else
            {
                curr_room.nr_people--;
                isinroom=false;
            }
        }
        void in_room(room &Room)
        {
            if(isinroom)
                out_room();
            curr_room=Room;
            isinroom=1;
            Room.nr_people++;
        }
};
int main()
{
    person me;
    me.age=19;
    me.name="Michal";
    me.student =1;
    room a158;

}
