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
 * Celestial bodies properties.
 * 1 unit = 1000000km (distance)
 * 1 unit = 1000km (radius)
 * 1 unit = 1 earth day
 *
 * Obs. All distances from the sun consider the planet at the perihelion.
 */
const GLdouble DISTANCE_SCALE = 0.000001f;
const GLdouble RADIUS_SCALE = 0.00001f;
const GLdouble ASTRONOMICAL_UNIT = 147095000.0f * DISTANCE_SCALE;

// Sun
const GLdouble SUN_RADIUS = 695700.0f * RADIUS_SCALE;
const GLdouble SUN_DISTANCE_FROM_THE_SUN = 0.0f * DISTANCE_SCALE;

// Mercury
const GLdouble MERCURY_RADIUS = 2440.0f * RADIUS_SCALE;
const GLdouble MERCURY_DISTANCE_FROM_THE_SUN = 0.307499f * ASTRONOMICAL_UNIT;

// Venus
const GLdouble VENUS_RADIUS = 6052.0f * RADIUS_SCALE;
const GLdouble VENUS_DISTANCE_FROM_THE_SUN = 0.718440f * ASTRONOMICAL_UNIT;

// Earth
const GLdouble EARTH_RADIUS = 6371.0f * RADIUS_SCALE;
const GLdouble EARTH_DISTANCE_FROM_THE_SUN = ASTRONOMICAL_UNIT;

// Mars
const GLdouble MARS_RADIUS = 3390.0f * RADIUS_SCALE;
const GLdouble MARS_DISTANCE_FROM_THE_SUN = 1.3814f * ASTRONOMICAL_UNIT;

// Jupiter
const GLdouble JUPITER_RADIUS = 69911.0f * RADIUS_SCALE;
const GLdouble JUPITER_DISTANCE_FROM_THE_SUN = 4.95029f * ASTRONOMICAL_UNIT;

// Saturn
const GLdouble SATURN_RADIUS = 58232.0f * RADIUS_SCALE;
const GLdouble SATURN_DISTANCE_FROM_THE_SUN = 9.024f * ASTRONOMICAL_UNIT;

// Uranus
const GLdouble URANUS_RADIUS = 25362.0f * RADIUS_SCALE;
const GLdouble URANUS_DISTANCE_FROM_THE_SUN = 18.33f * ASTRONOMICAL_UNIT;

// Neptune
const GLdouble NEPTUNE_RADIUS = 24622.0f * RADIUS_SCALE;
const GLdouble NEPTUNE_DISTANCE_FROM_THE_SUN = 29.81f * ASTRONOMICAL_UNIT;

#endif
