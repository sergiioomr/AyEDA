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
