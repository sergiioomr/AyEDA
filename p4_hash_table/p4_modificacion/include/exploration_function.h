/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file exploration_function.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief Declares the abstract class ExplorationFunction, to implement four derived classes
 *        LinearExploration, QuadraticExploration, DoubleExploration and RehashingExploration.
 *        That classes will be used to explore new positions in the table if the current is full 
 */

#ifndef EXPLORATION_FUNCTION_H
#define EXPLORATION_FUNCTION_H

#include "dispersion_function.h"

// Abstract class
template<class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key &k, unsigned i) const = 0;
    virtual ~ExplorationFunction() {}
};

// Derivated class to implement the linear method
template<class Key>
class LinearExploration : public ExplorationFunction<Key> {
  public:
    // Operator() overload
    virtual unsigned operator()(const Key &k, unsigned i) const override {

      return i;

    }
};

// Derived class to implement the quadratic method
template<class Key>
class QuadraticExploration : public ExplorationFunction<Key> {
  public:
    // Operator() overload
    virtual unsigned operator()(const Key &k, unsigned i) const override {

      return i * i;

    }
};

// Derived class to implement the double dispersion function
template<class Key>
class DoubleExploration : public ExplorationFunction<Key> {
  public:
    // Constructor. That derivated class use a dispersion function
    DoubleExploration<Key>(DispersionFunction<Key> *fd) : fd_(fd) {}  

    // Operator() overload
    virtual unsigned operator()(const Key &k, unsigned i) const override {
      return (*fd_)(k) * i;
    }

  private:
    DispersionFunction<Key> *fd_;
};

// Derived class to implement the rehashing method
template<class Key>
class RehashingExploration : public ExplorationFunction<Key> {
  public:
    // Constructor. That derived class use a dispersion function
    RehashingExploration<Key>(DispersionFunction<Key> *fd) : fd_(fd) {}

    // Operator() overload
    unsigned operator()(const Key &k, unsigned i) const override {
      srand(k);
      unsigned result = 0;
      for (unsigned j = 0; j < i; j++) {
        result = (*fd_)(rand());
      }

      return result;
    }

  private:
    DispersionFunction<Key> *fd_;
};

#endif // EXPLORATION_FUNCTION_H