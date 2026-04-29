/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file functions.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief Defines the functions to run the program. The menu and the way to parse the arguments
 */

#include "../include/functions.h"
#include <iostream>
#include <vector>

/**
 * @brief Show how to use the program
 * 
 */
void Usage() {
  std::cerr << "Incorrect use.\n"
            << "Options:\n"
            << "  -ab <abe|abb>       : Tree type\n"
            << "  -init <i> [f] [s]   : How to add the tree data (1 = manual, 2 = random [s = elements number], 3 = file [s = elements number] [f = file name])\n";
  std::exit(EXIT_FAILURE);
} 


/**
 * @brief Parse the arguments and returns a Options class with the options
 * 
 * @param argc 
 * @param argv 
 * @return Options 
 */
Options Parse(int argc, char* argv[]) {
  Options config;
  std::vector<std::string> args(argv + 1, argv + argc);
  for (size_t i = 0; i < args.size(); ++i) {
    if (args[i] == "-h") {
      Usage();
    }
    
    if (args[i] == "-ab") {
      if (++i < args.size()) {
        config.tree_type = args[i];
      } else {
        std::cerr << "Error. Tree type is required" << std::endl;
        exit(1);
      }
    } else if (args[i] == "-init") {
      if (++i < args.size()) {
        config.init = std::stoi(args[i]);
        if (config.init == 3) {
          if (++i < args.size()) {
            config.filename = args[i];
            if (++i < args.size()) {
              config.number_elements = std::stoi(args[i]);
            } else {
              std::cerr << "Error. File mode require a filename and a number of elements" << std::endl;
              exit(1);
            }
          } else {
            std::cerr << "Error. File mode require a filename and a number of elements" << std::endl;
            exit(1);
          }
        } else if (config.init == 2) {
          if (++i < args.size()) {
            config.number_elements = std::stoi(args[i]);
          } else {
            std::cerr << "Error. Random mode require a number of element " << std::endl;
            exit(1);
          }
        }
      } else {
      std::cerr << "Error. Initialization mode is required" << std::endl;
      exit(1);
      } 
    } 
  }

  if (config.tree_type != "abe" && config.tree_type != "abb") {
    std::cerr << "Error. Tree type must be abe or abb" << std::endl;
    exit(1);
  }

  return config;
}

void TreeInitialization(AB<Nif> *tree, const Options &config) {
  if (config.init == 1) {
    std::cout << "Manual mode intialization. Empty tree created" << std::endl;
  } else if (config.init == 2) {
    std::cout << "Random mode initialization. Random tree created" << std::endl;
    srand(time(nullptr));
    for (unsigned i = 0; i < config.number_elements; i++) {
      Nif nif;
      tree->Insertar(nif);
    }
  } else if (config.init == 3) {
    std::ifstream file(config.filename);
    if (!file) {
      std::cerr << "Error. Couldn't open de file" << std::endl;
      exit(1);
    }
    for (unsigned i = 0; i < config.number_elements; i++) {
      Nif nif;
      if (!(file >> nif)) {
        std::cerr << "Error reading file data" << std::endl;
        return;
      }
      tree->Insertar(nif);
    }
  }
}

void Main(AB<Nif> *tree) {
  int option = -1;
  while (option != 0) {
    std::cout << "\n[0] Exit\n"
              << "[1] Insert key\n"
              << "[2] Search key\n"
              << "[3] Show tree inorden\n"
              << "Option: ";
    std::cin >> option;

    switch (option) {
      case 0 :
        std::cout << "Closing the simulator..." << std::endl;
        break;
      
      case 1: {
        Nif nif;
        std::cout << "Insert a NIF: " << std::endl;
        std::cin >> nif;
        if (tree->Insertar(nif)) {
          std::cout << "Key inserted" << std::endl;
          std::cout << *tree;
        } else {
          std::cout << "That Nif already exists" << std::endl;
        }
        
        break;
      }
      
      case 2: {
        Nif nif;
        std::cout << "Enter a NIF to search: ";
        std::cin >> nif;
        if (tree->Buscar(nif)) {
          std::cout << "NIF found" << std::endl;
        } else {
          std::cout << "NIF not found" << std::endl;
        }
        break;
      }

      case 3: {
        tree->Inorden(tree->GetRoot());
        std::cout << std::endl;
        break;
      }

      default : 
        std::cout << "Invalid option" << std::endl;
        break;
    }    
  }
}

void MainModi() {
  int size = 10;
  for (int i = 0; i < 3; i++) {
    size = size * 10;
    // std::cout << "for iniciado" << std::endl;

    ABB<Nif> *abb_tree = new ABB<Nif>();
    ABE<Nif> *abe_tree = new ABE<Nif>();
    std::vector<Nif> keys;

    // std::cout << "arboles y vector creados " << std::endl;
    for (int j = 0; j < size; j++) {
      Nif nif;
      keys.push_back(nif);
      // std::cout << "clave " << i << " metida en el vector" << std::endl;
      abb_tree->Insertar(nif);
     //  std::cout << "clave " << i << " metida en abb" << std::endl;
      abe_tree->Insertar(nif);
      // std::cout << "clave " << i << " metida en abe" << std::endl;
    }
    
    // std::cout << "arboles llenos";
    for (int j = 0; j < 10; j++) {
      int index = rand() % size;
      abb_tree->Buscar(keys[index]);
      abe_tree->Buscar(keys[index]);
    }
    
    std::cout << "Number of comparisions in 10 search operations of the ABB tree with " << size << " keys --> " << abb_tree->GetCounter() << std::endl;
    std::cout << "Average of the number of comparisions in 10 search operations in the ABB tree with " << size << " keys --> " << abb_tree->GetCounter() / 10 << std::endl;

    std::cout << "\n";
    std::cout << "Number of comparisions in 10 search operations of the ABE tree with " << size << " keys --> " << abe_tree->GetCounter() << std::endl;
    std::cout << "Average of the number of comparisions in 10 search operations in the ABE tree with " << size << " keys --> " << abe_tree->GetCounter() / 10 << std::endl;
    
    std::cout << "\n\n";

    delete abb_tree;
    delete abe_tree;
  }
}