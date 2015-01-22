#include <vector>
#include "Point.h"
#include <map>
#include <ctime>
#include <Windows.h>
#include <stdint.h>
#include <omp.h>
#include <iostream>
#include "Point2D.h"
#include "line.h"
#include <future>
#include <thread>


bool checking(std::vector<std::vector<bool>> grid)
{
	Point2D<int> cen(10, 10);

	for (size_t s = 0; s < 2; s++)
	{
		for (size_t i = 0; i < 20; i++)
		{
			if (s == 0)
			{

			}
			else
			{

			}
		}
	}
	return true;
}


void main()
{



	std::vector<std::vector<bool>> grid;

	grid.resize(20);
	for (size_t i = 0; i < 20; i++)
	{
		grid[i].resize(20);
		for (size_t j = 0; j < 20; j++)
		{
			if ((j == 5 || j == 15) && (i > 5 && i < 15))
			{
				grid[i][j] = true;
			}
			else
			{
				grid[i][j] = false;
			}
		}
	}

	std::future<bool> future = std::async(checking, grid);

	while (true)
	{
		auto start = omp_get_wtime();

		if (future.wait_for(std::chrono::nanoseconds(0)) == std::future_status::ready)
		{
			break;
		}

		auto end = omp_get_wtime();

		auto time = end - start;

		std::cout << "Time: " << time << std::endl;

	}
}