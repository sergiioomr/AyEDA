/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file functions.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-13
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
            << "Options:\n"
            << "  -size <s>           : Sequence size (integer)\n"
            << "  -ord <m>            : Sort Method (Selection(a), Bubble(b), Merge(c), Heap(d), Shell(e), QuickAndSelection(f))\n"
            << "  -init <type> [f]    : How to add the sequence data (1 = manual, 2 = random, 3 = file [f = file name])\n"
            << "  -trace <y|n>        : Show or no the trace\n";
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
    
    if (args[i] == "-size") {
      if (++i < args.size()) {
        config.sequence_size = std::stoi(args[i]);
      } else {
        std::cerr << "Error. Size value is required" << std::endl;
        exit(1);
      }
    } else if (args[i] == "-ord") {
      if (++i < args.size()) {
        config.sort_method = args[i][0];
      } else {
        std::cerr << "Error. Sort method code is required" << std::endl;
        exit(1);
      }
    } else if (args[i] == "-init") {
      if (++i < args.size()) {
        config.init = std::stoi(args[i]);
        if (config.init == 3) {
          if (++i < args.size()) {
            config.filename = args[i];
          } else {
            std::cerr << "Error. File mode to initialize the sequence require a filename" << std::endl;
            exit(1);
          }
        }
      } else {
        std::cerr << "Error. Initialization mode is required" << std::endl;
        exit(1);
      }
    } else if (args[i] == "-trace") {
      if (++i < args.size()) {
        config.trace = (args[i] == "y");
      }
    } else {
      std::cerr << "Error. Unknown parameter" << std::endl;
      Usage();
      exit(1);
    }
  }

  // The table can't have size 0, and there must be a sort method
  if (config.sequence_size == 0 || config.sort_method.empty()) {
    Usage();
  }

  return config;
}

void PrintSequence(const StaticSequence<Nif> &sequence) {
  for (int i = 0; i < sequence.GetSize(); i++) {
    std::cout << sequence[i] << " ";
  }
}

bool Integer(const std::string &s) {
  if (s.empty()) return false;

  for (size_t i = 0; i < s.size(); i++) {
    if (!isdigit(s[i])){
      return false;
    }
  }

  return true;
}

void InitializingSequence(StaticSequence<Nif> &sequence, const Options &program_options) {
  // If n = 0, manual initialization
    
  if (program_options.init == 1) {
    std::cout << "Manual initialization" << std::endl;

    int counter = 0;

    while (counter < sequence.GetSize()) {
      std::cout << "Enter a NIF"<< std::endl;

      std::string number;
      std::cin >> number;

      if (!Integer(number)) {
        std::cerr << "Must be an integer number. Enter again" << std::endl;
      } else {
        Nif nif(std::stol(number));
        sequence[counter] = nif;
        counter++;
      }
    }
  } else if (program_options.init == 2) {
    // If n == 1, random initialization
    std::cout << "Random initialization" << std::endl;

    for (int i = 0; i < sequence.GetSize(); i++) {
      // Nif random initialization
      Nif nif;
      sequence[i] = nif;
    }
  } else {
    // File initialization
    std::ifstream file(program_options.filename);

    if (!file) {
      std::cerr << "Error opening the file" << std::endl;
      return;
    }

    for (int i = 0; i < sequence.GetSize(); i++) {
      if (!(file >> sequence[i])) {
        std::cerr << "Error reading file data" << std::endl;
        return;
      }
    }
  }
}

void Main(const Options &program_options) {
  std::cout << "Práctiac 5. Algoritmos de ordenación" << std::endl;

  StaticSequence<Nif> sequence(program_options.sequence_size);

  std::cout << "Initializating sequence" << std::endl;
  InitializingSequence(sequence, program_options);

  // Create the Sorting Method

  char method = program_options.sort_method[0];
  switch (method) {
    case 'a': {
      SelectionMethod<Nif> selection_sort(sequence, program_options.trace);
      selection_sort.Sort();
      break;
    }

    case 'b' : {
      BubbleMethod<Nif> bubble_sort(sequence, program_options.trace);
      bubble_sort.Sort();
      break;
    }

    case 'c' : {
      MergeMethod<Nif> merge_sort(sequence, program_options.trace);
      merge_sort.Sort();
      break;
    }

    case 'd' : {
      HeapMethod<Nif> heap_sort(sequence, program_options.trace);
      heap_sort.Sort();
      break;
    }

    case 'e' : {
      ShellMethod<Nif> shell_sort(sequence, program_options.trace);
      shell_sort.Sort();
      break;
    }

    case 'f' : {
      std::cout << "Initial sequence: " << std::endl;
      PrintSequence(sequence);
      std::cout << std::endl;
      ModificationMethod<Nif> modi_sort(sequence, program_options.trace);
      modi_sort.Sort();
      break;
    }
  }

  // Now, the sequence is sorted. Print.
  std::cout << "Sorted sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  
}