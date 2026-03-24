/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @file sequence.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief Implement the Sequence class. That will be use to store many keys in the same position of the hash table.
 *        There are two types. Dynamic, implemented with a list, and Static, implemented with a block_size positions vector
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include <vector>

// Abstract class
template<typename Key>
class Sequence {
  public:
    Sequence() {}
    virtual bool search(const Key &k) const = 0;
    virtual bool insert(const Key &k) = 0;
    virtual ~Sequence() {}

};

// Derived class. Implement the dynamic sequence
template<class Key>
class DynamicSequence : Sequence<Key> {
  public:
    DynamicSequence() {}

    // Search a given key in the list. Return true or false if it could be found or not
    virtual bool search(const Key &k) const override {

      for (const auto &elem : data_) {
        if (elem == k) {
          return true;
        }
        return false;
      }
      return false;
    }

    // Insert a given key in the list. Return true or false if it could be inserted
    virtual bool insert(const Key &k) override {

      if (!search(k)) {
        data_.push_back(k);
        return true;
      }
      return false;
    }

  private:
    std::list<Key> data_;
};

// Derived class. Implement the Static Sequence
template<class Key>
class StaticSequence : Sequence<Key> {
  public:
    StaticSequence(const unsigned block_size) : block_size_(block_size) {}
  
    // Search a given key in the vector. Return true or false if it could be found or not
    virtual bool search(const Key &k) const override {

      for (unsigned i = 0; i < data_.size(); i++) {
        if (data_[i] == k) {
          return true;
        }
        return false;
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
      return data_.size() >= block_size_;
    }

  private:
    unsigned block_size_;
    std::vector<Key> data_;
};

#endif // SEQUENCE_H