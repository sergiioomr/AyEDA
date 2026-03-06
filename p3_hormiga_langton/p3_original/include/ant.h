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
 * 				That class will be use to represent the Ant in the Tape.
 * 				Will be an abstract class. The method step is an pure virtual one, every ant_x must be define their unique behavior.
 */
#ifndef ANT_H
#define ANT_H

#include <iostream>
#include <utility>
#include "../include/enum_class.h"



class Ant {
	public:
	// Constructors
		Ant() : direction_{0}, position_{}, lifetime_{} {} // Default
		Ant(const Direction& direction, const std::pair<int, int>& position, int lifetime) 
			: direction_(direction), position_(position), lifetime_(lifetime) {}

	// Getters
		Direction GetDirection() const { return direction_; } 
		std::pair<int, int> GetPosition() const { return position_; }
		int GetLifeTime() const { return lifetime_; }
		virtual char GetCategory() const = 0;
		virtual std::string GetType() const = 0;

	// Setters
		void SetDirection(const Direction direction) {direction_ = direction; }
		void SetPosition(const std::pair<int, int> &position) {position_ = position; }

		virtual void Step(const Color &color) = 0;
		virtual void IncreaseLifetime(int amount) = 0;
		virtual void DecreaseLifetime(double amount) = 0;

	// Virtual destructor to avoid memory leaks if we delete an object ant_x
		virtual ~Ant() = default;

	protected:
	// Functions to use in Step. 
		void TurnLeft();
		void TurnRight();
		virtual void Move();

	// Protected arguments. Each ant must be able to change its own position or direction. Neede also to implement the Move in the Carnivorous Ant
		Direction direction_;
		// The ant current location
		std::pair<int, int> position_;	
		int lifetime_;		
};

std::ostream &operator<<(std::ostream& os, const Ant& ant);

#endif //ANT_H