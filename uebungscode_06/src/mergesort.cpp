<<<<<<< HEAD
#include <mergesort.hpp>
#include <iostream>
#include <vector>

std::vector<int> elminarr(const std::vector<int> &arr, const int &start, const int &num)
{
    // Funktion, die ein Array erstellt.
    // Wird benutzt, um linkes und rechtes Array zu erstellen

    std::vector<int> ret_arr;
    
    for (int i = start; i < num; i++)
    {
        ret_arr.push_back(arr[i]);
    }
    return ret_arr;
}

std::vector<int> mergesort(std::vector<int> &arr)
{
    // Mergesort-Funktion teile das gegebene Array in zwei anderen und ruft sich rekursiv
    int arr_size = arr.size();

    if (arr_size > 1)
    {
        int middle = arr_size / 2;

        // Ertstellen ein Array, das alle Zeilen ursp. Array bis zur Mitte hat
        std::vector<int> left_arr = elminarr(arr, 0, middle);
        // Ertstellen ein Array, das alle Zeilen ursp. Array nach der Mitte hat
        std::vector<int> right_arr = elminarr(arr, middle, arr_size);

        // Rufen rekursive Funktionen
        left_arr = mergesort(left_arr);
        right_arr = mergesort(right_arr);

        // Rufen merge-Funktion
        return merge(left_arr, right_arr);
    }
    else
    {
        return arr;
    }
}

std::vector<int> merge(std::vector<int> &left_arr, std::vector<int> &right_arr)
{
    std::vector<int> merge_arr(left_arr.size() + right_arr.size());
    int i = 0;
    int j = 0;

    // Schleife, um das Array mit Zahlen von den anderen Arrays zu fuellen
    while (i < left_arr.size() && j < right_arr.size())
    {
        if (left_arr[i] <= right_arr[j])
        {
            merge_arr[i + j] = left_arr[i];
            i++;
        }
        else
        {
            merge_arr[i + j] = right_arr[j];
=======
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
>>>>>>> sgitlab/AlPro_06_Kohn
            j++;
        }
    }

<<<<<<< HEAD
    // Zwei weiter Schleifen, die die Zahl am Ende des Arrays hinzufuegen
    while (i < left_arr.size())
    {
        merge_arr[i + j] = left_arr[i];
        i++;
    }
    while (j < right_arr.size())
    {
        merge_arr[i + j] = right_arr[j];
        j++;
    }
    return merge_arr;
=======
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
>>>>>>> sgitlab/AlPro_06_Kohn
}