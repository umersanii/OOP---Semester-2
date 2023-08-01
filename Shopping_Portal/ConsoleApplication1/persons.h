#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "shopping.h"
using namespace std;
class Person
{
protected:
    string fullname;
    string email;
    int Phone;
    string Address;
    string username;
    string password;

public:
    Person() : fullname(""), email(""), Phone(0), Address(""), username(""), password("") {}
    void setFullname(string name);
    string getFullname() const;
    void setEmail(int e);
    void setFullName(const string& name);
    string getFullName() const;
    void setEmail(string userEmail);
    string getEmail() const;
    void setPhone(int userPhone);   
    int getPhone() const;
    void setAddress(const string& userAddress);
    string getAddress() const;
    void setUsername(string xusername);
    string getUsername() const;
    void setPassword(string xPass);
    string getPassword() const;
   // virtual void menu ();
};

class StoreManager : public Person
{
    time_t tim;


public:
    bool updateItem(Inventory inv, int x);
    bool in_stock(string name);

};



class Customer : public Person
{
    int card_info;
    int Phone;
    string* categories;
    int categories_size;
    Inventory* products;
    int products_size;

public:
    Customer() : Phone(0), products_size(0), categories_size(0){}
    void setCardInfo(const int xno);
    int const getCardInfo() const;
    void registerNewCustomer();
    void createArray4Menu();
    void menu();
    Inventory getProducts(int x);
    void menuofProducts(string name);
    bool in_Stock(int x);
    void menu4ProductsDisplay();
    string getCategoryName(int x);
    void operator = (const Inventory& inv);
    ~Customer()
    {
        delete[] categories;

    }
};


class EmptyStock : Inventory
{
    Inventory emptyStock;
    int quantity2beStocked;
public:
    EmptyStock()
    {
        quantity2beStocked = 0;
    }
    Inventory* getEmptyStock() const;
   

    int getEmptyStockSize() const;
   

    int getQuantityToBeStocked() const;
   
    void setEmptyStock(Inventory* stock);
   
    void setEmptyStockSize(int size);
   
    void setEmptyStockName(const string s);
    void setEmptyStockSKU(int sku);
    void setEmptyStockSalePrice(int price);
    void setEmptyStockStockQuantity(int quantity);
    void setEmptyStockPurchasePrice(int price);
    void setEmptyStockCategory(const string& cat);
    void setEmptyStockDepartment(const string& department);

    string getEmptyStockName() const;
    int getEmptyStockSKU() const;
    int getEmptyStockSalePrice() const;
    int getEmptyStockStockQuantity() const;
    int getEmptyStockPurchasePrice() const;
    string getEmptyStockCategory() const;
    string getEmptyStockDepartment() const;



    
};
class Vendor : public Person
{
    EmptyStock* emptystock;
    int emptystock_size;
public:
    void view_requests();
    void acceptreject_request(int x);
};
class Admin
{
    string name;
    string mail;
    Inventory* inv;
    EmptyStock* emptystock;
    int emptystock_size;

    
public:
    Admin() : name(""), mail (""), emptystock_size(0) {}
    void AddProducts();
    void DeleteProducts();
    void UpdateProducts();
    void AddProductCategories();
    void DeleteProductCategories();
    void UpdateProductCategories();
    void AddDepartments();
    void UpdateDepartments();
    void DeleteDepartments();
    void getemptyStock();
    void makeStoreRequest();
    void NoOfRestocks();


};
