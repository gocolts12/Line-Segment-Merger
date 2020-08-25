#pragma once
#include <string>
#ifndef LineSegment_H
#define LineSegment_H

class LineSegment {

private:
	std::string id;
	double start_x;
	double start_y;
	double end_x;
	double end_y;
	double slope;
	double yIntercept;

	void calculateSlope();

	void calculateYIntercept();


public:
	LineSegment(double x1, double y1, double x2, double y2, std::string seg_id);

	double getSlope();

	double getYIntercept();

	double get_start_x();
	
	double get_end_x();

	double get_start_y();

	double get_end_y();

	std::string get_id();

	bool operator<(LineSegment line);

	
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
};
#endif