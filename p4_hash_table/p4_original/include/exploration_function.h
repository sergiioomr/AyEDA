/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file exploration_function.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-18
 * @brief Declares the abstract class ExplorationFunction, to implement four derived classes
 *        LinearExploration, QuadraticExploration, DoubleExploration and RehashingExploration.
 *        That classes will be used to transform the keys into integer index to the table, and implements two differents ways to do it. 
 */

template<typename Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const &Key, unsigned) const = 0;
    virtual ~ExplorationFunction() {}
};


template<typename Key>
class LinearExploration : public ExplorationFunction {
  public:

  private:
};


template<typename Key>
class QuadraticExploration : public ExplorationFunction {
  public:

  private:
};


template<typename Key>
class DoubleExploration : public ExplorationFunction {
  public:

  private:
};


template<typename Key>
class RehashingExploration : public ExplorationFunction {
  public:

  private:
};
