/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file sort_method.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-07
 * @brief 
 */

#ifndef SORT_METHOD_H
#define SORT_METHOD_H

#include "static_sequence.h"

template <class Key>
class SortMethod {
  public:
    SortMethod(StaticSequence<Key> &sequence) : sequence_(sequence) {}
    virtual void Sort() = 0;

    virtual ~SortMethod() {}
  protected:
    StaticSequence<Key> &sequence_;
};

#endif // SORT_METHOD_H