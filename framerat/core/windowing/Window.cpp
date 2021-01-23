/*
 * =====================================================================================
 *
 *       Filename:  Window.cpp
 *
 *    Description:  Defines core Window functionality
 *
 *        Version:  1.0
 *        Created:  01/17/21 15:38:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cedric Schwyter (D3PSI)
 *
 * =====================================================================================
 */
#include "Window.hpp"
#include "factory/WindowFactory.hpp"

namespace framerat::core::windowing {
    Window::Window(std::shared_ptr<WindowFactory> _factory, uint32_t _width, uint32_t _height,
                   const std::string& _title, const std::string& _icon, uint32_t _framerate)
        : RenderingTarget(), m_factory(_factory), m_width(_width), m_height(_height), m_title(_title), m_icon(_icon),
          m_framerate(_framerate) {
        m_factory->init();
    }

    void Window::draw() { m_factory->draw(); }

} // namespace framerat::core::windowing
