#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person
{
    string name;
    string address;
public:
    Person() 
    {
        name = "";
        address = "";
    }

    void set_n(string n, string add)
    {
        name = n;
        address = add;
    }

    string get_n()
    {
        return name;
    }

    string get_add()
    {
        return address;
    }
};

class Employee : public Person
{
    int Employee_Number;
    int hire_date;
public:
    Employee()
    {
        Employee_Number = 0;
        hire_date = 0;
    }

    void set_en(int en)
    {
        Employee_Number = en;
    }

    void set_hd(int hn)
    {
        hire_date = hn;
    }

    int get_en()
    {
        return Employee_Number;
    }

    int get_hd()
    {
        return hire_date;
    }
};

class ProductionWorker : public Employee
{
    int shift;
    double h_pay_r;
public:
    ProductionWorker()
    {
        shift = 0;
        h_pay_r = 0;
    }

    void set_s(int s)
    {
        shift = s;
    }

    void set_hr(double hr)
    {
        h_pay_r = hr;
    }

    int get_s()
    {
        return shift;
    }

    double get_hr()
    {
        return h_pay_r;
    }
};

void displayProductionWorkers(ProductionWorker p[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Production Worker #" << i+1 << "\n";
        cout << "Name: " << p[i].get_n() << "\n";
        cout << "Address: " << p[i].get_add() << "\n";
        cout << "Employee Number: " << p[i].get_en() << "\n";
        cout << "Hire Date: " << p[i].get_hd() << "\n";
        if(p[i].get_s() == 1)
        	cout << "Shift: Day\n";
        else
        	cout << "Shift: Night\n";
        cout << "Hourly Rate: " << p[i].get_hr() << "\n\n";
    }
}


int main()
{
   system("Color 0B");
    int n;
    string tes1, tes2; int tei; double ted;
    cout<<"How many number of Production workers are working\n";
    cin>>n;
   ProductionWorker * p = new ProductionWorker[n];
   for(int i = 0; i < n; i++)
   {
    cout<<"Enter Name : ";
    cin>>tes1;
    cout<<"\nEnter Address : ";
    cin>>tes2;
   p[i].set_n(tes1, tes2);
   cout<<"\nEnter Employee Number: ";
   cin>>tei;
   p[i].set_en(tei);
   cout<<"\nEnter Hire Date : ";
   cin>>tei;
   p[i].set_hd(tei);
   cout<<"\nEnter Shift (1-2)): ";
   cin>>tei;
   p[i].set_s(tei);
   cout<<"\nEnter Hourly Rate : ";
   cin>>ted;
   p[i].set_hr(ted);
   cout<<"\n";
   }
   cout<<"\n";

   displayProductionWorkers(p, n);

   delete[] p;
return 0;
}
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person
{
    string name;
    string address;
public:
    Person() 
    {
        name = "";
        address = "";
    }

    void set_n(string n, string add)
    {
        name = n;
        address = add;
    }

    string get_n()
    {
        return name;
    }

    string get_add()
    {
        return address;
    }
};

class Employee : public Person
{
    int Employee_Number;
    int hire_date;
public:
    Employee()
    {
        Employee_Number = 0;
        hire_date = 0;
    }

    void set_en(int en)
    {
        Employee_Number = en;
    }

    void set_hd(int hn)
    {
        hire_date = hn;
    }

    int get_en()
    {
        return Employee_Number;
    }

    int get_hd()
    {
        return hire_date;
    }
};

class ProductionWorker : public Employee
{
    int shift;
    double h_pay_r;
public:
    ProductionWorker()
    {
        shift = 0;
        h_pay_r = 0;
    }

    void set_s(int s)
    {
        shift = s;
    }

    void set_hr(double hr)
    {
        h_pay_r = hr;
    }

    int get_s()
    {
        return shift;
    }

    double get_hr()
    {
        return h_pay_r;
    }
};

class TeamLeader : public ProductionWorker
{
    int bonus;
    

public:
    TeamLeader() : bonus(0){}


    void set_bonus(int b)
    {
        bonus = b;
    }
  

    int get_bonus() const 
    { 
        return bonus; 
    }
    
    double calculateSalary(Date & d)
    {
        if(d.get_req_hrs()/8 >= d.get_hrs()/8)
        {
            cout<<"Congratulations! Your "<<d.get_hrs()/8 << "is: "<<bonus<<"$\n";
        }
        else
        {
            cout<<"You didn't get any bonus\n";
        }
    }
};

class Date : public TeamLeader
{
    int req_hrs;
    int hrs;
    public:
    Date() : req_hrs(0), hrs(0) {}
      void set_req_hrs(int rh) 
    {
        req_hrs = rh; 
    }
    void set_hrs(int h) 
    { 
        hrs = h;
    }
    int get_req_hrs() const 
    {
         return req_hrs; 
    }
    int get_hrs() const 
    {
         return hrs; 
    }
};

void displayProductionWorkers(ProductionWorker p[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Production Worker #" << i+1 << "\n";
        cout << "Name: " << p[i].get_n() << "\n";
        cout << "Address: " << p[i].get_add() << "\n";
        cout << "Employee Number: " << p[i].get_en() << "\n";
        cout << "Hire Date: " << p[i].get_hd() << "\n";
        if(p[i].get_s() == 1)
        	cout << "Shift: Day\n";
        else
        	cout << "Shift: Night\n";
        cout << "Hourly Rate: " << p[i].get_hr() << "\n\n";
    }
}


int main()
{
   system("Color 0B");
    int n;
    string tes1, tes2; int tei; double ted;
    cout<<"How many number of Production workers are working\n";
    cin>>n;
   Date * p = new Date[n];
   for(int i = 0; i < n; i++)
   {
    cout<<"Enter Name : ";
    cin>>tes1;
    cout<<"\nEnter Address : ";
    cin>>tes2;
   p[i].set_n(tes1, tes2);
   cout<<"\nEnter Employee Number: ";
   cin>>tei;
   p[i].set_en(tei);
   cout<<"\nEnter Hire Date : ";
   cin>>tei;
   p[i].set_hd(tei);
   cout<<"\nEnter Shift (1-2)): ";
   cin>>tei;
   p[i].set_s(tei);
   cout<<"\nEnter Hourly Rate : ";
   cin>>ted;
   p[i].set_hr(ted);
   cout<<"\nEnter bonus: ";
   cin>>ted;
   p[i].set_bonus(ted);
   cout<<"\nEnter Required Hours: ";
   cin>>ted;
   p[i].set_hrs(ted);
   cout<<"\nEnter Hours Worked: ";
   cin>>ted;
   p[i].set_hrs(ted);
   cout<<"\n";
   }
   cout<<"\n";

   displayProductionWorkers(p, n);

   delete[] p;
return 0;
}
