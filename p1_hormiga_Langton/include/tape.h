#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include "colors.h"
#include "ant.h"

// Guardar los códigos que corresponden a cada color
enum class Color {

	WHITE_CELL = 0,
	BLACK_CELL = 1,
};

class Tape {
	public:
		Tape(const std::vector<std::vector<Color>> tape, const int &size_x, const int &size_y) : tape_(tape), size_x_(size_x), size_y_(size_y) {}
		
		int GetSizeX() const { return size_x_; }
		int GetSizeY() const { return size_y_; }

		void PrintTapeAnt(const Ant &ant);
		Color CheckColor(const std::pair<int, int> &cell) const;
		void SetColor(const Color &color, const std::pair<int, int> &cell);

	private:
		std::vector<std::vector<Color>> tape_;
		int size_x_;
		int size_y_;
};

std::ostream &operator<<(std::ostream &os, const Tape &tape);

#endif "TAPE_H"
