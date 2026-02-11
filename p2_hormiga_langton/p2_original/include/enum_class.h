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

	RED_CELL = 0,
	GREEN_CELL = 1,
	YELLOW_CELL = 2,
	BLUE_CELL = 3,
	MAGENTA_CELL = 4,
	CYAN_CELL = 5, 
	ORANGE_CELL = 6,
	ROSE_CELL = 7,
	LBLUE_CELL = 8,
	LGRENN_CELL = 9,
	GRAY_CELL = 10,
	WHITE_CELL = 11,
	BLACK_CELL = 12,
};


#endif // ENUM_CLASS_H