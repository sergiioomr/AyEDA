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
#include "nodoAVL.h"
#include <queue>

template <class Key>
class AVL : public ABB<Key> {
  public:
    AVL(bool trace = false) : ABB<Key>(), trace_(trace) {}

    bool Insertar(const Key &k) override;
    bool Buscar(const Key &k) const override;

    void PrintNode(std::ostream& os, NodoB<Key>* nodo) const override;

    private:
      bool trace_;

      bool buscar_recursivo(NodoB<Key> *nodo, const Key &k) const;

      bool insertar_bal(NodoB<Key>* &nodo, NodoAVL<Key>* &nuevo, bool &crece);
      void insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool crece);
      void insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool crece);

      void RotateII(NodoAVL<Key>* &node);
      void RotateDD(NodoAVL<Key>* &node);
      void RotateID(NodoAVL<Key>* &node);
      void RotateDI(NodoAVL<Key>* &node);

      void PrintTraceBeforeRotation(const std::string& rotation, NodoAVL<Key>* nodo) const;
};

template <class Key>
bool AVL<Key>::Buscar(const Key &k) const {
  return buscar_recursivo(this->raiz_, k);
}

template <class Key>
bool AVL<Key>::buscar_recursivo(NodoB<Key> *nodo, const Key &k) const {
  if (nodo == nullptr) {
    return false;
  }

  if (k == nodo->GetData()) {
    return true;
  }

  if (k < nodo->GetData()) {
    return buscar_recursivo(nodo->GetLeft(), k);
  }

  if (k > nodo->GetData()) {
    return buscar_recursivo(nodo->GetRight(), k);
  }
}

template <class Key>
bool AVL<Key>::Insertar(const Key &k) {
  NodoAVL<Key> *nuevo = new NodoAVL<Key>(k);
  bool crece = false;
  return insertar_bal(this->raiz_, nuevo, crece);
}

template <class Key>
bool AVL<Key>::insertar_bal(NodoB<Key>* &nodo, NodoAVL<Key>* &nuevo, bool &crece) {
  if (nodo == nullptr) {
    nodo = new NodoAVL<Key>(nuevo->GetData());
    crece = true;
    return true;
  }

  NodoAVL<Key>* nodo_avl = reinterpret_cast<NodoAVL<Key>*>(nodo);
  if (nodo_avl->GetData() == nuevo->GetData()) {
    crece = false;
    return false;
  }

  if (nuevo->GetData() < nodo->GetData()) { 
    bool insertado = insertar_bal(nodo->GetLeft(), nuevo, crece);
    if (crece) {
      insert_re_balancea_izda(nodo_avl, crece);
      nodo = nodo_avl;
    }
    return insertado;
  } else {
    bool insertado = insertar_bal(nodo->GetRight(), nuevo, crece);
    if (crece) {
      insert_re_balancea_dcha(nodo_avl, crece);
      nodo = nodo_avl;
    }
    return insertado;
  }
}

template <class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool crece) {
  switch (nodo->GetBal()) {
    case -1 :
      nodo->SetBal(0);
      crece = false;
      break;
    case 0 :
      nodo->SetBal(1);
      break;
    case 1 : {
      NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(nodo->GetLeft());
      nodo->SetBal(2);
      if (nodo1->GetBal() == 1) {
        if (trace_) {
        PrintTraceBeforeRotation("II", nodo);
        RotateII(nodo);
        } else {
          RotateII(nodo);
        }
      } else {
        if (trace_) {
        PrintTraceBeforeRotation("ID", nodo);
        RotateID(nodo);
        } else {
          RotateID(nodo);
        }
      }       
      
      crece = false;
    }
  }
}


template <class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool crece) {
  switch (nodo->GetBal()) {
    case 1 : 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0 :
      nodo->SetBal(-1);
      break;
    case -1 : {
      NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(nodo->GetRight());
      nodo->SetBal(-2);
      if (nodo1->GetBal() == -1) {
        if (trace_) {
        PrintTraceBeforeRotation("DD", nodo);
        RotateDD(nodo);
        } else {
          RotateDD(nodo);
        }
      } else {
        if (trace_) {
        PrintTraceBeforeRotation("DI", nodo);
        RotateDI(nodo);
        } else {
          RotateDI(nodo);
        } 
      }        

      crece = false;
    }
  }
}



template <class Key>
void AVL<Key>::RotateII(NodoAVL<Key>* &node) {
  NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(node->GetLeft());
  node->SetLeft(nodo1->GetRight());
  nodo1->SetRight(node);

  if (nodo1->GetBal() == 1) {
    node->SetBal(0);
    nodo1->SetBal(0);
  } else {
    node->SetBal(1);
    nodo1->SetBal(-1);
  }

  node = nodo1;
}


template <class Key>
void AVL<Key>::RotateDD(NodoAVL<Key>* &node) {
  NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(node->GetRight());
  node->SetRight(nodo1->GetLeft());
  nodo1->SetLeft(node);
  if (nodo1->GetBal() == -1) {
    node->SetBal(0);
    nodo1->SetBal(0);
  } else {
    node->SetBal(-1);
    nodo1->SetBal(1);
  }

  node = nodo1;
}


template <class Key>
void AVL<Key>::RotateID(NodoAVL<Key>* &node) {
  NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(node->GetLeft());
  NodoAVL<Key> *nodo2 = reinterpret_cast<NodoAVL<Key>*>(node->GetRight());

  node->SetLeft(nodo2->GetRight());
  nodo2->SetRight(node);
  nodo1->SetRight(nodo2->GetLeft());
  nodo2->SetLeft(nodo1);

  if (nodo2->GetBal() == -1) {
    nodo1->SetBal(1);
  } else {
    nodo1->SetBal(0);
  }

  if (nodo2->GetBal() == 1) {
    node->SetBal(-1);
  } else {
    node->SetBal(0);
  }

  nodo2->SetBal(0);
  node = nodo2;
}


template <class Key>
void AVL<Key>::RotateDI(NodoAVL<Key>* &node) {
  NodoAVL<Key> *nodo1 = reinterpret_cast<NodoAVL<Key>*>(node->GetRight());
  NodoAVL<Key> *nodo2 = reinterpret_cast<NodoAVL<Key>*>(node->GetLeft());

  node->SetRight(nodo2->GetLeft());
  nodo2->SetLeft(node);
  nodo1->SetLeft(nodo2->GetRight());
  nodo2->SetRight(nodo1);

  if (nodo2->GetBal() == 1) {
    nodo1->SetBal(-1);
  } else {
    nodo1->SetBal(0);
  }

  if (nodo2->GetBal() == -1) {
    node->SetBal(1);
  } else {
    node->SetBal(0);
  }

  nodo2->SetBal(0);
  node = nodo2;
}

template <class Key>
void AVL<Key>::PrintNode(std::ostream& os, NodoB<Key>* nodo) const {
  if(nodo == nullptr) {
    os << "[.]";
  } else {
    NodoAVL<Key>* nodo_avl = reinterpret_cast<NodoAVL<Key>*>(nodo);

    if (trace_) {
      os << "[" << nodo_avl->GetData() << "(" << nodo_avl->GetBal() << ")]";
    } else {
      os << "[" << nodo_avl->GetData() << "]";
    }
  }
}

template <class Key>
void AVL<Key>::PrintTraceBeforeRotation(const std::string& rotation, NodoAVL<Key>* nodo) const {
  if(!trace_) return;
  std::cout << "Desbalanceo:\n";
  std::cout << *this;
  std::cout << "Rotación " << rotation << " en [" << nodo->GetData() << "(" << nodo->GetBal() << ")]:\n";
}



#endif // AVL_H