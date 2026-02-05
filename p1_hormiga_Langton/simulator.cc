/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzados
 * @file simulator.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief 
 */

#include "simulator.h"

void Simulator::Step() {
  
  std::pair<int, int> current_position = ant_.GetPosition();
  Color current_color = tape_.CheckColor(current_position);

  // Now, the ant change the cell color, and move
  // If the color is white, it always changes to black, and vice versa
  if (current_color == Color::WHITE) {
    tape_.SetColor(Color::BLACK, current_position);
  } else if (current_color == Color::BLACK) {
    tape_.SetColor(Color::WHITE, current_position);
  }

  // The ant move to the next cell
  ant_.Move(current_color);

  // Add one step to the counter
  counter++;

  // The ant is in the correct cell, so print the new tape
  PrintTape();
}

void Simulator::Simulation() {
  while(true) {
    Step();
  }
}