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
    virtual bool search(const Key &k) const override {

      for (const auto &elem : data_) {
        if (elem == k) {
          return true;
        }
        return false;
      }

    }

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


template<class Key>
class StaticSequence : Sequence<Key> {
  public:
    StaticSequence(const unsigned block_size) : block_size_(block_size) {}
  
    virtual bool search(const Key &k) const override {

      for (int i = 0; i < data_)
        if (data_[i] == k) {
          return true;
        }
        return false;

    }

    virtual bool insert(const Key &k) override {

      if ((!IsFull()) && (!search(k))) {
        data_.push_back(k);
        return true;
      }
      
      return false;
    }

    virtual bool IsFull() const {
      return data_.size() >= block_size_;
    }

  private:
    unsigned block_size_;
    std::vector<Key> data_;
};

#endif // SEQUENCE_H