/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file simulator.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief 
 */
            
#include "tape.h"
#include "ant.h"
#include "colors.h"

class Simulator {
  public:
    Simulator(Tape &tape, Ant &ant) : tape_(tape), ant_(ant) {}
    void PrintTapeAnt();
    void Step();
    void Simulation();

  private:
    int counter;
    Tape tape_;
    Ant ant_;
};