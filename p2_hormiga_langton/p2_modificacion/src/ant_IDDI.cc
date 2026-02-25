/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_IDDI.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-25
 * @brief Definition of ant_DDII class
 */

#include "../include/ant_IDDI.h"

/**
 * @brief Specify how the ant moves.

 * 
 * @param color  
 */
void Ant_IDDI::Step(const Color &color) {
  size_t color_code = static_cast<int>(color);

  // According to the movements rules IDDI, with the second and third color, turn right, else, left
  if ((color_code == 1) || (color_code == 2)) {
    TurnRight();
  } else {
    TurnLeft();
  }

  // Then, move one cell. This is independent of the ant type. 
  Move();
}
