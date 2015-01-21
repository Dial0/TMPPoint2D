#pragma once
#include "line.h"
#include <cstdlib>
#include "Point2D.h"

template<class PointType>
class line
{
public:
	Point2D<PointType> start;
	Point2D<PointType> end;

	bool intersect(line<PointType> compare)
	{
		inline double Dot(const Point& a, const Point& b)                        { return (a.x*b.x) + (a.y*b.y); }
		inline double PerpDot(const Point& a, const Point& b)                    { return (a.y*b.x) - (a.x*b.y); }

		bool LineCollision(const Point& A1, const Point& A2,
			const Point& B1, const Point& B2,
			double* out = 0)
		{
			Point a(A2 - A1);
			Point b(B2 - B1);

			double f = PerpDot(a, b);
			if (!f)      // lines are parallel
				return false;

			Point c(B2 - A2);
			double aa = PerpDot(a, c);
			double bb = PerpDot(b, c);

			if (f < 0)
			{
				if (aa > 0)     return false;
				if (bb > 0)     return false;
				if (aa < f)     return false;
				if (bb < f)     return false;
			}
			else
			{
				if (aa < 0)     return false;
				if (bb < 0)     return false;
				if (aa > f)     return false;
				if (bb > f)     return false;
			}

			if (out)
				*out = 1.0 - (aa / f);
			return true;
		}


	}

	//line();
	//~line();
};








template<typename T1> void Path(Point2D<T1> Start, Point2D<T1> End, std::vector<std::vector<bool>> Grid)
{

	//check 4 grid points to see which is closest
	//each grid point has a cost to avoid going back
	//only 10 previous grid points stored


}

template<typename T1> void Bresenham(Point2D<T1> Start, Point2D<T1> End, std::vector<std::vector<bool>> Grid)
{
	int x1 = Start.x;
	int y1 = Start.y;
	int x2 = End.x;
	int y2 = End.y;

	int delta_x(x2 - x1);

	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));

	delta_x = std::abs(delta_x) << 1;

	int delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	//origin

	int error;
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
		else
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