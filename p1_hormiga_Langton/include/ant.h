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
#include "../include/tape.h"
#include "../include/enum_class.h"



class Ant {
	public:
		Ant() : direction_{0}, position_{} {}
		Ant(const Direction& direction, const std::pair<int, int>& position) : direction_(direction), position_(position) {}

	// Getters
		Direction GetDirection() const { return direction_; } 
		std::pair<int, int> GetPosition() const { return position_; }


		// Color CheckColor(const std::pair<int, int> &position) const;
		void Move();
		void Step(const Color &color);


	private:
		Direction direction_;
		// The ant current location
		std::pair<int, int> position_;		
		
		void TurnLeft();
		void TurnRight();
};

std::ostream &operator<<(std::ostream& os, const Ant& ant);

#endif //ANT_H