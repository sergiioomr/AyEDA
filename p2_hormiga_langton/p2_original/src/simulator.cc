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
Simulator::Simulator(const std::string& filename) : tape_{}, ants_{}, num_colors_{} {
  
  std::ifstream input_file{filename};
  std::string line;
  int num_colors;   
  int size_x, size_y;

  // Line 1. Size and number of colors of the tape
  getline(input_file, line);
  std::istringstream iss(line);
  iss >> size_x >> size_y >> num_colors;

  // Line 2. Type, initial position and orientations of the ant. N ants, separated by ';'
  
  // Read the line
  getline(input_file, line);

  // Convert into a stream
  std::istringstream ants_line(line);
  std::string single_ant;

  // Read from ants_line, with getline(), every ant, separating ants by ';'
  while(getline(ants_line, single_ant, ';')) {
    // Now, single_ant onlye have the single ant information
    
    std::istringstream data(single_ant);
    std::string move_rules;
    int ant_x, ant_y;
    char direction_character;

    data >> move_rules >> ant_x >> ant_y >> direction_character;

    // Convert direction
    Direction direction;
    switch (direction_character) {
      case '>' :
        direction = Direction::RIGHT;
        break;
      case '<' :
        direction = Direction::LEFT;
        break;
      case 'v' :
        direction = Direction::DOWN;
        break;
      case '^' : 
        direction = Direction::UP;
        break;
      default :
        std::cerr << "Error. Invalid orientation." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Validate the movement rules
    for (const char c : move_rules) {
      if ((c != 'D') && (c != 'd') && (c != 'I') && (c != 'i')) {
        std::cerr << "Error. Invalid charcater in the movement rules" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    // Create the ant and add to the vector
    ants_.push_back(Ant_X{direction, std::make_pair(ant_x, ant_y), move_rules});
  }

  // Create the tape
  Tape tape{size_x, size_y};

  // Read the color cells
  while(getline(input_file, line)) {
    int row, column, color_code;
    iss = std::istringstream(line);
    iss >> row >> column >> color_code;

    // Check if the color code is not higher than the number of colors of the tape
    if (color_code >= num_colors) {
      std::cerr << "A cell have been initializated with an invalid color, please change the number" << std::endl;
      exit(EXIT_FAILURE);
    }
    // Convert the code to a color
    Color color = static_cast<Color>(color_code);

    tape.SetColor(color, std::make_pair(row, column));
  }

  tape_ = tape;
  num_colors_ = num_colors;
}

void Simulator::PrintTapeAnt() {
  for (int i = 0; i < tape_.GetSizeX(); i++) {
    for (int j = 0; j < tape_.GetSizeY(); j++) {
      
      bool is_ant = false;
      int ant_index;
      for (size_t k = 0; k < ants_.size(); k++) {
        if ((i == ants_[k].GetPosition().first) && (j == ants_[k].GetPosition().second)) {
          is_ant = true;
          ant_index = k;
        }
      }

      if (is_ant) {
        // Get the symbol of the ant
        char ant_symbol;
        switch (ants_[ant_index].GetDirection()) {
          case Direction::UP :
            ant_symbol = '^';
            break;
          case Direction::DOWN : 
            ant_symbol = 'v';
            break;
          case Direction::LEFT :
            ant_symbol = '<';
            break;
          case Direction::RIGHT : 
            ant_symbol = '>'; 
            break;
        }

        tape_.PrintCell(std::make_pair(i, j), ant_symbol);

      } else {
        tape_.PrintCell(std::make_pair(i, j));
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

    std::cout << "Press N(Next step) or S(Save current state)" << std::endl;
    char answer;
    std::cin >> answer;
    
    if (answer == 'N' || answer == 'n') {
      step_counter++;

      for (size_t i = 0; i < ants_.size(); i++) {
        
        // Get the current color of the ant's cell
        Color color = tape_.CheckColor(ants_[i].GetPosition());

        // Change the cell color before the ant moves
        int current_cell_color_code = static_cast<int>(color);
        int next_color_code = (current_cell_color_code + 1) % num_colors_;
        Color next_color = static_cast<Color>(next_color_code);
        tape_.SetColor(next_color, ants_[i].GetPosition());

        // Now, the ant makes the step
        ants_[i].Step(color);

        // Verify if the ant went out of the limits
        if (ants_[i].GetPosition().first < 0 || ants_[i].GetPosition().first >= tape_.GetSizeX() || ants_[i].GetPosition().second < 0 || ants_[i].GetPosition().second >= tape_.GetSizeY()) {
          std::system("clear");
          std::cout << "One ant has gone outside the limits of the tape" << std::endl;
          std::cout << "Step number: " << step_counter + 1 << std::endl;
          break;
        }
      }

      // Now, all the ants have been moved. If a collision is detected now, the simulation will stop
        for (size_t i = 0; i < ants_.size(); i++) {
          for (size_t j = i + 1; j < ants_.size(); j++) {
            if (ants_[i].GetPosition() == ants_[j].GetPosition()) {
              std::system("clear");
              std::cout << "Two ants have been collisioned" << std::endl;
              std::cout << "Ant " << i << " and Ant " << j << std::endl;
              std::cout << "Position: (" << ants_[i].GetPosition().first << ", " << ants_[i].GetPosition().second << ")" << std::endl;
              std::cout << "Step number: " << step_counter << std::endl;
              return;
          }
        }
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
  output_file << tape_.GetSizeX() << " " <<  tape_.GetSizeY() << num_colors_ << std::endl;
  // Print in the output file all the ants
  for (size_t i = 0; i < ants_.size(); i++) {
    // First get the character of the ant orientation
    char ant_symbol;
    switch (ants_[i].GetDirection()) {
      case Direction::UP :
        ant_symbol = '^';
        break;
      case Direction::DOWN : 
        ant_symbol = 'v';
        break;
      case Direction::LEFT :
        ant_symbol = '<';
        break;
      case Direction::RIGHT : 
        ant_symbol = '>'; 
        break;
    }
    output_file << ants_[i].GetMoveRules() << ants_[i].GetPosition().first << ants_[i].GetPosition().second << ant_symbol;
    // If is not the last ant, write ';'
    if (i != ants_.size() - 1) {
      output_file << " ; ";
    }
  }

  output_file << std::endl;

  for (int i = 0; i < tape_.GetSizeX(); i++) {
    for (int j = 0; j < tape_.GetSizeY(); j++) {
      if (tape_.CheckColor(std::make_pair(i, j)) == Color::BLACK_CELL) {
        output_file << i << " " << j << std::endl;
      }
    }
  }
}