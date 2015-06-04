#pragma once

#include <memory>
#include <vector>

#include "logging\logging.hpp"
#include "pfcam.h"

#include "helpers.hpp"
#include "port_info.hpp"
#include "properties.hpp"

namespace pf
{
	namespace detail
	{
		// 
		class activated_camera
		{
		public:
			// 
			activated_camera(const port_info& port_info) : 
				port_info_(port_info)
			{
				open();
			}

			// 
			~activated_camera()
			{
				try
				{
					close();
				}
				catch (const std::exception& ex)
				{
					log_error(ex.what());
				}
			}

			// 
			void open()
			{
				int result = ::pfDeviceOpen(this->port_info().port());
				handle_result(result);
			}

			// 
			void close()
			{
				int result = ::pfDeviceClose(this->port_info().port());
				handle_result(result);
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
			pf::port_info port_info_;
		};
	}

	std::vector<port_info> get_ports()
	{
		std::vector<port_info> ports;
		int port, port_count;
		int result = ::pfPortInit(&port_count);
		detail::handle_result(result);
		for (port = 0; port < port_count; port++)
			ports.emplace_back(port);

		return ports;
	}

	typedef std::shared_ptr<detail::activated_camera> camera_type;

	camera_type activate_camera(const port_info& port_info)
	{
		return std::make_shared<detail::activated_camera>(port_info);
	}
}