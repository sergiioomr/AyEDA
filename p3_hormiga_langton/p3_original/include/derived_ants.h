/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file derived_ants.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-03
 * @brief Declarates two kinds of ants. Carnivorous and Herviborous
 * 
 */
#ifndef DERIVED_ANTS_H
#define DERIVED_ANTS_H

#include "../include/ant.h"
#include <cmath> // std::round to aproximate to the nearest integer the lifetime when its multiplicated by the voracity

class CarnivorousAnt : public Ant {
  public: 
  // The carnivorous ant will have a lifetime of 15 once it is created
    CarnivorousAnt(const Direction &direction, const std::pair<int, int> &position) : Ant{direction, position}, voracity_() {}
    
    double GetVoracity() const { return voracity_; }
    void IncreaseLifetime(int other_ant_lifetime);
    void DecreaseLifetime(double other_ant_voracity);

  private : 
  // percentage of lifetime that the ants take from another
    double voracity_;

};

class HerbivorousAnt : public Ant {
  public:
    HerbivorousAnt(const Direction &direction, const std::pair<int, int> &position) : Ant{direction, position} {}

    void IncreaseLifetime(const Color &cell_color);
    void DecreaseLifetime(double other_ant_voracity);
};









#endif DERIVED_ANTS_H