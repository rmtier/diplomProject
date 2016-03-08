#pragma once
#include <chrono>
/*
* @file  
* @author: Rami Mtier
* @section DESCRIPTION
* Module for measuring time and memory usage
*/
class MeasureModule
{
private:
	std::chrono::high_resolution_clock::time_point startTime;
	bool running;
public:
	MeasureModule();
	virtual ~MeasureModule();
	void startMeasure();
	long stopMeasure();
};

