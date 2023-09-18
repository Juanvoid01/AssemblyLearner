#pragma once

#include <vector>
#include "instructions/Instruction.hpp"
#include <memory>

class Alu
{
public:

	Alu();

	void execute(int programCounter, Ram& ram, RegisterBank& registerBank);

	void add(std::unique_ptr<Instruction> instruction);
	void swap(int instruction1, int instruction2);
	void remove(int instructionNumber);
	bool validPC(int programCounter);

private:
	std::vector<std::unique_ptr<Instruction>> instructions;
};

