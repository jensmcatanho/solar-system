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
#ifndef CORE_H
#define CORE_H

#include "Prerequisites.h"
#include "Planet.h"
#include "Singleton.h"
#include "SolarSystem.h"
#include "Star.h"
#include "Window.h"

class Core : public Singleton<Core> {
	public:
		Core();

		void Setup();
		
		void Run();

		static std::stringstream ReadFile(std::string path);

		std::shared_ptr<Star> GetStar() const;

		std::shared_ptr<Planet> GetPlanet(unsigned int id) const;

		std::shared_ptr<Window> GetWindow() const;

		static Core &GetSingleton();

		static Core *GetSingletonPtr();

		std::shared_ptr<Camera> m_Camera;

		GLfloat m_DeltaTime;

	private:
		std::shared_ptr<Window> m_Window;

		std::shared_ptr<SolarSystem> m_SolarSystem;
};

inline std::shared_ptr<Star> Core::GetStar() const {
	return m_SolarSystem->GetStar();
}

inline std::shared_ptr<Planet> Core::GetPlanet(unsigned int id) const {
	return m_SolarSystem->GetPlanet(id);
}

inline std::shared_ptr<Window> Core::GetWindow() const {
	return m_Window;
}

#endif