#include "Simulator.hpp"


Simulator::Simulator(int ramSize) {
	ram = std::make_unique<Ram>(ramSize);
	registerBank = std::make_unique<RegisterBank>();
	observers.reserve(10);
}

void Simulator::setChar(int index, char value)
{
	ram->setChar(index, value);
}

void Simulator::setInt(int index, int value)
{
	ram->setInt(index, value);
}

void Simulator::setRegisterChar(int registerNumber, char value) {
	registerBank->setChar(registerNumber,value);
}

void Simulator::setRegisterInt(int registerNumber, int value) {
	registerBank->setInt(registerNumber, value);
}

void Simulator::setPc(int value) {
	registerBank->programCounter = value;
}

void Simulator::setLr(int value) {
	registerBank->linkRegister = value;
}

void Simulator::setSp(int value) {
	registerBank->stackPointer = value;
}

void Simulator::setCPSR(RegisterFlag flag) {
	registerBank->CPSR = flag;
}

void Simulator::incrementPc() {
	registerBank->programCounter++;
}

void Simulator::addObserver(std::shared_ptr<SimulatorObserver> observer)
{
	observers.emplace_back(std::move(observer));
}
void Simulator::advance() {
	for (auto& o : observers) {
		o->onAdvance();
	}
}

void Simulator::reset() {
	for (auto& o : observers) {
		o->onReset();
	}
	ram->reset();
	registerBank->reset();
}