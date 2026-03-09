/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file tape.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-05
 * @brief Tape class definition
 */

#include "../include/tape.h"



/**
 * @brief Converts a color into a code to print in the terminal. Useful to print a cell.
 * 
 * @param color 
 * @return std::string 
 */
std::string Tape::ColorToCode(const Color &color) {
  std::string color_code;
  switch (color) {
    case Color::WHITE_CELL : 
      color_code = BG_WHITE;
      break;
    case Color::BLACK_CELL : 
      color_code = BG_BLACK;
      break;
    case Color::RED_CELL : 
      color_code =  BG_RED;
      break;
    case Color::BLUE_CELL : 
      color_code =  BG_BLUE;
      break;
    case Color::GREEN_CELL : 
      color_code = BG_GREEN;
      break;
    case Color::LBLUE_CELL : 
      color_code = BG_LBLUE;
      break;
    case Color::LGRENN_CELL : 
      color_code = BG_LGREEN;
      break;
    case Color::YELLOW_CELL : 
      color_code = BG_YELLOW;
      break;
    case Color::CYAN_CELL : 
      color_code = BG_CYAN;
      break;
    case Color::GRAY_CELL : 
      color_code = BG_GRAY;
      break;
    case Color::ROSE_CELL : 
      color_code = BG_ROSE;
      break;
    case Color::ORANGE_CELL : 
      color_code = BG_ORANGE;
      break;
    case Color::MAGENTA_CELL: 
      color_code = BG_MAGENTA;
      break;
  }
  
  return color_code;
}

/**
 * @brief Method to print a cell with the indicate color and character
 * 
 * @param position 
 * @param symbol 
 */
void Tape::PrintCell(const std::pair<int, int> &position, const char symbol) {
  Color cell_color = CheckColor(position);
  std::cout << ColorToCode(cell_color) << symbol << RESET;
}

/**
 * @brief << operator overloading
 * 
 * @param os 
 * @param tape 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Tape &tape) {
  for (int i = 0; i < tape.GetSizeX(); i++) {
    for (int j = 0; j < tape.GetSizeY(); j++) {
      os << BG_LBLUE << " " << RESET << " "; 
    }

    os << std::endl << std::endl;
  }

  return os;
}

