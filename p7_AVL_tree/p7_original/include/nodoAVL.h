/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file nodoAVL.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-22
 * @brief 
 */

#ifndef NODOAVL_H
#define NODOAVL_H

#include "nodoB.h"

template <class Key>
class NodoAVL : public NodoB<Key> {
  public:
    NodoAVL(const Key &data, NodoB<Key> *left = nullptr, NodoB<Key> *right = nullptr, int bal = 0) : NodoB<Key>(data, left, right), bal_(bal) {}

    int GetBal() const { return bal_; }
    void SetBal(int bal) { bal_ = bal; }
    
  private: 
    int bal_;  
};

#endif //NODOAVL_H