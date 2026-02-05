/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * @file ant.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-04
 * @brief 
 */
#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <utility>
#include "tape.h"

/**
 * @brief Type to 
 * 
 */
enum class Direction {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

class Ant {
	public:
	// The constructor receives two parameters, the initial direction and the initial position of the ant in the tape
		Ant(const Direction& direction, const std::pair<int, int>& position) : direction_(direction), position_(position) {}

	// Getters
		Direction GetDirection() const { return direction_; } 
		std::pair<int, int> GetPosition() const { return position_; }

		void TurnLeft();
		void TurnRight();
		Color CheckColor(const std::pair<int, int> &position) const;
		void Move(const Color &color);

	private:
		Direction direction_;

		// The ant current location
		std::pair<int, int> position_;
};

std::ostream &operator<<(std::ostream& os, const Ant& ant);

#endif "ANT_H"