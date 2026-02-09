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

#include "../include/simulator.h"

Simulator::Simulator(const std::string& filename) : tape_{}, ant_{} {
  std::ifstream input_file{filename};
  std::string line;
  int size_x, size_y;
  int ant_x, ant_y, ant_direction;
 
  // Line 1. Tape size
  getline(input_file, line);
  std::istringstream iss(line);
  iss >> size_x >> size_y;

  // Line 2. Ant initial position and orientation
  getline(input_file, line);
  iss = std::istringstream(line);
  iss >> ant_x >> ant_y >> ant_direction;

  // Create the tape
  Tape tape{size_x, size_y};

  // Create the ant
  Ant ant{static_cast<Direction>(ant_direction), std::make_pair(ant_x, ant_y)};

  // Read and change the black cells
  while(getline(input_file, line)) {
    size_t row, column;
    iss = std::istringstream(line);
    iss >> row >> column;
    tape.SetColor(Color::BLACK_CELL, std::make_pair(row, column));
  }

  tape_ = tape;
  ant_ = ant;
}


void Simulator::PrintTapeAnt() {
  for (int i = 0; i < tape_.GetSizeY(); i++) {
    for (int j = 0; j < tape_.GetSizeX(); j++) {
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
    std::cout << std::endl;
  }
}


void Simulator::Simulation() {
  int step_counter = 0;

  while(true) {  
    std::system("clear");
    std::cout << "Paso número: " << step_counter << "\n\n";
    PrintTapeAnt();

    std::cout << "Press N(Next Step) or S(Save current state)" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'N' || answer == 'n') {
      step_counter++;
      Color cell_current_color = tape_.CheckColor(ant_.GetPosition());
      
      // Now, the ant's cell color is saved to do the step, so before, change the ant's cell color to the oposite
      if (cell_current_color == Color::BLACK_CELL) {
        tape_.SetColor(Color::WHITE_CELL, ant_.GetPosition());
      } else {
        tape_.SetColor(Color::BLACK_CELL, ant_.GetPosition());
      }

      // Do the step
      ant_.Step(cell_current_color);
      continue;
    } else  if (answer == 'S' || answer == 's') {
      // ExportFile();
      std::cout << "File exported" << std::endl;
      break;
    } else {
      std::cout << "ERROR: incorrect option, try again" << std::endl;
    }
  }
}

void Simulator::Export() {
  std::ofstream output_file{"output.txt"};
  for (int i = 0; i < tape_.GetSizeX(); i++) {
    for (int j = 0; j < tape_.GetSizeY(); j++) {
      Color cell_color = tape_.CheckColor(std::make_pair(i, j));
      if ((i == ant_.GetPosition().first) && (j == ant_.GetPosition().second)) {
        if (cell_color == Color::BLACK_CELL) {
          output_file << BLACK << BG_RED << ant_ << RESET;
        } else {
          output_file << BLACK << BG_BLUE << ant_ << RESET;
        }
      } else {
          if (cell_color == Color::BLACK_CELL) {
            output_file << BG_RED << " " << RESET;
          } else {
            output_file << BG_BLUE << " " << RESET;
          }
      }
    }
  }
}