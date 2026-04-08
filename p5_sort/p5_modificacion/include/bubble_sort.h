/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file bubble_sort.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-08
 * @brief 
 */

 #ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort_method.h"

template <class Key>
class BubbleMethod : public SortMethod {
  public:
    BubbleMethod(StaticSequence<Key> &sequence) : SortMethod<Key>(sequence) {}

    void Sort(StaticSequence<Key> &sequence) {
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

    
};


#endif // BUBBLE_SORT_H