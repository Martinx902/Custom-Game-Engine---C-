/**
 * @author    Martin Pérez Villabrille
 * @copyright Copyright (c) 2023+ Martin Pérez Villabrille.
 *            All rights reserved
 */

#include <string>

#pragma once

typedef struct SDL_Window SDL_Window;
typedef void* SDL_GLContext;

namespace Mgine
{
	/**
	 * @brief Creates a window using SDL.
	 *
	 * The window class displays all models on screen and manages visuals.
	 */
	class Window
	{
		SDL_Window* handle;                     ///< Reference to the actual SDL Window
		SDL_GLContext gl_context;               ///< Reference to the actual SDL Window
		static bool sdl_video_initialized;      ///< Flag to see if the window has been initialized

	public:

		/**
		 * @brief Construct a new Window object and can be set to fullscreen
		 *
		 * @param title The title of the window.
		 * @param width The width of the window.
		 * @param height The height of the window.
		 * @param fullscreen Whether the window should be fullscreen (default: true).
		 */
		Window(const std::string& title, unsigned width, unsigned height, bool fullscreen = true);

		/**
		 * @brief Construct a new Window object in an especific location
		 *
		 * @param title The title of the window.
		 * @param x The x-coordinate of the window position.
		 * @param y The y-coordinate of the window position.
		 * @param width The width of the window.
		 * @param height The height of the window.
		 */
		Window(const std::string& title, unsigned x, unsigned y, unsigned width, unsigned height);

		/**
		 * @brief Destroy the Window object.
		 */
		~Window();

		/**
		 * @brief Get the width of the window.
		 *
		 * @return The width of the window.
		 */
		unsigned get_width() const;

		/**
		 * @brief Get the height of the window.
		 *
		 * @return The height of the window.
		 */
		unsigned get_height() const;

		/**
		 * @brief Check if the window is in fullscreen mode.
		 *
		 * @return True if the window is in fullscreen mode, false otherwise.
		 */
		bool is_full_screen() const;

		/**
		 * @brief Clears the content of the depth and color buffers of the window.
		 */
		void clear() const;

		/**
		 * @brief Swap the front and back buffers of the window.
		 */
		void swap_buffers() const;

	private:

		/**
		 * @brief Initialize the SDL video subsystem.
		 */
		static void initialize_video();

		/**
		 * @brief Finalize SDL Video and the Window.
		 */
		static void finalize_sdl();
	};
}