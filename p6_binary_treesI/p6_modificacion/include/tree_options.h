/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file table_options.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief Struct to store the parameters/options 
 */

#ifndef TREE_OPTIONS_H
#define TREE_OPTIONS_H

#include <string>

struct Options {
  std::string tree_type = "";
  unsigned init = 0;
  unsigned number_elements = 0;
  std::string filename = "";
};

#endif // TREE_OPTIONS_H