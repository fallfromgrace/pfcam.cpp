#pragma once

#include "includes.hpp"

#include "property.hpp"

namespace pf
{
	// 
	class exposure_property : public detail::property
	{
	public:
		// 
		exposure_property(int port) :
			property(port, "ExposureTime")
		{

		}

		// 
		int32_t get() const
		{
			return static_cast<int32_t>(this->get_float() * 1000);
		}

		// 
		void set(int32_t value) const
		{
			this->set_float(value * 0.001f);
		}
	};

	// 
	class camera_name_property : public detail::property
	{
	public:
		// 
		camera_name_property(int port) :
			property(port, "CameraName")
		{

		}

		// 
		std::string get() const
		{
			return this->get_string();
		}
	};

	// 
	class serial_number_property : public detail::property
	{
	public:
		// 
		serial_number_property(int port) :
			property(port, "Info.Serial")
		{

		}

		// 
		std::string get() const
		{
			return this->get_string();
		}
	};

	// 
	class pixel_clock_property : public detail::property
	{
	public:
		// 
		pixel_clock_property(int port) :
			property(port, "Header.PixelClock")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}
	};

	// 
	class temperature_property : public detail::property
	{
	public:
		// 
		temperature_property(int port) :
			property(port, "Header.PixelClock")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}
	};

	// 
	class window_x_property : public detail::property
	{
	public:
		// 
		window_x_property(int port) :
			property(port, "Window.X")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}

		// 
		void set(int32_t value) const
		{
			this->set_int(value);
		}
	};

	// 
	class window_y_property : public detail::property
	{
	public:
		// 
		window_y_property(int port) :
			property(port, "Window.Y")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}

		// 
		void set(int32_t value) const
		{
			this->set_int(value);
		}
	};

	// 
	class window_w_property : public detail::property
	{
	public:
		// 
		window_w_property(int port) :
			property(port, "Window.W")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}

		// 
		void set(int32_t value) const
		{
			this->set_int(value);
		}
	};

	// 
	class window_h_property : public detail::property
	{
	public:
		// 
		window_h_property(int port) :
			property(port, "Window.H")
		{

		}

		// 
		int32_t get() const
		{
			return this->get_int();
		}

		// 
		void set(int32_t value) const
		{
			this->set_int(value);
		}
	};
}