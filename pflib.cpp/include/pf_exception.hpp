#pragma once

#include <stdexcept>

#include "pfcam.h"

namespace pf
{
	// 
	class pf_exception : public std::runtime_error
	{
	public:
		// 
		pf_exception(int error) :
			error_(error),
			runtime_error(::pfGetErrorString(error))
		{

		}

		// 
		int error() const
		{
			return this->error_;
		}
	private:
		int error_;
	};
}