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

public:
	LineSegment(double x1, double y1, double x2, double y2, std::string seg_id) :
		start_x{ x1 }, start_y{ y1 }, end_x{ x2 }, end_y{ y2 }, id{ seg_id }
	{
		calculateSlope();
		calculateYIntercept();
	}

	void calculateSlope()
	{
		slope = (end_y - start_y) / (end_x - start_x);
	}
	void calculateYIntercept()
	{
		yIntercept = start_y - (start_x * slope);
	}
	double getSlope()
	{
		return slope;
	}
	double getYIntercept()
	{
		return yIntercept;
	}

};