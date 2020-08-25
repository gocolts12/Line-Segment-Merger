#pragma once
#include <string>
#include "linesegment.h"

	//std::string id;
	//double start_x;
	//double start_y;
	//double end_x;
	//double end_y;
	//double slope;
	//double yIntercept;

	LineSegment::LineSegment(double x1, double y1, double x2, double y2, std::string seg_id) :
	start_x(x1), start_y(y1), end_x(x2), end_y(y2), id(seg_id)
	{
		calculateSlope();
		calculateYIntercept();
	}

	void LineSegment::calculateSlope()
	{
		slope = (end_y - start_y) / (end_x - start_x);
	}
	void LineSegment::calculateYIntercept()
	{
		yIntercept = start_y - (start_x * slope);
	}

	double LineSegment::getSlope()
	{
		return slope;
	}
	double LineSegment::getYIntercept()
	{
		return yIntercept;
	}
	double LineSegment::get_start_x()
	{
		return start_x;
	}
	double LineSegment::get_end_x()
	{
		return end_x;
	}
	double LineSegment::get_start_y()
	{
		return start_y;
	}
	double LineSegment::get_end_y()
	{
		return end_y;
	}
	std::string LineSegment::get_id()
	{
		return id;
	}
	bool LineSegment::operator<(LineSegment line)
	{
		if (this->start_x < line.get_start_x()) return true;
		else return false;
	}

	//operator == for test cases later
	//bool operator==(LineSegment line)
	//{
	//	if (this->start_x == line.get_start_x() && this->start_y == line.get_start_y() &&
	//		this->end_x == line.get_end_x() && this->end_y == line.get_end_y())
	//		return true;
	//	else
	//		return false;
	//}

	//bool operator<=(LineSegment line)
	//{
	//	if (this->start_x < line.get_start_x() || this->start_x <= line.get_start_x()) return true;
	//	else return false;
	//}
