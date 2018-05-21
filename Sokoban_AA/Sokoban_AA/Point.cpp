#include "Point.h"

Point::Point()	
{

}

Point::Point(int x, int y) 
{
	m_x = x;
	m_y = y;
}

int Point::get_x()
{
	return m_x;
}

int Point::get_y()
{
	return m_y;
}

/*Point& Point::operator= (const Point& point) 
{
	m_x = point.m_x;
	m_y = point.m_y;
	return *this;
}*/

Point& Point::operator+(const Point & point)
{
	Point res;
	res.m_x = m_x + point.m_x;
	res.m_y = m_y + point.m_y;
	return res;
}
