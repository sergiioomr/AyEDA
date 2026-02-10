/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file tape.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief Tape class definition
 */

#include "../include/tape.h"

/**
 * @brief Construct a new Tape object. Initialize and resize the vector of vectors (grid)
 * 
 * @param size_x 
 * @param size_y 
 */
Tape::Tape(const int &size_x, const int &size_y) : tape_{}, size_x_(size_x), size_y_(size_y) {
  tape_.resize(size_x_);
  for (int i = 0; i < size_x_; i++) {
    tape_[i].resize(size_y_);
    for (int j = 0; j < size_y_; j++) {
      tape_[i][j] = Color::WHITE_CELL;
    }
  }

}

/**
 * @brief Method to check a cell's color
 * 
 * @param cell 
 * @return Color 
 */
Color Tape::CheckColor(const std::pair<int, int> &cell) const{
  return tape_[cell.first][cell.second];
}

/**
 * @brief Method to change a cell's color
 * 
 * @param color 
 * @param cell 
 */
void Tape::SetColor(const Color &color, const std::pair<int , int> &cell) {
  tape_[cell.first][cell.second] = color;
}

/**
 * @brief << operator overloading
 * 
 * @param os 
 * @param tape 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Tape &tape) {
  for (int i = 0; i < tape.GetSizeX(); i++) {
    for (int j = 0; j < tape.GetSizeY(); j++) {
      os << BG_LBLUE << " " << RESET << " "; 
    }

    os << std::endl << std::endl;
  }

  return os;
}

