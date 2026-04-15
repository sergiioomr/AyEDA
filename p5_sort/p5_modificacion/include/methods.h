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
    SelectionMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        SelectionSortTrace(this->sequence_, this->sequence_.GetSize());
      } else {
        SelectionSort(this->sequence_, this->sequence_.GetSize());
      }
    }

  private:
    bool trace_;

};


template <class Key>
class BubbleMethod : public SortMethod<Key> {
  public:
    BubbleMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        BubbleSortTrace(this->sequence_, this->sequence_.GetSize());
      } else {
        BubbleSort(this->sequence_, this->sequence_.GetSize());
      }
    }

  private: 
    bool trace_;

};

template <class Key>
class MergeMethod : public SortMethod<Key> {
  public:
    MergeMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        MergeSortTrace(this->sequence_, 0, this->sequence_.GetSize());
      } else {
        MergeSort(this->sequence_, 0, this->sequence_.GetSize());
      }
    }

  private:
    bool trace_;
};


template <class Key>
class HeapMethod : public SortMethod<Key> {
  public:
    HeapMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        HeapSortTrace(this->sequence_, this->sequence_.GetSize());
      } else {
        HeapSort(this->sequence_, this->sequence_.GetSize());
      }
    }

  private: 
    bool trace_;
};

template <class Key>
class ShellMethod : public SortMethod<Key> {
  public:
    ShellMethod(StaticSequence<Key> &sequence, bool trace) : SortMethod<Key>(sequence), trace_(trace) {}

    void Sort() override {
      if (trace_) {
        ShellSortTrace(this->sequence_, this->sequence_.GetSize());
      } else {
        ShellSort(this->sequence_, this->sequence_.GetSize());
      }
    }

  private: 
    bool trace_;
};



#endif // METHODS_H