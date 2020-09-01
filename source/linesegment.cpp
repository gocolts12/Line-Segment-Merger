#pragma once
#define _USE_MATH_DEFINES

#include <string>
#include "linesegment.h"
#include <cmath>
#include <utility>
#include <math.h>
#include <limits>


	LineSegment::LineSegment(double x1, double y1, double x2, double y2, std::string seg_id) :
	start_x(x1), start_y(y1), end_x(x2), end_y(y2), id(seg_id)
	{
		calculateSlope();
		calculateYIntercept();
		epsilon = 0.00001;
	}

	void LineSegment::calculateSlope()
	{
		//We need to be able to account for undefined slopes, so in lieu 
		//if a placeholder variable, we can use infinity
		if (end_x - start_x == 0) slope = std::numeric_limits<double>::infinity();
		else slope = (end_y - start_y) / (end_x - start_x);
	}
	void LineSegment::calculateYIntercept()
	{
		//If the slope is undefined, likewise make the y-intercept infinity
		if (slope == std::numeric_limits<double>::infinity()) yIntercept = std::numeric_limits<double>::infinity();
		else yIntercept = start_y - (start_x * slope);
	}

	double LineSegment::getSlope()
	{
		return slope;
	}
	double LineSegment::getYIntercept()
	{
		return yIntercept;
	}
	double LineSegment::get_start_x() const
	{
		return start_x;
	}
	double LineSegment::get_end_x() const
	{
		return end_x;
	}
	double LineSegment::get_start_y() const
	{
		return start_y;
	}
	double LineSegment::get_end_y() const
	{
		return end_y;
	}
	std::string LineSegment::get_id() const
	{
		return id;
	}
	bool LineSegment::operator<(const LineSegment &line) const
	{
		//Returns the definitely lesser value with precision of 0.00001
		return (line.get_start_x() - start_x) > ((fabs(start_x) < fabs(line.get_start_x()) ? fabs(line.get_start_x()) : fabs(start_x)) * epsilon);
	}

	//operator == for test cases later
	bool LineSegment::operator==(const LineSegment& line) const
	{
		return (start_x == line.get_start_x() && start_y == line.get_start_y() &&
			end_x == line.get_end_x() && end_y == line.get_end_y());

	}