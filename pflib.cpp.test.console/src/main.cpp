#include <cstdio>
#include <iostream>
#include <tchar.h>
#include "camera.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	auto ports = pf::get_ports();

	std::vector<pf::camera> cameras;

	for (const auto& port : ports)
	{
		try
		{
			pf::camera camera(port);
			cameras.push_back(std::move(camera));
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << " " << port.port() << std::endl;
		}
	}

	return 0;
}

