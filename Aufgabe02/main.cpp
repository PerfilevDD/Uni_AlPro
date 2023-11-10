#include <iostream>
#include <string>
#include <vector>

void drucke_int(const std::vector<int>& arr, const size_t& size){
    /* Die Funktion drueckt die Array */
    // Sie ist const, da sie nicht veraendern wird

    // Drucken jeder Element
    for(const int& zahl: arr){ //Range-Based For-Loop
        std::cout << zahl << " ";
    }
    std::cout << std::endl; // \n am Ende
}

void betrag(std::vector<int>& arr, const size_t& size){
    /* Die Funktion drueckt die Array */
    // Arr nicht const, da sie veraendern wird

    // Drucken jeder Element
    for(int& zahl : arr){ //Range-Based For-Loop
        if (zahl < 0){
            zahl = -1 * zahl;
        }
    }

    drucke_int(arr, arr.size());
}

void drucke_str(const std::vector<std::string>& arr, const size_t& size){
    /* Die Funktion drueckt die Array */
    // Sie ist const, da sie nicht veraendern wird

    // Drucken jeder Element
    for(const std::string& wort : arr){ //Range-Based For-Loop
        std::cout << wort << std::endl;
    }
    std::cout << std::endl; // \n am Ende
}

std::vector<int> lies_int(){
    std::vector<int> arr;
    size_t eingabe = 0; // Deffenieren Aufgabewert

    std::cout << "Tippe die Zahle" << std::endl;

    // Schleife, die in Array die Zahlen einsetzt
    while (eingabe != 42)
    {
        std::cin >> eingabe;
        arr.push_back(eingabe); // Setze die Zahl am Ende des Arrays ein
    }
    return arr;
}

int main(void){
    std::vector<int> arr{5,-4,2,-1,4};
    std::vector<std::string> str_arr{"1. Wort", "2. Wort", "3. Wort"};


    drucke_int(arr, arr.size()); // Teil 1
    std::cout << std::endl;

    betrag(arr, arr.size()); // Teil 2
    std::cout << std::endl;

    drucke_str(str_arr, str_arr.size()); // Teil 3
    std::cout << std::endl;

    std::vector<int> arr_42 = lies_int(); // Teil 4
    drucke_int(arr_42, arr_42.size()); // Drucken Array aus Teil 4 mit der Funk aus Teil 1
}