#pragma once
#include "animal.h"
#include <string>
#include <algorithm>
#include <iostream>

class sort_by_name{
public:
    static void sort(animal** animals, int n);
};
