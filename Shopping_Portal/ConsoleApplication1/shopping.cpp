#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "shopping.h"
#include <chrono>
#include <iomanip>
#include <random>


using namespace std;



    void Inventory::input_add()
    {
        cout << "Enter data for the product";
        cout << "\n\nName: ";
        getline(std::cin, name);
        cout << "\nSKU: ";
        std::cin >> SKU;
        cout << "\nSale Price: ";
        std::cin >> sale_price;
        cout << "\nStock Quantity: ";
        std::cin >> stock_quantity;
        cout << "\nPurchase Price: ";
        std::cin >> purchase_price;
        cout << "\nCategory: ";
        std::cin >> category;
        cout << "\nDepartment: ";
        cin >> dep;
    }

    void Inventory::input_up()
    {
        cout << "Enter data for the product";
        cout << "\n\nName: ";
        std::getline(std::cin, name);
        cout << "\nSKU: ";
        std::cin >> SKU;
        cout << "\nSale Price: ";
        std::cin >> sale_price;
        cout << "\nStock Quantity: ";
        std::cin >> stock_quantity;
        cout << "\nPurchase Price: ";
        std::cin >> purchase_price;
    }

    void Inventory::operator = (const Inventory inv)
    {
        this->category = inv.getCategory();
        this->dep = inv.getDep();
        this->name = inv.getName();
        this->purchase_price = inv.getPurchasePrice();
        this->sale_price = inv.getSalePrice();
        this->SKU = inv.getSKU();
        this->stock_quantity = inv.getStockQuantity();
    }

    string Inventory::getName() const
    {
        return name;
    }
    int Inventory::getSKU() const
    {
        return SKU;
    }

    int Inventory::getSalePrice() const
    {
        return sale_price;
    }

    int Inventory::getStockQuantity() const
    {
        return stock_quantity;
    }

    int Inventory::getPurchasePrice() const
    {
        return purchase_price;
    }

    string Inventory::getCategory() const
    {
        return category;
    }
    string Inventory::getDep() const
    {
        return dep;
    }
    void Inventory::setName(const string& newName)
    {
        name = newName;
    }

    void Inventory::setSKU(int newSKU)
    {
        SKU = newSKU;
    }

    void Inventory::setSalePrice(double newSalePrice)
    {
        sale_price = newSalePrice;
    }

    void Inventory::setStockQuantity(int newStockQuantity)
    {
        stock_quantity = newStockQuantity;
    }

    void Inventory::setPurchasePrice(double newPurchasePrice)
    {
        purchase_price = newPurchasePrice;
    }

    void Inventory::setCategory(const std::string& newCategory)
    {
        category = newCategory;
    }
    void Inventory::setDep(const string& newDep)
    {
        dep = newDep;
    }

    /// <summary>
    /// ///////////////////////////////////////////////////////////////////
    /// </summary>
    /// <returns></returns>
        string Cart_Items::getName() const
    {
        return inv->getName();
    }

    void Cart_Items::setName(const string& newName)
    {
        inv->setName(newName);
    }

    int Cart_Items::getSKU() const
    {
        return inv->getSKU();
    }

    void Cart_Items::setSKU(int newSKU)
    {
        inv->setSKU(newSKU);
    }

    int Cart_Items::getSalePrice() const
    {
        return inv->getSalePrice();
    }

    void Cart_Items::setSalePrice(int newSalePrice)
    {
        inv->setSalePrice(newSalePrice);
    }

    int Cart_Items::getStockQuantity() const
    {
        return inv->getStockQuantity();
    }

    void Cart_Items::setStockQuantity(int newStockQuantity)
    {
        inv->setStockQuantity(newStockQuantity);
    }

    int Cart_Items::getPurchasePrice() const
    {
        return inv->getPurchasePrice();
    }

    void Cart_Items::setPurchasePrice(int newPurchasePrice)
    {
        inv->setPurchasePrice(newPurchasePrice);
    }

    string Cart_Items::getCategory() const
    {
        return inv->getCategory();
    }

    void Cart_Items::setCategory(const string& newCategory)
    {
        inv->setCategory(newCategory);
    }

    string Cart_Items::getDep() const
    {
        return inv->getDep();
    }

    void Cart_Items::setDep(const string& newDep)
    {
        inv->setDep(newDep);
    }


    void Cart_Items::setQuantity(int x)
    {
        quantity = x;
    }
    int Cart_Items::getQuantity()
    {
        return quantity;
    }

    Inventory Cart_Items::getInv(int x)
    {
        return inv[x];
    }

    void Cart_Items::setInv(Inventory x)
    {
        this->inv->setName(x.getName());
        this->inv->setSKU(x.getSKU());
        this->inv->setSalePrice(x.getSalePrice());
        this->inv->setStockQuantity(x.getStockQuantity());
        this->inv->setPurchasePrice(x.getPurchasePrice());
        this->inv->setCategory(x.getCategory());
        this->inv->setDep(x.getDep());

    }
     ///////////////////////////////////////////////Cart/////////////////////////////////////////////////////////////////


        Cart_Items Cart::getCart(int x)
        {
            return cart[x];
        }
        
        int Cart::getCartSize()
        {
            return cart_size;
        }
        void Cart::addtoCart(Inventory inv, int xquantity)
        {
            Cart_Items* temp = new Cart_Items[cart_size + 1];

            for (int i = 0; i < cart_size; i++)
            {
                temp[i] = cart[i];
            }

            temp[cart_size].setInv(inv);
            temp[cart_size].setQuantity(xquantity);
            delete[] cart;
            cart = temp;

            cart_size++;
        }

        void Cart::calculateSumTotal()
        {
            sum_total = 0;
            for (int i = 0; i < cart_size; i++)
            {
                sum_total += cart[i].getSalePrice() * cart[i].getQuantity();
            }
        }

        float Cart::getSumTotal()
        {
            return sum_total;
        }
        void Cart::viewCart()
        {
            cout << "Product Name\tQuantity\tPrice\n";
            for (int i = 0; i < cart_size; i++)
            {
                cout << cart[i].getName() << "\t" << cart[i].getQuantity() << "\t" << cart[i].getPurchasePrice() << "\n";
            }
            cout << "---------------------------------------------------------------------------------------------------\n";
            calculateSumTotal();
            cout << "\t\t" << sum_total<<"\n\n";
        }

        ///////////////////////////////////////////////////////////Invoice//////////////////////////////////////////////////////////////

            void Invoicing::displayInvoice(Cart xcart, int x)
            {   
                /*tim = time(nullptr);
                struct tm* localTime = localtime(&tim);  

                char dateTimeString[100];
                strftime(dateTimeString, sizeof(dateTimeString), "%Y-%m-%d %H:%M:%S", localTime);*/

                std::random_device rd; 
                std::mt19937 gen(rd()); 

           
                uniform_int_distribution<int> dis(1, 100);
                int randomNumber = dis(gen);

                fstream f("transactions.txt", ios::app);
                string user;
                if (x == 2)
                {
                    user = "Customer";
                }
                else if (x == 3)
                {
                    user = "Vendor";
                }
                else
                {
                    user = "Admin";
                }
                for (int i = 0; i < xcart.getCartSize(); i++)
                {
                    f << xcart.getCart(i).getName() << "\t" << xcart.getCart(i).getSalePrice() << "\t" << xcart.getCart(i).getQuantity() << "\t" /*<< dateTimeString*/ <<"\n";
                }
                id = randomNumber;
                f << "Invoicing ID: " << id << "\t\t\t\t---------- - " << xcart.getSumTotal() << "\n";
                f << "<------------------------------------------------------------------------------------------->\n\n";
                f.close();

                cout << setw(35) << left << "Item Name";
                cout << setw(10) << left << "Price";
                cout << setw(10) << left << "Quantity" << endl;
                cout << setfill('-') << setw(55) << "" << endl;
                cout << setfill(' ');

                for (int i = 0; i < xcart.getCartSize(); i++)
                {

                    // Output item details in table rows
                    cout << setw(35) << left << xcart.getCart(i).getName();
                    cout << setw(10) << left << xcart.getCart(i).getSalePrice();
                    cout << setw(10) << left << xcart.getCart(i).getQuantity() << endl;
                }

                cout << setfill('-') << setw(55) << "" << endl;
                cout << setfill(' ');

                cout << "Invoicing ID: " << id << endl;
                cout << "User: " << user << endl;
                cout << "Total: " << xcart.getSumTotal() << endl;

                cout << "\t\t-------------------------------------------------------------------------------------------\n";
                cout << "\t\t-------------------------------------------------------------------------------------------\n\n";

            }
            
            void Invoicing::saleRecord(int mode, int t)
            {
               /* tim = time(nullptr);
                struct tm* localTime = localtime(&tim);

                char dateTimeString[100];
                strftime(dateTimeString, sizeof(dateTimeString), "%d-%m-%Y", localTime);*/
                string l;
                fstream f("SalesRecord.txt", ios::app);
                    while (getline(f, l))
                    {
                        if (mode == 1)
                        {
                            f << "->" /* << //localTime*/;
                            f << "Customer\t\t" << t;
                        }
                        else if (mode == 2)
                        {
                            f << "->" /*<< localTime*/;
                            f << "Vendor\t\t" << -t;
                        }
                        cout << "\n\n<------------------------------------------------------------------>\n\n";
                    }
                
            }

            void Invoicing::displaySaleRecord(int start , int end)
            {
                string l, temp; bool found = false;
                ifstream ifs("Sales_Record.txt");
                while (getline(cin, l))
                {
                    temp = l;
                    temp = temp.replace(0, 2, "");
                    if (temp == to_string(start))
                    {
                        {
                            found == true;
                        }

                    }
                    else if (temp == to_string(end))
                    {
                        found == false;
                    }
                   
                }

                if (found == true)
                {
                    cout << l << "\n";
                }
                else
                {
                    return;
                }

                
            }


       
            ///////////////////////////////////////////////DateTime/////////////////////////////////////////////////////


               