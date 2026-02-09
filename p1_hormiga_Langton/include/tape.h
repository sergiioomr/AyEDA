#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include "../include/colors.h"
#include "../include/ant.h"
#include "../include/enum_class.h"



class Tape {
	public:
		Tape() : tape_{}, size_x_{}, size_y_{} {}
		Tape(const int &size_x, const int &size_y);
		
		int GetSizeX() const { return size_x_; }
		int GetSizeY() const { return size_y_; }

		Color CheckColor(const std::pair<int, int> &cell) const;
		void SetColor(const Color &color, const std::pair<int, int> &cell);

	private:
		std::vector<std::vector<Color>> tape_;
		int size_x_;
		int size_y_;
};

std::ostream &operator<<(std::ostream &os, const Tape &tape);

#endif //TAPE_H
