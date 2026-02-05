#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>

// Guardar los códigos que corresponden a cada color
enum class Color {

	WHITE = 0,
	BLACK = 1,
};

class Tape {
	public:
		Tape(const std::vector<std::vector<Color>> tape) : tape_(tape) {}
		
		Color CheckColor(const std::pair<int, int> &cell) const;
		void SetColor(const Color &color, const std::pair<int, int> &cell);

	private:
		std::vector<std::vector<Color>> tape_;
		int size_x;
		int size_y;
};

#endif "TAPE_H"
