/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file derived_tapes.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-02
 * @brief 
 */

#include "../include/derived_tapes.h"

TapePeriodic::TapePeriodic(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}

TapeReflective::TapeReflective(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}

TapeSliding::TapeSliding(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}


Color TapePeriodic::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}

Color TapeReflective::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}

Color TapeSliding::CheckColor(const std::pair<int, int> &cell) const {
  return grid_[cell.first][cell.second];
}



void TapePeriodic::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}

void TapeReflective::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}

void TapeSliding::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}


std::pair<std::pair<int, int>, Direction> TapePeriodic::Reposition(const std::pair<int, int> &position, const Direction direction) {
  int new_x = position.first;
  int new_y = position.second;

  if (new_x < 0) {
    new_x = GetSizeX() - 1;
  } else if (new_x >= GetSizeX()) {
    new_x = 0;
  }

  if (new_y < 0) {
    new_y = GetSizeY() - 1;
  } else if (new_y >= GetSizeY()) {
    new_y = 0;
  }

  return std::make_pair(std::make_pair(new_x, new_y), direction);
}

std::pair<std::pair<int, int>, Direction> TapeReflective::Reposition(const std::pair<int, int> &position, const Direction direction) {
  int new_x = position.first;
  int new_y = position.second;
  Direction new_direction = direction;

  // The new direction will be the oposite to represent the reflective effect
  switch (direction) {
        case Direction::UP: 
          new_direction = Direction::DOWN;
          break;
        case Direction::DOWN: 
          new_direction = Direction::UP;
          break;
        case Direction::LEFT: 
          new_direction = Direction::RIGHT;
          break;
        case Direction::RIGHT:  
          new_direction = Direction::LEFT;
          break;
    }

  // Now, change the position
  if (new_x < 0) {
    new_x = 0;
  } else if (new_x >= GetSizeX()) {
    new_x = GetSizeX() - 1;
  }
  
  if (new_y < 0) {
    new_y = 0;
  } else if (new_y >= GetSizeY()) {
    new_y = GetSizeY() - 1;
  }

  return std::make_pair(std::make_pair(new_x, new_y), new_direction);
}


void TapeSliding::NewColLeft() {
  for (int i = grid_.GetMinIndex(); i < grid_.GetMaxIndex(); i++) {
    grid_[i].push_front(Color::WHITE_CELL);
  }

  // A new col has been added, so the size will change
  size_y_++;
}

void TapeSliding::NewColRight() {
  for (int i = grid_.GetMinIndex(); i < grid_.GetMaxIndex(); i++) {
  grid_[i].push_back(Color::WHITE_CELL);
  }

  // A new col has been added, so the size will change
  size_y_++;
}

void TapeSliding::NewRowUp() {
  // Create a new SlideVector of colors to introduce in the grid
  // First, take the size of all the SlideVectors of the grid to create the new
  int min_col = grid_[grid_.GetMinIndex()].GetMinIndex();
  int max_col = grid_[grid_.GetMinIndex()].GetMaxIndex();

  // now, create the SlideVector and initialize every cell with white
  SlidingVector<Color> new_row(min_col, max_col);
  for (int i = new_row.GetMinIndex(); i < new_row.GetMaxIndex(); i++) {
    new_row[i] = Color::WHITE_CELL;
  }

  // Insert the new vector at the beginnning
  grid_.push_front(new_row);

  // A new row has been added, so the size will change
  size_x_++;
}

void TapeSliding::NewRowDown() {
  // Create a new SlideVector of colors to introduce in the grid
  // First, take the size of all the SlideVectors of the grid to create the new
  int min_col = grid_[grid_.GetMinIndex()].GetMinIndex();
  int max_col = grid_[grid_.GetMinIndex()].GetMaxIndex();

  // now, create the SlideVector and initialize every cell with white
  SlidingVector<Color> new_row(min_col, max_col);
  for (int i = new_row.GetMinIndex(); i < new_row.GetMaxIndex(); i++) {
    new_row[i] = Color::WHITE_CELL;
  }

  // Insert the new vector at the end
  grid_.push_back(new_row);

  // A new row has been added, so the size will change
  size_x_++;
}

std::pair<std::pair<int, int>, Direction> TapeSliding::Reposition(const std::pair<int, int> &position, const Direction direction) {
  int new_x = position.first;
  int new_y = position.second;

  // If the position is off the tape to the left or right, insert a new white cell to every vector in the tape
  if (position.second < grid_[position.first].GetMinIndex()) {
    NewColLeft();
  } else if (position.second >= grid_[position.first].GetMaxIndex()) {
    NewColRight();
  }

  // If the position is off the tape to the top or bottom, insert a new vector in the grid in the begin or the end
  if (position.first < grid_.GetMinIndex()) {
    NewRowDown();
  } else if (position.first > grid_.GetMaxIndex()) {
    NewRowUp();
  }

  return std::make_pair(std::make_pair(new_x, new_y), direction);
}