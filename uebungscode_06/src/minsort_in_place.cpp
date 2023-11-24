#include <minsort_in_place.hpp>
#include <vector>
#include <iostream>

// Hier wird minsort in place implementiert

std::vector<int> min_arr(const std::vector<int>& arr, const int& start){
    // Function return min of received array with start value 
    // Returned min and index of min

    std::vector<int> return_min_arr (2); // An array for min and index of min
    return_min_arr[0] = arr[start];

    for (int i = start; i < arr.size(); i++){
        if (return_min_arr[0] > arr[i]){
            return_min_arr[0] = arr[i];
            return_min_arr[1] = i;
        } else if (return_min_arr[0] == arr[i]){
            return_min_arr[0] = arr[i];
            return_min_arr[1] = i;
        }
    }
    return return_min_arr;
}

void minsort (std::vector<int>& arr){
    // MinSort-Algorithm

    int temp; // For swap
    std::vector<int> mins (2); // An array for swap

    for (int i = 0; i < arr.size(); i++){
        mins = min_arr(arr, i); // An array from function min_arr, receives min of arr and index of min
        
        if (arr[i] != mins[0]){
            temp = arr[i];
            arr[i] = mins[0];
            arr[mins[1]] = temp;
        }
    }
}