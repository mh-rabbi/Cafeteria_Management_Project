#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>
using namespace std;

// color code and name...
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

//System time and its functions.
int currentTime()
{
    cout << endl << setw(12) << GREEN << "PANORAMIC_CAFETERIA_MANAGEMENT_SYSTEM" << RESET << endl;
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    cout << setw(22) << BLUE << "---------------------" << RESET <<endl;
    cout << setw(22) << BLUE << "| time: " << setw(2) << setfill('0') << date.tm_hour << "h-" << setw(2) << setfill('0') << date.tm_min << "m-" << setw(2) << setfill('0')  << date.tm_sec <<"s |" <<setfill(' ')<< RESET << endl;
    cout << setw(22) << BLUE << "| date: " << setw(2) << setfill('0') << date.tm_mday << "-" << setw(2) << setfill('0') << date.tm_mon+1 << "-" << setw(2) << setfill('0') << date.tm_year+1900 <<"  |" <<setfill(' ') << RESET << endl;
    cout << setw(22) << BLUE << "---------------------" << RESET <<endl;
    cout << endl;
    // return date.tm_hour;
    return 9;

}


//Items representation.
void itemsBar()
{
    cout << setw(19) <<setfill(' ') << "Items"  <<setw(19) <<"Prices"  <<setw(21) << "Quantity"<<endl;
    cout << setw(20)  <<"---------" <<setw(20) <<"---------" <<setw(20) <<"---------" <<endl;
}


//Quantity of the items.
int Quantity()
{
    int quantity = 100;
    return quantity;
}


//creating structure sor vector, will use to add value of items.
struct MenuItem
{
    string name;
    float price;
    int quantity = Quantity();
};


// A parent class with a function call flage(), used for display worning.
class Flage
{
protected:
    string flage()
    {
        return "WELCOME TO PANORAMIC_CAFETERIA YOU. \nPLEASE MAKE SURE TO READ DOCOMENTATION BEFORE ENTERING VALUES.";
    }
};


//Adding BreakFast item.
class BreakFast : public Flage
{
private:
    vector<MenuItem> menuItems =
    {
        {"Beef Chowmein",      150.00 },
        {"Chicken Chowmein",   110.00 },
        {"Khichuri",            70.00 },
        {"Pasta",               60.00 },
        {"Chicken Wings",       40.00 },
        {"Cup Cake",            25.00 },
        {"Mixed Vegetable",     25.00 },
        {"Eggs",                20.00 },
        {"Vagfry",              20.00 },
        {"Parata",              10.00 },
        {"Coffee",              30.00 },
        {"Green Tee",           10.00 }
    };

    friend void checkBreakFast(BreakFast);
public:
    void items()
    {
        cout << RED << flage() <<RESET << endl;
        cout << GREEN << "It's BRESKFAST time.." << RESET << endl <<endl ;
        cout << "Note: To select food for order press number 1 to " << menuItems.size() <<" according to the list:" << endl << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i)
        {
            cout << left << setfill('.') << setw(2)
                 << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    float getPrice(int &index)
    {
        return menuItems[index].price;
    }

    float getQuantity(int &index)
    {
        return menuItems[index].quantity;
    }

    void updateQuantity(int &index, int &qty)
    {
        menuItems[index].quantity -= qty;
    }

};

// Calculating orders and price for BreakFirst.
void checkBreakFast(BreakFast prObj)
{

    cout << endl << setw(5) <<setfill(' ') <<"" <<"Enter 0 to confirm the order."<<endl
         << setw(5) <<"" <<"Enter your items number 1 to " << prObj.menuItems.size() <<" like (1 = Beef Kala Bhuna): ";

    float sum = 0;
    int order, quantity;
    cin >> order;

    if (order == 0)
    {
        cout << setw(10) <<"" << "You have not ordered yet..." << endl;
    }
    else
    {
        while (order != 0)
        {
            if (order >= 1 && order <= prObj.menuItems.size())
            {
                cout << setw(5) <<"" << "Enter the quantity: ";
                cin >> quantity;
                order-=1;
                if(quantity > prObj.getQuantity(order ))
                {
                    cout << setw(5) <<"" << "Apologize sir, we're out of " << prObj.menuItems[order].name <<"." <<endl;
                }
                else
                {
                    cout << setw(5) <<"" << "You have ordered: " << prObj.menuItems[order ].name  <<", and the quantity is: " << quantity << "." << endl <<endl;

                    //Calculating totat price to pay.
                    sum += prObj.getPrice(order ) * quantity;
                    //Updating quantity.
                    prObj.updateQuantity(order, quantity);
                }

            }
            else
            {
                cout << setw(5) <<"" << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << setw(5) <<"" << "Enter your item number to continue purchase or 0 to confirm your selected order: ";
            cin >> order;
        }
    }

    prObj.items();
    cout << endl;
    cout << GREEN << setw(5) << setfill(' ') <<""  << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..."  << endl;
    cout << setw(5) <<"" << "--------------------------------" << RESET << endl << endl << endl << endl;
}



//Adding Lunch item.
class Lunch : public Flage
{
private:
    vector<MenuItem> menuItems =
    {
        {"Beef Kala Bhuna", 160.00},
        {"Beef Bhuna",      130.00},
        {"Beef Biryani",    160.00},
        {"Chicken Biryani", 120.00},
        {"Khichuri",         90.00},
        {"Chicken Fry",      90.00},
        {"Fish Curry",       80.00},
        {"Fish Curry",       25.00},
        {"Dal",              20.00}
    };

    friend void checkLunch(Lunch);
public :
    void items()
    {
        cout << RED << flage() <<RESET << endl;
        cout << GREEN << "It's Lunch time.." << RESET << endl;
        cout << "Note: To select food for order press number 1 to " << menuItems.size() <<" according to the list:" << endl << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i)
        {
            cout << left << setfill('.') << setw(2)
                 << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    inline float getPrice(int &index)
    {
        return menuItems[index].price;
    }

    inline float getQuantity(int &index)
    {
        return menuItems[index].quantity;
    }

    inline void updateQuantity(int &index, int &qty)
    {
        menuItems[index].quantity -= qty;
    }
};

// Calculating orders and price for Lunch.
void checkLunch(Lunch prObj)
{

    cout << endl << setw(5) <<setfill(' ') <<""  <<"Enter 0 to confirm the order."<<endl
         << setw(10) <<"" <<"Enter your items number 1 to " << prObj.menuItems.size() <<" like (1 = Beef Kala Bhuna): ";

    float sum = 0;
    int order, quantity;
    cin >> order;

    if (order == 0)
    {
        cout << setw(10) <<"" << "You have not ordered yet..." << endl;
    }
    else
    {
        while (order != 0)
        {
            if (order >= 1 && order <= prObj.menuItems.size())
            {
                cout << setw(5) <<"" << "Enter the quantity: ";
                cin >> quantity;
                order-=1;
                if(quantity > prObj.getQuantity(order ))
                {
                    cout << setw(5) <<"" << "Apologize sir, we're out of " << prObj.menuItems[order].name <<"." <<endl;
                }
                else
                {
                    cout << setw(5) <<"" << "You have ordered: " << prObj.menuItems[order ].name  <<", and the quantity is: " << quantity << "." << endl <<endl;

                    //Calculating totat price to pay.
                    sum += prObj.getPrice(order ) * quantity;
                    //Updating quantity.
                    prObj.updateQuantity(order, quantity);
                }

            }
            else
            {
                cout << setw(5) <<"" << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << setw(5) <<"" << "Enter your item number to continue purchase or 0 to confirm your selected order: ";
            cin >> order;
        }
    }

    prObj.items();
    cout << endl;
    cout << setw(5) <<"" << GREEN << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..."  << endl;
    cout << setw(5) <<"" << "--------------------------------" << RESET << endl << endl << endl << endl;
}



//Adding Snacks item.
class Snacks : public Flage
{
private:
    vector<MenuItem> menuItems =
    {
        {"Grill Chicken Full",     300.00},
        {"Grill Chicken Half",     230.00},
        {"Grill Chicken Quater",   160.00},

        {"Beef Kala Bhuna",        160.00},
        {"Beef Bhuna",             130.00},

        {"Seekh Kebab",            100.00},

        {"Falooda",                100.00},
        {"Haleem",                  60.00},
        {"Mughlai",                 60.00},

        {"Fuchka Full",             50.00},
        {"Fuchka Half",             30.00},

        {"Naan Roti",               25.00},

        {"Shingara",                10.00},
        {"Samosa",                  10.00},
        {"Luchi",                   10.00},

        {"kola",                    10, 5}

    };

    friend void checkSnacks(Snacks);
public :
    void items()
    {
        cout << RED << flage() <<RESET << endl;
        cout << GREEN << "It's Snacks time.." << RESET << endl;
        cout << "Note: To select food for order press number 1 to " << menuItems.size() <<" according to the list:" << endl << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i)
        {
            cout << left << setfill('.') << setw(2)
                 << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(0) << menuItems[i].price << " tk.../" << right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    inline float getPrice(int &index)
    {
        return menuItems[index].price;

    }

    inline int getQuantity(int &index)
    {
        return menuItems[index].quantity;
    }

    inline void updateQuantity(int &index, int &qty)
    {
        menuItems[index].quantity -= qty;
    }
};

// Calculating orders and price for Snacks.
void checkSnacks(Snacks prObj)
{

    cout << endl << setw(5) << setfill(' ') <<"" <<"Enter 0 to confirm the order."<<endl
         << setw(5) <<"" <<"Enter your items number 1 to " << prObj.menuItems.size() <<" like (1 = Grill Chicken Full): ";

    float sum = 0;
    int order, quantity;
    cin >> order;

    if (order == 0)
    {
        cout << setw(10) <<"" << "You have not ordered yet..." << endl;
    }
    else
    {
        while (order != 0)
        {
            if (order >= 1 && order <= prObj.menuItems.size())
            {
                cout << setw(5) <<"" << "Enter the quantity: ";
                cin >> quantity;
                order-=1;
                if(quantity > prObj.getQuantity(order ))
                {
                    cout << setw(5) <<"" << "Apologize sir, we're out of " << prObj.menuItems[order].name <<"." <<endl;
                }
                else
                {
                    cout << setw(5) <<"" << "You have ordered: " << prObj.menuItems[order ].name  <<", and the quantity is: " << quantity << "." << endl <<endl;

                    //Calculating totat price to pay.
                    sum += prObj.getPrice(order ) * quantity;
                    //Updating quantity.
                    prObj.updateQuantity(order, quantity);
                }

            }
            else
            {
                cout << setw(5) <<"" << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << setw(5) <<"" << "Enter your item number to continue purchase or 0 to confirm your selected order: ";
            cin >> order;
        }
    }

    prObj.items();
    cout << endl;
    cout << setw(5) <<"" << GREEN << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..."  << endl;
    cout << setw(5) <<"" << "--------------------------------" << RESET << endl << endl << endl << endl;

}



//Adding Snacks item.
class Dinner : public Flage
{
private:
    vector<MenuItem> menuItems =
    {
        {"Beef_Kala_Bhuna",     300.00},
        {"Beef_Biryani",        130.00},
        {"Beef_Bhuna",          160.00},

        {"Chicken_Biryani",     160.00},
        {"Khichuri",            130.00},

        {"Chicken_Fry",         100.00},

        {"Fish_Curry",          100.00},
        {"Vegetable_Bhaji",      60.00},
        {"Dal",                  60.00},

        {"Fuchka_Full",          50.00},
        {"Fuchka_Half",          30.00},

        {"Naan_Roti",            25.00},

        {"Shingara",             10.00},
        {"Samosa",               10.00},
        {"Luchi",                10.00}
    };

    friend void checkDinner(Dinner);
public :
    void items()
    {
        cout << RED << flage() <<RESET << endl;
        cout << GREEN << "It's Dinner time.." <<RESET << endl;
        cout << "Note: To select food for order press number 1 to " << menuItems.size() <<" according to the list:" << endl << endl;
        cout << endl;
        itemsBar();
        cout << endl;

        for (int i = 0; i < menuItems.size(); ++i)
        {
            cout << left << setfill('.') << setw(2)
                 << i + 1 << ". " << setw(25) << menuItems[i].name << ": " << setw(10) << fixed << setprecision(2) << menuItems[i].price << " tk.../" <<right <<setw(8) <<"0"<< menuItems[i].quantity << endl;
        }
        cout << endl;
    }
    inline float getPrice(int &index)
    {
        return menuItems[index].price;
    }

    inline float getQuantity(int &index)
    {
        return menuItems[index].quantity;
    }

    inline void updateQuantity(int &index, int &qty)
    {
        menuItems[index].quantity -= qty;
    }
};

// Calculating orders and price for Dinner.
void checkDinner(Dinner prObj)
{

    cout << endl << setw(5) <<setfill(' ') <<"" <<"Enter 0 to confirm the order."<<endl
         << setw(5) <<"" <<"Enter your items number 0 to " << prObj.menuItems.size() <<" like (1 = Beef Kala Bhuna): ";

    float sum = 0;
    int order, quantity;
    cin >> order;

    if (order == 0)
    {
        cout << setw(10) <<"" << "You have not ordered yet..." << endl;
    }
    else
    {
        while (order != 0)
        {
            if (order >= 1 && order <= prObj.menuItems.size())
            {
                cout << setw(5) <<"" << "Enter the quantity: ";
                cin >> quantity;
                order-=1;
                if(quantity > prObj.getQuantity(order ))
                {
                    cout << setw(5) <<"" << "Apologize sir, we're out of " << prObj.menuItems[order].name <<"." <<endl;
                }
                else
                {
                    cout << setw(5) <<"" << "You have ordered: " << prObj.menuItems[order ].name  <<", and the quantity is: " << quantity << "." << endl <<endl;

                    //Calculating totat price to pay.
                    sum += prObj.getPrice(order ) * quantity;
                    //Updating quantity.
                    prObj.updateQuantity(order, quantity);
                }

            }
            else
            {
                cout << setw(5) <<"" << endl <<  "Invalid item number." << endl << "Please enter a valid item number or 0 to confirm the order." << endl <<endl;
            }
            cout << setw(5) <<"" << "Enter your item number to continue purchase or 0 to confirm your selected order: ";
            cin >> order;
        }
    }

    prObj.items();
    cout << endl;
    cout << setw(5) <<"" << GREEN << "Total check to pay: " << fixed << setprecision(2) << sum << " tk..."  << endl;
    cout << setw(5) <<"" << "--------------------------------" << RESET << endl << endl << endl << endl;

}


int main()
{

    int time = currentTime();

    if(time < 8 && time > 22)
    {
        cout <<setw(33) <<".....SORRY! We're closed....." << endl<<endl;
    }
    else if(time >= 8 && time < 11)
    {
        BreakFast breakFast;
        breakFast.items();
        checkBreakFast(breakFast);

    }
    else if(time >= 11 && time < 16)
    {
        Lunch lunch;
        lunch.items();
        checkLunch(lunch);
    }
    else if (time >= 16 && time < 20)
    {
        Snacks snacks;
        snacks.items();
        checkSnacks(snacks);
    }
    else
    {
        Dinner dinner;
        dinner.items();
        checkDinner(dinner);
    }
    return 0;
}
