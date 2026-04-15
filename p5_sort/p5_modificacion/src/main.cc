/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file main.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-13
 * @brief Main program
 */

#include "../include/nif.h"
#include "../include/table_options.h"
#include "../include/functions.h"
#include "../include/methods.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  Options options = Parse(argc, argv);
  Main(options);
  return 0;
}