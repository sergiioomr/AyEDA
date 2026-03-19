/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * 
 * @file sequence.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief 
 */

template<typename Key>
class Sequence {
  public:
    virtual bool search(const &Key k) const = 0;
    virtual bool insert(const &Key k) = 0;0

};