#include "SimulatorObserver.hpp"
#include <vector>

#pragma once
class Simulator : public SimulatorObserver
{
public:
	Simulator();
	void advance();
	void reset();

private:
	void addObserver(SimulatorObserver& observer) { observers.emplace_back(observer); }
private:
	std::vector<SimulatorObserver&> observers;
};

