/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file ant.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-04
 * @brief 
 */

#include "../include/ant.h"

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

void Ant::Move() {

  // Move one cell in the actual direction
  switch (direction_) {
    case Direction::UP :
      position_.second--;
      break;
    case Direction::DOWN :
      position_.second++;
      break;
    case Direction::LEFT : 
      position_.first--;
      break;
    case Direction::RIGHT : 
      position_.first++;
      break;
  }
}

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

void Ant::Step(const Color &color) {
  // First, the ant has to turn
  if (color == Color::BLACK_CELL) {
    TurnRight();
  } else {
    TurnLeft();
  }

  // Now, the ant has to move one cell in the current direction
  Move();
}