#pragma once

#include "SimulatorObserver.hpp"
#include <vector>
#include <memory>
#include "Ram.hpp"
#include "RegisterBank.hpp"
#include "Alu.hpp"

class Simulator
{
public:
	Simulator(int ramSize);
	void advance();
	void reset();

	//ram
	char getChar(int index) { return ram->getChar(index); }
	int getInt(int index) { return ram->getInt(index); }
	void setChar(int index, char value);
	void setInt(int index, int value);
	int getRamSize() { return static_cast<int>(ram->getSize()); }
	BlockType getType(int index) { return ram->getType(index); }

	//registerBank
	char getRegisterChar(int index) { return registerBank->getChar(index); }
	int getRegisterInt(int index) { return registerBank->getInt(index); }
	void setRegisterChar(int registerNumber, char value);
	void setRegisterInt(int registerNumber, int value);
	int getRegisterSize() { return static_cast<int>(registerBank->getSize()); }
	BlockType getRegisterType(int index) { return registerBank->getType(index); }
	void setPc(int value);
	void setLr(int value);
	void setSp(int value);
	void setCPSR(RegisterFlag flag);
	void incrementPc();
	int getPc() { return registerBank->programCounter; }
	int getLr(){ return registerBank->linkRegister; }
	int getSp(){ return registerBank->stackPointer; }
	RegisterFlag getCPSR(){ return registerBank->CPSR; }

private:
	void addObserver(std::shared_ptr<SimulatorObserver> observer);
private:

	std::vector<std::shared_ptr<SimulatorObserver>> observers;
	std::unique_ptr<Ram> ram;
	std::unique_ptr<Alu> alu;
	std::unique_ptr<RegisterBank> registerBank;
	Simulator();

};

