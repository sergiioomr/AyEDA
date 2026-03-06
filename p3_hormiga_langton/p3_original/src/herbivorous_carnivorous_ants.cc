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

#include "../include/herbivorous_carnivorous_ants.h"

void CarnivorousAnt::IncreaseLifetime(int other_ant_lifetime) {
  int increase = std::round(other_ant_lifetime * voracity_);
  lifetime_ += increase;
}

void CarnivorousAnt::DecreaseLifetime(double other_ant_voracity) {
  int decrease = std::round(GetLifeTime() * other_ant_voracity);
  lifetime_ -= decrease;
}

void CarnivorousAnt::Move() {
  switch (direction_) {
    case Direction::UP : 
      position_.first--;
      position_.second++;
      break;

    case Direction::DOWN :
      position_.first++;
      position_.second--;
      break;

    case Direction::LEFT :
      position_.second--;
      position_.first--;
      break;
    
    case Direction::RIGHT : 
      position_.second++;
      position_.first++;
      break;
  }
}

void HerbivorousAnt::IncreaseLifetime(int color_code) {
  lifetime_ += color_code;
}

void HerbivorousAnt::DecreaseLifetime(double other_ant_voracity) {
  int decrease = std::round(GetLifeTime() * other_ant_voracity);
  lifetime_ -= decrease;
}