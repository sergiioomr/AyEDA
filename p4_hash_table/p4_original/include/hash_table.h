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
      for (int i = 0; i < table_size_; i++) {
        table_[i] = new Container(block_size);
      }
    }

    bool search(const Key &k) const override {
      unsigned index = fd_(k) % table_size_;
      return table_[index]->search(k);
    }
  
    bool insert(const Key &k) override {
      unsigned index = fd_(k) % table_size_;
      return table_[index]->insert(k);
    }
    
  private:
    unsigned table_size_;
    // Vector of container pointers. Containers will be the static sequence
    Container** table_;
    DispersionFunction<Key> &fd_;
    ExplorationFunction<Key> &fe_;
    unsigned block_size_;

};

template<class Key, class Containter=DynamicSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable(unsigned table_size, DispersionFunction<Key>& fd) : table_size_(table_size), fd_(fd) {
      for (int i = 0; i < table_size_; i++) {
        table_[i] = new Containter();
      }
    }

    bool search(const Key &k) const override {
      unsigned index = fd_(k) % table_size_;
      return table_[index]->search(k);
    }

    bool insert(const Key &k) override {
      unsigned index = fd_(k) & table_size_;
      return table_[index]->insert(k);
    }
    
  private:
    unsinged table_size_;
    // Vector of container pointers. Contairners will be the dynamic sequence
    Container** table_;
    DispersionFunction<Key> &fd_;
};

#endif // HASH_TABLE_H