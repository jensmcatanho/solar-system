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
	std::shared_ptr<Star> sun(
		new Star(
			SUN_DISTANCE_FROM_THE_SUN,
			SUN_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(SUN_INCLINATION)),
			0,
			SUN_RADIUS,
			SUN_ROTATION,
			SUN_AXIAL_TILT
		)
	);

	sun->Start(36, 36);
	AddStar(sun);

	std::shared_ptr<Planet> mercury(
		new Planet(
			MERCURY_DISTANCE_FROM_THE_SUN,
			MERCURY_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(MERCURY_INCLINATION)),
			0,
			MERCURY_RADIUS,
			MERCURY_ROTATION,
			MERCURY_AXIAL_TILT
		)
	);

	mercury->Start(36, 36);
	AddPlanet(mercury);

	std::shared_ptr<Planet> venus(
		new Planet(
			VENUS_DISTANCE_FROM_THE_SUN,
			VENUS_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(VENUS_INCLINATION)),
			0,
			VENUS_RADIUS,
			VENUS_ROTATION,
			VENUS_AXIAL_TILT
		)
	);

	venus->Start(36, 36);
	AddPlanet(venus);

	std::shared_ptr<Planet> earth(
		new Planet(
			EARTH_DISTANCE_FROM_THE_SUN,
			EARTH_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(EARTH_INCLINATION)),
			0,
			EARTH_RADIUS,
			EARTH_ROTATION,
			EARTH_AXIAL_TILT
		)
	);
	
	earth->Start(36, 36);
	AddPlanet(earth);

	std::shared_ptr<Planet> mars(
		new Planet(
			MARS_DISTANCE_FROM_THE_SUN,
			MARS_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(MARS_INCLINATION)),
			0,
			MARS_RADIUS,
			MARS_ROTATION,
			MARS_AXIAL_TILT
		)
	);

	mars->Start(36, 36);
	AddPlanet(mars);

	std::shared_ptr<Planet> jupiter(
		new Planet(
			JUPITER_DISTANCE_FROM_THE_SUN,
			JUPITER_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(JUPITER_INCLINATION)),
			0,
			JUPITER_RADIUS,
			JUPITER_ROTATION,
			JUPITER_AXIAL_TILT
		)
	);

	jupiter->Start(36, 36);
	AddPlanet(jupiter);

	std::shared_ptr<Planet> saturn(
		new Planet(
			SATURN_DISTANCE_FROM_THE_SUN,
			SATURN_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(SATURN_INCLINATION)),
			0,
			SATURN_RADIUS,
			SATURN_ROTATION,
			SATURN_AXIAL_TILT
		)
	);

	saturn->Start(36, 36);
	AddPlanet(saturn);

	std::shared_ptr<Planet> uranus(
		new Planet(
			URANUS_DISTANCE_FROM_THE_SUN,
			URANUS_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(URANUS_INCLINATION)),
			0,
			URANUS_RADIUS,
			URANUS_ROTATION,
			URANUS_AXIAL_TILT
		)
	);

	uranus->Start(36, 36);
	AddPlanet(uranus);

	std::shared_ptr<Planet> neptune(
		new Planet(
			NEPTUNE_DISTANCE_FROM_THE_SUN,
			NEPTUNE_DISTANCE_FROM_THE_SUN * glm::sin(glm::radians(NEPTUNE_INCLINATION)),
			0,
			NEPTUNE_RADIUS,
			NEPTUNE_ROTATION,
			NEPTUNE_AXIAL_TILT
		)
	);

	neptune->Start(36, 36);
	AddPlanet(neptune);
}

void SolarSystem::Load() {
	m_Star->Load("resources/shaders/sun.vert", "resources/shaders/sun.frag", "resources/textures/sun_diffuse_map.jpg", "resources/textures/sun_specular_map.jpg");

	m_Planets[0]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/mercury_diffuse_map.jpg",
		"resources/textures/mercury_specular_map.jpg"
	);

	m_Planets[1]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/venus_diffuse_map.jpg",
		"resources/textures/venus_specular_map.jpg"
	);

	m_Planets[2]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/earth_diffuse_map.jpg",
		"resources/textures/earth_specular_map.jpg"
	);

	m_Planets[3]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/mars_diffuse_map.jpg",
		"resources/textures/mars_specular_map.jpg"
	);

	m_Planets[4]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/jupiter_diffuse_map.jpg",
		"resources/textures/jupiter_specular_map.jpg"
	);

	m_Planets[5]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/saturn_diffuse_map.jpg",
		"resources/textures/saturn_specular_map.jpg"
	);

	m_Planets[6]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/uranus_diffuse_map.jpg",
		"resources/textures/uranus_specular_map.jpg"
	);

	m_Planets[7]->Load(
		"resources/shaders/planet.vert",
		"resources/shaders/planet.frag",
		"resources/textures/neptune_diffuse_map.jpg",
		"resources/textures/neptune_specular_map.jpg"
	);
}

void SolarSystem::Draw(glm::mat4 vp_matrix) {
	m_Star->Draw(vp_matrix);
	
	for (int i = 0; i < m_Planets.size(); i++)
		m_Planets[i]->Draw(vp_matrix);
}