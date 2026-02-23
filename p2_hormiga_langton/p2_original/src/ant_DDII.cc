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

#include "../include/ant_DDII.h"

/**
 * @brief Specify how the ant moves.

 * 
 * @param color 
 */
void Ant_DDII::Step(const Color &color) {
  size_t color_code = static_cast<int>(color);

  // According to the movements rules DDII, with the first and second color, turn right, else, left
  if ((color_code == 0) || (color_code == 1)) {
    TurnRight();
  } else {
    TurnLeft();
  }

  // Then, move one cell. This is independent of the ant type. 
  Move();
}
