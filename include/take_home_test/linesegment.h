#pragma once
#include <string>

class LineSegment {

private:
	std::string id;
	double start_x;
	double start_y;
	double end_x;
	double end_y;
	double slope;
	double yIntercept;

	void calculateSlope()
	{
		slope = (end_y - start_y) / (end_x - start_x);
	}
	void calculateYIntercept()
	{
		yIntercept = start_y - (start_x * slope);
	}

public:
	LineSegment(double x1, double y1, double x2, double y2, std::string seg_id) :
		start_x( x1 ), start_y( y1 ), end_x( x2 ), end_y( y2 ), id( seg_id )
	{
		calculateSlope();
		calculateYIntercept();
	}
	double getSlope()
	{
		return slope;
	}
	double getYIntercept()
	{
		return yIntercept;
	}
	double get_start_x() 
	{
		return start_x;
	}
	double get_end_x()
	{
		return end_x;
	}
	double get_start_y()
	{
		return start_y;
	}
	double get_end_y()
	{
		return end_y;
	}
	std::string get_id()
	{
		return id;
	}
	bool operator<(LineSegment line)
	{
		if (this->start_x < line.get_start_x()) return true;
		else return false;
	}

	//bool operator<=(LineSegment line)
	//{
	//	if (this->start_x < line.get_start_x() || this->start_x <= line.get_start_x()) return true;
	//	else return false;
	//}
};