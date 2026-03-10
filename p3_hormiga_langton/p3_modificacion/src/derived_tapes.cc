/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file derived_tapes.cc
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-03-02
 * @brief Define the methodos of the derivated class of tape
 */

#include "../include/derived_tapes.h"

/**
 * @brief Construct a new Tape Periodic. Initialize the cells in white color
 * 
 * @param size_x 
 * @param size_y 
 */
TapePeriodic::TapePeriodic(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}

/**
 * @brief Recalculates the coordinates of the ant if it go out of limits. The ant will resposition in the begin of the tape. 
 * 
 * @param position 
 * @param direction 
 * @return std::pair<std::pair<int, int>, Direction> 
 */
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

/**
 * @brief Construct a new Tape Reflective. Initialize the cells in white color
 * 
 * @param size_x 
 * @param size_y 
 */
TapeReflective::TapeReflective(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}

/**
 * @brief Recalculates the coordinates of the ant if it go out of limits. The ant will reflect with the tape and go back.
 * 
 * @param position 
 * @param direction 
 * @return std::pair<std::pair<int, int>, Direction> 
 */
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

/**
 * @brief Construct a new Tape Sliding. Initialize the cells with white color
 * 
 * @param size_x 
 * @param size_y 
 */
TapeSliding::TapeSliding(const int size_x, const int size_y) : Tape(size_x, size_y), grid_{} {
  grid_.resize(size_x);
  for (int i = 0; i < size_x; i++) {
    grid_[i].resize(size_y);
    for (int j = 0; j < size_y; j++) {
      grid_[i][j] = Color::WHITE_CELL;
    }
  }
}

/**
 * @brief Return the color of a cell
 * 
 * @param cell 
 * @return Color 
 */
Color TapeSliding::CheckColor(const std::pair<int, int> &cell) const {
  try {
    const SlidingVector<Color>& column = grid_[cell.first];
    try {
      return column[cell.second];    
    } catch (const SVException& column_exception) {
      return Color::WHITE_CELL; 
    }
  } catch(const SVException& row_exception) {
    return Color::WHITE_CELL;
  }
}

/**
 * @brief Changes the color of a cell
 * 
 * @param color 
 * @param cell 
 */
void TapeSliding::SetColor(const Color &color, const std::pair<int, int> &cell) {
  grid_[cell.first][cell.second] = color;
}


std::pair<std::pair<int, int>, Direction> TapeSliding::Reposition(const std::pair<int, int> &position, const Direction direction) {
  int new_x = position.first;
  int new_y = position.second;

  // If the position is off the tape to the top or bottom, insert a new vector in the grid in the begin or the end
  if (new_x < grid_.GetMinIndex()) {
    NewRowUp();
    new_x = grid_.GetMinIndex();
  } else if (new_x > grid_.GetMaxIndex()) {
    NewRowDown();
    new_x = grid_.GetMaxIndex();
  }
  std::cout << "comprobado primer par de if" << std::endl;
  // If the position is off the tape to the left or right, insert a new white cell to every vector in the tape
  if (new_y < grid_[new_x].GetMinIndex()) {
    std::cout << "Comprobación tercer if hecha, si esto aparece, el fallo no son los corchetes, sino el newcolleft" << std::endl;
    NewColLeft();
  } else if (new_y > grid_[new_x].GetMaxIndex()) {
    NewColRight();
  }

  return std::make_pair(std::make_pair(new_x, new_y), direction); 
}

/**
 * @brief Add a new column at the begin
 * 
 */
void TapeSliding::NewColLeft() {
  for (int i = grid_.GetMinIndex(); i <= grid_.GetMaxIndex(); i++) {
    grid_[i].push_front(Color::WHITE_CELL);
  }

  // A new col has been added, so the size will change
  size_y_++;
}

/**
 * @brief Add a new column at the end 
 * 
 */
void TapeSliding::NewColRight() {
  for (int i = grid_.GetMinIndex(); i <= grid_.GetMaxIndex(); i++) {
  grid_[i].push_back(Color::WHITE_CELL);
  }

  // A new col has been added, so the size will change
  size_y_++;
}

/**
 * @brief Add a new row at the begin
 * 
 */
void TapeSliding::NewRowUp() {
  // Create a new SlideVector of colors to introduce in the grid
  // First, take the size of all the SlideVectors of the grid to create the new
  int min_col = grid_[grid_.GetMinIndex()].GetMinIndex();
  int max_col = grid_[grid_.GetMinIndex()].GetMaxIndex();

  // now, create the SlideVector and initialize every cell with white
  SlidingVector<Color> new_row(min_col, max_col);
  for (int i = new_row.GetMinIndex(); i <= new_row.GetMaxIndex(); i++) {
    new_row[i] = Color::WHITE_CELL;
  }

  // Insert the new vector at the beginnning
  grid_.push_front(new_row);

  // A new row has been added, so the size will change
  size_x_++;
}

/**
 * @brief Add a new row at the end
 * 
 */
void TapeSliding::NewRowDown() {
  // Create a new SlideVector of colors to introduce in the grid
  // First, take the size of all the SlideVectors of the grid to create the new
  int min_col = grid_[grid_.GetMinIndex()].GetMinIndex();
  int max_col = grid_[grid_.GetMinIndex()].GetMaxIndex();

  // now, create the SlideVector and initialize every cell with white
  SlidingVector<Color> new_row(min_col, max_col);
  for (int i = new_row.GetMinIndex(); i <= new_row.GetMaxIndex(); i++) {
    new_row[i] = Color::WHITE_CELL;
  }

  // Insert the new vector at the end
  grid_.push_back(new_row);

  // A new row has been added, so the size will change
  size_x_++;
}