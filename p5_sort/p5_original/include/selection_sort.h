/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * @asignatura
 * @file selection_sort.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-08
 * @brief 
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort_method.h"
#include "sort_algorithm_library.h"

template <class Key>
class SelectionMethod : public SortMethod {
  public:
    SelectionMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort(StaticSequence<Key> &sequence_) {
      if (trace_) {
        SelectionSortTrace(sequence_, sequence_.size());
      } else {
        SelectionSort(sequence_, sequence_.size());
      }
    }

  private: 
    bool trace_;
};

template <class Key>
class BubbleMethod : public SortMethod {
  public: 
    BubbleMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort(StaticSequence<Key> &sequence_) {
      if (trace_) {
        BubbleSortTrace(sequence_, sequence_.size());
      } else {
        BubbleSort(sequence_, sequence_.size());
      }
    }

  private: 
    bool trace_;
};

template <class Key>
class MergeMethod : public SortMethod {
  public:
    MergeMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence); trace_(trace) {}

    void Sort(StaticSequence<Key> &sequence_) {
      if (trace_) {
        BubbleSortTrace(sequence_, sequence_[0], sequence_[sequence_.size()]);
      } else {
        BubbleSort(sequence_, sequence_[0], sequence_[sequence_.size()]);
      }
    }

  private:
    bool trace_;
};


#endif // SELECTION_SORT_H