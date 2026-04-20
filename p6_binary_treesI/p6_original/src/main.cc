/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file main.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief 
 */

#include "../include/functions.h"

int main(int argc, char* argv[]) {
  Options config = Parse(argc, argv);
  AB<Nif> *tree = nullptr;
  if (config.tree_type == "abe") {
    tree = new ABE<Nif>();
  } else {
    tree = new ABB<Nif>();
  }

  TreeInitialization(tree, config);
  std::cout << *tree;
  Main(tree);

  delete tree;
  return 0;
}