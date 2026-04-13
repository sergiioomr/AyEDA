/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file static_sequence.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-07
 * @brief 
 */
#ifndef STATIC_SEQUENCE_H
#define STATIC_SEQUENCE_H

#include "sequence.h"

// Derived class. Implement the Static Sequence
template<class Key>
class StaticSequence : Sequence<Key> {
  public:
    StaticSequence(const unsigned size) : size_(size) {}
  

    int GetSize() const { return size_; }  

    virtual Key operator[](const unsigned index) const {
      return data_[index];
    }

    virtual Key& operator[](const unsigned index) {
      return data_[index];
    }
    // Search a given key in the vector. Return true or false if it could be found or not
    virtual bool search(const Key &k) const override {

      for (unsigned i = 0; i < data_.size(); i++) {
        if (data_[i] == k) {
          return true;
        }
      }

      return false;
    }

    // Insert a given key in the vector. Return true or false if it could be found or not
    virtual bool insert(const Key &k) override {

      if ((!IsFull()) && (!search(k))) {
        data_.push_back(k);
        return true;
      }
      
      return false;
    }

    // Return if the vector is full
    virtual bool IsFull() const {
      return data_.size() >= size_;
    }

  private:
    unsigned size_;
    std::vector<Key> data_;
};

#endif // STATIC_SEQUENCE_H