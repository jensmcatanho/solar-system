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
#ifndef WINDOW_H
#define WINDOW_H

#include "Prerequisites.h"

class Window {
	public:
		/**
		 * Default constructor.
		 */
		Window(std::string title, int width, int height);

		/**
		 *
		 */
		bool Create();

		/**
		 *
		 */
		void ProcessInput();
	
		/**
		 *
		 */
		void DisplayFPS();

		/**
		 *
		 */
		void SwapBuffers();

		/**
		*
		*/
		void PollEvents() const;

		/**
		 *
		 */
		void Close();

		/**
		 * 
		 */
		GLFWwindow *GetPointer() const;

		/**
		 * Window's width.
		 */
		int m_Width;

		/**
		 * Window's height.
		 */
		int m_Height;

		/**
		 * Aspect Ratio.
		 */
		float m_AspectRatio;

	private:
		/**
		 * Pointer to the GLFWwindow type.
		 */
		GLFWwindow *m_Window;

		/**
		 * 
		 */
		std::string m_Title;

		/**
		 *
		 */
		GLfloat m_DeltaTime;
};

inline void Window::Close() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

inline void Window::SwapBuffers() {
	glfwSwapBuffers(m_Window);
}

inline void Window::PollEvents() const {
	glfwPollEvents();
}

inline GLFWwindow *Window::GetPointer() const {
	return m_Window;
}

#endif