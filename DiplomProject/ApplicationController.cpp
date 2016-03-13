#include "ApplicationController.h"


ApplicationController::ApplicationController()
{
}


ApplicationController::~ApplicationController()
{
}

void ApplicationController::start()
{
	ViewInterface interface;
	AligmentCalculation calculation;
	MeasureModule measureModule;
	Aligment * aligment;
	long time;

	while (interface.continueComputing())
	{
		measureModule.startMeasure();
		aligment = calculation.calculateTask(interface.takeTask());
		time = measureModule.stopMeasure();
		interface.print(aligment, time, aligment->getAlgorithm());
		delete aligment;
	}
	return;
}