/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @file sequence.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief 
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>

template<typename Key>
class Sequence {
  public:
    Sequence() {}
    virtual bool search(const &Key k) const = 0;
    virtual bool insert(const &Key k) = 0;
    virtual ~Sequence() {}

};

// All synonym key values that generates a collision will be saved in the same position of the table
// It requires a dynamic data structure in the position with many value keys
template<class Key>
class DynamicSequence : Sequence<Key> {
  public:
    DynamicSequence() {}
    virtual bool search(const &Key k) const override {

      // Function code

    }

    virtual bool insert(const &Key k) override {

      //Function code

    }
  private:
    std::list<Key> data_;
};


template<class Key>
class StaticSequence : Sequence<Key> {
  public:
    StaticSequence(const unsigned block_size) : block_size_(block_size) {}
  
    virtual bool search(const &Key k) const override {

      // function code

    }

    virtual bool insert(const &Key k) override {

      // Function code

    }

    virtual bool IsFull() const {
      
    }

  private:
    unsigned block_size_;
    std::vector<Key> data_;
};

#endif // SEQUENCE_H