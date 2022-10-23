#include "zoo.h"
#include "animal.h"
#include "vegie.h"
#include "hunter.h"
#include "sort_by_animalID.h"
#include "sort_by_name.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    zoo* one = new zoo("Zoo One", 100, 50);
    animal** test = one->get_animals();
    for (int i = 0; i < 150; i++){
        cout << test[i]->get_id() << endl;
    }
    sort_by_animalID::sort(test,150);
    for (int i = 0; i < 150; i++){
        cout << test[i]->get_id() << endl;
    }
    sort_by_name::sort(test,150);
    for (int i = 0; i < 150; i++){
        cout << test[i]->get_name() << endl;
    }
}
