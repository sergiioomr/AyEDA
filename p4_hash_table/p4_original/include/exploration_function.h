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
 *        That classes will be used to transform the keys into integer index to the table, and implements two differents ways to do it. 
 */

#ifndef EXPLORATION_FUNCTION_H
#define EXPLORATION_FUNCTION_H

#include "dispersion_function.h"

template<class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key &k, unsigned i) const = 0;
    virtual ~ExplorationFunction() {}
};


template<class Key>
class LinearExploration : public ExplorationFunction<Key> {
  public:
    virtual unsigned operator()(const Key &k, unsigned i) const override {

      return i;

    }
};


template<class Key>
class QuadraticExploration : public ExplorationFunction<Key> {
  public:
    virtual unsigned operator()(const Key &k, unsigned i) const override {

      return i * i;

    }
};


template<class Key>
class DoubleExploration : public ExplorationFunction<Key> {
  public:
    DoubleExploration<Key>(DispersionFunction<Key> *fd) : fd_(fd) {}  

    virtual unsigned operator()(const Key &k, unsigned i) const override {
      return fd_(k) * i;
    }

  private:
    ExplorationFunction<Key> *fd_;
};


template<class Key>
class RehashingExploration : public ExplorationFunction<Key> {
  public:
    RehashingExploration<Key>(DispersionFunction<Key> *fd) : fd_(fd) {}
    unsigned operator()(const Key &k, unsigned i) const override {
      srand(k);
      unsigned result = 0;
      for (int j = 0; j < i; j++) {
        result = (*fd_)(rand());
      }

      return result;
    }

  private:
    ExplorationFunction<Key> *fd_;
};

#endif // EXPLORATION_FUNCTION_H