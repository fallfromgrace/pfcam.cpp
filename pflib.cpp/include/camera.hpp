#pragma once

#include <vector>

#include "includes.hpp"
#include "logging\logging.hpp"
#include "pfcam.h"

#include "helpers.hpp"
#include "port_info.hpp"
#include "properties.hpp"

namespace pf
{
	// 
	class camera
	{
	public:
		// 
		camera(const port_info& port_info) :
			port_info_(port_info), is_open_(false)
		{
			this->open();
		}

		camera(camera&& other) :
			is_open_(other.is_open_),
			port_info_(std::move(other.port_info_))
		{
			other.is_open_ = false;
		}

		camera(const camera&) = delete;

		camera& operator=(const camera&) = delete;

		// 
		~camera()
		{
			try
			{
				this->close();
			}
			catch (const std::exception& ex)
			{
				log_error(ex.what());
			}
		}

		// 
		bool_t is_open() const
		{
			return this->is_open_;
		}

		// 
		void open()
		{
			if (this->is_open() == false)
			{
				int result = ::pfDeviceOpen(this->port_info().port());
				detail::handle_result(result);
				this->is_open_ = true;
			}
		}

		// 
		void close()
		{
			if (this->is_open() == true)
			{
				int result = ::pfDeviceClose(this->port_info().port());
				detail::handle_result(result);
				this->is_open_ = false;
			}
		}

		camera_name_property name() const
		{
			return camera_name_property(this->port_info().port());
		}

		camera_name_property serial_number() const
		{
			return camera_name_property(this->port_info().port());
		}

		pixel_clock_property pixel_clock() const
		{
			return pixel_clock_property(this->port_info().port());
		}

		temperature_property temperature() const
		{
			return temperature_property(this->port_info().port());
		}

		window_x_property x() const
		{
			return window_x_property(this->port_info().port());
		}

		window_y_property y() const
		{
			return window_y_property(this->port_info().port());
		}

		window_w_property w() const
		{
			return window_w_property(this->port_info().port());
		}

		window_h_property h() const
		{
			return window_h_property(this->port_info().port());
		}

		port_info port_info() const
		{
			return this->port_info_;
		}

	private:
		bool_t is_open_;
		const pf::port_info port_info_;
	};

	std::vector<port_info> get_ports()
	{
		std::vector<port_info> ports;
		int port, port_count;
		int result = ::pfPortInit(&port_count);
		detail::handle_result(result);
		for (port = 0; port < port_count; port++)
		{
			port_info port_info(port);
			if (port_info.type() == port_type::clallserial)
				ports.push_back(std::move(port_info));
		}

		return ports;
	}
}