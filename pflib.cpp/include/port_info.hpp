#pragma once

#include <stdexcept>

#include "pfcam.h"

#include "helpers.hpp"
#include "pf_exception.hpp"

namespace pf
{
	// 
	enum port_type
	{
		clallserial,
		pfremote,
		usb,
		rs232,
	};

	// 
	enum clallserial_version
	{
		no_port,
		no_dll,
		v1_0,
		v1_1
	};

	namespace convert
	{
		// 
		port_type to_port_type(int port_type)
		{
			switch (port_type)
			{
			case 0: return port_type::clallserial;
			case 1: return port_type::pfremote;
			case 2: return port_type::usb;
			case 3: return port_type::rs232;
			default: throw std::invalid_argument("port_type");
			}
		}

		// 
		clallserial_version to_clallserial_version(int clallserial_version)
		{
			switch (clallserial_version)
			{
			case 0: return clallserial_version::no_port;
			case 1: return clallserial_version::no_dll;
			case 2: return clallserial_version::v1_0;
			case 3: return clallserial_version::v1_1;
			default: throw std::invalid_argument("clallserial_version");
			}
		}
	}

	// 
	class port_info
	{
	public:
		// 
		port_info(int port) :
			port_(port)
		{
			char manufacturer_buffer[32];
			int manufacturer_buffer_size;
			char name_buffer[32];
			int name_buffer_size;
			int clallserial_version;
			int port_type;
			int result = ::pfPortInfo(port,
				manufacturer_buffer, &manufacturer_buffer_size,
				name_buffer, &name_buffer_size,
				&clallserial_version,
				&port_type);
			detail::handle_result(result);

			this->manufacturer_ = std::string(manufacturer_buffer, manufacturer_buffer_size);
			this->name_ = std::string(name_buffer, name_buffer_size);
			this->type_ = convert::to_port_type(port_type);
			this->version_ = convert::to_clallserial_version(clallserial_version);
		}

		// 
		int port() const
		{
			return this->port_;
		}

		// 
		std::string manufacturer() const
		{
			return this->manufacturer_;
		}

		// 
		std::string name() const
		{
			return this->name_;
		}

		// 
		port_type type() const
		{
			return this->type_;
		}

		// 
		clallserial_version version() const
		{
			return this->version_;
		}
	private:
		const int port_;
		std::string manufacturer_;
		std::string name_;
		clallserial_version version_;
		port_type type_;
	};
}