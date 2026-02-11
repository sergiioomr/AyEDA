/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_x.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-11
 * @brief This file declarates the Ant_X class.
 *        That class heritates of Ant, and represent many types of ants, which follows n rules to move
 *        and recognize n colors
 */

#ifndef ANT_X
#define ANT_X

#include "../include/ant.h"
#include <string>

class Ant_X : public Ant {
  public:
    Ant_X(const std::pair<int, int> &position, const Direction &direction, const std::string &move_rules)


  private:

};

#endif // ANT_X