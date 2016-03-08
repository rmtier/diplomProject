#include "MeasureModule.h"


MeasureModule::MeasureModule()
{
	running = false;
}


MeasureModule::~MeasureModule()
{
}

void MeasureModule::startMeasure()
{
	running = true;
	startTime = std::chrono::high_resolution_clock::now();
}

long MeasureModule::stopMeasure()
{
	if (!running) 
		return NULL;
	std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	running = false;
	return duration;
}