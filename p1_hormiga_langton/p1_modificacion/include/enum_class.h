/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @file enum_class.h
 * @author Sergio Molina Ríos (alu0101718194@ull.edu.es)
 * @date 2026-02-10
 * @brief File to define two enum class
 * 				Directions, to represent up, down left and right
 * 				Colors, to represent black and white and allow to include more colors in the simulator
 */

#ifndef ENUM_CLASS_H
#define ENUM_CLASS_H

enum class Direction {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

enum class Color {

	WHITE_CELL = 0,
	BLACK_CELL = 1,
};

#endif // ENUM_CLASS_H