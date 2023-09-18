#pragma once

#include "../Ram.hpp"
#include "../RegisterBank.hpp"

enum class InstructionName {
	NONE,
	ADD,
	SUB,
	LOAD,
	STORE,
	BRANCH,
	CMP,
	END,

};

enum class OpMode {
	INMEDIATE,
	REGISTER,
	MEMORY,

};
class Instruction {

public:
	
	virtual ~Instruction() = default;
	InstructionName name = InstructionName::NONE;
	virtual void execute(Ram& ram, RegisterBank& registerBank) = 0;


protected:
	void opProcess(int& op, OpMode opMode, Ram& ram, RegisterBank& registerBank) {
		if (opMode == OpMode::REGISTER) {
			op = registerBank.getInt(op);
		}
		else if (opMode == OpMode::MEMORY)
		{
			op = ram.getInt(registerBank.getInt(op));
		}
		else
		{

		}
	}
};