#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Customer
{
    int ID;
    string name;
    int phone;
    public:
    Customer() 
    {
      ID = 0;
      name = "";
      phone = 0;
    }

    int getID() 
    {
      return ID;
    }

    void setID(int newID) 
    {
      ID = newID;
    }

    string getName() 
    {
      return name;
    }

    void setName(string newName) 
    {
      name = newName;
    }

    int getPhone() 
    {
      return phone;
    }

    void setPhone(int newPhone) 
    {
      phone = newPhone;
    }
};

class Account
{
    protected:
    int no;
    int balance;
    string type;

    public:
    Account() 
    {
         no = 0;
         balance = 0;
         type = "";
      }

      int getNo() 
      {
         return no;
      }

      void setNo(int x) 
      {
         no = x;
      }

      int getBalance() 
      {
         return balance;
      }

      void setBalance(int x) 
      {
         balance = x;
      }

      string getType() 
      {
         return type;
      }

      void setType(string x) 
      {
         type = x;
      }
};

class SavingAccounts : private Account
{
    int interest_rate;
    int min_balance;
    int max_balance;
    public:
    SavingAccounts()
    {
        interest_rate = 0;
        min_balance = 0;
        max_balance = 0;
        type = "Savings";
    }
     int getNo() 
      {
         return no;
      }

      void setNo(int x) 
      {
         no = x;
      }

      int getBalance() 
      {
         return balance;
      }

      void setBalance(int x) 
      {
         balance = x;
      }

      string getType() 
      {
         return type;
      }

      void setType(string x) 
      {
         type = x;
      }
    int get_interest_rate()
    {
        return interest_rate;
    }

    void set_interest_rate(int xinterest_rate)
    {
        interest_rate = xinterest_rate;
    }

    int get_min_balance()
    {
        return min_balance;
    }

    void set_min_balance(int xmin_balance)
    {
        min_balance = xmin_balance;
    }

    int get_max_balance()
    {
        return max_balance;
    }

    void set_max_balance(int xmax_balance)
    {
        max_balance = xmax_balance;
    }
};

class CurrentAccount : private Account
{
    int transaction_limit;
    public:
    CurrentAccount()
    {
        transaction_limit = 0;
    }

    int get_transaction_limit() 
    {
        return transaction_limit;
    }

    void set_transaction_limit(int x) 
    {
        transaction_limit = x;
    }

    int getNo() 
    {
        return no;
    }

    void setNo(int x) 
    {
        no = x;
    }

    int getBalance() 
    {
        return balance;
    }

    void setBalance(int x) 
    {
        balance = x;
    }

    string getType() 
    {
        return type;
    }

    void setType(string x) 
    {
        type = x;
    }
};

class Bank
{
    Customer * c;
    SavingAccounts * sa;
    CurrentAccount * ca;
    int inp1, inp2, inp3;

    public:
    Bank()
    {
        cout<<"Enter no of Customers in the bank: ";
        cin>>inp1;
        c = new Customer [inp1];
        cout<<"\nEnter no of Saving Accounts in the bank: ";
        cin>>inp2;
        sa = new SavingAccounts[inp2];
        cout<<"\nEnter no of Current Accounts in the bank: ";
        cin>>inp3;        
        ca = new CurrentAccount[inp3];
        cout<<"\n";
    }

    void input_customer()
    {   int t1; string s1;
        for (int i = 0; i < inp1; i++)
        {   cout<<"Enter the data for customer "<<i+1<<": \n\n";
            cout<<"Enter the name of the Customer: ";
            cin>>s1;
            c[i].setName(s1);
            cout<<"\nEnter the ID of the Customer: ";
            cin>>t1;
            c[i].setID(t1);
            cout<<"\nEnter the Phone of the Customer: ";
            cin>>t1;
            c[i].setPhone(t1);
            cout<<"\n";
        }        
    }

    void disp_customer()
    {
        for (int i = 0; i < inp1; i++)
        {   
            cout<<"Customer 1 Details: \n\n";
            cout<<"Name: "<<c[i].getName();
            cout<<"\nID: "<<c[i].getID();
            cout<<"\nPhone: "<<c[i].getPhone();
            cout<<"\n\n";
        }

    }

    void input_SavingsAccount()
    {   int t1; string s1;
        for (int i = 0; i < inp2; i++)
        {
            cout<<"Enter Account No: ";
            cin>>t1;
            sa[i].setNo(t1);
            cout<<"\nEnter Balance: ";
            cin>>t1;
            sa[i].setBalance(t1);
            cout<<"\nEnter Interest Rate: ";
            cin>>t1;
            sa[i].set_interest_rate(t1);
            cout<<"\nEnter Max Balance: ";
            cin>>t1;
            sa[i].set_max_balance(t1);
            cout<<"\nEnter Min Balance: ";
            cin>>t1;
            sa[i].set_min_balance(t1);
            cout<<"\n\n";
        }
        
    }

    void disp_SavingsAccount()
    {
        for (int i = 0; i < inp2; i++)
        {   cout<<"Details of the Customer "<<i+1<<": \n\n";
            cout<<"Account No: "<<sa[i].getNo();
            cout<<"\nBalance: "<<sa[i].getBalance();
            cout<<"\nInterest Rate: "<<sa[i].get_interest_rate();
            cout<<"\nMax Balance: "<<sa[i].get_max_balance();
            cout<<"\nMin Balance: "<<sa[i].get_min_balance();
            cout<<"\n\n";
        }
        
    }

    void input_CurrentAccount()
    {
        for (int i = 0; i < inp3; i++)
        {   int t1; string s1;
           cout<<"Enter Data for the Current Account "<<i+1<<": ";
           cout<<"\nEnter Account No: ";
           cin>>t1;
           ca[i].setNo(t1);
           cout<<"\nEnter Balance: ";
           cin>>t1;
           ca[i].setBalance(t1);
           cout<<"\nEnter Transaction Limit: ";
           cin>>t1;
           ca[i].set_transaction_limit(t1);
           cout<<"\n\n";

        }
        
    }

    void disp_CurrentAccount()
    {
    for (int i = 0; i < inp3; i++)
    {   cout<<"Details of the Customer "<<i+1<<": \n\n";
        cout<<"Account No: "<<ca[i].getNo();
        cout<<"\nBalance: "<<ca[i].getBalance();
        cout<<"\nTransaction Limit: "<<ca[i].get_transaction_limit();
        cout<<"\n\n";
    
    }
    }
    ~Bank()
    {
        delete []c;
        delete []sa;
        delete []ca;
    }


};

int main()
{   
    Bank B;
    B.input_customer();
    B.input_SavingsAccount();
    B.input_CurrentAccount();
    B.disp_customer();
    B.disp_SavingsAccount();
    B.disp_CurrentAccount();

   system("Color 0B");

return 0;
}