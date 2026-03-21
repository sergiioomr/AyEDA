/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos
 * @file nif.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-21
 * @brief 
 */
#include <cstdlib>

class Nif {
  public:
    Nif() : value_(rand() % 100000000) {} 

    Nif(long value) : value_(value) {}

    bool operator==(const Nif &other) const {
      return value_ == other.value_;
    }

    bool operator!=(const Nif &other) {
      return value_ != other.value_;
    }

    operator long() const {
      return value_;
    }

  private:
    long value_;
};