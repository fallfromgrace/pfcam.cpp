#pragma once

#include <cstdlib>
#include <string>

#include "includes.hpp"
#include "pfcam.h"

#include "helpers.hpp"

namespace pf
{
	namespace detail
	{
		// 
		class pfvalue_int
		{
		public:

			pfvalue_int(int32_t value = 0)
			{
				this->pfvalue.len = 0;
				this->pfvalue.type = PropertyType::PF_INT;
				this->pfvalue.value.i = static_cast<long>(value);
			}

			// 
			PFValue* get()
			{
				return &this->pfvalue;
			}

			//
			int32_t get_value() const
			{
				return static_cast<int32_t>(this->pfvalue.value.i);
			}
		private:
			PFValue pfvalue;
		};

		// 
		class pfvalue_float
		{
		public:

			pfvalue_float(float32_t value = 0)
			{
				this->pfvalue.len = 0;
				this->pfvalue.type = PropertyType::PF_FLOAT;
				this->pfvalue.value.f = static_cast<float>(value);
			}

			// 
			PFValue* get()
			{
				return &this->pfvalue;
			}

			//
			float32_t get_value() const
			{
				return static_cast<float32_t>(this->pfvalue.value.f);
			}
		private:
			PFValue pfvalue;
		};

		// 
		class pfvalue_string
		{
		public:
			pfvalue_string(size_t size = 256) : 
				pfvalue_string(std::string(size, '\0'))
			{

			}

			pfvalue_string(const std::string& value) : 
				value(value)
			{
				this->pfvalue.len = static_cast<int>(this->value.size());
				this->pfvalue.type = PropertyType::PF_STRING;
				this->pfvalue.value.p = static_cast<void*>(const_cast<char*>(this->value.c_str()));
			}

			// 
			PFValue* get()
			{
				return &this->pfvalue;
			}

			//
			std::string get_value() const
			{
				return this->value;
			}
		private:
			std::string value;
			PFValue pfvalue;
		};

		//int32_t get_int(int port, TOKEN token)
		//{
		//	pfvalue_int pfvalue;
		//	int result = pfDevice_GetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//	return pfvalue.get_value();
		//}

		//float32_t get_float(int port, TOKEN token)
		//{
		//	pfvalue_float pfvalue;
		//	int result = pfDevice_GetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//	return pfvalue.get_value();
		//}

		//std::string get_string(int port, TOKEN token)
		//{
		//	pfvalue_string pfvalue;
		//	int result = pfDevice_GetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//	return pfvalue.get_value();
		//}

		//void set(int32_t value, int port, TOKEN token)
		//{
		//	pfvalue_int pfvalue(value);
		//	int result = pfDevice_SetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//}
		//void set(float32_t value, int port, TOKEN token)
		//{
		//	pfvalue_float pfvalue(value);
		//	int result = pfDevice_SetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//}
		//void set(const std::string& value, int port, TOKEN token)
		//{
		//	pfvalue_string pfvalue(value);
		//	int result = pfDevice_SetProperty(port, token, pfvalue.get());
		//	handle_result(result);
		//}

		// 
		class property
		{
		public:
			// 
			property(int port, const std::string& name) :
				port(port), token(::pfProperty_ParseName(port, name.c_str()))
			{

			}

		protected:

			int32_t get_int() const
			{
				pfvalue_int pfvalue;
				int result = pfDevice_GetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
				return pfvalue.get_value();
			}

			float32_t get_float() const
			{
				pfvalue_float pfvalue;
				int result = pfDevice_GetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
				return pfvalue.get_value();
			}

			std::string get_string() const
			{
				pfvalue_string pfvalue;
				int result = pfDevice_GetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
				return pfvalue.get_value();
			}

			void set_int(int32_t value) const
			{
				pfvalue_int pfvalue(value);
				int result = pfDevice_SetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
			}
			void set_float(float32_t value) const
			{
				pfvalue_float pfvalue(value);
				int result = pfDevice_SetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
			}
			void set_string(const std::string& value) const
			{
				pfvalue_string pfvalue(value);
				int result = pfDevice_SetProperty(this->port, this->token, pfvalue.get());
				handle_result(result);
			}
		private:
			int port;
			TOKEN token;
		};
	}
}