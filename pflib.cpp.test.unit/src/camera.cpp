#include "CppUnitTest.h"

#include "camera.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pflibcpptestunit
{
	TEST_CLASS(camera_tests)
	{
	public:

		TEST_METHOD(get_ports)
		{
			auto ports = pf::get_ports();
			for (auto port : ports)
			{
				
			}
		}

	};
}