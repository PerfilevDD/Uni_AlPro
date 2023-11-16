#include "minsort_in_place.hpp"

// Min Sort In Place - ein Array wird aufsteigend ohne Erstellen eines weiteren Arrays sortiert
void minsort_in_place(std::vector<int>& array) {

    for (int i = 0; i < array.size() - 1; ++i) {
        int min = i; // Hier wird angenommen, dass das aktuelle Element die kleinste Zahl des Arrays ist

        // Hier wird das kleinste Element im verbleibenden unsortierten Teil des Arrays gesucht
        for (int j = i + 1; j < array.size(); ++j) { // j beginnt zu suchen ab dem Element rechts von array[i]
            if (array[j] < array[min]) {
                min = j;  /* Wenn das Element an der Position j kleiner ist als das bisher angenommene Minimum,
                             dann wird die das Element an die Position des Minimums auf j aktualisiert */
            }
        }

         int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }