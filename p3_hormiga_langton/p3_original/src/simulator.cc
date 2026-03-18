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
Simulator::Simulator(const std::string& filename, const std::string &tape_type) : tape_{}, ants_{} {
  
  std::ifstream input_file{filename};
  std::string line;
  int size_x, size_y;

  // Line 1. Size and number of colors of the tape
  getline(input_file, line);
  std::istringstream iss(line);
  iss >> size_x >> size_y >> num_colors_;

  // Create the tape
  if (tape_type == "periodic") {
      tape_ = std::make_unique<TapePeriodic>(size_x, size_y);
    } else if (tape_type == "reflective") {
      tape_ = std::make_unique<TapeReflective>(size_x, size_y);
    } else if (tape_type == "sliding") {
      tape_ = std::make_unique<TapeSliding>(size_x, size_y);
    } else {
        std::cerr << "Unknown tape. Please, select one between: periodic, reflective or sliding" << std::endl;
        exit(1);
    }

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
    std::string ant_type;
    int ant_x, ant_y;
    char direction_character;

    data >> ant_type >> ant_x >> ant_y >> direction_character;

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
    if (ant_type == "C-DDII") {
      ants_.push_back(std::make_unique<Ant_C_DDII>(direction, std::make_pair(ant_x, ant_y)));
    } else if (ant_type == "C-IDID") {
      ants_.push_back(std::make_unique<Ant_C_IDID>(direction, std::make_pair(ant_x, ant_y)));
    } else if (ant_type == "H-DDII") {
      ants_.push_back(std::make_unique<Ant_H_DDII>(direction, std::make_pair(ant_x, ant_y)));
    } else if (ant_type == "H-IDID") {
      ants_.push_back(std::make_unique<Ant_H_IDID>(direction, std::make_pair(ant_x, ant_y)));
    } else {
      std::cerr << "ERROR: Unknown ant type. The valid types are: DDII or IDID." << std::endl;
      exit(EXIT_FAILURE);      
    }
  }


  // Read the color cells
  while(getline(input_file, line)) {
    int row, column, color_code;
    std::istringstream color_cell_stream(line);
    color_cell_stream >> row >> column >> color_code;

    // Check if the color code is not higher than the number of colors of the tape
    if (color_code >= num_colors_) {
      std::cerr << "A cell have been initializated with an invalid color, please change the number" << std::endl;
      exit(EXIT_FAILURE);
    }
    // Convert the code to a color
    Color color = static_cast<Color>(color_code);

    tape_->SetColor(color, std::make_pair(row, column));
  }

  input_file.close();
}

/**
 * @brief Prints the actual state of the tape and all the ants
 * 
 */
void Simulator::PrintTapeAnt() {
  for (int i = tape_->GetMinX(); i < tape_->GetMinX() + tape_->GetSizeX(); i++) {
    for (int j = tape_->GetMinY(); j < tape_->GetMinY() + tape_->GetSizeY(); j++) {
      
      int ants_counter = 0;
      int ant_index = -1;
      for (size_t k = 0; k < ants_.size(); k++) {
        if ((i == ants_[k]->GetPosition().first) && (j == ants_[k]->GetPosition().second)) {
          ant_index = k;
          ants_counter++;
        }
      }

      int color_code = static_cast<int>(tape_->CheckColor(std::make_pair(i, j)));
      if (ants_counter == 1) {
        // Get the symbol of the ant
        char ant_symbol;
        switch (ants_[ant_index]->GetDirection()) {
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

        tape_->PrintCell(std::make_pair(i, j), ant_symbol);

      } else if (ants_counter > 1) {
        // If there are many ants in the same cell, represent with an X
        tape_->PrintCell(std::make_pair(i, j), 'X');
      } else {
        if (color_code == 0) {
          // Print without number in the cell
          tape_->PrintCell(std::make_pair(i, j), ' ');
        } else {
          char char_color_code = color_code + '0';
          tape_->PrintCell(std::make_pair(i, j), char_color_code);
        }
      }
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  //Now, print the ants information
  for(size_t i = 0; i < ants_.size(); i++) {
    std::cout << ants_[i]->GetType() << ": (" << ants_[i]->GetPosition().first + 1 << ", " << 
      ants_[i]->GetPosition().second + 1 << ") " << ants_[i]->GetLifeTime() << std::endl;
  }
}

/**
 * @brief Make the herbivorous and carnivorous ants make their eat rules
 * 
 */
void Simulator::ApplyAntRules() {
  for (size_t i = 0; i < ants_.size(); i++) {
    // If the ant has died, skip
    if (ants_[i]->GetLifeTime() <= 0) {
      continue;
    }

    if (ants_[i]->GetCategory() == 'H') {

      // If the ant is herbivorous, onlye eat with the cell number
      HerbivorousAnt* herb_ant = dynamic_cast<HerbivorousAnt*>(ants_[i].get());
      herb_ant->IncreaseLifetime(static_cast<int>(tape_->CheckColor(herb_ant->GetPosition())));

    } else {
      // The ant is carnivorous, so will attack all the ants in its cell
      for (size_t j = 0; j < ants_.size(); j++) {
        // If has died, skip
        if (ants_[j]->GetLifeTime() <= 0) {
          continue;
        }
        // If they are the same, skip
        if (i == j) {
          continue; 
        }

        if (ants_[i]->GetPosition() == ants_[j]->GetPosition()) {
          
          // If they are in the same cell, increase ants_[i] lifetime and decreas ants_[j]
          ants_[i]->IncreaseLifetime(ants_[j]->GetLifeTime());
          CarnivorousAnt* carnv_ant = dynamic_cast<CarnivorousAnt*>(ants_[i].get());
          ants_[j]->DecreaseLifetime(carnv_ant->GetVoracity());
          std::cout << "Ant type: " << ants_[i]->GetType() << " attack to ant type: " << ants_[j]->GetType() << std::endl;

          // Now, if the ant j is carnivorous, attack the ant i
          if (ants_[j]->GetCategory() == 'C') {
            CarnivorousAnt* other_carnv_ant = dynamic_cast<CarnivorousAnt*>(ants_[j].get());
            ants_[j]->IncreaseLifetime(ants_[i]->GetLifeTime());
            ants_[i]->DecreaseLifetime(other_carnv_ant->GetVoracity());
          }
        }
      }
    }
    }
}

/**
 * @brief Check if the ant went out of limits
 * 
 * @param ant_position 
 * @return true 
 * @return false 
 */
bool Simulator::OutOfLimits(const int ant_position) {
  if (ants_[ant_position]->GetPosition().first < 0 || 
      ants_[ant_position]->GetPosition().first >= tape_->GetSizeX() ||
      ants_[ant_position]->GetPosition().second < 0 ||
      ants_[ant_position]->GetPosition().second >= tape_->GetSizeY()) {
              
      return true;
    }
      
    return false;
}

/**
 * @brief Erase the died antes once all have moved
 * 
 */
void Simulator::EraseDiedAnts() {
  for (int i = ants_.size() - 1; i >= 0; i--) {
    if (ants_[i]->GetLifeTime() <= 0) {
      std::string type = ants_[i]->GetType();
      ants_.erase(ants_.begin() + i);
      std::cout << "Ant " << type << " has died" << std::endl;
    }
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
    // Print the new tape
    std::system("clear");
    std::cout << "Paso número: " << step_counter << "\n\n";
    PrintTapeAnt();

    // Answer for a option
    std::cout << "Press N(Next step) or S(Save current state)" << std::endl;
    char answer;
    std::cin >> answer;
    
    if (answer == 'N' || answer == 'n') {
      // new step to the counter
      step_counter++;

      for (size_t i = 0; i < ants_.size(); i++) {
        // Get the current color of the ant's cell
        Color color = tape_->CheckColor(ants_[i]->GetPosition());

        // Change the cell color before the ant moves
        int current_cell_color_code = static_cast<int>(color);
        int next_color_code = (current_cell_color_code + 1) % num_colors_;
        Color next_color = static_cast<Color>(next_color_code);
        tape_->SetColor(next_color, ants_[i]->GetPosition());

        // Now, the ant makes the step
        ants_[i]->Step(color);

        // For every step, the ant must decrement in one its lifetime
        ants_[i]->Decrease1Lifetime();

        // Change te coordinates of the ant if its needed. If not, Reposition will return the current coordinates
        std::pair<std::pair<int, int>, Direction> new_ant_data = tape_->Reposition(ants_[i]->GetPosition(), ants_[i]->GetDirection());
        ants_[i]->SetDirection(new_ant_data.second);
        ants_[i]->SetPosition(new_ant_data.first);
      }

      // Now, all the ants finish their movements. Check the collisions and change their lifetime. Remove the dead ants also
      ApplyAntRules();

     // Now, delete all the died ants
      EraseDiedAnts();
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
 *          Line 1. Tape's size and number of colors
 *          Line 2. Type, initial position and orientation of every ant. Separated by ';'
 *          Line 3...n. Position and color of all the non-white cells
 */
void Simulator::Export() {
  std::ofstream output_file{"output.txt"};

  // Line 1. Tape's size and number of colors
  output_file << tape_->GetSizeX() << " " <<  tape_->GetSizeY() << " " << num_colors_ << std::endl;

  // Line 2. Print to the output file all the ants
  for (size_t i = tape_->GetMinX(); i < ants_.size(); i++) {
    // First get the character of the ant orientation
    char ant_symbol;
    switch (ants_[i]->GetDirection()) {
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
    output_file << ants_[i]->GetType() << " " << ants_[i]->GetPosition().first << " " << ants_[i]->GetPosition().second << " " << ant_symbol;
    // If is not the last ant, write ';'
    if (i != ants_.size() - 1) {
      output_file << " ; ";
    }
  }

  output_file << std::endl;

  // Lines 3...n. Print all the non-white cells
  for (int i = tape_->GetMinX(); i < tape_->GetSizeX() + tape_->GetMinX(); i++) {
    for (int j = tape_->GetMinY(); j < tape_->GetSizeY() + tape_->GetMinY(); j++) {
      int color_code = static_cast<int>(tape_->CheckColor(std::make_pair(i, j)));
      // Write only non-white cells (color != 0) to the file
      if (color_code != 0) {
        output_file << i - tape_->GetMinX() << " " << j - tape_->GetMinY() << " " << color_code << std::endl;
      }
    }
  }

  output_file.close();
}