/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file main.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-21
 * @brief Main program
 */

#include "../include/hash_table.h"
#include "../include/nif.h"
#include "../include/table_options.h"
#include "../include/functions.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  Options options = Parse(argc, argv);
  Sequence<Nif>* hash_table = CreateHashTable(options);
  Menu(*hash_table);
  delete hash_table;
  return 0;
}