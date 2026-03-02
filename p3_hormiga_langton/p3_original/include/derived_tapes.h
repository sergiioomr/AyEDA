/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file tape.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-01
 * @brief This file declarates the classes derived from Tape.
 * 				This classes are used to represent the grid in the simulation
 *        Their difference is the way to implement the borders
 */

#ifndef DERIVED_TAPES_H
#define DERIVED_TAPES_H

#include <iostream>
#include <vector>
#include "../include/colors.h"
#include "../include/ant.h"
#include "../include/enum_class.h"
#include "../include/tape.h"

class TapePeriodic : public Tape {
  public: 

  private: 
    std::vector<std::vector<Color>> grid_;
};


class TapeReflective : public Tape {
  public:

  private:
    std::vector<std::vector<Color>> grid_;
};


class TapeSliding : public Tape {
  public:

  private:
    SlidingVector<SlidingVector<Color>> grid_;
};




#endif // DERIVED_TAPES_H