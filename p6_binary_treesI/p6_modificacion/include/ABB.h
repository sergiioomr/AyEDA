/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file ABB.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief 
 */

#ifndef ABB_H
#define ABB_H

#include "AB.h" 

template <class Key>
class ABB : public AB<Key> {
  public:
    ABB() : AB<Key>(), comparations_counter_(0) {}

    ~ABB() {}

    bool Insertar(const Key &k) override {
      if (Buscar(k)) {
        return false;
      }
      return InsertarRama(this->raiz_, k);
    }

    bool Buscar(const Key &k) override {
      return BuscarRama(k, this->raiz_);
    }

    int GetCounter() const { return comparations_counter_; }
  private:
  bool InsertarRama(NodoB<Key> *&nodo, const Key &k) {
    if (nodo == nullptr) {
      nodo = new NodoB<Key>(k, nullptr, nullptr);
      return true;
    } else if (k < nodo->GetData()) {
      return InsertarRama(nodo->GetLeft(), k);
    } else {
      return InsertarRama(nodo->GetRight(), k);
    }
  }

  bool BuscarRama(const Key &k, NodoB<Key> *nodo) {
      if (nodo == nullptr) {
        comparations_counter_++;
        return false;
      }

      if (k == nodo->GetData()) {
        comparations_counter_++;
        return true;
      }

      if (k < nodo->GetData()) {
        return BuscarRama(k, nodo->GetLeft());
      } else {
        return BuscarRama(k, nodo->GetRight());
      }
    }

    int comparations_counter_;
};

#endif // ABB_H