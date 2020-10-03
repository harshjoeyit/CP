#include<bits/stdc++.h>
#include "hashMap.h"
using namespace std;

int main() {
    Hashtable<int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 40);
    price_menu.insert("Pizza", 200);
    price_menu.insert("Noodles", 150);
    price_menu.insert("Coke", 40);
    price_menu.print();

    price_menu.erase("Noodles");
    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Price is " << *price << endl;
    }
    cout << price_menu["Dosa"] << endl;
}