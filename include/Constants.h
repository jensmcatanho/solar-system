/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2016 Jean Michel Catanho

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <glm/gtc/constants.hpp>

/**
 * Mathematical constants.
 */
const GLdouble PI = glm::pi<float>();
const GLdouble HALF_PI = glm::half_pi<float>();
const GLdouble TWO_PI = 2 * glm::pi<float>();
const GLdouble INV_PI = 1 / glm::pi<float>();

/**
 * Camera's default values.
 */
enum Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 5.0f;
const GLfloat SENSITIVITY = 0.1f;
const GLfloat ZOOM = 45.0f;

/**
 * Celestial bodies properties.
 * - Radius' and distances from the sun are scaled for better visualization.
 * - Distances from the sun consider the planet at the perihelion.
 * - Rotations are relative to Earth's rotation period.
 * - Inclinations are relative to the Sun's equator.
 */
const GLdouble DISTANCE_SCALE = 0.000001f;
const GLdouble RADIUS_SCALE = 0.00001f;
const GLdouble ASTRONOMICAL_UNIT = 147095000.0f * DISTANCE_SCALE;
const GLdouble EARTH_DAY = 1.0f;

// Sun
const GLdouble SUN_RADIUS = 695700.0f * RADIUS_SCALE;
const GLdouble SUN_DISTANCE_FROM_THE_SUN = 0.0f * DISTANCE_SCALE;
const GLdouble SUN_ROTATION = 24.47f * EARTH_DAY;
const GLdouble SUN_AXIAL_TILT = 7.5f;
const GLdouble SUN_INCLINATION = 0.0f;

// Mercury
const GLdouble MERCURY_RADIUS = 2440.0f * RADIUS_SCALE;
const GLdouble MERCURY_DISTANCE_FROM_THE_SUN = 0.307499f * ASTRONOMICAL_UNIT;
const GLdouble MERCURY_ROTATION = 58.7f * EARTH_DAY;
const GLdouble MERCURY_AXIAL_TILT = 2.11f;
const GLdouble MERCURY_INCLINATION = 3.38f;

// Venus
const GLdouble VENUS_RADIUS = 6052.0f * RADIUS_SCALE;
const GLdouble VENUS_DISTANCE_FROM_THE_SUN = 0.718440f * ASTRONOMICAL_UNIT;
const GLdouble VENUS_ROTATION = 243.0f * EARTH_DAY;
const GLdouble VENUS_AXIAL_TILT = 177.4f;
const GLdouble VENUS_INCLINATION = 3.86f;

// Earth
const GLdouble EARTH_RADIUS = 6371.0f * RADIUS_SCALE;
const GLdouble EARTH_DISTANCE_FROM_THE_SUN = ASTRONOMICAL_UNIT;
const GLdouble EARTH_ROTATION = EARTH_DAY;
const GLdouble EARTH_AXIAL_TILT = 23.5f;
const GLdouble EARTH_INCLINATION = 7.155f;

// Mars
const GLdouble MARS_RADIUS = 3390.0f * RADIUS_SCALE;
const GLdouble MARS_DISTANCE_FROM_THE_SUN = 1.3814f * ASTRONOMICAL_UNIT;
const GLdouble MARS_ROTATION = 1.026f * EARTH_DAY;
const GLdouble MARS_AXIAL_TILT = 25.0f;
const GLdouble MARS_INCLINATION = 5.65f;

// Jupiter
const GLdouble JUPITER_RADIUS = 69911.0f * RADIUS_SCALE;
const GLdouble JUPITER_DISTANCE_FROM_THE_SUN = 4.95029f * ASTRONOMICAL_UNIT;
const GLdouble JUPITER_ROTATION = 0.41f * EARTH_DAY;
const GLdouble JUPITER_AXIAL_TILT = 3.13f;
const GLdouble JUPITER_INCLINATION = 6.09f;

// Saturn
const GLdouble SATURN_RADIUS = 58232.0f * RADIUS_SCALE;
const GLdouble SATURN_DISTANCE_FROM_THE_SUN = 9.024f * ASTRONOMICAL_UNIT;
const GLdouble SATURN_ROTATION = 0.425f * EARTH_DAY;
const GLdouble SATURN_AXIAL_TILT = 26.7f;
const GLdouble SATURN_INCLINATION = 5.51f;

// Uranus
const GLdouble URANUS_RADIUS = 25362.0f * RADIUS_SCALE;
const GLdouble URANUS_DISTANCE_FROM_THE_SUN = 18.33f * ASTRONOMICAL_UNIT;
const GLdouble URANUS_ROTATION = 0.7458f * EARTH_DAY;
const GLdouble URANUS_AXIAL_TILT = 98.0f;
const GLdouble URANUS_INCLINATION = 6.48f;

// Neptune
const GLdouble NEPTUNE_RADIUS = 24622.0f * RADIUS_SCALE;
const GLdouble NEPTUNE_DISTANCE_FROM_THE_SUN = 29.81f * ASTRONOMICAL_UNIT;
const GLdouble NEPTUNE_ROTATION = 6.39f * EARTH_DAY;
const GLdouble NEPTUNE_AXIAL_TILT = 28.32f;
const GLdouble NEPTUNE_INCLINATION = 6.43f;

#endif
