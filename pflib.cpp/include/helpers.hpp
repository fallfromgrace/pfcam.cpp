#pragma once

#include "logging\logging.hpp"
#include "pfcam.h"

#include "pf_exception.hpp"

namespace pf
{
	namespace detail
	{
		// 
		void handle_result(int result)
		{
			if (result < 0)
				throw pf_exception(result);
			else if (result > 0)
				log_warn(::pfGetErrorString(result));
		}
	}
}