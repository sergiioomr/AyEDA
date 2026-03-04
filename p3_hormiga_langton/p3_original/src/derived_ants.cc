/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file derived_ants.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-04
 * @brief 
 */

#include "../include/derived_ants.h"

/**
 * @brief Specify the DDII movement

 * 
 * @param color 
 */
void Ant_H_DDII::Step(const Color &color) {
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

/**
 * @brief Specify the IDID movement

 * 
 * @param color 
 */
void Ant_H_IDID::Step(const Color &color) {
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

/**
 * @brief Specify the DDII movement

 * 
 * @param color 
 */
void Ant_C_DDII::Step(const Color &color) {
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

/**
 * @brief Specify the IDID movement

 * 
 * @param color 
 */
void Ant_C_IDID::Step(const Color &color) {
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