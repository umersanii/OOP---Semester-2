#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Person
{
protected:
    string fullname;
    int email;

public:
    Person() : fullname(""), email(0) {}
    void setFullname(string name)
    {
        fullname = name;
    }
    string getFullname() const
    {
        return fullname;
    }
    void setEmail(int e)
    {
        email = e;
    }
    int getEmail() const
    {
        return email;
    }

};


class Inventory
{
    string name;
    int SKU;
    int sale_price;
    int stock_quantity;
    int purchase_price;
    string category;

public:

    Inventory()
    {
        name = "";
        SKU = 0;
        sale_price = 0;
        stock_quantity = 0;
        purchase_price = 0;
        category = "";

    }

    void input()
    {
        cout << "Enter data for the product";
        cout << "\n\nName: ";
        getline(cin, name);
        cout << "\nSKU: ";
        cin >> SKU;
        cout << "\nSale Price: ";
        cin >> sale_price;
        cout << "\nStock Quantity: ";
        cin >> stock_quantity;
        cout << "\nPurchase Price: ";
        cin >> purchase_price;
        cout << "\nCategory: ";
        cin >> category;
    }

    string getName() const
    {
        return name;
    }
    int getSKU() const
    {
        return SKU;
    }

    int getSalePrice() const
    {
        return sale_price;
    }

    int getStockQuantity() const
    {
        return stock_quantity;
    }

    int getPurchasePrice() const
    {
        return purchase_price;
    }

    string getCategory() const
    {
        return category;
    }

};

class Admin : private Person
{
    Inventory inv;
public:
    void AddProducts()
    {
        string t1, t2, t3, temp, temp2;
        ifstream ifs("data.txt");
    depnono:
        cout << "Enter the name of the Department the product is in: ";
        cin >> t1;
        if (ifs.is_open())
        {
            while (getline(ifs, t3))
            {
                if (t3 != t1)
                {
                    cout << t1 << " not found! Please renter the department name\n\n";
                    goto depnono;
                }
                else
                {
                catenono:
                    cout << "Department found! Now enter the name of the Category: ";
                    cin >> t2;
                    while (getline(ifs, t3))
                    {
                        if (t3 != t2)
                        {
                            cout << t2 << " not found! Please renter the Category name\n\n";
                            goto catenono;
                        }
                        else
                        {
                            cout << "Category is also found! Now insert data of the product : ";
                            inv.input();
                            ofstream e("temp.txt");
                            if (ifs.is_open())
                                cout << "yes";
                            else
                                cout << "no";
                            while (getline(ifs, temp))
                            {

                                if (temp2 == t2)
                                {
                                    e << temp2 << "\n";
                                    e << inv.getName() << ", " << inv.getSKU() << ", " << inv.getSalePrice() << ", " << inv.getPurchasePrice() << ", " << inv.getCategory() << "\n";
                                }

                                else
                                {
                                    e << temp2 << "\n";
                                }
                            }
                            ifs.close();
                            e.close();
                            remove("data.txt");
                            rename("temp.txt", "data.txt");

                        }
                    }
                }
            }
        }
    }



    void DeleteProducts()
    {
        string t, te;
        cout << "Enter the Name of the Product you want to delete: ";
        cin >> t;
        ifstream f("data.txt");
        ofstream e("temp.txt");
        while (getline(f, te))
        {
            int pos = te.find(',');
            string name = te.substr(0, pos);
            if (name == t)
            {
                continue;
            }

            else
            {
                e << te << "\n";
            }
        }
        f.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

    }
    void UpdateProducts()
    {
        string t, te;
        cout << "Enter the Name of the Product you want to update: ";
        cin >> t;
        cout << "\nEnter the updated info of that product: ";
        inv.input();
        cout << "\n";
        ifstream f("data.txt");
        ofstream e("temp.txt");
        while (getline(f, te))
        {
            int pos = te.find(',');
            string name = te.substr(0, pos);
            if (name == t)
            {
                continue;
            }

            else
            {
                e << te << "\n";
            }
        }
        f.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }

    void AddProductCategories()
    {
        string t, te;
        cout << "Enter the Name of the Product Category you want to add: ";
        cin >> t;
        // if()

    }
    void UpdateProductCategories()
    {

    }
    void DeleteProductCategories()
    {

    }
    void AddDepartments()
    {

    }
    void DeleteDepartments()
    {

    }
    void UpdateDepartments()
    {

    }
};

class Invoicing
{
    int invoice_id;
    string item_name;
    int item_quantity;

};

bool login(string username, string password)
{
    fstream cred;
    cred.open("Admin.txt", ios::in);

    if (cred.is_open()) {
        string line;
        bool found_username = false;

        while (getline(cred, line))
        {
            if (line.find(username) != string::npos)
            {
                found_username = true;
                getline(cred, line);
                if (line.find(password) != string::npos)
                {
                    cout << "Access granted" << endl;
                    return true;
                }
                else
                {
                    cout << "Invalid password" << endl;
                    return false;
                }
            }
        }

        if (!found_username) {
            cout << "Invalid username" << endl;
            return false;
        }

        cred.close();
    }
    else
    {
        cout << "File not found" << endl;
        return false;
    }
}

void filewrite()
{

}
int main()
{
    Admin adm;
    cout << "Admin enter your username\n";
    string username;
    cin >> username;

    cout << "Admin enter your password\n";
    string password;
    cin >> password;

    if (login(username, password) == true)
    {
        adm.AddProducts();
        adm.DeleteProducts();
    }


}
