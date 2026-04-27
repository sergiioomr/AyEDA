/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file functions.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-25
 * @brief 
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "ABB.h"  
#include "ABE.h"
#include "tree_options.h"
#include "nif.h"
#include "AVL.h"
#include <cstdlib>
#include <iostream>
#include <fstream>


void Usage();
Options Parse(int argc, char* argv[]);
void TreeInitialization(AB<Nif> *tree, const Options &config);
void Main(AB<Nif> *tree);

#endif // FUNCTIONS_H