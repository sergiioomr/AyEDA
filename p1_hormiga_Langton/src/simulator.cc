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

void Simulator::PrintTapeAnt() {
  for (int i = 0; i < tape_.GetSizeX(); i++) {
    for (int j = 0; j < tape_.GetSizeY(); j++) {
      Color cell_color = tape_.CheckColor(std::make_pair(i, j));
      if ((i == ant_.GetPosition().first) && (j == ant_.GetPosition().second)) {
        if (cell_color == Color::BLACK_CELL) {
          std::cout << BLACK << BG_RED << ant_ << RESET;
        } else {
          std::cout << BLACK << BG_BLUE << ant_ << RESET;
        }
      } else {
          if (cell_color == Color::BLACK_CELL) {
            std::cout << BG_RED << " " << RESET;
          } else {
            std::cout << BG_BLUE << " " << RESET;
          }
      }
    }
  }
}


void Simulator::Step() {
  
  std::pair<int, int> current_position = ant_.GetPosition();
  Color current_color = tape_.CheckColor(current_position);

  // Now, the ant change the cell color, and move
  // If the color is white, it always changes to black, and vice versa
  if (current_color == Color::WHITE_CELL) {
    tape_.SetColor(Color::BLACK_CELL, current_position);
  } else if (current_color == Color::BLACK_CELL) {
    tape_.SetColor(Color::WHITE_CELL, current_position);
  }

  // The ant move to the next cell
  ant_.Move(current_color);

  // Add one step to the counter
  counter++;

  // The ant is in the correct cell, so print the new tape
}

void Simulator::Simulation() {
  while(true) {
    std::cout << counter << std::endl << std::endl;
    std::cout << std::endl << std::endl;

    PrintTapeAnt();
    
    Step();
  }
}