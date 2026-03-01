/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant_IDDI.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-25
 * @brief This file declarates the Ant_IDDI class.
 *        That class heritates of Ant, and represent an special type of ant, which follows DDII rules to move
 *        and recognize 4 colors. It beahves same as the parent class except in the method Step.   
 */

#ifndef ANT_IDDI_H
#define ANT_IDDI_H
#include "../include/ant.h"

class Ant_IDDI : public Ant {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_IDDI(const Direction &direction, const std::pair<int, int> &position) : Ant{direction, position} {}

    std::string GetType() const override { return "IDDI"; }
    void Step(const Color &color) override;
};


#endif //ANT_IDDI_H