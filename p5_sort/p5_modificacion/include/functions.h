/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file functions.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-23
 * @brief Declares the functions to run the program. The menu and the way to parse the arguments
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "methods.h"  
#include "table_options.h"
#include "nif.h"
#include <iostream>
#include <fstream>


void Usage();
Options Parse(int argc, char* argv[]);
void PrintSequence(const StaticSequence<Nif> &sequence);
bool Integer(const std::string &s);
void InitializingSequence(StaticSequence<Nif> &sequence, int n, std::string filename);
void Main(const Options &program_options);

#endif // FUNCTIONS_H