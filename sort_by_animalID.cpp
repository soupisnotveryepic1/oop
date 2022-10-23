#include "sort_by_animalID.h"

void sort_by_animalID::sort(animal **animals, int n) {
        int i, j;
        for (i = 0; i < n - 1; i++)
            // Last i elements are already in place
            for (j = 0; j < n - i - 1; j++)
                if (animals[j]->get_id() > animals[j + 1]->get_id()) {
                    swap(animals[j], animals[j + 1]);
                }
}