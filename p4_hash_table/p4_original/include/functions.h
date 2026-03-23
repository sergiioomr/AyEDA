/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file functions.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-23
 * @brief 
 */

#include "hash_table.h"
#include "nif.h"
#include "table_options.h"

void Usage();
Options Parse(int argc, char* argv[]);
Sequence<Nif>* CreateHashTable(const Options& options); 
void Menu(Sequence<Nif>& tabla);