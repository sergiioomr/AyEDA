/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos
 * 
 * @file sort_algorithm_library.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-09
 * @brief 
 */

#ifndef SORT_ALGORITHM_LIBRARY_H
#define SORT_ALGORITHM_LIBRARY_H

#include "static_sequence.h"
#include <iostream>

/**
 * @brief Swap two values
 * 
 * @tparam Key 
 * @param elem1 
 * @param elem2 
 */
template <typename Key>
void Swap(Key &elem1, Key &elem2) {
  Key aux = elem1;
  elem1 = elem2;
  elem2 = aux;
}

template <typename Key>
void SwapTrace(Key &elem1, Key &elem2) {
  Key aux = elem1;
  elem1 = elem2; 
  elem2 = aux;
  std::cout << "Element " << elem1 << " swap with element " << elem2 << std::endl;
}

// Selection algorithms. With and without traces
template <typename Key>
void SelectionSort(StaticSequence<Key> &sequence, int n) {
  /*
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  */

  for (int i = 0; i < n; i++) {
    int min = i;

    for (int j = i + 1 ; j < n; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }

    Swap(sequence[min], sequence[i]);
  }
}

template <typename Key>
void SelectionSortTrace(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  
  for (int i = 0; i < n; i++) {
    int min = i;

    for (int j = i + 1 ; j < n; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }

    SwapTrace(sequence[min], sequence[i]);
    std::cout << "Iteration " << i << " : " << std::endl;
    PrintSequence(sequence);
    std::cout << std::endl;
  }
}


// Bubble algorithms. With and without traces
template <typename Key>
void BubbleSort(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;

  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      if (sequence[j] < sequence[j - 1]) {
        Swap(sequence[j], sequence[j - 1]);
      }
    }
  }
}

template <typename Key>
void BubbleSortTrace(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;  
  
  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      if (sequence[j] < sequence[j - 1]) {
        SwapTrace(sequence[j], sequence[j - 1]);
      }
    }

    std::cout << "Iteration " << i << " : " << std::endl;
    PrintSequence(sequence);
    std::cout << std::endl;
  }
}



// Merge algorithms. There are four, two for the algorithm with trace, and two for the algorithm without trace
template <typename Key>
void MergeSort(StaticSequence<Key> &sequence, int ini, int fin) {
  if (ini < fin) {
      int medium = (ini + fin) / 2;
      MergeSort(sequence, ini, medium);
      MergeSort(sequence, medium + 1, fin);
      Merge(sequence, ini, medium, fin);
  }
}

template <typename Key>
void Merge(StaticSequence<Key> &sequence, int ini, int medium, int fin) {
  int i = ini;
  int j = medium + 1; 
  int k = ini;
  std::vector<Key> aux(fin + 1);
  while ((i <= medium) && (j <= fin)) {
    if (sequence[i] < sequence[j]) {
      aux[k] = sequence[i];
      i++;
    } else {
      aux[k] = sequence[j];
      j++;
    }

    k++;
  }

  if (i > medium) {
    while (j <= fin) {
      aux[k] = sequence[j];
      j++; 
      k++;
    } 
  } else {
      while (i <= medium) {
        aux[k] = sequence[i];
        i++;
        k++;
      }
  }

  for (int k = ini; k <= fin; k++) {
    sequence[k] = aux[k];
  }
}

template <typename Key>
void MergeTrace(StaticSequence<Key> &sequence, int ini, int fin) {
  if (ini < fin) {
      int medium = (ini + fin) / 2;
      MergeTrace(sequence, ini, medium);
      MergeTrace(sequence, medium + 1, fin);
      Merge(sequence, ini, medium, fin);
      PrintSequence(sequence);
      std::cout << std::endl;
  }
}

template <typename Key>
void MergeSortTrace(StaticSequence<Key> &sequence, int ini, int fin) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  MergeTrace(sequence, ini, fin);
}


template<typename Key>
void Baja(int i, StaticSequence<Key> &sequence, int n) {
  int h1, h2, h;
  while(2 * i + 1 < n ) {
    h1 = 2 * i + 1;
    h2 = 2 * i + 2;
    if(h2 < n && sequence[h2] > sequence[h1]){
      h = h2;
    } else {
      h = h1;
    }
    if(sequence[h] <= sequence[i]){
      break ;
    } else {
      Swap(sequence[i], sequence[h]);
      i = h;
    }
  }
}

template <typename Key>
void HeapSort(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;

  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, sequence, n);
  }

  for (int i = n - 1; i > 0; i--) {
    Swap(sequence[0], sequence[i]);
    Baja(0, sequence, i);
  }
}
  

template <typename Key>
void HeapSortTrace(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;

  for (int i = n / 2 - 1; i >= 0; i--) {
    Baja(i, sequence, n);
  }

  int counter = 0;
  for (int i = n - 1; i > 0; i--) {
    SwapTrace(sequence[0], sequence[i]);
    Baja(1, sequence, i - 1);
    std::cout << "Iteration " << counter++ << ": " << std::endl;
    PrintSequence(sequence);
    std::cout << std::endl;
  }
}

template <typename Key>
void DeltaSort(int delta, StaticSequence<Key> &sequence, int n) {
  Key x;
  int j;
  for (int i = delta; i < n; i++) {
    x = sequence[i];
    j = i;
    while ((j >= delta) && (x < sequence[j - delta])) {
      sequence[j] = sequence[j - delta];
      j = j - delta;
    } 

    sequence[j] = x;
  }
}

template <typename Key>
void ShellSort(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  
  double alpha = 0.5;
  std::cout << "Introduce the alpha value (default 0.5): " << std::endl;
  std::cin >> alpha;
  int delta = n * alpha;
  while (delta > 1) {
    DeltaSort(delta, sequence, n);
    delta = delta * alpha;
  }
}

template <typename Key>
void DeltaSortTrace(int delta, StaticSequence<Key> &sequence, int n) {
  Key x;
  int j;
  for (int i = delta; i < n; i++) {
    x = sequence[i];
    j = i;
    while ((j >= delta) && (x < sequence[j - delta])) {
      sequence[j] = sequence[j - delta];
      j = j - delta;
    } 

    sequence[j] = x;
  }

  PrintSequence(sequence);
  std::cout << std::endl;
}

template <typename Key>
void ShellSortTrace(StaticSequence<Key> &sequence, int n) {
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  
  double alpha = 0.5;
  std::cout << "Introduce the alpha value (default 0.5): " << std::endl;
  std::cin >> alpha;
  std::cout << std::endl;
  int delta = n * alpha;
  while (delta > 1) {
    DeltaSort(delta, sequence, n);
    PrintSequence(sequence);
    std::cout << std::endl;
    delta = delta * alpha;
  }
}

template <typename Key>
void SelectionSortForModi(StaticSequence<Key> &sequence, int ini, int fin) {
  /*
  std::cout << "Initial sequence: " << std::endl;
  PrintSequence(sequence);
  std::cout << std::endl;
  */

  for (int i = ini; i <= fin; i++) {
    int min = i;

    for (int j = i + 1 ; j <= fin; j++) {
      if (sequence[j] < sequence[min]) {
        min = j;
      }
    }

    Swap(sequence[min], sequence[i]);
  }
}

template <typename Key>
void QuickSortAndSelectionSort(StaticSequence<Key> &sequence, int ini, int fin) {
  int i = ini; 
  int f = fin;
  Key p = sequence[(i+f)/2];

  while (i <= f) {
    while (sequence[i] < p) {
      i++;
    }

    while (sequence[f] > p) {
      f--;
    }

    if (i <= f) {
      SwapTrace(sequence[i],sequence[f]) ;
      i++ ; 
      f-- ;
    }
  }

  if (ini < f) {
    if (f - ini < 5) {
      std::cout << "size < 5, selection" << std::endl;
      SelectionSortForModi(sequence, ini, f);
    } else {
      std::cout << "size >= 5, QuickSort" << std::endl;
      QuickSortAndSelectionSort(sequence, ini, f); 
    }
  }

  if (i < fin) {
    if (fin - i < 5) {
      std::cout << "size < 5, selection" << std::endl;
      SelectionSortForModi(sequence, i, fin);
    } else {
      std::cout << "size >= 5, QuickSort" << std::endl;
      QuickSortAndSelectionSort(sequence, i, fin);
    }
  } 
}



#endif // SORT_ALGORITHM_LIBRARY_H