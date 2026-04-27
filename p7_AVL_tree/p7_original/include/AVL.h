/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file AVL.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-22
 * @brief 
 */

#ifndef AVL_H
#define AVL_H

#include "ABB.h"

template <class Key>
class AVL : public ABB<Key> {
  public:
    AVL() : ABB<Key>() {}

    bool Insertar(const Key &k) override {

    }


};

#endif // AVL_H