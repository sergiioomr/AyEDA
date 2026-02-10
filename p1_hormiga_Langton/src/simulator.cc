/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzados
 * 
 * @file simulator.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief Simulator class definition
 */

#include "../include/simulator.h"

/**
 * @brief Construct a new Simulator getting the information by the file passed by parameter
 * 
 * @param filename 
 */
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

/**
 * @brief Prints the actual state of the tape and the ant
 * 
 */
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
    std::cout << std::endl;
  }
}

/**
 * @brief Main loop for running the simulation. Its not an infinit simulation. Waits for the user request in every step.
 *        The user can stop and save the actual state or continue with the next step
 * 
 */
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

      // check if the ant went out of limits
      if (ant_.GetPosition().first < 0 || ant_.GetPosition().first >= tape_.GetSizeX() || ant_.GetPosition().second < 0 || ant_.GetPosition().second >= tape_.GetSizeY()) {
        std::system("clear");
        std::cout << "The ant has gone outside the limits of the tape" << std::endl;
        std::cout << "Step number: " << step_counter + 1 << std::endl;
        break;
      }

      continue;
    } else  if (answer == 'S' || answer == 's') {
      Export();
      std::cout << "File exported" << std::endl;
      break;
    } else {
      std::cout << "ERROR: incorrect option, try again" << std::endl;
    }
  }

}

/**
 * @brief Private method to export the actual state of the tape to an output file.
 *        Follows the same structure than the input file:
 * 
 *          Line 1. Tape's size
 *          Line 2. Initial position and Ant's orientation
 *          Line 3...n. Black cells position
 */
void Simulator::Export() {
  std::ofstream output_file{"output.txt"};
  output_file << tape_.GetSizeX() << " " <<  tape_.GetSizeY() << std::endl;
  output_file << ant_.GetPosition().first << " " << ant_.GetPosition().second << " " << static_cast<int>(ant_.GetDirection()) << std::endl;
  for (int i = 0; i < tape_.GetSizeX(); i++) {
    for (int j = 0; j < tape_.GetSizeY(); j++) {
      if (tape_.CheckColor(std::make_pair(i, j)) == Color::BLACK_CELL) {
        output_file << i << " " << j << std::endl;
      }
    }
  }
}