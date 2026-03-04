/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file derived_ants.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-04
 * @brief 
 */

#ifndef DERIVED_ANTS_H
#define DERIVED_ANTS_H

#include "herbivorous_carnivorous_ants.h"

class Ant_H_IDID : public HerbivorousAnt {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_H_IDID(const Direction &direction, const std::pair<int, int> &position, int lifetime) : HerbivorousAnt{direction, position, lifetime} {}

    std::string GetType() const override { return "IDID"; }
    void Step(const Color &color) override;
};

class Ant_H_DDII : public HerbivorousAnt {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_H_DDII(const Direction &direction, const std::pair<int, int> &position, int lifetime) : HerbivorousAnt{direction, position, lifetime} {}

    std::string GetType() const override { return "DDII"; }
    void Step(const Color &color) override;
};


// CHANGE CARNIVOROUS MOVEMENT --> THEY SHOULD MOVE DIAGONALLY


class Ant_C_DDII : public CarnivorousAnt {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_C_DDII(const Direction &direction, const std::pair<int, int> &position, int lifetime, int voracity) : CarnivorousAnt{direction, position, lifetime, voracity} {}

    std::string GetType() const override { return "DDII"; }
    void Step(const Color &color) override;
};

class Ant_C_IDID : public CarnivorousAnt {
  public:
  // Constructor. First, call Ant constructor, then, assingn the ant_x parameters
    Ant_C_IDID(const Direction &direction, const std::pair<int, int> &position, int lifetime, int voracity) : CarnivorousAnt{direction, position, lifetime, voracity} {}

    std::string GetType() const override { return "IDID"; }
    void Step(const Color &color) override;
};



#endif // DERIVED_ANTS_H