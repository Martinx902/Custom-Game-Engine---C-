// Martin Pérez Villabrille
//Copyrigth (c)

#include "../headers/Window.hpp"
#include <SDL.h>
#include <OpenGL.hpp>
#include <cstdlib>

namespace Mgine
{
	bool Window::sdl_video_initialized = false;

	//Fullscreen window
	Window::Window(const std::string& title, unsigned width, unsigned height, bool fullscreen)
	{
		initialize_video();

		Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

		if (fullscreen) window_flags |= SDL_WINDOW_FULLSCREEN;

		handle = SDL_CreateWindow
		(
			title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			window_flags
		);

		if (handle)
		{
			gl_context = SDL_GL_CreateContext(handle);

			if (gl_context && glt::initialize_opengl_extensions())
			{
				if (fullscreen)
				{
					SDL_SetWindowFullscreen(handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
			}
		}

		SDL_assert(handle != nullptr);
	}

	//Not fullscreen window
	Window::Window(const std::string& title, unsigned x, unsigned y, unsigned width, unsigned height)
	{
		initialize_video();

		handle = SDL_CreateWindow
		(
			title.c_str(),
			x,
			y,
			width,
			height,
			SDL_WINDOW_SHOWN
		);

		SDL_assert(handle != nullptr);
	}

	Window::~Window()
	{
		SDL_assert(handle != nullptr);

		SDL_DestroyWindow(handle);
	}

	unsigned  Window::get_width() const
	{
		int width;

		SDL_GetWindowSize(handle, &width, nullptr);

		return unsigned(width);
	}

	unsigned  Window::get_height() const
	{
		int height;

		SDL_GetWindowSize(handle, nullptr, &height);

		return unsigned(height);
	}

	bool  Window::is_full_screen() const
	{
		Uint32 window_flags = SDL_GetWindowFlags(handle);

		return (window_flags & SDL_WINDOW_FULLSCREEN) != 0;
	}

	/**
	* If result is 0 everything good, else there's a problem
	*/
	void Window::initialize_video()
	{
		if (not sdl_video_initialized)
		{
			auto result = SDL_Init(SDL_INIT_VIDEO);

			sdl_video_initialized = result == 0;

			SDL_assert(sdl_video_initialized == true);

			atexit(finalize_sdl);
		}
	}

	void Window::finalize_sdl()
	{
		SDL_Quit();
	}

	void Window::clear() const
	{
        if (gl_context)
        {
            glClearColor(0.15f, 0.15f, 0.15f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(handle);
	}
}