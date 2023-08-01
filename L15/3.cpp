#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Employee 
{
    protected:
    string nic;
    string first_name;
    string last_name;
public:
    Employee() 
    {
        nic = "";
        first_name = "";
        last_name = "";
    }
    Employee(string nic, string first_name, string last_name) 
    {
        this->nic = nic;
        this->first_name = first_name;
        this->last_name = last_name;
    }
    string getNic() 
    {
        return nic;
    }

    void setNic(string nic) 
    {
        this->nic = nic;
    }

    string getFirstName() 
    {
        return first_name;
    }

    void setFirstName(string first_name) 
    {
        this->first_name = first_name;
    }

    string getLastName() 
    {
        return last_name;
    }

    void setLastName(string last_name) 
    {
        this->last_name = last_name;
    }

    double earnings()
    {
        return 0.0;
    }
};
class SalariedEmployee : private Employee
{
    private:
    double salary;
    public:
    SalariedEmployee() 
    {
        nic = "";
        first_name = "";
        last_name = "";
        salary = 0.0;
    }

    SalariedEmployee(string nic, string first_name, string last_name, double salary) 
    {
        this->nic = nic;
        this->first_name = first_name;
        this->last_name = last_name;
        if(salary<0)
        {
            cout<<"Salary can't be -ve\n";
        }
        else
        {
            this->salary = salary;
        }
    }
    string getNic() 
    {
        return nic;
    }

    void setNic(string nic) 
    {
        this->nic = nic;
    }

    string getFirstName() 
    {
        return first_name;
    }

    void setFirstName(string first_name) 
    {
        this->first_name = first_name;
    }

    string getLastName() 
    {
        return last_name;
    }

    void setLastName(string last_name) 
    {
        this->last_name = last_name;
    }

    void setSalary(double xsalary)
    {
        this->salary = xsalary;
    }
    
    double getSalary()
    {
        return salary;
    } 
    double earnings () 
    {
        return salary;
    }
};

class Comission_Employee: private Employee
{
    double grossSales;
    double comissionRate;
    double salary;

    public:
    Comission_Employee()
    {
        nic = "";
        first_name = " ";
        last_name = " ";
        grossSales = 0;
        comissionRate = 0;
        salary = 0;

    }
    Comission_Employee(string nic, string first_name, string last_name, double grossSales, double comissionRate) : Employee(nic, first_name, last_name)
    {   
        this->nic = nic;
        this->first_name = first_name;
        this->last_name = last_name;
        if(grossSales<0 || comissionRate<0)
        {
            cout<<"Gross Sales or Comission Rate can't be 0\n";
        }

        else
        {
            this->grossSales = grossSales;
            this->comissionRate = comissionRate;
        }
    }

    string getNic() 
    {
        return nic;
    }

    void setNic(string nic) 
    {
        this->nic = nic;
    }

    string getFirstName() 
    {
        return first_name;
    }

    void setFirstName(string first_name) 
    {
        this->first_name = first_name;
    }

    string getLastName() 
    {
        return last_name;
    }

    void setLastName(string last_name) 
    {
        this->last_name = last_name;
    }

    void setCommissionRate(double comissionrate)
    {
        if(comissionrate>0)
        this->comissionRate = comissionrate;
        else
        cout<<"Couldn't set -ve value\n";
    }

    double getcomissionRate()
    {
        return comissionRate;
    }

    void setGrossSales(double grosssales)
    {   if(grosssales>0)
        this->grossSales = grosssales;
        else
        cout<<"Couldn't set -ve value\n";

    }

    double getGrossSales()
    {
        return grossSales;
    }
    
    double getSalary()
    {
        return salary;
    } 
    double earnings () 
    {
        return salary;
    }

};
int main()
{
    SalariedEmployee se("123456789v", "Ali", "Ahmad", 50000.0);
    Comission_Employee ce("987654321v", "Bashir", "Khan", 100000.0, 0.2);

    cout << "Salaried Employee Details" << endl;
    cout << "NIC: " << se.getNic() << endl;
    cout << "First Name: " << se.getFirstName() << endl;
    cout << "Last Name: " << se.getLastName() << endl;
    cout << "Salary: " << se.getSalary() << endl;
    cout << "Earnings: " << se.earnings() << endl;

    cout << endl;

    cout << "Commission Employee Details" << endl;
    cout << "NIC: " << ce.getNic() << endl;
    cout << "First Name: " << ce.getFirstName() << endl;
    cout << "Last Name: " << ce.getLastName() << endl;
    cout << "Gross Sales: " << ce.getGrossSales() << endl;
    cout << "Commission Rate: " << ce.getcomissionRate() << endl;
    cout << "Earnings: " << ce.earnings() << endl;
   system("Color 0B");

return 0;
}