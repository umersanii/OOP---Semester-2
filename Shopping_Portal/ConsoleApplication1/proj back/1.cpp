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

    void input_add()
    {
        cout << "Enter data for the product";
        cout << "\n\nName: ";
        cin.ignore();
        getline(cin, name);
        cout << name;
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

    void input_up()
    {
        cout << "Enter data for the product";
        cout << "\n\nName: ";
        cin.ignore();
        getline(cin, name);
        cout << name;
        cout << "\nSKU: ";
        cin >> SKU;
        cout << "\nSale Price: ";
        cin >> sale_price;
        cout << "\nStock Quantity: ";
        cin >> stock_quantity;
        cout << "\nPurchase Price: ";
        cin >> purchase_price;
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

    Inventory* inv;
public:
    void AddProducts()
    {
        inv = new Inventory;
        string t1, t2, t3, temp, temp2;
        ifstream ifs("data.txt");

    depnono:
        cout << "Enter the name of the Department the product is in: ";
        cin >> t1;

        if (ifs.is_open())
        {
            while (getline(ifs, t3))
            {
                t3 = t3.replace(0, 13, "");

                if (t3 != t1 && ifs.eof() == true)
                {
                    cout << t1 << " not found! Please enter the department name again.\n\n";
                    goto depnono;
                }
                else if(t3 == t1)
                {
                catenono:
                    cout << "Department found! Now enter the name of the Category: ";
                    cin >> t2;

                    while (getline(ifs, t3))
                    {
                        t3 = t3.replace(0, 11, "");

                        if (t3 != t2 && ifs.eof() == true)
                        {
                            cout << t2 << t3 << " not found! Please enter the Category name again.\n\n";
                            goto catenono;
                        }
                        else if (t3 == t2)
                        {
                            cout << "Category is also found! Now insert data of the product : \n";
                            inv->input_add();
                            ifs.close();
                            ifstream ifs("data.txt");

                            ofstream e("temp.txt");
                            if (ifs.is_open())
                                cout << "yes";
                            else
                                cout << "no";
                            while (getline(ifs, temp2))
                            {
                                temp = temp2;
                                temp2 = temp2.replace(0, 11, "");

                                if (temp2 == t2)
                                {
                                    e << "Category : "<<t2 << endl;
                                    e << inv->getName() << ", " << inv->getSKU() << ", " << inv->getSalePrice() << ", " << inv->getPurchasePrice() << ", " << inv->getCategory() << ", " << t2 << ", "<< t1 << "\n";
                                }

                                else
                                {
                                    e  << temp << "\n";
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
        delete inv;
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
        string dep, cat;
        inv = new Inventory;
        cout << "Enter the Name of the Product you want to update: ";
        cin >> t;
        cout << "\n";
        ifstream f("data.txt");
        ofstream e("temp.txt");
        {
            string l;


            while (getline(f, l))
            {
                int pos = l.find(',');
                string name = l.substr(0, pos);
                if (name == t)
                {
                    cout << "Product found!\n";
                    cout << "\nEnter the updated info of that product: ";
                    inv->input_up();
                    int lastCommaPos = l.find_last_of(',');

                    if (lastCommaPos != string::npos) {
                        dep = l.substr(lastCommaPos + 1);
                        l.erase(lastCommaPos);
                        int secondLastCommaPos = l.find_last_of(',');
                        if (secondLastCommaPos != string::npos) {
                            cat = l.substr(secondLastCommaPos + 1);
                        }
                    }
                }

                else if (name != t && f.eof() == true)
                {
                    cout << "Product not found";
                }

            }
        }
        if (f.is_open())
            f.close();

        ifstream f1("data.txt");


        while (getline(f1, te))
        {
            int pos = te.find(',');
            string name = te.substr(0, pos);
            if (name == t)
            {
                e << inv->getName() << ", " << inv->getSKU() << ", " << inv->getSalePrice() << ", " << inv->getPurchasePrice() << ", " << cat << ", " << dep << "\n";

            }

            else
            {
                e << te << "\n";
            }
        }
        f1.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
        delete inv;
    }

    void AddProductCategories()
    {
        string t1, t2, t3, temp, temp2;
        int e1;
        ifstream ifs("data.txt");
        ofstream e("temp.txt");

    depnono:
        cout << "Enter the name of the Department the product is in: ";
        cin >> t1;
        if (ifs.is_open())
        {
            while (getline(ifs, t3))
            {
                temp = t3;
                t3 = t3.replace(0, 13, "");
                if (t3 != t1 && ifs.eof() == true)
                {
                    cout << t1 << " not found! Please renter the department name\n\n";
                    goto depnono;
                }
                else if(t3 == t1)
                {
                catenono:
                    cout << "Department found! Now enter the name of the new Category you want to add: ";
                    cin >> t2;
                    e << "DEPARTMENT : " << t3 << endl;
                    e << "Category : "<<t2 << endl;

                }
                else
                {
                    e << temp << endl;
                }
            }

        }
        ifs.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }
    void UpdateProductCategories()
    {
        string t, te, t2;
        string dep, cat;
        inv = new Inventory;
        cout << "Enter the Name of the Category you want to update: ";
        cin >> t;
        cout << "\n";
        ifstream f("data.txt");
        ofstream e("temp.txt");
        {
            string l;


            while (getline(f, l))
            {
                int pos = l.find(',');
                string name = l.substr(0, pos);
                if (name == t)
                {
                    cout << "Category found!\n";
                    cout << "\nEnter the updated name of that category: ";
                    cin >> t2;
                    e << t2 << endl;
                }

                else if (name != t && f.eof() == true)
                {
                    cout << "Category not found";
                }
                else
                {
                    e << l << endl;
                }

            }
        }
        
        f.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
       
    
    }
    void DeleteProductCategories()
    {
        string t, te, temp; int c = 0;
        bool found = false;

        cout << "Enter the Name of the Category you want to delete: ";
        cin >> t;

        ifstream f("data.txt");
        ofstream e("temp.txt");

        while (getline(f, te))
        {
            temp = te;
            te = te.replace(0, 11, "");

            if (te == t)
            {
                found = true;
            }
            else if (found == true && temp.substr(0,11) == "Category : ")
            {
                found = false;
            }
            

            if (found == true)
            {
                continue;
            }
            else if(te != t && c == 0 && f.eof() == true)
            {
                cout << "Category not found\n";
            }
            else
            {
                e << temp << "\n";

            }
        }

        f.close();
        e.close();

       

        remove("data.txt");
        rename("temp.txt", "data.txt");

        cout << "Category successfully deleted.\n";
    }
    void AddDepartments()
    {
   
            string t1, t2, t3, temp, temp2;
            int e1;
            ifstream ifs("data.txt");
            ofstream e("temp.txt");

        depnono:
            cout << "Enter the name of the Department: ";
            cin >> t1;
            if (ifs.is_open())
            {
                e << "DEPARTMENT : " << t1;
                
            }
            ifs.close();
            e.close();
            remove("data.txt");
            rename("temp.txt", "data.txt");
        
    }
    void UpdateDepartments()
    {
        string t, te, t2;
        string dep, cat;
        inv = new Inventory;
        cout << "Enter the Name of the Department you want to update: ";
        cin >> t;
        cout << "\n";
        ifstream f("data.txt");
        ofstream e("temp.txt");
        {
            string l;


            while (getline(f, l))
            {

                string name = l.substr(0, 13);
                if (name == t)
                {
                    e << "Department : " << t;
                }

                else if (name != t && f.eof() == true)
                {
                    cout << "Category not found";
                }
                else
                {
                    e << l << endl;
                }
            }

            }
        

        f.close();
        e.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

    }
    void DeleteDepartments()
    {
        string t, te, temp; int c = 0;
        bool found = false;

        cout << "Enter the Name of the Department you want to delete: ";
        cin >> t;

        ifstream f("data.txt");
        ofstream e("temp.txt");

        while (getline(f, te))
        {
            temp = te;
            te = te.replace(0, 13, "");

            if (te == t)
            {
                found = true;
            }
            else if (found == true && temp.substr(0, 13) == "DEPARTMENT : ")
            {
                found = false;
            }


            if (found == true)
            {
                continue;
            }
            else if (te != t && c == 0 && f.eof() == true)
            {
                cout << "Department not found\n";
            }
            else
            {
                e << temp << "\n";

            }
        }

        f.close();
        e.close();



        remove("data.txt");
        rename("temp.txt", "data.txt");

        cout << "Department successfully deleted.\n";
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



int main()
{
    int log;
    Admin adm;
    cout << "Enter your username\n";
    string username;
    cin >> username;

    cout << "Admin enter your password\n";
    string password;
    cin >> password;

    if (login(username, password) == true)
    {
        adm.DeleteDepartments();
    }

}

