#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "persons.h"
#include <iomanip>

using namespace std;

/////////////////////////////////////////////////////////////Empty Stock///////////////////////////////////////////////////////
void EmptyStock::setEmptyStockName(const string s) 
{
    emptyStock.setName(s);
}

std::string EmptyStock::getEmptyStockName() const 
{
    return emptyStock.getName();
}

void EmptyStock::setEmptyStockSKU(int sku) 
{
    emptyStock.setSKU(sku);
}

int EmptyStock::getEmptyStockSKU() const 
{
    return emptyStock.getSKU();
}

void EmptyStock::setEmptyStockSalePrice(int price) 
{
    emptyStock.setSalePrice(price);
}

int EmptyStock::getEmptyStockSalePrice() const 
{
    return emptyStock.getSalePrice();
}

void EmptyStock::setEmptyStockStockQuantity(int quantity) 
{
    emptyStock.setStockQuantity(quantity);
}

int EmptyStock::getEmptyStockStockQuantity() const 
{
    return emptyStock.getStockQuantity();
}

void EmptyStock::setEmptyStockPurchasePrice(int price) 
{
    emptyStock.setPurchasePrice(price);
}

int EmptyStock::getEmptyStockPurchasePrice() const 
{
    return emptyStock.getPurchasePrice();
}

void EmptyStock::setEmptyStockCategory(const string& cat) 
{
    emptyStock.setCategory(cat);
}

std::string EmptyStock::getEmptyStockCategory() const 
{
    return emptyStock.getCategory();
}

void EmptyStock::setEmptyStockDepartment(const string& department) 
{
    emptyStock.setDep(department);
}

std::string EmptyStock::getEmptyStockDepartment() const 
{
    return emptyStock.getDep();
}


////////////////////////////Admin//////////////////////////
    void Person::setFullname(string name)
    {
        fullname = name;
    }
    string Person::getFullname() const
    {
        return fullname;
    }
    void Person::setEmail(string e)
    {
        email = e;
    }
    string Person::getEmail() const
    {
        return email;
    }
    void Person::setFullName(const string& name)
    {
        fullname = name;
    }

    string Person::getFullName() const
    {
        return fullname;
    }

    void Person::setEmail(int userEmail)
    {
        email = userEmail;
    }


    void Person::setPhone(int userPhone)
    {
        Phone = userPhone;
    }

    int Person::getPhone() const
    {
        return Phone;
    }

    void Person::setAddress(const string& userAddress)
    {
        Address = userAddress;
    }

    string Person::getAddress() const
    {
        return Address;
    }

    void Person::setUsername(string xusername)
    {
        username = xusername;
    }

    string Person::getUsername() const
    {
        return username;
    }
    void Person::setPassword(string xPass)
    {
        password = xPass;
    }
    string Person::getPassword() const
    {
        return password;
    }

    void Admin::AddProducts()
    {
        inv = new Inventory;
        string t1, t2, t3, temp, temp2;
        ifstream ifs("data.txt");

    depnono:
        cout << "Enter the name of the Department the product is in: ";
        std::cin >> t1;

        if (ifs.is_open())
        {
            while (getline(ifs, t3))
            {
                t3 = t3.replace(0, 12, "");

                if (t3 != t1 && ifs.eof() == true)
                {
                    cout << t1 << " not found! Please enter the department name again.\n\n";
                    goto depnono;
                }
                else if (t3 == t1)
                {
                catenono:
                    cout << "Department found! Now enter the name of the Category: ";
                    std::cin >> t2;

                    while (getline(ifs, t3))
                    {
                        t3 = t3.replace(0, 10, "");

                        if (t3 != t2 && ifs.eof() == true)
                        {
                            cout << t2 << t3 << " not found! Please enter the Category name again.\n\n";
                            goto catenono;
                        }
                        else if (t3 == t2)
                        {
                            cout << "Category is also found! Now insert data of the product : \n";
                            inv->input_up();
                            ifs.close();
                            ifstream ifs("data.txt");
                            ofstream e("temp.txt");
                            while (getline(ifs, temp2))
                            {
                                temp = temp2;
                                temp2 = temp2.replace(0, 10, "");

                                if (temp2 == t2)
                                {
                                    e << "Category : " << t2 << endl;
                                    e << inv->getName() << ", " << inv->getSKU() << ", " << inv->getSalePrice() << ", " <<inv->getStockQuantity() <<". " << inv->getPurchasePrice() << ", " << t2 << ", "<<t1<<"\n";
                                }

                                else
                                {
                                    e << temp << "\n";
                                }
                            }
                            ifs.close();
                            e.close();
                            std::remove("data.txt");
                            std::rename("temp.txt", "data.txt");

                        }
                    }
                }
            }
        }
        delete inv;
    }



    void Admin::DeleteProducts()
    {
        string t, te;
        cout << "Enter the Name of the Product you want to delete: ";
        getline(cin, t);
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
        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");

    }
    void Admin::UpdateProducts()
    {
        string t, te;
        inv = new Inventory;
        cout << "Enter the Name of the Product you want to update: ";
        getline(cin, t);
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
                    inv->input_add();
                    e << inv->getName() << ", " << inv->getSKU() << ", " << inv->getSalePrice() << ", " << inv->getStockQuantity() << ". " << inv->getPurchasePrice() << ", " << inv->getCategory() << ", " << inv->getDep() << "\n";
                 
                }

                else
                {
                    e << l << "\n";
                }

            }
        }

        delete inv;
        f.close();
        e.close();

        remove("data.txt");
        rename("temp.txt", "data.txt");
    }

    void Admin::AddProductCategories()
    {
        string t1, t2, t3, temp, temp2;
        int e1;
        ifstream ifs("data.txt");
        ofstream e("temp.txt");

    depnono:
        cout << "Enter the name of the Department the product is in: ";
        std::cin >> t1;
        if (ifs.is_open())
        {
            while (getline(ifs, t3))
            {
                temp = t3;
                t3 = t3.replace(0, 12, "");
                if (t3 != t1 && ifs.eof() == true)
                {
                    cout << t1 << " not found! Please renter the department name\n\n";
                    goto depnono;
                }
                else if (t3 == t1)
                {
                catenono:
                    cout << "Department found! Now enter the name of the new Category you want to add: ";
                    std::cin >> t2;
                    e << "Department: " << t3 << endl;
                    e << "Category: " << t2 << endl;

                }
                else
                {
                    e << temp << endl;
                }
            }
            cout << "Operation Successful\n";
        }
        ifs.close();
        e.close();
        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");
    }
    void Admin::UpdateProductCategories()
    {
        string t, te, t2;
        string dep, cat;
        inv = new Inventory;
        cout << "Enter the Name of the Category you want to update: ";
        std::cin >> t;
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
                    std::cin >> t2;
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
        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");


    }
    void Admin::DeleteProductCategories()
    {
        string t, te, temp; int c = 0;
        bool found = false;

        cout << "Enter the Name of the Category you want to delete: ";
        std::cin >> t;

        ifstream f("data.txt");
        ofstream e("temp.txt");

        while (getline(f, te))
        {
            temp = te;
            te = te.replace(0, 10, "");

            if (te == t)
            {
                found = true;
            }
            else if (temp.substr(0, 10) == "Category : " || temp.substr(0,12) == "Department: ")
            {
                found = false;
            }


            if (found == true)
            {   
                c++;
                continue;
            }
            else if (te != t && c == 0 && f.eof() == true)
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



        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");

        cout << "Category successfully deleted.\n";
    }
    void Admin::AddDepartments()
    {

        string t1, t2, t3, temp, temp2;
        int e1;
        ifstream ifs("data.txt");
        ofstream e("temp.txt");

    depnono:
        cout << "Enter the name of the Department: ";
        std::cin >> t1;
        if (ifs.is_open())
        {
            while (getline(ifs, t2))
            {
                e << "Department: " << t1 <<"\n";
                e << t2 << "\n";
            }

        }
        ifs.close();
        e.close();
        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");

    }
    void Admin::UpdateDepartments()
    {
        string t, te, t2; bool find = false;
        string dep, cat;
        cout << "Enter the Name of the Department you want to update: ";
        std::cin >> t;
        cout << "\n";
        ifstream f("data.txt");
        ofstream e("temp.txt");
        {
            string l;


            while (getline(f, l))
            {
                te = l;
                string name = l.replace(0, 12, "");
                if (name == t)
                {   
                    cout << "What do you want to rename it as: ";
                    cin >> t2; cout << "\n";
                    e << "Department: " << t2 <<"\n";
                    find = true;
                }

                else if (find==false && f.eof() == true)
                {
                    cout << "Department not found";
                }
                else
                {
                    e << te << endl;
                }
            }

        }


        f.close();
        e.close();
        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");

    }
    void Admin::DeleteDepartments()
    {
        string t, te, temp; int c = 0;
        bool found = false;

        cout << "Enter the Name of the Department you want to delete: ";
        std::cin >> t;

        ifstream f("data.txt");
        ofstream e("temp.txt");

        while (getline(f, te))
        {
            temp = te;
            te = te.replace(0, 12, "");

            if (te == t)
            {
                found = true;
            }
            else if (found == true && temp.substr(0, 12) == "Department: ")
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



        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");

        cout << "Department successfully deleted.\n";
    }
    void Admin::getemptyStock()
    {
        string t, te, temp; int c = 0;int pos; int count = 1; 
        bool found2 = false;
        bool found = false;

        ifstream f("data.txt");
        while (getline(f, te))
        {   
            temp = te;
             te = te.substr(0, 10);
            t = temp.substr(0, 12);
            if ((te.compare("Category: ") == 0) || (t.compare("Department: ") == 0) || t.empty() == true)
            {
                continue;
            }
            else
            {

                string line;

                stringstream ss(temp);
                string sname, id, sale_pri, stock, pur_pri, category, dep;
                getline(ss, sname, ',');
                getline(ss, id, ',');
                getline(ss, sale_pri, ',');
                getline(ss, stock, '.');
                getline(ss, pur_pri, ',');
                getline(ss, category, ',');
                getline(ss, dep, ',');

                if (stoi(stock) == 0)
                {
                    EmptyStock* tempq = new EmptyStock[emptystock_size + 1];


                    for (int i = 0; i < emptystock_size; i++)
                    {
                        tempq[i] = emptystock[i];
                    }

                    tempq[emptystock_size].setEmptyStockName(sname);
                    tempq[emptystock_size].setEmptyStockSKU(stoi(id));
                    tempq[emptystock_size].setEmptyStockSalePrice(stoi(sale_pri));
                    tempq[emptystock_size].setEmptyStockStockQuantity(stoi(stock));
                    tempq[emptystock_size].setEmptyStockPurchasePrice(stoi(pur_pri));
                    tempq[emptystock_size].setEmptyStockCategory(category);
                    tempq[emptystock_size].setEmptyStockDepartment(dep);

                    delete[] emptystock;

                    emptystock = tempq;
                    emptystock_size++;
                }
                
            }
           
        }
        
    }

    void Admin::NoOfRestocks()
    {   
        int temp;
        cout << "Please enter for every item how much do you want to restock\n";
        for (int i = 0; i < emptystock_size; i++)
        {
            cout << emptystock[i].getEmptyStockName() << ": ";
            cin >> temp;
            emptystock[i].setEmptyStockStockQuantity(temp);
            cout << "\n";
        }
    }
    void Admin::makeStoreRequest()
    {
        ifstream ifs("VendorRequests.txt");
        ofstream f("temp.txt", ios::app);
        string l, temp; int c = 0;
        int sum = 0;
        if (f.is_open())
            cout << "yes";
        while (getline(ifs, l))
        {
            temp = l.replace(0, 3, "");
            if(temp == "Pending")
            {
                
                for (int i = 0; i < emptystock_size; i++)
                {
                    f << emptystock[i].getEmptyStockName() << ", " << emptystock[i].getEmptyStockSalePrice() << ", " << emptystock[i].getEmptyStockSalePrice()<<"," << emptystock[i].getEmptyStockStockQuantity() << "\n";
                    sum += emptystock[i].getEmptyStockSalePrice() * emptystock[i].getEmptyStockStockQuantity();
                }

                f << "-------------------------------------------------\n";
                f << "Total: " << sum << "\n";
                f << "<<<------------------------------------------->>>\n\n";
            }
        }
        ifs.close();
        f.close();
        

    
    }


    //----------------------------------------------------------------------Customer-------------------------------------------------------------------//

    void Customer::setCardInfo(const int xno)
    {
        card_info = xno;
    }

    int const Customer::getCardInfo() const
    {
        return card_info;
    }

    void Customer::registerNewCustomer()
    {
        string s; int t;
        cout << "Enter your username\n";
        getline(cin, username);
        cout << "Enter your Password\n";
        getline(cin, password);
        cout << "Enter your name\n";
        getline(cin, fullname);
        cout << fullname << endl;
        cout << "Enter your email\n";
        getline(cin, email);
        cout << "Enter your phone Number\n";
        cin >> Phone;
        cout << "Enter your Address\n";
        cin.ignore();
        getline(cin, Address);
        cout << "Please enter your Card information, Don't worry we will keep this information safe\n";
        cin>>card_info;

        ifstream in("login.txt");
        ofstream e("temp.txt");
        string te, temp; bool found = false;

        if (e.is_open() == true)
            cout << "yes";
        else
            cout << "no";
        while (getline(in, te))
        {   
            temp = te;

            if (te == "->2")
            {
                e << te << "\n";
                found = true;

            }
            else if (found == true)
            {
                e << username << "\n";
                e << password << "\n";
                e << fullname << "\n";
                e << email << "\n";
                e << Phone << "\n";
                e << Address << "\n";
                e << "'" << card_info << "'\n";
                e << "\t\t\t<-------------->\n";
                    e<<te<<"\n";
                found = false;
            }
            else
            {
                e << te << endl;
            }
        }

        in.close();
        e.close();



        std::remove("login.txt");
        std::rename("temp.txt", "login.txt");



    }


    void Customer::createArray4Menu()
   {
        string l;
        ifstream f("data.txt");
        while (getline(f, l))
        {
            if (l.empty() == true)
                continue;

            if ("Category: " == l.substr(0, 10))
            {
                l = l.replace(0, 10, "");

                string* temp = new string[categories_size + 1];

                for (int i = 0; i < categories_size; i++)
                {
                    temp[i] = categories[i];
                }

                temp[categories_size] = l;

                delete[] categories;

                categories = temp;

                categories_size++;
            }
            else if (l.find("Category: ") == string::npos && f.eof())
            {
                f.close();
            }
        }
    }


    void Customer::menu()
    {
        createArray4Menu();
        for (int i = 0; i < categories_size; i++)
        {
            cout << i+1 << ". " << categories[i] << "\n";
        }
    }

    void Customer::operator = (const Inventory& inv)
    {
        this->products->setCategory(inv.getCategory());
        this->products->setDep(inv.getDep());
        this->products->setName(inv.getName());
        this->products->setPurchasePrice(inv.getPurchasePrice());
        this->products->setSalePrice(inv.getSalePrice());
        this->products->setSKU(inv.getSKU());
        this->products->setStockQuantity(inv.getStockQuantity());
    }

    void Customer::menuofProducts(string xname)
    {
       
            string t, te, temp; int c = 0;int pos; int count = 1;
            bool found2 = false;
            bool found = false;

            ifstream f("data.txt");
            
            while (getline(f, te))
            {
               temp = te;
               t = temp.replace(0,10,"");
               temp = te;
                if (t == xname)
                {
                    found = true;
                }
                else if (te.empty() && found == true)
                {
                    c++;

                }

                if (found == true && found2 == true && c==0)
                {

                    string line;

                    stringstream ss(temp);
                    string sname, id, sale_pri, stock, pur_pri, category, dep;
                    getline(ss, sname, ',');
                    getline(ss, id, ',');
                    getline(ss, sale_pri, ',');
                    getline(ss, stock, '.');
                    getline(ss, pur_pri, ',');
                    getline(ss, category, ',');
                    getline(ss, dep, ',');
                    
                    Inventory* tempq = new Inventory[products_size + 1];


                    for (int i = 0; i < products_size; i++)
                    {
                        tempq[i] = products[i];
                    }

                    tempq[products_size].setName(sname);
                    tempq[products_size].setSKU(stoi(id));
                    tempq[products_size].setSalePrice(stoi(sale_pri));
                    tempq[products_size].setStockQuantity(stoi(stock));
                    tempq[products_size].setPurchasePrice(stoi(pur_pri));
                    tempq[products_size].setCategory(category);
                    tempq[products_size].setDep(dep);

                    delete[] products;

                    products = tempq;
                    products_size++;
                }
                else if (c!=0)
                {
                    menu4ProductsDisplay();
                    return;
                }
                if (found == true)
                {
                    found2 = true;
                }
            }

           
            
    }

    void Customer::menu4ProductsDisplay()
    {
        for (int i = 0; i < products_size; i++)
        {
            cout << i + 1 << ". " << products[i].getName() << "\t\t" << products[i].getSalePrice() << "\n";
        }
    }

    string Customer::getCategoryName(int x)
    {
        
        string s;
        s = categories[x];
        return s;
    }

    bool Customer::in_Stock(int x)
    {
        if (products->getStockQuantity() >= 0)
            return true;
        else
            return false;
    }

    Inventory Customer::getProducts(int x)
    {
        return products[x];
    }

    //----------------------------------------------------------------------StoreManager-------------------------------------------------------------------//
    bool StoreManager::updateItem(Inventory inv, int x)
    {
        ifstream f("data.txt");
        ofstream e("temp.txt");
        string l; int val; bool operation = false;



            while (getline(f, l))
            {
                string xname = l.substr(0, l.find(','));
                if (inv.getName() == xname)
                {
                    val = inv.getStockQuantity() - x;
                    if (val >= 0)
                    {
                        e << inv.getName() << ", " << inv.getSKU() << ", " << inv.getSalePrice() << ", " << val <<". " << inv.getPurchasePrice() << ", " << inv.getCategory() << ", " << inv.getDep() << "\n";
                        operation = true;
                    }
                    else
                    {
                        e << l << "\n";

                    }
                }

                else 
                {
                    e << l << "\n";
                }

            }
        
        f.close();
        e.close();

        std::remove("data.txt");
        std::rename("temp.txt", "data.txt");
        if (operation == true)
            return true;
        else
        {
            cout << "Not enough stock, please revise your quantity. Available stock is: " << inv.getStockQuantity() << "\n";
        }

    }

    bool StoreManager:: in_stock(string name)
    {
        ifstream f("data.txt");
            {
                string l, val;
        
        
                while (getline(f, l))
                {   
                    string xname = l.substr(0, l.find(','));
                    if (name == xname)
                    {
                        int pos = l.find('.');
                        int lastCommaPos = l.find_last_of('.');
                        int f_pos = l.find('.');
                        val = l.substr(f_pos+2,lastCommaPos-pos-2);
                        if (stoi(val) > 0)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                      
                    }
        
                    else if (name != xname && f.eof() == true)
                    {
                        cout << "Not found\n";
                        return false;
                    }
        
                }
            }
    }

    /////////////////////////////////////////////////////////Vendor////////////////////////////////////////////////////////
    void Vendor::view_requests()
    {
        int tot = 0;
        ifstream ifs("VendorRequests.txt");
        string l, temp, t; int c = 0; bool c1 = false;
        int sum = 0;
        while (getline(ifs, l))
        {
            t = l;
            temp = l.replace(0, 3, "");
            if (temp == "Pending")
            {
                c1 = true;
                continue;


            }
            
            else if ((temp == "Approved" || temp == "Unapproved" || t.substr(0, 2) == "->") && c1 == true)
            {
                for (int i = 0; i < emptystock_size; i++)
                {
                    cout<<emptystock[i].getEmptyStockName()<<"\n";
                }
                ifs.close();
                return;
            }


            if (c1 == true)
            {
                if (temp.substr(0, 2) == "--" || temp.empty() == true)
                    continue;
                else if (t.substr(0, 7) == "Total: ")
                    tot = stoi(t.replace(0, 7, ""));
            else
                {
                    string line;

                    stringstream ss(t);
                    string sname, id, sale_pri;
                    getline(ss, sname, ',');
                    getline(ss, id, ',');
                    getline(ss, sale_pri, ',');


                    EmptyStock* tempq = new EmptyStock[emptystock_size + 1];
                    for (int i = 0; i < emptystock_size; i++)
                    {
                        tempq[i] = emptystock[i];
                    }

                    tempq[emptystock_size].setEmptyStockName(sname);
                    tempq[emptystock_size].setEmptyStockSKU(stoi(id));
                    tempq[emptystock_size].setEmptyStockSalePrice(stoi(sale_pri));

                    delete[] emptystock;

                    emptystock = tempq;
                    emptystock_size++;
                }
            }
        
        }
        
    }
    void Vendor::acceptreject_request(int x)
    {
        ifstream ifs("VendorRequests.txt");
        ofstream e("temp.txt");
        string l, temp, t; int c = 0; bool c1 = true;
        int sum = 0;
        while (getline(ifs, l))
        {
            t = l;
            temp = l.replace(0, 3, "");
            
                

            if (temp == "Approved" && x == 1)
            {
                e << t << "\n";
                for (int i = 0; i < emptystock_size; i++)
                {
                    e << emptystock[i].getEmptyStockName() << ", " << emptystock[i].getEmptyStockSalePrice() << ", " << emptystock[i].getEmptyStockSalePrice() << "," << emptystock[i].getEmptyStockStockQuantity() << "\n";
                    sum += emptystock[i].getEmptyStockSalePrice() * emptystock[i].getEmptyStockStockQuantity();
                }

                e << "-------------------------------------------------\n";
                e << "Total: " << sum << " \nVendor_Signed\n";
                e << "<<<------------------------------------------->>>\n\n";
            }


            else if (temp == "Unapproved" && x == 0)
            {
                e << t << "\n";
                for (int i = 0; i < emptystock_size; i++)
                {
                    e << emptystock[i].getEmptyStockName() << ", " << emptystock[i].getEmptyStockSalePrice() << ", " << emptystock[i].getEmptyStockSalePrice() << "," << emptystock[i].getEmptyStockStockQuantity() << "\n";
                    sum += emptystock[i].getEmptyStockSalePrice() * emptystock[i].getEmptyStockStockQuantity();
                }

                e << "-------------------------------------------------\n";
                e << "Total: " << sum << " \nVendor_Signed\n";
                e << "<<<------------------------------------------->>>\n\n";

            }
            else if (temp == "Pending" || c != 0)
            {
                
                    if (c == 0)
                    {
                        e << t << "\n";
                        c++;
                    }
                    else if (l.substr(0, 2) == "->")
                    {
                        e << l << "\n";
                        c++;
                    }
                    else if (c == 1)
                    {
                        continue;
                    }
                    else
                    {
                        e << t << "\n";

                    }
                }
                else
                {
                    e << t << "\n";
                }
                if (t.substr(0, 4) == "->  ")
                {
                    c = 0;
                }
                }
        ifs.close();
        e.close();

        remove("VendorRequests.txt");
        rename("temp.txt", "VendorRequests.txt");

        
    }
    //void view_requests(int x)
    //{
    //    fstream f

    //    if (!f) 
    //    {
    //        cout << "Error opening file for writing!" << endl;
    //        return;
    //    }

    //    if (f.empty)
    //    {
    //        int number = 1000000;
    //        // Write the integer to the file
    //        f.write(reinterpret_cast<const char*>(&number), sizeof(number));

    //        // Close the file
    //        f.close();
    //    }

    //    // Open the file in binary mode for reading


    //

    //    return 0;
    //}

   /* int returnStoreCredit()
    {
        std::ifstream inFile("credit.bin", std::ios::binary);

        if (!inFile) {
            std::cout << "Error opening file for reading!" << std::endl;
            return;
        }

        int readNumber;
        inFile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));

        inFile.close();

        return readNumber;
    }*/

    /*void updateStoreCredit(int x)
    {
        ofstream inFile("credit.bin", std::ios::binary);

        if (!inFile) {
            std::cout << "Error opening file for reading!" << std::endl;
            return;
        }
        int credit = returnStoreCredit();
        credit += x;
        inFile.write(reinterpret_cast<char*>(&credit), sizeof(x));

        inFile.close();
    }*/