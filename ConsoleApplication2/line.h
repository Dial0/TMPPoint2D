#pragma once
#include "line.h"
#include <cstdlib>
#include "Point2D.h"

template<class PointType>
class Line
{
public:
	Point2D<PointType> start;
	Point2D<PointType> end;

	bool intersects(Line<PointType> compare)
	{
		Point2D<PointType> a(end - start);
		Point2D<PointType> b(compare.end - compare.start);
		PointType f = a.PerpDotProd(b);

		if (!f)
		{
			return false;
		}

		Point2D<PointType> c(compare.end - end);
		PointType aa = a.PerpDotProd(c);
		PointType bb = b.PerpDotProd(c);

		if (f < 0)
		{
			if (aa > 0 || bb > 0 || aa < f || bb < f)
			{
				return false;
			}
		}
		else
		{
			if (aa < 0 || bb < 0 || aa > f || bb > f)
			{
				return false;
			}
		}

		return true;
	}
};

template<typename T1> void Path(Point2D<T1> Start, Point2D<T1> End, std::vector<std::vector<bool>> Grid)
{
	//check 4 grid points to see which is closest
	//each grid point has a cost to avoid going back
	//only 10 previous grid points stored
}

template<typename T> void Bresenham(Line<T> Line, std::vector<std::vector<bool>> Grid)
{
	T x1 = Line.Start.x;
	T y1 = Line.Start.y;
	T x2 = Line.End.x;
	T y2 = Line.End.y;

	T delta_x(x2 - x1);

	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));

	delta_x = std::abs(delta_x) << 1;

	T delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	T error;
	bool shallow;
	if (delta_x >= delta_y)
	{
		shallow = true;
		// error may go below zero
		error = (delta_y - (delta_x >> 1));
	}
	else
	{
		shallow = false;
		// error may go below zero
		error = (delta_x - (delta_y >> 1));
	}

	bool loop = true;
	while (loop)
	{

		Grid[x1][y1] = true;

		if (shallow)
		{
			if ((error >= 0) && (error || (ix > 0)))
			{
				error -= delta_x;
				y1 += iy;
			}
			// else do nothing

			error += delta_y;
			x1 += ix;

			if (x1 == x2)
			{
				loop = false;
			}
		}
		else //tall
		{
			if ((error >= 0) && (error || (iy > 0)))
			{
				error -= delta_y;
				x1 += ix;
			}
			// else do nothing

			error += delta_x;
			y1 += iy;

			if (y1 == y2)
			{
				loop = false;
			}
		}
	}
}