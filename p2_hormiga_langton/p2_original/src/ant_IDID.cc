/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_x.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-11
 * @brief Definition of ant_IDID class
 */

#include "../include/ant_IDID.h"

/**
 * @brief Specify how the ant moves.

 * 
 * @param color 
 */
void Ant_IDID::Step(const Color &color) {
  size_t color_code = static_cast<int>(color);

  // According to the movements rules IDID, with the first and third color, turn right, else, left
  if ((color_code == 0) || (color_code == 2)) {
    TurnLeft();
  } else {
    TurnRight();
  }

  // Then, move one cell. This is independent of the ant type. 
  Move();
}