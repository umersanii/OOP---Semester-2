#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>


using namespace std;
class Inventory
{protected:
    string name;
    int SKU;
    int sale_price;
    int stock_quantity;
    int purchase_price;
    string category;
    string dep;

public:

    Inventory()
    {
        name = "";
        SKU = 0;
        sale_price = 0;
        stock_quantity = 0;
        purchase_price = 0;
        category = "";
        dep = "";
    }

    void input_add();
    void input_up();
    string getName() const;
    int getSKU() const;

    int getSalePrice() const;

    int getStockQuantity() const;

    int getPurchasePrice() const;

    string getCategory() const;
    string getDep() const;
    void setName(const string& newName);

    void setSKU(int newSKU);

    void setSalePrice(double newSalePrice);

    void setStockQuantity(int newStockQuantity);

    void setPurchasePrice(double newPurchasePrice);


    void setCategory(const string& newCategory);
    void setDep(const string& newDep);

    void operator = (const Inventory);
};

class Cart_Items
{
    Inventory* inv;
    int quantity;

public:
    Cart_Items() : quantity(1) { inv = new Inventory(); }
    void setQuantity(int x);
    int getQuantity();
    Inventory getInv(int x);
    void setInv(Inventory x);
    std::string getName() const;
    void setName(const std::string& newName);

    int getSKU() const;
    void setSKU(int newSKU);

    int getSalePrice() const;
    void setSalePrice(int newSalePrice);

    int getStockQuantity() const;
    void setStockQuantity(int newStockQuantity);

    int getPurchasePrice() const;
    void setPurchasePrice(int newPurchasePrice);

    std::string getCategory() const;
    void setCategory(const std::string& newCategory);

    std::string getDep() const;
    void setDep(const std::string& newDep);

   
};

class Cart
{
private:
    Cart_Items* cart;
    int cart_size;
    float sum_total;
public:
    Cart_Items getCart(int x);
    Cart()
    {
        sum_total = 0.0;
        cart_size = 0;
    }
    ~Cart()
    {
        delete[] cart;
    }
    int getCartSize();
    void addtoCart(Inventory inv, int xquantity);
    float getSumTotal();
    void viewCart();
    void calculateSumTotal();

};

class Invoicing
{
    int id;
    time_t tim;

public:
    void displayInvoice(Cart xcart, int x);
    void saleRecord(int mode, int x);
    void displaySaleRecord(int start, int end);
};

struct DateTime 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    void gettimedate();
   
};