/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructura de Datos Avanzadas
 * @file methods.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-13
 * @brief 
 */

#ifndef METHODS_H
#define METHODS_H

#include "sort_algorithm_library.h"
#include "sort_method.h"


template <class Key>
class SelectionMethod : public SortMethod<Key> {
  public:
    SelectionMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence), trace_(trace) {}

    void Sort() override {
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
class BubbleMethod : public SortMethod<Key> {
  public:
    BubbleMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence), trace_(trace) {}

    void Sort() override {
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
class MergeMethod : public SortMethod<Key> {
  public:
    MergeMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        MergeSortTrace(sequence_, sequence_.size());
      } else {
        MergeSort(sequence_, 0, sequence_.size());
      }
    }

  private:
    bool trace_;
};


template <class Key>
class HeapMethod : public SortMethod<Key> {
  public:
    HeapMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        HeapSortTrace(sequence_, sequence_.size());
      } else {
        HeapSort(sequence_, sequence_.size());
      }
    }

  private: 
    bool trace_;
};

template <class Key>
class ShellMethod : public SortMethod<Key> {
  public:
    ShellMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        ShellSortTrace(sequence_, sequence_.size());
      } else {
        ShellSort(sequence_, sequence_.size());
      }
    }

  private: 
    bool trace_;
};



#endif // METHODS_H