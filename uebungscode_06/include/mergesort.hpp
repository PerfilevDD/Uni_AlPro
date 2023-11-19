#pragma once

#include <vector>

// Funktion, die Zahlen von einem Array in einen anderen hinzufügt
std::vector<int> elminarr(const std::vector<int>& arr, const int& start, const int& num);

// Mergesort-Funktion
std::vector<int> mergesort(std::vector<int>& A);

// Funktion, die merge 2 Arrays
std::vector<int> merge(std::vector<int>& L, std::vector<int>& R);