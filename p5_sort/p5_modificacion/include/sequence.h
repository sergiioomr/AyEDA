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
    virtual Key operator[](const unsigned index) const = 0;
    virtual Key& operator[](const unsigned index) = 0;
    virtual ~Sequence() {}

};


#endif // SEQUENCE_H