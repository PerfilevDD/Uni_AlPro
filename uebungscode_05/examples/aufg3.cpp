#include <iostream>

#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>

int main(int, char**) {
  size_t scheibe;

  std::cout << "Anzahl von Scheiben -> ";
  std::cin >> scheibe;

  hanoi_loesen::Hanoi_loesen h(scheibe);

  h.bewege_rekursiv(scheibe,0,2,1); // Ruf Rekursion auf
}
