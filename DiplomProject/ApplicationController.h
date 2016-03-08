#pragma once
#include "ViewInterface.h"
#include "MeasureModule.h"
#include "AligmentCalculation.h"
#include "Aligment.h"
/*
* @file
* @author: Rami Mtier
* @date: 26.2.2016
* 
* @section DESCRIPTION
* Control aplication comunicate with view interface, measue module and aligment calculation
*/
class ApplicationController
{
public:
	ApplicationController();
	virtual ~ApplicationController();
	void start();
};

