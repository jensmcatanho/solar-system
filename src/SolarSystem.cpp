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
#include "SolarSystem.h"
#include "Planet.h"
#include "Star.h"

SolarSystem::SolarSystem(unsigned int num_planets) {
	m_Planets.reserve(num_planets);

}

void SolarSystem::Start() {
	std::shared_ptr<Star> sun(new Star(-2, 0, -10));
	sun->Start(0.5, 24, 24);
	AddStar(sun);

	std::shared_ptr<Planet> mars(new Planet(0, 0, -10));
	mars->Start(0.5, 24, 24);
	AddPlanet(mars);
}

void SolarSystem::Load() {
	m_Star->Load();

	for (auto planet : m_Planets)
		planet->Load();
}

void SolarSystem::Draw(glm::mat4 vp_matrix) {
	m_Star->Draw(vp_matrix);

	for (auto planet : m_Planets)
		planet->Draw(vp_matrix);
}