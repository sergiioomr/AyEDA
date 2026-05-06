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

    ABE() : AB<Key>() {}

    ~ABE() {}

    bool Insertar(const Key &k) override;
    bool Buscar(const Key &k) const override;

  private:

    bool InsertaEquilRama(const Key &k, NodoB<Key> *nodo);
    int TamRama(NodoB<Key> *nodo) const;
    bool BuscarRama(NodoB<Key> *nodo, const Key &k) const;
};

/**
   * @brief Insert a given Key. If the key is already in the tree, return false.
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABE<Key>::Insertar(const Key &k)  {
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


/**
 * @brief Search a given Key in the tree. 
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABE<Key>::Buscar(const Key &k) const {
  return BuscarRama(this->raiz_, k);
}


/**
 * @brief Recursive method to insert the key in the tree. Insert will call this method
 * 
 * @tparam Key 
 * @param k 
 * @param nodo 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABE<Key>::InsertaEquilRama(const Key &k, NodoB<Key> *nodo) {
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

/**
 * @brief Return the size of a "Rama" in the tree
 * 
 * @tparam Key 
 * @param nodo 
 * @return int 
 */
template <class Key>
int ABE<Key>::TamRama(NodoB<Key> *nodo) const {
  if (nodo == nullptr) {
    return 0;
  }
  return 1 + TamRama(nodo->GetLeft()) + TamRama(nodo->GetRight());
}


/**
 * @brief Recursive method to search the given Key in the tree. Buscar will call this method
 * 
 * @tparam Key 
 * @param nodo 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABE<Key>::BuscarRama(NodoB<Key> *nodo, const Key &k) const {
  if (nodo == nullptr) {
    return false;
  }
  if (nodo->GetData() == k) {
    return true;
  }

  if (BuscarRama(nodo->GetLeft(), k)) {
    return true;
  }

  return BuscarRama(nodo->GetRight(), k);
}

#endif // ABE_H