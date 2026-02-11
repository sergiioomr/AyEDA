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
 *        That class will be use to make the simulation with the tape and the ant classes
 */
            
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../include/ant.h"
#include "../include/tape.h"
#include "../include/colors.h"
#include "../include/enum_class.h"
#include <string>
#include <fstream>
#include <sstream>

class Simulator {
  public:
  // Constructor
    Simulator(const std::string &filename);

    void PrintTapeAnt();
    void Simulation();

  private:
    Tape tape_;
    std::vector<Ant> ants_;

    void Export();
};

#endif // SIMULATOR_H