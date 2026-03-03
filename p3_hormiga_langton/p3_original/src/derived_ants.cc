/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file derived_ants.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-03
 * @brief 
 */

#include "../include/derived_ants.h"

void CarnivorousAnt::IncreaseLifetime(int other_ant_lifetime) {
  int increase = std::round(other_ant_lifetime * voracity_);
  SetLifetime(increase);
}

void CarnivorousAnt::DecreaseLifetime(double other_ant_voracity) {
  int decrease = std::round(GetLifeTime() * other_ant_voracity);
  SetLifetime(-decrease);
}

void HerbivorousAnt::IncreaseLifetime(const Color &color) {
  SetLifetime(static_cast<int>(color));
}

void HerbivorousAnt::DecreaseLifetime(double other_ant_voracity) {
  int decrease = std::round(GetLifeTime() * other_ant_voracity);
  SetLifetime(-decrease);
}