#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Vehicle
{  
   protected:
   string name;
   int wheels;
   int seats;
   Vehicle()
   {
      name = "";
      wheels = 0;
      seats = 0;
   }

   string getname()
   {
      return name;
   }

   void setname(string xname)
   {
      name = xname;
   }

   int getwheels()
   {
      return wheels;
   }

   void setwheels(int xwheels)
   {
      wheels = xwheels;
   }

   int getseats()
   {
      return seats;
   }

   void setseats(int xseats)
   {
      seats = xseats;
   }
};

class Car : private Vehicle
{
   public:
   Car()
   {
      name = "";
      wheels = 4;
      seats = 0;
   }
   string getname()
   {
      return name;
   }

   void setname(string xname)
   {
      name = xname;
   }

   int getwheels()
   {
      return wheels;
   }
  

   int getseats()
   {
      return seats;
   }

   void setseats(int xseats)
   {
      seats = xseats;
   }

};

class TwoWheeler
{  protected:
   int engine;

   TwoWheeler()
   {
      engine = 0;
   }

   int getengine()
   {
      return engine;
   }

   void setengine(int xengine)
   {
      engine = xengine;
   }
};

class Motorcycle : private TwoWheeler, Vehicle
{
   public:
   Motorcycle()
   {
      name = "";
      wheels = 2;
      seats = 0;
      engine = 0;
   }

   int getengine()
   {
      return engine;
   }

   void setengine(int xengine)
   {
      engine = xengine;
   }

   string getname()
   {
      return name;
   }

   void setname(string xname)
   {
      name = xname;
   }

   int getwheels()
   {
      return wheels;
   }

   void setwheels(int xwheels)
   {
      wheels = xwheels;
   }

   int getseats()
   {
      return seats;
   }

   void setseats(int xseats)
   {
      seats = xseats;
   }
};

class Truck : private Vehicle
{
   string type;
	public:
   Truck()
   {
      name = "";
      wheels = 0;
      seats = 0;
      type = "heavy";
   }

   string getname()
   {
      return name;
   }

   void setname(string xname)
   {
      name = xname;
   }

   int getwheels()
   {
      return wheels;
   }

   void setwheels(int xwheels)
   {
      wheels = xwheels;
   }

   int getseats()
   {
      return seats;
   }

   void setseats(int xseats)
   {
      seats = xseats;
   }

   void settype(string xtype)
   {
      type = xtype;
   }   

   string gettype()
   {
      return type;
   }
};


int main()
{
    Car car;
    Motorcycle motorcycle;
    Truck truck;

    cout << "Enter car name: ";
    string carName;
    getline(cin, carName);
    car.setname(carName);


    cout << "Enter motorcycle name: ";
    string motorcycleName;
    cin.ignore();
    getline(cin, motorcycleName);
    motorcycle.setname(motorcycleName);


    cout << "Enter truck name: ";
    string truckName;
    cin.ignore();
    getline(cin, truckName);
    truck.setname(truckName);

    cout << "Enter number of wheels for truck: ";
    int truckWheels;
    cin >> truckWheels;
    truck.setwheels(truckWheels);

    cout << "Enter truck type: ";
    string truckType;
    cin.ignore();
    getline(cin, truckType);
    truck.settype(truckType);

    cout << "Car: " << car.getname() << ", " << car.getwheels() << " wheels" << endl;
    cout << "Motorcycle: " << motorcycle.getname() << ", " << motorcycle.getwheels() << " wheels" << endl;
    cout << "Truck: " << truck.getname() << ", " << truck.getwheels() << " wheels, " << truck.gettype() << " type" << endl;
  
return 0;
}
