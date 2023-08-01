#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Shopping.h"
#include <iomanip>
#include <Windows.h>

using namespace std;

Person* personptr;
StoreManager storemanager;
Customer customer;
Vendor vendor;
Admin admin;
Cart cart;
Invoicing invoice;

int iopt = 0; int choice = 0; string sopt;
void usernamedisplay(string username)
{
    std::string title = "Los Pollos Hermanos";
    std::string loggedInAs = "Logged in as: " + username;

    int maxLength = 120;
    int availableSpace = maxLength - title.length() - loggedInAs.length();

    if (availableSpace < 0) {
        // If the available space is less than 0, adjust the lengths of the strings
        int excess = std::abs(availableSpace);
        if (excess < loggedInAs.length()) {
            loggedInAs = loggedInAs.substr(0, loggedInAs.length() - excess);
        }
        else {
            loggedInAs.clear();
            title = title.substr(0, maxLength);
        }
    }

    std::string header = title + std::string(availableSpace, ' ') + loggedInAs;
    cout << header;

    //int x = username.length();
    //cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tLogged in as: " << "\033[31m" << username << "\033[0m" << "\n";
    cout << "\033[33m" << setw(124) << setfill('=') << "\033[0m" << "\n\n\n";

}

void bottomUI(int c)
{
    if (c != 0)
    {
        cout << "\n\n";

        cout << "\033[33m" << setw(124) << setfill('=') << "\033[0m" << "\n";
        cout << "\t[\033[32m0\033[0m]. Login Page";
        cout << "\n\n";
    }
    else
    {
        cout << "\n\n";
        cout << "\033[33m" << setw(124) << setfill('=') << "\033[0m" << "\n";
        cout << "\t[\033[32m0\033[0m]. Login Page\t\t\t\t\t\t\t\t\t\t\t[\033[32m999\033[0m]. Back";
        cout << "\n\n";
    }
}

void WelcomeScreen(string username)
{
    system("CLS");
    cout << "\n\n\n\n\n\n\t\n\t\n\n\t\t\t\tWelcome " << "\033[31m" << username << "\033[0m" << ". Good to see you back :)\n\t\t\t\t";
    system("pause");
}

int StoreManagerUI(string username)
{
    cout << "\033[35m";
storemanagerstartl:

    system("CLS");
    usernamedisplay(username);
    cout << "Choose from the following: \n";
    cout << "1. View Store Items\n";
    cout << "2. Update Stock of an Item\n";
    cout << "3. Check if an item is in stock\n";
    cout << "4. View Store Credit\n";
    cout << "5. Update Store Credit\n";
    bottomUI(0);
    cout << "Your Choice: ";
    cin >> iopt;
    if (iopt == 1)
    {
    catenterl:

        usernamedisplay(username);
        customer.menu();
        bottomUI(1);
        cout << "\nPlease enter the category: ";
        cin >> iopt;
        if (iopt == 0)
        {
            return 1;
        }
    quantitynono:

        system("CLS");
        usernamedisplay(username);
        customer.menuofProducts(customer.getCategoryName(iopt - 1));
        customer.menu4ProductsDisplay();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 1;
        }
        else if (iopt == 999)
        {
            goto catenterl;
        }
        goto storemanagerstartl;

    }

    else if (iopt == 2)
    {
    catenter2l:

        usernamedisplay(username);
        customer.menu();
        bottomUI(1);
        cout << "\nPlease enter the category: ";
        cin >> iopt;
        if (iopt == 0)
        {
            return 1;
        }

        system("CLS");
        usernamedisplay(username);
        customer.menuofProducts(customer.getCategoryName(iopt - 1));
        customer.menu4ProductsDisplay();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 1;
        }
        else if (iopt == 999)
        {
            goto catenter2l;
        }
        else
        {
            int p = 0;
            cout << "Enter the No of Stocks you want to add\n";
            cin >> p;
            storemanager.updateItem(customer.getProducts(iopt - 1), p);
            cout << "Product updated successfully\n";
        }
        goto storemanagerstartl;

    }
    else if (iopt == 3)
    {
        cout << "Enter the name of the product:";
        cin >> sopt;
        if (storemanager.in_stock(sopt))
        {
            cout << sopt << " is in stock\n";
        }
        else
        {
            cout << sopt << " is not in stock\n";
        }
        goto storemanagerstartl;
    }
    else if (iopt == 4)
    {
        cout << "The Store has around " << storemanager.returnStoreCredit() << " Rs\n";
    }
    else if (iopt == 4)
    {
        int p = 0;
        cout << "Enter the amount you want to subtract or add to store credit\n";
        storemanager.updateStoreCredit(p);
        cout << "Operation Successful";
    }
}
int AdminUI(string username)
{

adminstartl:
    system("CLS");
    usernamedisplay(username);
    cout << "Welcome " << username << " You have unlocked all the privileges of the Admin\n";
    cout << "Please choose from the following\n";
    cout << "\033[32m1\033[0m. Add a New Department\n";
    cout << "\033[32m2\033[0m. Add a New Product Category\n";
    cout << "\033[32m3\033[0m. Add a New Product\n";
    cout << "\033[32m4\033[0m. Update an Existing Department\n";
    cout << "\033[32m5\033[0m. Update an Existing Product Category\n";
    cout << "\033[32m6\033[0m. Update an Existing Product\n";
    cout << "\033[32m7\033[0m. Delete an Existing Department\n";
    cout << "\033[32m8\033[0m. Delete an Existing Category\n";
    cout << "\033[32m9\033[0m. Delete an Existing Product\n";
    cout << "\033[32m10\033[0m. Make Restock Request\n";
    cout << "\033[32m11\033[0m. View Store Credit\n";
    cout << "\033[32m12\033[0m. Update Store Credit\n";
    cout << "\033[32m13\033[0m. See Sales Report \n";
    bottomUI(0);
    cin >> iopt;
    if (iopt == 1)
    {
        system("CLS");
        usernamedisplay(username);
        admin.AddDepartments();
        bottomUI(1);
        invalidl:
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }

    }
    else if (iopt == 2)
    {
        system("CLS");
        usernamedisplay(username);
        admin.AddProductCategories();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }

    }
    else if (iopt == 3)
    {
        system("CLS");
        usernamedisplay(username);
        admin.AddProducts();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }

    }
    else if (iopt == 4)
    {
        system("CLS");
        usernamedisplay(username);
        admin.UpdateDepartments();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }

    }
    else if (iopt == 5)
    {
        system("CLS");
        usernamedisplay(username);
        admin.UpdateProductCategories();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 6)
    {
        system("CLS");
        usernamedisplay(username);
        admin.UpdateProducts();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 7)
    {
        system("CLS");
        usernamedisplay(username);
        admin.DeleteDepartments();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 8)
    {
        system("CLS");
        usernamedisplay(username);
        admin.DeleteProductCategories();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 9)
    {
        system("CLS");
        usernamedisplay(username);
        admin.DeleteProducts();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 10)
    {
        system("CLS");
        usernamedisplay(username);
        admin.makeStoreRequest();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 11)
    {
        system("CLS");
        usernamedisplay(username);
        cout << "The Store has around " << storemanager.returnStoreCredit() << " Rs\n";
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 12)
    {
        system("CLS");
        usernamedisplay(username);
        int p = 0;
        cout << "Enter the amount you want to subtract or add to store credit\n";
        cin >> p;
        storemanager.updateStoreCredit(p);
        cout << "Operation Successful";
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 13)
    {
        usernamedisplay(username);
        system("cls");
        cout << "Sales Record:\n\n\n";
        invoice.displaySaleRecord();
        bottomUI(1);
        cin >> iopt;
        if (iopt == 0)
        {
            return 0;
        }
        else if (iopt == 999)
        {
            goto adminstartl;
        }
        else
        {
            cout << "Please enter a valid choice: ";
            goto invalidl;
        }
    }
    else if (iopt == 0)
    {
        return 1;
    }
}
int vendorUI(string username)
{

vendorstartl:
    system("CLS");
    usernamedisplay(username);
    cout << "Please enter 1 to approve and 2 to unapprove request\n";

    vendor.view_requests();
    bottomUI(0);

    cin >> iopt;
    if (iopt == 0)
    {
        return 0;
    }
    vendor.acceptreject_request(iopt);
    cout << "Press any key to go back\n";
    cin >> iopt;

    goto vendorstartl;


}
int CustomerUI(string username)
{
catmenul:
    system("CLS");
    usernamedisplay(username);
catenterl:
    customer.menu();
    bottomUI(1);
    cout << "\nPlease enter the category: ";
    cin >> iopt;
    if (iopt == 0)
    {
        return 1;
    }
quantitynono:

    system("CLS");
    usernamedisplay(username);
    customer.menuofProducts(customer.getCategoryName(iopt - 1));
    customer.menu4ProductsDisplay();
    bottomUI(0);
    cout << "\n\nEnter the product you want to add to cart\n";
    cin >> iopt;
    if (iopt == 0)
    {
        return 1;
    }
    else if (iopt == 999)
    {
        customer.productssdelte();
        goto catmenul;
    }

    if (customer.in_Stock(iopt - 1) == true)
    {
        cout << "Enter the number of products you want to buy\n";
        int p;
        cin >> p;

        if (iopt == 0)
        {
            return 1;
        }
        else if (iopt == 999)
        {
            goto catmenul;
        }

        if (storemanager.updateItem(customer.getProducts(iopt - 1), -p) == true)
        {
            cart.addtoCart(customer.getProducts(iopt - 1), p);
            system("CLS");
            usernamedisplay(username);
            cout << "Item added to cart\n Please choose from the following\n";
            cout << "\t\033[32m[1]\033[0m. Go back to Main Menu\n\t\033[32m[2]\033[0m. View More Products\n\t\t\033[32m[3]\033[0m. View Cart\n\t\033[32m[4]\033[0m. Checkout";
            bottomUI(0);
            cin >> choice;
            if (choice == 1)
            {
                return 1;
            }
            else if (choice == 2)
            {
                goto catmenul;
            }

            else if (choice == 3)
            {
                system("CLS");
                cart.viewCart();
                cout << "\033[32m[1]\033[0mCheckout\t\t\t\t\t\t\033[32m[2]\033[0mProducts";
                cin >> iopt;
                if (iopt == 1)
                {
                    cart.calculateSumTotal();
                    invoice.displayInvoice(cart, 2);
                }
                else if (iopt == 2)
                {
                    goto catmenul;

                }
                else
                {
                    cout << "Invalid option. Please select again\n";
                }
            }
            else if (choice == 4)
            {
                cart.calculateSumTotal();
                invoice.displayInvoice(cart, 2);
            }
        }
        else
        {
            cin >> iopt;
            if (iopt == 1)
            {
                goto catmenul;
            }
            else if (iopt == 2)
            {
                goto quantitynono;

            }
        }
    }
    else
    {

        goto catmenul;
    }



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

            else if (mark == true && line.substr(2) == "3")
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




int main()
{
loginpagel:
    cout << "\033[0m";
    cout << "Welcome to Shop. Please Select from the following options\n";
    char charopt;
    int log, iopt, choice; bool registered = true;
    string username, password;

    cout << "[\033[32m1\033[0m]. Admin\n[\033[32m2\033[0m]. Customer\n[\033[32m3\033[0m]. Vendor\n[\033[32m4\033[0m]. Store Manager\n\nYour Choice: ";
logl:
    cin >> log;
    if (log > 0 && log < 5)
    {
        cout << "Now enter your login details\n";
        cout << "Enter your username: ";
        cin >> username;

        cout << "\nEnter your password: ";
        cin >> password; cout << "\n";

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
            cout << "Invalid Choice. Please enter again\n";
            goto yesnol;
        }

    }

    if (log_f == 1)
    {
        if (log == 1)
        {
            WelcomeScreen(username);
            
            if (AdminUI(username) == 1)
            {
                goto loginpagel;
            }
        }
        else if (log == 2)
        {
            WelcomeScreen(username);
            if (CustomerUI(username) == 1)
            {
                goto loginpagel;
            }


        }
        else if (log == 3)
        {


            WelcomeScreen(username);
            if (vendorUI(username) == 0)
            {
                goto loginpagel;
            }

        }
        else if (log == 4)
        {
            WelcomeScreen(username);
            if (StoreManagerUI(username) == 0)
            {
                goto loginpagel;
            }
        }
    }
}