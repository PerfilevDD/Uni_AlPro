#include <iostream>
#include <string>
#include <vector>

void drucke(const std::vector<int>& arr, const size_t& size){
    /* Die Funktion drueckt die Array */
    // Sie ist const, da sie nicht veraendern wird

    // Drucken jeder Element
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // \n am Ende
}

void betrag(std::vector<int>& arr, const size_t& size){
    /* Die Funktion drueckt die Array */
    // Arr nicht const, da sie veraendern wird

    // Drucken jeder Element
    for(int i = 0; i < size; i++){
        if (arr[i] < 0){
            arr[i] = -1 * arr[i];
        }
    }
}

int main(void){
    std::vector<int> arr{5,-4,2,-1,4};

    drucke(arr, arr.size()); // Teil 1

    betrag(arr, arr.size()); // Teil 2
    drucke(arr, arr.size());
}