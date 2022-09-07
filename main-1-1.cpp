
#include <iostream>
#include "Cage.h"
int main(){
    Cage one("Cage One", 5);
    cout << one.get_name() << " " << one.get_IDnum() << endl;
    return 0;
}