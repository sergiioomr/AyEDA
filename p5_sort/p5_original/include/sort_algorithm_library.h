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

template <typename Key>
void Swap(Key &elem1, Key &elem2) {
  Key aux = elem1;
  elem1 = elem2;
  elem2 = aux;
}

template <typename Key>
void SelectionSort(StaticSequence<Key> &sequence, int n) {
  for (int i = 0; i < n; i++) {
    int min = i;

    for (int j = i + 1 ; j < n; j++) {
      if (sequence[j] < sequence[i]) {
        min = j;
      }
    }

    Swap(sequence[min], sequence[i]);
  }
}

template <typename Key>
void SelectionSortTrace(StaticSequence<Key> &sequence, int n) {
  for (int i = 0; i < sequence.size_(); i++) {
    int min = i;

    for (int j = i + 1 ; j < sequence.size_(); j++) {
      if (sequence[j] < sequence[i]) {
        min = j;
      }
    }

    Swap(sequence[min], sequence[i]);
  }
}

template <typename Key>
void BubbleSort(StaticSequence<Key> &sequence, int n) {
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
  for (int i = 1; i < n; i++) {
    for (int j = n - 1; j >= i; j--) {
      if (sequence[j] < sequence[j - 1]) {
        Swap(sequence[j], sequence[j - 1]);
      }
    }
  }
}



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
  std::vector<Key> aux(sequence.size());
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

  for (int k = ini; k < fin; k++) {
    sequence[k] = aux[k];
  }
}

template <typename Key>
void MergeTrace(StaticSequence<Key> &sequence, int n) {

}

template <typename Key>
void MergeSortTrace(StaticSequence<Key> &sequence, int n) {

}




#endif // SORT_ALGORITHM_LIBRARY_H