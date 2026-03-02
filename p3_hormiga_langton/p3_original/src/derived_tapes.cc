/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file derived_tapes.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-02
 * @brief 
 */

#include "../include/derived_tapes.h"

Color TapePeriodic::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}

Color TapeReflective::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}

Color TapeSliding::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}



void TapePeriodic::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}

void TapeReflective::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}

void TapeSliding::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}

