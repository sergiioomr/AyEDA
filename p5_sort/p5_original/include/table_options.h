/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file table_options.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-13
 * @brief Struct to store the parameters/options 
 */

#ifndef TABLE_OPTIONS_H
#define TABLE_OPTIONS_H

#include <string>

struct Options {
  unsigned table_size = 0;
  std::string sort_method = "";
  unsigned init = 0;
  bool trace = false;
  std::string filename = "";
};

#endif //TABLE_OPTIONS_H