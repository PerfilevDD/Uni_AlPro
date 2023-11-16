#include <iostream>

#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>

int main(int, char**) {
  hanoi_loesen::Hanoi_loesen h(3);
  h.bewege_rekursiv(3,0,1,2);
}
