/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file main.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-21
 * @brief 
 */

#include "hash_table.h"
#include "nif.h"
#include <string>
#include <iostream>


int main(int argc, char* argv[]) {
  unsigned table_size, block_size;
  int fd_code, fe_code;
  std::string hash;

  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "-ts") {
      table_size = atoi(argv[++i]);
    } else if (std::string(argv[i]) == "-fd") {
      fd_code = atoi(argv[++i]);
    } else if (std::string(argv[i]) == "-hash") {
      hash = argv[++i];
    } else if (std::string(argv[i]) == "-bs") {
      block_size = atoi(argv[++i]);
    } else if (std::string(argv[i]) == "-fe") {
      fe_code = atoi(argv[++i]);
    } else  {
      std::cerr << "Error. Wrong options. Use: " << std::endl;
    }
  }

  DispersionFunction<Nif>* fd;
  switch(fd_code) {
    case 1 : 
      fd = new ModuleDispersionFunction<Nif>(table_size);
      break;
    case 2 :
      fd = new SumDispersionFunction<Nif>(table_size);
      break;
    case 3 : 
      fd = new PseudoRandomDispersionFunction<Nif>(table_size);
      break;
  }

  if (hash == "open") {
    HashTable<Nif, DynamicSequence<Nif>> hash_table(table_size, *fd);
  } else {

    ExplorationFunction<Nif>* fe;
    switch(fe_code) {
      case 1 : 
        fe = new LinearExploration<Nif>(); 
        break;
      case 2 : 
        fe = new QuadraticExploration<Nif>();
        break;
      case 3 : 
        fe = new DoubleExploration<Nif>(fd);
        break;
      case 4 : 
        fe = new RehashingExploration<Nif>(fd);
        break;
    }

    HashTable<Nif> hash_table(table_size, *fd, *fe, block_size);
  }


}