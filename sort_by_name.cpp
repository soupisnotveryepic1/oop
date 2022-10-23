#include "sort_by_name.h"

void sort_by_name::sort(animal **animals, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (animals[j]->get_name() > animals[j + 1]->get_name()) {
                swap(animals[j], animals[j + 1]);
            }
}
