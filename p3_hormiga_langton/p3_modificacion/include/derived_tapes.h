/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file tape.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-01
 * @brief This file declarates the classes derived from Tape.
 * 				This classes are used to represent the grid in the simulation
 *        Their difference is the way to implement the borders
 */

#ifndef DERIVED_TAPES_H
#define DERIVED_TAPES_H

#include <iostream>
#include <vector>
#include "../include/tape.h"

class TapePeriodic : public Tape {
  public: 
    TapePeriodic(const int size_x, const int size_y);
    Color CheckColor(const std::pair<int, int> &cell) const override { return grid_[cell.first][cell.second]; }
    void SetColor(const Color &color, const std::pair<int, int> &cell) override {grid_[cell.first][cell.second] = color; }
    std::pair<std::pair<int, int>, Direction> Reposition(const std::pair<int, int> &position, const Direction direction) override;

  private: 
    std::vector<std::vector<Color>> grid_;
};


class TapeReflective : public Tape {
  public:
    TapeReflective(const int size_x, const int size_y);
    Color CheckColor(const std::pair<int, int> &cell) const override { return grid_[cell.first][cell.second]; }
    void SetColor(const Color &color, const std::pair<int, int> &cell) override { grid_[cell.first][cell.second] = color; }
    std::pair<std::pair<int, int>, Direction> Reposition(const std::pair<int, int> &position, const Direction direction) override;
  private:
    std::vector<std::vector<Color>> grid_;
};


class TapeSliding : public Tape {
  public:
    TapeSliding(const int size_x, const int size_y);
    Color CheckColor(const std::pair<int, int> &cell) const override;
    void SetColor(const Color &color, const std::pair<int, int> &cell) override;
    std::pair<std::pair<int, int>, Direction> Reposition(const std::pair<int, int> &position, const Direction direction) override;
    int GetMinX() const override { return grid_.GetMinIndex(); }
    int GetMinY() const override { return grid_[grid_.GetMinIndex()].GetMinIndex(); }

  private:
    SlidingVector<SlidingVector<Color>> grid_;
    void NewRowUp();
    void NewRowDown();
    void NewColRight();
    void NewColLeft();
};




#endif // DERIVED_TAPES_H