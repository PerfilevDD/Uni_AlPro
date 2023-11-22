#include "mergesort.hpp"
void mergesort(std::vector<int>& array){
    int length = array.size();
    
    // Überprüfen ob die Länge des Arrays kleiner oder gleich 1 ist (wenn ja - beenden, da es bereits sortiert ist)
    if(length <= 1){
        return;
    }

    // Das Array wird in zwei Hälften aufgeteilt
    int middle = length / 2;
    std::vector<int> leftArray(middle);
    std::vector<int> rightArray(length - middle);

    int j = 0; // Index für das rechte Array

    // Die beiden Hälften des ursprünglichen Arrays werden in leftArray und rightArray kopiert
    for(int i = 0; i < length; i++){
        if(i < middle){
            leftArray[i] = array[i];
        }
        if(i >= middle){
            rightArray[j] = array[i];
            j++;
        }
    }

   // Merge Sort wird auf die beiden Hälften (leftArray und rightArray) angewendet und teilt die
    mergesort(leftArray);
    mergesort(rightArray);

    // Merge Funktion wird aufgerufen
    merge(leftArray, rightArray, array);
}

// Funktion merge, die zwei gegebene, sortierte Arrays in ein Ziel Array schreibt
void merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& array){
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();
    int i = 0, l = 0, r = 0;

     /* Die Schleife vergleicht die Elemente von leftArray und rightArray und fügt das kleinere Element
                             in das resultierende array ein.*/
    while(l < leftSize && r < rightSize){
        if(leftArray[l] < rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        } else { /* Wenn das aktuelle Element im rightArray kleiner oder gleich dem aktuellen Element im leftArray
                  ist, wird das Element aus dem rightArray in das resultierende array eingefügt*/
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }

          /* Falls nach dem Vergleich noch Elemente in einem der Arrays verbleiben,
           werden diese direkt in das resultierende array eingefügt. */
    while(l < leftSize){
        array[i] = leftArray[l];
        i++;
        l++;
    }

    while(r < rightSize){
        array[i] = rightArray[r];
        i++;
        r++;
    }
}