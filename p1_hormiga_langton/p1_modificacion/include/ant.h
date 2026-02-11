/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file ant.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-04
 * @brief This file declarates the Ant class. 
 * 				That class will be use to represent the Ant in the Tape
 */
#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <utility>
#include "../include/tape.h"
#include "../include/enum_class.h"



class Ant {
	public:
	// Constructors
		Ant() : direction_{0}, position_{} {} // Default
		Ant(const Direction& direction, const std::pair<int, int>& position) : direction_(direction), position_(position) {}

	// Getters
		Direction GetDirection() const { return direction_; } 
		std::pair<int, int> GetPosition() const { return position_; }

		void Step(const Color &color);

	private:
		Direction direction_;
		// The ant current location
		std::pair<int, int> position_;		
		
		// Functions to use in Step. 
		void TurnLeft();
		void TurnRight();
		void Move();

};

std::ostream &operator<<(std::ostream& os, const Ant& ant);

#endif //ANT_H