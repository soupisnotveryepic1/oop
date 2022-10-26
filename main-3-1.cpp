#include <iostream>
using namespace std;
#include "Shop.h"

int main(){
    Shop* a;
    Employee* b;
    b = new Manager(5);
    a = Shop::createShop(10);
    a->addEmployee(b);
    Employee** c;
    c = a->get_employees();
    c[0]->set_payRate(50);
    cout << c[0]->get_payRate() << endl;
    return 0;
}