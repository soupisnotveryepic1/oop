#include "Clinic.h"
#include <iostream>

int main(){
    Clinic clinic("One", 2);
    Cage one("Cage one", 5);
    Cage two("Two", 6);
    Cage three("Three", 7);

    bool a = clinic.add_cage(one);
    if (a == false){
        cout << "Fail 1" << endl;
    }
    cout << a << endl;
    bool b = clinic.add_cage(two);
    if (b == false){
        cout << "Fail 2" << endl;
    }
    cout << b << endl;

    bool c = clinic.add_cage(three);
    if (c == false){
        cout << "Fail 3" << endl;
    }
    cout << c << endl;

    return 0;
}

