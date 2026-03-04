/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file tape.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-10
 * @brief This file declarates the Tape class
 * 				This class is used to represent the grid in the simulation
 */
#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include "../include/colors.h"
#include "../include/ant.h"
#include "../include/enum_class.h"
#include "../include/sliding_vector.h"



class Tape {
	public:
	// Constructors
		Tape() : size_x_{}, size_y_{} {} // Default
		Tape(const int &size_x, const int &size_y) : size_x_(size_x), size_y_(size_y) {}
		
	// Getters
		int GetSizeX() const { return size_x_; }
		int GetSizeY() const { return size_y_; }

	// Every derived tape must implement its methods to viewing and changing the color of a cell and recolocate an ant when reached the limits of the tape
		virtual Color CheckColor(const std::pair<int, int> &cell) const = 0;
		virtual void SetColor(const Color &color, const std::pair<int, int> &cell) = 0;
		virtual std::pair<std::pair<int, int>, Direction> Reposition(const std::pair<int, int> &position, const Direction direction) = 0;

		void PrintCell(const std::pair<int, int> &position, const char symbol = ' ');

	protected:
	// The size is protected. Each tape must be able to change its size.
		int size_x_;
		int size_y_;

	private:
		// The grid will be implemented in every derived class, because all they don't use the same data structure
		std::string ColorToCode(const Color &color);
};

std::ostream &operator<<(std::ostream &os, const Tape &tape);

#endif //TAPE_H
