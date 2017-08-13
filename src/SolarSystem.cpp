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
	std::shared_ptr<Star> sun(new Star(SUN_DISTANCE_FROM_THE_SUN, 0, 0));
	sun->Start(SUN_RADIUS, 36, 36);
	AddStar(sun);

	std::shared_ptr<Planet> mercury(new Planet(MERCURY_DISTANCE_FROM_THE_SUN, 0, 0));
	mercury->Start(MERCURY_RADIUS, 36, 36);
	AddPlanet(mercury);

	std::shared_ptr<Planet> venus(new Planet(VENUS_DISTANCE_FROM_THE_SUN, 0, 0));
	venus->Start(VENUS_RADIUS, 36, 36);
	AddPlanet(venus);

	std::shared_ptr<Planet> earth(new Planet(EARTH_DISTANCE_FROM_THE_SUN, 0, 0));
	earth->Start(EARTH_RADIUS, 36, 36);
	AddPlanet(earth);

	std::shared_ptr<Planet> mars(new Planet(MARS_DISTANCE_FROM_THE_SUN, 0, 0));
	mars->Start(MARS_RADIUS, 36, 36);
	AddPlanet(mars);

	std::shared_ptr<Planet> jupiter(new Planet(JUPITER_DISTANCE_FROM_THE_SUN, 0, 0));
	jupiter->Start(JUPITER_RADIUS, 36, 36);
	AddPlanet(jupiter);

	std::shared_ptr<Planet> saturn(new Planet(SATURN_DISTANCE_FROM_THE_SUN, 0, 0));
	saturn->Start(SATURN_RADIUS, 36, 36);
	AddPlanet(saturn);

	std::shared_ptr<Planet> uranus(new Planet(URANUS_DISTANCE_FROM_THE_SUN, 0, 0));
	uranus->Start(URANUS_RADIUS, 36, 36);
	AddPlanet(uranus);

	std::shared_ptr<Planet> neptune(new Planet(NEPTUNE_DISTANCE_FROM_THE_SUN, 0, 0));
	neptune->Start(NEPTUNE_RADIUS, 36, 36);
	AddPlanet(neptune);
}

void SolarSystem::Load() {
	m_Star->Load("resources/textures/sun.jpg");

	m_Planets[0]->Load("resources/textures/mercury.jpg");
	m_Planets[1]->Load("resources/textures/venus.jpg");
	m_Planets[2]->Load("resources/textures/earth.jpg");
	m_Planets[3]->Load("resources/textures/mars.jpg");
	m_Planets[4]->Load("resources/textures/jupiter.jpg");
	m_Planets[5]->Load("resources/textures/saturn.jpg");
	m_Planets[6]->Load("resources/textures/uranus.jpg");
	m_Planets[7]->Load("resources/textures/neptune.jpg");
}

void SolarSystem::Draw(glm::mat4 vp_matrix) {
	m_Star->Draw(vp_matrix);
	
	for (int i = 0; i < m_Planets.size(); i++)
		m_Planets[i]->Draw(vp_matrix);
}