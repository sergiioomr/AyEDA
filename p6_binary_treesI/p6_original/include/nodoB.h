/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructura de Datos Avanzadas
 * @file nodoB.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief 
 */

#ifndef NODOB_H
#define NODOB_H

template <class Key>
class NodoB {
  public:
    NodoB(const Key& data, NodoB* left, NodoB* right) : dato_(data), izdo_(left), dcho_(right) {}


    // Getters
    const Key &GetData() const { return dato_; }
    NodoB *GetLeft() const { return izdo_; }
    NodoB * GetRight() const { return dcho_; }

    // Setters
    void SetLeft(NodoB<Key> *left) { izdo_ = left; }
    void SetRight(NodoB<Key> *right) {dcho_ = right; }
    
  protected:
    Key dato_;
    NodoB* izdo_;
    NodoB* dcho_;
};


#endif // NODOB_H