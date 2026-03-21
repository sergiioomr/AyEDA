/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file hash_table.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-19
 * @brief 
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "dispersion_function.h"
#include "sequence.h"
#include "exploration_function.h"
#include <vector>

template<class Key, class Container=StaticSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable(unsigned table_size, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned block_size) 
    : table_size_(table_size), fd_(fd), fe_(fe), block_size_(block_size) {
      table_ = new Container*[table_size_];
      for (unsigned i = 0; i < table_size_; i++) {
        table_[i] = new Container(block_size);
      }
    }

    ~HashTable() {
      for (unsigned i = 0; i < table_size_; i++) {
        delete table_[i];
      }
      delete[] table_;
    }

    bool search(const Key &k) const override {
      unsigned index = fd_(k);
      for (unsigned i = 0; i < table_size_; i++) {
        // If the key is found in the vector of the position calculated with the distribution function, return true
        if (table_[index]->search(k)) {
          return true;
        }
        // If the vector of the position calculated with the fd is not full, and the key is not in the vector, that implies the key is not in the table
        if (!table_[index]->IsFull()) {
          return false;
        }
        // If the key has not been founded, then, recalculate the position to search using the exploration function
        index = (fd_(k) + fe_(k, i)) % table_size_;
      }
      return false;
    }
  
    bool insert(const Key &k) override {
      unsigned index = fd_(k);
      for (unsigned i = 0; i < table_size_; i++) {
        // If the key is found in the vector of the position calculated with the fd, return false, not insert duplicates
        if (table_[index]->search(k)) {
          return false;
        }

        // If the vector is not full, and the key has not been founded, insert
        if (!table_[index]->IsFull()) {
          table_[index]->insert(k);
          return true;
        }

        // If the vector is full, recalculates the position with the fe, and try insert again in the next iteration
        index = (fd_(k) + fe_(k, i)) % table_size_;
      }

      // If the can't been added, return false
      return false;
    }
    
  private:
    unsigned table_size_;
    // Vector of container pointers. Containers will be the static sequence
    Container** table_;
    DispersionFunction<Key> &fd_;
    ExplorationFunction<Key> &fe_;
    unsigned block_size_;

};

template<class Key>
class HashTable<Key, DynamicSequence<Key>> : public Sequence<Key> {
  public:
    HashTable(unsigned table_size, DispersionFunction<Key>& fd) : table_size_(table_size), fd_(fd) {
      table_ = new DynamicSequence<Key>*[table_size_];
      for (unsigned i = 0; i < table_size_; i++) {
        table_[i] = new DynamicSequence<Key>();
      }
    }

    ~HashTable() {
      for (unsigned i = 0; i < table_size_; i++) {
        delete table_[i];
      }
      delete[] table_;
    }

    bool search(const Key &k) const override {
      unsigned index = fd_(k);
      return table_[index]->search(k);
    }

    bool insert(const Key &k) override {
      unsigned index = fd_(k);
      return table_[index]->insert(k);
    }
    
  private:
    unsigned table_size_;
    // Vector of container pointers. Contairners will be the dynamic sequence
    DynamicSequence<Key>** table_;
    DispersionFunction<Key> &fd_;
};

#endif // HASH_TABLE_H