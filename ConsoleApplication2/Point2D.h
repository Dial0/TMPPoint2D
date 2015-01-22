#pragma once
#include <ostream>

template <class PointType> 
class Point2D
{
public:
	PointType x, y;

	template< typename T > Point2D<PointType> operator- (const Point2D<T>& OtherPoint2D)
	{
		Point2D<PointType> rt;
		rt.x = x - OtherPoint2D.x;
		rt.y = y - OtherPoint2D.y;
		return rt;
	}

	template< typename T > Point2D<PointType> operator+ (const Point2D<T>& OtherPoint2D)
	{
		Point2D<PointType> rt;
		rt.x = x + OtherPoint2D.x;
		rt.y = y + OtherPoint2D.y;
		return rt;
	}

	template< typename T > void operator+= (const Point2D<T>& OtherPoint2D)
	{
		x += OtherPoint2D.x;
		y += OtherPoint2D.y;
	}

	template< typename T > void operator-= (const Point2D<T>& OtherPoint2D)
	{
		x -= OtherPoint2D.x;
		y -= OtherPoint2D.y;
	}

	template< typename T > Point2D(const Point2D<T>& OtherPoint2D)
	{
		x = OtherPoint2D.x;
		y = OtherPoint2D.y;
	}
	
	template< typename T, typename T2 > Point2D(const T PointX, const T2 PointY)
	{
		x = PointX;
		y = PointY;
	}

	Point2D()
	{
		x = PointType();
		y = PointType();
	}

	template < typename T > PointType ScalarMul(const Point2D<T>& OtherPoint2D)
	{
		return (x * OtherPoint2D.x) + (y * OtherPoint2D.y);
	}

	template < typename T > void ScaleBy(const T& Scale)
	{
		x *= Scale;
		y *= Scale;
	}

	std::ostream operator<<(std::ostream& output)
	{
		output << x << "," << y;
		return output;
	}

	template < typename T > bool operator==(const Point2D<T>& OtherPoint2D)
	{
		if (x == OtherPoint2D.x && y == OtherPoint2D.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template< typename T > PointType DotProd(const Point2D<T>& OtherPoint2D)
	{
		return (x*OtherPoint2D.x) + (y*OtherPoint2D.y);
	}

	template< typename T > PointType PerpDotProd(const Point2D<T>& OtherPoint2D)
	{
		return (y*OtherPoint2D.x) - (x*OtherPoint2D.y);
	}
};
