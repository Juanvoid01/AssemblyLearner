#include "Simulator.hpp"


Simulator::Simulator() {

}

void Simulator::advance() {
	for (auto& o : observers) {
		o.onAdvance();
	}
}

void Simulator::reset() {
	for (auto& o : observers) {
		o.onReset();
	}
}