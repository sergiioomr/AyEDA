/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file sliding_vector_t.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-01
 * @brief Declarates a special kind of vector, derived from std::vector
 *        This will allow to index the vector with negative positions
 */
#ifndef SLIDING_VECTOR_H
#define SLIDING_VECTOR_H

#include <vector>

struct SVException : public std::exception {
  int index;
  int min_range;
  int max_range;

  SVException(int idx, int min, int max) : index(idx), min_range(min), max_range(max) {}
};

template <class T>
class SlidingVector {
  public: 
    SlidingVector(const int max_index, const int min_index) : max_index_(max_index), min_index_(min_index), slide_vector(max_index - min_index + 1) {}
    
    int GetMinIndex() const { return min_index_; }
    int GetMaxIndex() const { return max_index_; }
    int GetSize() const { return slide_vector.size(); }

    // [] overloading to acces the elements with range comprobation
    T& operator[] (int index) {
      if (index < min_index_  || index > max_index_) {
        throw SVException(index, min_index_, max_index_);
      }

      return slide_vector[ChangeIndex(index)];
    }

    const T& operator[] (int index) const {
      if (index < min_index_  || index > max_index_) {
        throw SVException(index, min_index_, max_index_);
      }

      return slide_vector[ChangeIndex(index)];
    }

    // Add elements at the end
    void push_back(const T& value) {
      slide_vector.push_back(value);
      max_index_++;
    }

    // Add elements at the beginning
    void push_front(const T& value) {
      slide_vector.insert(slide_vector.begin(), value);
      min_index_--;
    }
    
  private:
  int max_index_;
  int min_index_;
  std::vector<T> slide_vector;

  int ChangeIndex(const int index) const{
    return index - min_index_;
  }
};

#endif // SLIDING_VECTOR_H