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

template <typename Key>
void Swap(Key &elem1, Key &elem2) {
  Key aux = elem1;
  elem1 = elem2;
  elem2 = aux;
}

template <typename Key>
void SelectionSort() {
  for (int i = 0; i < sequence.size_(); i++) {
    int min = i;

    for (int j = i + 1 ; j < sequence.size_(); j++) {
      if (sequence[j] < sequence[i]) {
        min = j;
      }
    }

    int aux = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = aux;
  }
}

template <typename Key>
void SelectionSortTrace() {
  for (int i = 0; i < sequence.size_(); i++) {
    int min = i;

    for (int j = i + 1 ; j < sequence.size_(); j++) {
      if (sequence[j] < sequence[i]) {
        min = j;
      }
    }

    int aux = sequence[min];
    sequence[min] = sequence[i];
    sequence[i] = aux;
  }
}

template <typename Key>
void BubbleSort() {

}

template <typename Key>
void BubbleSortTrace() {

}


#endif // SORT_ALGORITHM_LIBRARY_H