/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file ABE.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief 
 */

#ifndef ABE_H
#define ABE_H

#include "AB.h" 

template <class Key>
class ABE : public AB<Key> {
  public:

    ABE() : AB<Key>(), comparations_counter_(0) {}

    ~ABE() {}

    bool Insertar(const Key &k) override {
      if (Buscar(k)) {
        return false;
      }

      if (this->raiz_ == nullptr) {
        this->raiz_ = new NodoB<Key>(k, nullptr, nullptr);
        return true;
      } else {
        return InsertaEquilRama(k, this->raiz_);
      }
    }

    bool Buscar(const Key &k) override {
      return BuscarRama(this->raiz_, k);
    }

    int GetCounter() const { return comparations_counter_; }

  private:

    bool InsertaEquilRama(const Key &k, NodoB<Key> *nodo) {
      if (TamRama(nodo->GetLeft()) <= TamRama(nodo->GetRight())) {
        if (nodo->GetLeft() != nullptr) {
          return InsertaEquilRama(k, nodo->GetLeft());
        } else {
          nodo->SetLeft(new NodoB<Key>(k, nullptr, nullptr));
          return true;
        }
      } else {
        if (nodo->GetRight() != nullptr) {
          return InsertaEquilRama(k, nodo->GetRight());
        } else {
          nodo->SetRight(new NodoB<Key>(k, nullptr, nullptr));
          return true;
        }
      }
    }

    int TamRama(NodoB<Key> *nodo) const {
      if (nodo == nullptr) {
        return 0;
      }
      return 1 + TamRama(nodo->GetLeft()) + TamRama(nodo->GetRight());
    }

    bool BuscarRama(NodoB<Key> *nodo, const Key &k) {
      if (nodo == nullptr) {
        comparations_counter_++;
        return false;
      }

      if (nodo->GetData() == k) {
        comparations_counter_++;
        return true;
      }

      if (BuscarRama(nodo->GetLeft(), k)) {
        return true;
      }

      return BuscarRama(nodo->GetRight(), k);
    }

    int comparations_counter_;
};

#endif // ABE_H