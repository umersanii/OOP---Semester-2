#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Monster
{
    string name;
    public:
    virtual string attack() = 0;
};

class Firemonster : public Monster
{   public:
    string attack()
    {
        return "-10 HP\n";
    }
};

class WaterMonster : public Monster
{   public:
    string attack()
    {
        return "-30 HP\n";
    }
};

class StoneMonster : public Monster
{   public:
    string attack()
    {
        return "-50 HP\n";
}
};

int main()
{
    Firemonster f;
    WaterMonster w;
    StoneMonster s;
    
   system("Color 0B");

cout<<f.attack();
cout<<w.attack();
cout<<s.attack();


return 0;
}
