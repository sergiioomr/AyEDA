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

class SVException : public std::exception {
  public:
    SVException(int idx, int min, int max) : index(idx), min_range(min), max_range(max) {
      std::cout << "SVException. Invalid access. Out of the limits" << std::endl;
    }

  private:
    int index;
    int min_range;
    int max_range;
};

template <class T>
class SlidingVector {
  public: 
    SlidingVector(const int min_index, const int max_index) : min_index_(min_index), max_index_(max_index), slide_vector(max_index - min_index + 1) {}
    // Default constructor. The size will be 0, and is not possible to access with [] to any position, always throw an exception
    SlidingVector() : min_index_(0), max_index_(-1), slide_vector() {}

    int GetMinIndex() const { return min_index_; }
    int GetMaxIndex() const { return max_index_; }
    int GetSize() const { return slide_vector.size(); }

    void resize(int new_size) {
      slide_vector.resize(new_size);
      max_index_ = min_index_ + new_size - 1;
    }

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
  int min_index_;
  int max_index_;
  std::vector<T> slide_vector;

  int ChangeIndex(const int index) const{
    return index - min_index_;
  }
};

#endif // SLIDING_VECTOR_H