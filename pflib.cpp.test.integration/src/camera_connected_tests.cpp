#include "CppUnitTest.h"

#include "camera.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pflibcpptestunit
{
	TEST_CLASS(camera_connected_tests)
	{
	public:
		// 
		TEST_METHOD(check_properties)
		{
			auto ports = pf::get_ports();
			Assert::IsTrue(ports.size() > 0, L"No available ports.");
			pf::camera camera(ports[0]);
			Assert::IsTrue(camera.is_open(), L"Camera did not open successfully.");

			auto name = camera.name().get();
			auto clock = camera.pixel_clock().get();
		}
	};
}