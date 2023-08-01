#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "shopping.h"
#include "persons.h"
#include <iomanip>
#include <Windows.h>
#define _WIN32_WINNT 0x0500


    


void AdminUI(string username)
{
    Admin adm;
    int iopt;
    cout << "Welcome " << username << " You have unlocked all the privileges of the Admin\n";
    cout << "Please choose from the following\n";
    cout << "1. Add a New Department\n";
    cout << "2. Add a New Product Category\n";
    cout << "3. Add a New Product\n";
    cout << "4. Update an Existing Department\n";
    cout << "5. Update an Existing Product Category\n";
    cout << "6. Update an Existing Product\n";
    cout << "7. Delete an Existing Department\n";
    cout << "8. Delete an Existing Category\n";
    cout << "9. Delete an Existing Product\n";
    cout << "10. Make Restock Request\n";
    cout << "11. View Store Credit\n";
    cout << "\n\n\n";
    cin >> iopt;
    if (iopt == 1)
    {
        adm.AddDepartments();
    }
    else if (iopt == 2)
    {
        adm.AddProductCategories();
    }
    else if (iopt == 3)
    {
        adm.AddProducts();
    }
    else if (iopt == 4)
    {
        adm.UpdateDepartments();
    }
    else if (iopt == 5)
    {
        adm.UpdateProductCategories();
    }
    else if (iopt == 6)
    {
        adm.UpdateProducts();
    }
    else if (iopt == 7)
    {
        adm.DeleteDepartments();
    }
    else if (iopt == 8)
    {
        adm.DeleteProductCategories();
    }
    else if (iopt == 9)
    {
        adm.DeleteProducts();
    }
    else if (iopt == 10)
    {
        adm.makeStoreRequest();
    }
    else if (iopt == 11)
    {
        // view store credit code here
    }
}


void usernamedisplay(string username)
{
    cout << "\n\n";
    cout  << setw(200) << right << "Logged in as: "<<username << endl;

}


int login(string username, string password, int log)
{

    ifstream in("login.txt");
    if (!in) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    string category;
    int c = 0;
    bool mark = false;

    while (getline(in, line)) {
        if (line.length() > 2)
        {
            if (line.find("->") != string::npos && mark == false)
            {
                category = line.substr(2);
                if (category == to_string(log))
                {
                    mark = true;
                }
            }

            else if (mark == true && line.substr(2) == category)
            {
                return 0;
            }
        }

        if (mark == true)
        {
            if (line == username && mark == true && c == 0)
            {
                c++;
            }
            else if (c == 1 && line == password)
            {
                return 1;
            }
        }


    }

    in.close();
}


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int main()
{
loginpagel:
    DWORD newStyle = WS_CAPTION | DS_MODALFRAME | WS_MINIMIZEBOX | WS_SYSMENU;
    SetWindowLong(hConsole, GWL_STYLE, newStyle);
    SetWindowPos(hConsole, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);
        cout << "Welcome to Shop. Please Select from the following options\n";
        char charopt;
        int log, iopt, choice; bool registered = true;
        string username, password;
        Customer customer;
        StoreManager store_manager;
        Vendor vendor;
        Cart cart;
        Invoicing invo;
        Admin adm;

        cout << "1. Admin\n2. Customer\n3. Vendor\n";
    logl:
        cin >> log;
        if (log > 0 && log < 4)
        {
            cout << "Now enter your login details\n";
            cout << "Enter your username\n";
            cin >> username;

            cout << "Admin enter your password\n";
            cin >> password;

        }
        else
        {
            cout << "Invalid option selected. Please renter the correct choice\n";
            goto logl;
        }
            

        int log_f;
        log_f = login(username, password, log);
        if (log_f == 0 && log == 2)
        {
            cout << "Customer not registered in database. Do you want to register yourself? [Y] or [N]\n";
            yesnol:
            cin >> charopt;
            if (charopt == 'Y' || charopt == 'y')
            {
                customer.registerNewCustomer();
                cout << "Please login again to confirm Registration.\n";
                goto loginpagel;

            }
            else if (charopt == 'n' || charopt == 'n')
            {
                goto loginpagel;
            }
            else
            {
                cout<<"Invalid Choice. Please enter again\n";
                goto yesnol;
            }

        }

        if (log_f == 1)
        {
            if (log == 1)
            {
                AdminUI(username);
            }
            else if (log == 2)
            {
                system("CLS");
                cout << "\n\n\n\n\n\n\n\t\t\t\tWelcome " << username << ". Good to see you back :)\n\t\t\t\t";
                system("pause");
            catmenul:
                system("CLS");
                usernamedisplay(username);
                customer.menu();
            catenterl:
                cout << "Please enter the category";

                cin >> iopt;
                customer.menuofProducts(customer.getCategoryName(iopt - 1));
                cout << "\n\nEnter the product you want to add to cart\n";
                cin >> iopt;
                if (customer.in_Stock(iopt - 1) == true)
                {
                    cout << "Enter the number of products you want to buy\n";
                    int p;
                quantitynono:
                    cin >> p;

                    if (store_manager.updateItem(customer.getProducts(iopt - 1), p) == true)
                    {
                        cart.addtoCart(customer.getProducts(iopt - 1), p);
                        cout << "Item added to cart\n Please choose from the following\n";
                        cout << "1. Go back to Main Menu\n2. View More Products\n3. Change Category\n4. View Cart\n5. Checkout";
                        cin >> choice;
                        if (choice == 1)
                        {
                            goto logl;
                        }
                        else if (choice == 2)
                        {
                            goto catmenul;
                        }
                        else if (choice == 3)
                        {
                            goto catenterl;
                        }
                        else if (choice == 4)
                        {
                            cart.viewCart();
                        }
                        else if (choice == 5)
                        {
                            cart.calculateSumTotal();
                            invo.displayInvoice(cart, 2);
                        }
                    }
                    else
                        goto quantitynono;
                }
                else
                {
                    cout << "Sorry out of stock\n";
                }
            }
            else
                cout << "wrong again\n";

        }
        else if (log == 3)
        {
            cout << "Welcome" << " You have unlocked all the privilidges of the Vendor";
        }
        

    

}
