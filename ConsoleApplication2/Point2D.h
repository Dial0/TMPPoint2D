#pragma once
#include <ostream>

template <class PointType> 
class Point2D
{
public:
	PointType x, y;

	template<typename T1> Point2D<PointType> operator- (const Point2D<T1>& OtherPoint2D)
	{
		x -= OtherPoint2D.y;
		y -= OtherPoint2D.y;
		return *this;
	}

	template<typename T2> Point2D<PointType> operator+ (const Point2D<T2>& OtherPoint2D)
	{
		x += OtherPoint2D.y;
		y += OtherPoint2D.y;
		return *this;
	}

	template<typename T3> void operator+= (const Point2D<T3>& OtherPoint2D)
	{
		x += OtherPoint2D.x;
		y += OtherPoint2D.y;
	}

	template<typename T4> Point2D(const Point2D<T4>& OtherPoint2D)
	{
		x = OtherPoint2D.x;
		y = OtherPoint2D.y;
	}
	template<typename T8, typename T9>
	Point2D(const T8 PointX, const T9 PointY)
	{
		x = PointX;
		y = PointY;
	}

	Point2D()
	{
		x = PointType();
		y = PointType();
	}

	template < typename T5 > PointType ScalarMul(const Point2D<T5>& OtherPoint2D)
	{
		return x * OtherPoint2D.x + y * OtherPoint2D.y;
	}

	template < typename T6 > void ScaleBy(const T6& Scale)
	{
		x *= Scale;
		y *= Scale;
	}

	template < typename T7 > std::ostream operator<<(std::ostream& output)
	{
		output << x << "," << y;
		return output;
	}

	template < typename T8 > bool operator==(const Point2D<T8>& OtherPoint2D)
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

};
