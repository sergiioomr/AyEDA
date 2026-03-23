/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file dispersion_function.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief Declares the abstract class DispertionFunction, to implement three derived classes
 *        SumDispertionFunction, ModuleDispersionFunction and PseudoRandomDispersionFunction. 
 *        That classes will be used to transform the keys into integer index to the table, and implements two differents ways to do it.
 */

#ifndef DISPERSION_FUNCTION_H
#define DISPERSION_FUNCTION_H
#include <cstdlib>

// Abstract base class for dispertion functions
template<class Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key &k) const = 0;
    virtual ~DispersionFunction() {}
};

// Derivated class for module dispersion function
template<class Key>
class ModuleDispersionFunction : public DispersionFunction<Key> {
  public:
    ModuleDispersionFunction(const unsigned table_size) : table_size_(table_size) {}

    virtual unsigned operator()(const Key &k) const override {
      
      return k % table_size_;

    }
  private:
    unsigned table_size_;
};

// Derivated class for sum dispersion function
template<class Key>
class SumDispersionFunction : public DispersionFunction<Key> {
  public:
    SumDispersionFunction(const unsigned table_size) : table_size_(table_size) {}

    virtual unsigned operator()(const Key &k) const override {
      
      int sum = 0;
      unsigned value = k;
      while (value > 0) {
        sum += sum % 10;
        value = value / 10;
      }

      return (sum % table_size_);
    }

  private:
    unsigned table_size_;

};


// Derivated class for pseudo random dispersion function
template<class Key> 
class PseudoRandomDispersionFunction : public DispersionFunction<Key> {
  public:
    PseudoRandomDispersionFunction(const unsigned table_size) : table_size_(table_size) {}
    
    virtual unsigned operator()(const Key &k) const override {

      srand(k);
      return rand() % table_size_;

    }

  private:
    unsigned table_size_;
};


#endif // DISPERSION_FUNCION_H