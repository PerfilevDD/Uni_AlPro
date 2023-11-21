#include <simpler_graph/simpler_graph.hpp>
#include <iostream>
#include <vector>

namespace SimplerGraph
{
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) : knoten_anz(knoten_anzahl),
                                                     matrix(knoten_anzahl, std::vector<bool>(knoten_anzahl, false))
  {
  }

  void SimplerGraph::new_knoten(const size_t &num1, const size_t &num2)
  {
    if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
    {
      matrix[num1][num2] = true;
      matrix[num2][num1] = true;
    }
  }
  void SimplerGraph::enf_knoten(const size_t &num1, const size_t &num2)
  {
    if (num1 >= 0 && num1 < knoten_anz && num2 >= 0 && num2 < knoten_anz)
    {
      matrix[num1][num2] = false;
      matrix[num2][num1] = false;
    }
  }

  void SimplerGraph::drucken()
  {
    for (int i = 0; i < knoten_anz; i++)
    {
      for (int j = 0; j < knoten_anz; j++)
      {
        if (matrix[i][j]==true)
        {

          std::cout << "(" << i << " -> " << j << ")" << std::endl;
        }
      }
    }
    // Index sind Kntoten
    /*std::cout << " "
              << " a "
              << "a "
              << "a " << std::endl;
    for (const auto &matr1 : matrix)
    {
      std::cout << "a"
                << " ";
      for (const auto &matr2 : matr1)
      {
        std::cout << matr2 << " ";
      }
      std::cout << std::endl;
    }*/
  }
}
