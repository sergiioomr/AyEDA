/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file tape.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief 
 */

#include "tape.h"

Color Tape::CheckColor(const std::pair<int, int> &cell) const{
  return tape_[cell.first][cell.second];
}

void Tape::SetColor(const Color &color, const std::pair<int , int> &cell) {
  tape_[cell.first][cell.second] = color;
}

std::ostream &operator<<(std::ostream &os, const Tape &tape) {
  for (int i = 0; i < tape.GetSizeX(); i++) {
    for (int j = 0; j < tape.GetSizeY(); j++) {
      os << BG_LBLUE << " " << RESET << " "; 
    }

    os << std::endl << std::endl;
  }

  return os;
}

void Tape::PrintTapeAnt(const Ant &ant) {
  for (int i = 0; i < size_x_)
}

int main() {
  std::vector<std::vector<Color>> v(8, std::vector<Color>(20));
  Tape tape(v, 8, 20);
  std::cout << tape << std::endl;
  return 0;
}