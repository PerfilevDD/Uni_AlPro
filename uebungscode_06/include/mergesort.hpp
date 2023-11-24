#pragma once
#include <vector>

// Hier kommt die Deklaration (und Beschreibung) von mergesort hin

// Deklaration von mergesort und merge die nach dem Divide and Conquer Prinzip funktionieren
void mergesort(std::vector<int>&);
void merge(std::vector<int>&,std::vector<int>&,std::vector<int>&);
