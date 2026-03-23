/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file table_options.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-23
 * @brief 
 */

#ifndef TABLE_OPTIONS_H
#define TABLE_OPTIONS_H

#include <string>

struct Options {
  unsigned table_size = 0;
  std::string disp_func = "";
  std::string type = "";
  unsigned block_size = 0;
  std::string explor_func = "";
};

#endif //TABLE_OPTIONS_H