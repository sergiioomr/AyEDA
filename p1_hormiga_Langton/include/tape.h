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



class Tape {
	public:
	// Constructors
		Tape() : tape_{}, size_x_{}, size_y_{} {} // Default
		Tape(const int &size_x, const int &size_y);
		
	// Getters
		int GetSizeX() const { return size_x_; }
		int GetSizeY() const { return size_y_; }

		Color CheckColor(const std::pair<int, int> &cell) const;
		void SetColor(const Color &color, const std::pair<int, int> &cell);

	private:
		std::vector<std::vector<Color>> tape_; // The grid
		int size_x_;
		int size_y_;
};

std::ostream &operator<<(std::ostream &os, const Tape &tape);

#endif //TAPE_H
