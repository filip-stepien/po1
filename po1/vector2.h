/**
 * @file vector2.h
 * @brief Klasa wektora 2D
 */

#pragma once
#include <cmath>

/**
 * @brief Klasa wektora 2D
 */
class Vector2 {
public:
	//! składowa X wektora
	double x;
	//! składowa Y wektora
	double y;

	/**
	 * @brief Konstruktor klasy wektora 2D
	 */
	Vector2();

	/**
	 * @brief Konstruktor klasy wektora 2D
	 * @param x składowa X wektora
	 * @param y składowa Y wektora
	 */
	Vector2(double x, double y);

	/**
	 * @brief Przeciążenie operatora mnożenia
	 * @param num liczba, przez którą zostaną pomnożone składowe wektora
	 * @return przemnożony wektor
	 */
	Vector2 operator * (double num);

	/**
	 * @brief Przeciążenie operatora minus
	 * @return odwrócony wektor
	 */
	Vector2 operator - ();

	/**
	 * @brief Normalizacja wektora
	 * @return znormalizowany wektor
	 */
	Vector2 normalized();
};
