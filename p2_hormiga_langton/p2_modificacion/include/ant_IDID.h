/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_IDID.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-11
 * @brief This file declarates the Ant_IDID class.
 *        That class heritates of Ant, and represent an special type of ant, which follows IDID rules to move
 *        and recognize 4 colors. It beahves same as the parent class except in the method Step.  
 */

#ifndef ANT_IDID_H
#define ANT_IDID_H
#include "../include/ant.h"

class Ant_IDID : public Ant {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_IDID(const Direction &direction, const std::pair<int, int> &position) : Ant{direction, position} {}

    std::string GetType() const override { return "IDID"; }
    void Step(const Color &color) override;
};


#endif //ant_IDID_H