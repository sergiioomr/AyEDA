/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file functions.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-23
 * @brief 
 */

#include "../include/functions.h"
#include "../include/table_options.h"
#include <iostream>

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

Options Parse(int argc, char* argv[]) {
  Options  config;
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

  if (config.table_size == 0 || config.disp_func.empty() || config.type.empty()) {
    Usage();
  }
  if (config.type == "close") {
    if (config.block_size == 0 || config.explor_func.empty()) {
      std::cerr << "Error: La dispersión cerrada requiere -bs y -fe.\n";
      Usage();
    }
  }
  return config;
}

Sequence<Nif>* CreateHashTable(const Options& options) {
  DispersionFunction<Nif>* fd = nullptr;
  if(options.disp_func == "mod") {
    fd = new ModuleDispersionFunction<Nif>(options.table_size);
  } else if(options.disp_func == "sum") {
    fd = new SumDispersionFunction<Nif>(options.table_size);
  } else if(options.disp_func == "ran") {
    fd = new PseudoRandomDispersionFunction<Nif>(options.table_size);
  }

  if (fd == nullptr) {
    std::cerr << "Error: Invalid dispersion function.\n";
    Usage();
  }

  if(options.type == "open") {
    return new HashTable<Nif, DynamicSequence<Nif>>(options.table_size, *fd);
  } else {
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

    if (fe == nullptr) {
      std::cerr << "Error: Invalid exploration function.\n";
      Usage();
    }

    return new HashTable<Nif, StaticSequence<Nif>>(options.table_size, *fd, *fe, options.block_size);
  }


}

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
        std::cout << "Write the NIF (8 digits max): ";
        std::cin >> input_dni;
        try {
          Nif nuevo_nif(input_dni);
          if (tabla.insert(nuevo_nif)) {
            std::cout << "[ÉXITO] El NIF " << input_dni << " se ha insertado correctamente.\n";
          } else {
            std::cout << "[FALLO] No se pudo insertar. ¿La tabla está llena o el NIF ya existe?\n";
          }
        } catch (const std::invalid_argument& e) {
          std::cerr << e.what() << "\n";
        }
        break;
      }

      case 2: {
        std::cout << "Introduce el DNI a buscar: ";
        std::cin >> input_dni;
        try {
          Nif nif_buscado(input_dni);
          if (tabla.search(nif_buscado)) {
            std::cout << "[ENCONTRADO] El NIF " << input_dni << " ESTÁ en la tabla.\n";
          } else {
            std::cout << "[NO ENCONTRADO] El NIF " << input_dni << " NO está en la tabla.\n";
          }
        } catch (const std::invalid_argument& e) {
          std::cerr << "[ERROR DE FORMATO] " << e.what() << "\n";
        }
        break;
      }
      case 3:
        std::cout << "Saliendo del simulador...\n";
        break;
      default:
        std::cout << "Opción incorrecta. Elige 1, 2 o 3.\n";
    }
  }
}