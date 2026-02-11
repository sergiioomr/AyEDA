/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-04
 * @brief Ant class definition
 */

#include "../include/ant.h"

/**
 * @brief Ant turns 90º to the left by changing its direction, using a switch structure.
 * 
 */
void Ant::TurnLeft() {
  switch (direction_) {
    case Direction::DOWN : 
      direction_ = Direction::RIGHT;
      break;
    case Direction::UP : 
      direction_ = Direction::LEFT;
      break;
    case Direction::RIGHT :
      direction_ = Direction::UP;
      break;
    case Direction::LEFT :
      direction_ = Direction::DOWN;
      break; 
  }
}

/**
 * @brief Ant turns 90º to the right by changing its direction, using a switch structure.
 * 
 */
void Ant::TurnRight() {
  switch (direction_) {
    case Direction::DOWN : 
      direction_ = Direction::LEFT;
      break;
    case Direction::UP : 
      direction_ = Direction::RIGHT;
      break;
    case Direction::RIGHT :
      direction_ = Direction::DOWN;
      break;
    case Direction::LEFT :
      direction_ = Direction::UP;
      break; 
  }
}

/**
 * @brief The ant move itself in the actual direccion. 
 *        Increasing or decreasing its pair of coordinates
 *        That version rotate 45º the movement.
 * 
 */
void Ant::Move() {
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

/**
 * @brief That method make the complete step to do a movement.
 *        First choose the side to turn, then, move one cell.
 * 
 * @param color 
 */
void Ant::Step(const Color &color) {
  if (color == Color::BLACK_CELL) {
    TurnRight();
  } else {
    TurnLeft();
  }

  Move();
}

/**
 * @brief << operator overloading
 * 
 * @param os 
 * @param ant 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Ant &ant) {
  switch (ant.GetDirection()) {
    case Direction::UP :
      os << "^";
      break;
    case Direction::DOWN :
      os << "v";
      break;
    case Direction::RIGHT : 
      os << ">";
      break;
    case Direction::LEFT :
      os << "<";
      break;
  }

  return os;
}
