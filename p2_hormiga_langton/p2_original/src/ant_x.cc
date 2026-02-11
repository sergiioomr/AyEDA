/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_x.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-11
 * @brief 
 */

#include "../include/ant_x.h"

void Ant_X::Step(const Color &color) {
  // int possible_movements_num = move_rules_.size();
  size_t color_code = static_cast<int>(color);

  // The position n (n = code that represents the color) have a character 'D' or 'd', with that color, the and must turn right
  if (move_rules_.at(color_code) == 'D' || move_rules_.at(color_code) == 'd') {
    TurnRight();

  // Else, the character wil be 'I' or 'i'. There is not posibility to be other character because the simulator control that.
  } else {
    TurnLeft();
  }

  // Then, move one cell. This is independent of the ant type. 
  Move();
}

