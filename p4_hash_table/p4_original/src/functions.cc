/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file functions.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-23
 * @brief Defines the functions to run the program. The menu and the way to parse the arguments
 */

#include "../include/functions.h"
#include "../include/table_options.h"
#include <iostream>

/**
 * @brief Show how to use the program
 * 
 */
void Usage() {
  std::cerr << "Incorrect use.\n"
            << "Basic options:\n"
            << "  -ts <s>         : Table size (integer)\n"
            << "  -fd <f>         : Dispersion function (ej: mod, sum, rand)\n"
            << "  -hash <type>    : Hash table mode (open o close)\n"
            << "\nAddtional options (only if -hash is close):\n"
            << "  -bs <s>         : Block size (integer)\n"
            << "  -fe <f>         : Exploration function (ej: lin, quad, dob, red)\n";
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
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    if (arg == "-ts" && i + 1 < argc) {
      config.table_size = std::stoi(argv[++i]);
    } else if (arg == "-fd" && i + 1 < argc) {
      config.disp_func = argv[++i];
    } else if (arg == "-hash" && i + 1 < argc) {
      config.type = argv[++i];
    } else if (arg == "-bs" && i + 1 < argc) {
      config.block_size = std::stoi(argv[++i]);
    } else if (arg == "-fe" && i + 1 < argc) {
      config.explor_func = argv[++i];
    } else {
      Usage();
    }
  }

  // The table can't have size 0, and there must be a dispersion function and a type for the hash table
  if (config.table_size == 0 || config.disp_func.empty() || config.type.empty()) {
    Usage();
  }

  // Also, if the type is close, the block size can't be 0 and there must be an exploration function
  if (config.type == "close") {
    if (config.block_size == 0 || config.explor_func.empty()) {
      std::cerr << "Error: La dispersión cerrada requiere -bs y -fe.\n";
      Usage();
    }
  }

  return config;
}

/**
 * @brief Create a Hash Table, use the object options that contains the parameters of the hash table
 * 
 * @param options 
 * @return Sequence<Nif>* 
 */
Sequence<Nif>* CreateHashTable(const Options& options) {
  
  // Create the dispersion function using the parameter
  DispersionFunction<Nif>* fd = nullptr;
  if(options.disp_func == "mod") {
    fd = new ModuleDispersionFunction<Nif>(options.table_size);
  } else if(options.disp_func == "sum") {
    fd = new SumDispersionFunction<Nif>(options.table_size);
  } else if(options.disp_func == "ran") {
    fd = new PseudoRandomDispersionFunction<Nif>(options.table_size);
  }

  // If the dispersion function couldn't be created, it will be null, so return an error
  if (fd == nullptr) {
    std::cerr << "Error: Invalid dispersion function.\n";
    Usage();
  }

  // Is the table is open, return the hash table with the dispersion function created
  if(options.type == "open") {
    return new HashTable<Nif, DynamicSequence<Nif>>(options.table_size, *fd);
  } else {
    // Else, create the hash table with the close type parameters. Create the exploration funcion
    ExplorationFunction<Nif>* fe = nullptr;
    if(options.explor_func == "lin") {
      fe = new LinearExploration<Nif>();
    } else if(options.explor_func == "quad") {
      fe = new QuadraticExploration<Nif>();
    } else if(options.explor_func == "dob") {
      DispersionFunction<Nif>* fd_aux = new SumDispersionFunction<Nif>(options.table_size);
      fe = new DoubleExploration<Nif>(fd_aux);
    } else if(options.explor_func == "red") {
      DispersionFunction<Nif>* fd_aux = new SumDispersionFunction<Nif>(options.table_size);
      fe = new RehashingExploration<Nif>(fd_aux);
    }

    // If the exploration function couldn't be created, it will be null, so return an error
    if (fe == nullptr) {
      std::cerr << "Error: Invalid exploration function.\n";
      Usage();
    }

    return new HashTable<Nif, StaticSequence<Nif>>(options.table_size, *fd, *fe, options.block_size);
  }


}

/**
 * @brief Implement the hash table menu
 * 
 * @param tabla 
 */
void Menu(Sequence<Nif>& tabla) {
  int option = 0; 
  long input_dni;

  
  while (option != 3) {
    std::cout << "\n=== HASH TABLE MENU ===\n"
              << "1. Insert NIF\n"
              << "2. Search NIF\n"
              << "3. Exit\n"
              << "Choose an option: ";

    std::cin >> option;

    switch(option) {
      case 1: {
        // Create the NIF and insert if it's possible
        std::cout << "Write the NIF (8 digits max): ";
        std::cin >> input_dni;
        try {
          Nif new_nif(input_dni);
          if (tabla.insert(new_nif)) {
            std::cout << "NIF " << new_nif << " has been added.\n";
          } else {
            std::cout << "Error. Can't insert. The table is full or the NIF already exists\n";
          }
        } catch (const std::invalid_argument& e) {
          // The NIF must be and 8 digits number
          std::cerr << e.what() << "\n";
        }
        break;
      }

      case 2: {
        // Search a Nif, return exit if it was found, else, return failiure
        std::cout << "Enter the NIF to search: ";
        std::cin >> input_dni;
        try {
          Nif searched_nif(input_dni);
          if (tabla.search(searched_nif)) {
            std::cout << "The NIF " << input_dni << " is in the table\n";
          } else {
            std::cout << "The NIF " << input_dni << " is NOT in the table.\n";
          }
        } catch (const std::invalid_argument& e) {
          std::cerr << e.what() << "\n";
        }
        break;
      }

      case 3:
      // Exit to the menu
        std::cout << "Leaving...\n";
        break;
      default:
        std::cout << "Incorrect option. Choose 1, 2 or 3.\n";
    }
  }
}