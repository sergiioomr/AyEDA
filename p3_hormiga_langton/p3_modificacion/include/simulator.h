/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file simulator.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief That file defines the Langton's Ant Simulator class. 
 *        That class will be use to make the simulation with the tape and the ant_x classes
 */
            
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../include/ant.h"
#include "../include/tape.h"
#include "../include/colors.h"
#include "../include/enum_class.h"
#include "../include/derived_ants.h"
#include "../include/derived_tapes.h"
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>

class Simulator {
  public:
  // Constructor
    Simulator(const std::string &filename, const std::string &tape_type);

    void PrintTapeAnt();
    void ApplyAntRules();
    void EraseDiedAnts();
    bool OutOfLimits(const int ant_position);
    void Simulation();

  private:
    std::unique_ptr<Tape> tape_;
    std::vector<std::unique_ptr<Ant>> ants_;
    int num_colors_;
    void Export();
};

#endif // SIMULATOR_H