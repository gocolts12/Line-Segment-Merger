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
	double epsilon; //our precision variable for double comparisons

	void calculateSlope();

	void calculateYIntercept();


public:
	LineSegment(double x1, double y1, double x2, double y2, std::string seg_id);

	double getSlope();

	double getYIntercept();

	double get_start_x() const;
	
	double get_end_x()const;

	double get_start_y()const;

	double get_end_y()const;

	std::string get_id()const;

	bool operator<(const LineSegment &line)const;

	
	//operator == for test cases later
	bool operator==(const LineSegment& rhs)const;

};
#endif