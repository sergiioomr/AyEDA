/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file ABB.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-04-20
 * @brief That file implements the ABB class, that represents an Binary Search Tree.
 *        It inherits from the AB class. Implement the virtual Insert and Buscar methods. 
 */

#ifndef ABB_H
#define ABB_H

#include "AB.h" 

template <class Key>
class ABB : public AB<Key> {
  public:
    ABB() : AB<Key>() {}

    ~ABB() {}

    bool Insertar(const Key &k) override;

    bool Buscar(const Key &k) const override;

  private:

  bool InsertarRama(NodoB<Key> *&nodo, const Key &k);
  bool BuscarRama(const Key &k, NodoB<Key> *nodo) const;
};

/**
 * @brief Insert a key in the tree. If it already exists, return false. 
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::Insertar(const Key &k) {
  if (Buscar(k)) {
    return false;
  }
  return InsertarRama(this->raiz_, k);
}


/**
 * @brief Search a given Key in the tree
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::Buscar(const Key &k) const  {
  return BuscarRama(k, this->raiz_);
}


/**
 * @brief Recursive method to insert the Key in the tree. Insert call to this method.
 * 
 * @tparam Key 
 * @param nodo 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::InsertarRama(NodoB<Key> *&nodo, const Key &k) {
  if (nodo == nullptr) {
    nodo = new NodoB<Key>(k, nullptr, nullptr);
    return true;
  } else if (k < nodo->GetData()) {
    return InsertarRama(nodo->GetLeft(), k);
  } else {
    return InsertarRama(nodo->GetRight(), k);
  }
  }


  /**
   * @brief Recursive method to search the Key in the tree. Buscar will call this method
   * 
   * @tparam Key 
   * @param k 
   * @param nodo 
   * @return true 
   * @return false 
   */
template <class Key>
bool ABB<Key>::BuscarRama(const Key &k, NodoB<Key> *nodo) const {
  if (nodo == nullptr) {
    return false;
  }

  if (k == nodo->GetData()) {
    return true;
  }

  if (k < nodo->GetData()) {
    return BuscarRama(k, nodo->GetLeft());
  } else {
    return BuscarRama(k, nodo->GetRight());
  }
}

#endif // ABB_H