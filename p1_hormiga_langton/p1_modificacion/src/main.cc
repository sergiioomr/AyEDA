/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file main.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-10
 * @brief Main program of Langton's Ant simulation. 
 *        Creates a Simulator Objetct. Pass a file by parameter. That files is used to make the Tape and Ant objects. Consists:
 *            
 *        Line 1. Tape's size
 *        Line 2. Initial position and Ant's orientation
 *        Line 3...n. Black cells position
 */
#include "../include/ant.h"
#include "../include/tape.h"
#include "../include/simulator.h"


int main(int argc, char* argv[]) {
  Simulator simulator{argv[1]};
  simulator.Simulation(); 
  return 0;
}