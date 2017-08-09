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
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "Prerequisites.h"

typedef std::vector<std::shared_ptr<Planet>> PlanetList;

class SolarSystem {
	public:
		SolarSystem(unsigned int num_planets);

		void AddStar(std::shared_ptr<Star> star);

		void AddPlanet(std::shared_ptr<Planet> planet);

		void Start();

		void Draw();

	private:
		std::shared_ptr<Star> m_Star;

		PlanetList m_Planets;
};

inline void SolarSystem::AddStar(std::shared_ptr<Star> star) {
	m_Star = star;
}

inline void SolarSystem::AddPlanet(std::shared_ptr<Planet> planet) {
	m_Planets.push_back(planet);
}

#endif