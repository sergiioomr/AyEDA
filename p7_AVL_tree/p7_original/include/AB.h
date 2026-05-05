/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file Binary_tree.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief 
 */

#ifndef AB_H
#define AB_H

#include "nodoB.h"
#include <queue>
#include <iostream>


template <class Key>
class AB {
  public:
    AB() : raiz_(nullptr) {}
    
    virtual ~AB() {}
    // Pure virtual methods
    virtual bool Insertar(const Key &k) = 0;
    virtual bool Buscar(const Key &k) const = 0;

    // Visualize the tree 
    void Inorden(NodoB<Key> *nodo) const {
      if (nodo != nullptr) {
        Inorden(nodo->GetLeft());
        std::cout << nodo->GetData() << " ";
        Inorden(nodo->GetRight());

      }
    }

    // Getters
    virtual NodoB<Key> *GetRoot() const { return raiz_; }

    virtual void PrintNode(std::ostream& os, NodoB<Key>* nodo) const;

    virtual void PrintTree(std::ostream& os) const;

  protected:
    NodoB<Key> *raiz_;
};

template <class Key>
void AB<Key>::PrintTree(std::ostream& os) const {
  NodoB<Key> *raiz = this->raiz_;
  std::queue<std::pair<NodoB<Key>*, int>> queue;
  NodoB<Key> *nodo;
  int nivel, nivel_actual = 0;

  queue.push({raiz, 0});
  os << "Nivel 0: ";

  while (!queue.empty()) {
    nodo = queue.front().first;
    nivel = queue.front().second;
    queue.pop();

    if (nivel > nivel_actual) {
      nivel_actual = nivel;
      os << "\nNivel " << nivel_actual << ": ";
    }

    if (nodo != nullptr) {
      PrintNode(os, nodo);
      queue.push({nodo->GetLeft(), nivel + 1});
      queue.push({nodo->GetRight(), nivel + 1});
    } else {
      os << "[.] ";
    }
  }
  os << "\n";
}

template<class Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& tree) {
  tree.PrintTree(os);
  return os;
}


template <class Key>
void AB<Key>::PrintNode(std::ostream& os, NodoB<Key>* nodo) const {
  if (nodo == nullptr) {
    os << "[.]";
  } else {
    os << "[" << nodo->GetData() << "]";
  }
}

#endif // AB_H