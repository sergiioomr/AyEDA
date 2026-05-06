/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos
 * @file nif.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief Declares a class to represent a NIF. 
 */

#ifndef NIF_H
#define NIF_H

#include <exception>
#include <cstdlib>
#include <iomanip>

class Nif {
  public:
    Nif() : value_(0) {
      srand(time(nullptr));
      value_ = rand() % 100000000;
    } 

    
    Nif(long value): value_{} {
      if (value < 0 || value > 99999999) {
        throw std::invalid_argument("Invalid NIF format");
      }
      value_ = value;
    }

    // Operator== overload. Allows to compare NIFs
    bool operator==(const Nif &other) const {
      return value_ == other.value_;
    }

    // Operator!= overload. Allows to compare NIFs
    bool operator!=(const Nif &other) {
      return value_ != other.value_;
    }

    operator long() const {
      return value_;
    }

    /**
     * @brief Operator << overload. That allows to print in the correct format numbers like 1 -> 00000001 or 1235 -> 00001235
     * 
     * @param os 
     * @param n 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Nif &n) {
      os << std::setfill('0') << std::setw(8) << n.value_;
      return os;
    }

    friend std::istream& operator>>(std::istream& is, Nif& nif) {
      long value;
      is >> value;
      nif = Nif(value);
      return is;
    }
    
    bool operator<(const Nif &other) const {
      return value_ < other.value_;
    }
    
    bool operator>(const Nif &other) const {
    return value_ > other.value_;
    }

  private:
    long value_;
};

#endif // NIF_H 