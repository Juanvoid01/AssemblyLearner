#pragma once
#include "Instruction.hpp"

class CompareInstruction : public Instruction {
public:

	int op1;
	int op2;
	OpMode op1Mode;
	OpMode op2Mode;

	CompareInstruction(int op1, int op2, OpMode op1Mode, OpMode op2Mode)
		:op1(op1), op2(op2), op1Mode(op1Mode), op2Mode(op2Mode)
	{

	}

	void execute(Ram& ram, RegisterBank& registerBank) override {

		opProcess(op1, op1Mode, ram, registerBank);
		opProcess(op2, op2Mode, ram, registerBank);

		int value = op1 - op2;

		if (value == 0) {
			registerBank.CPSR = RegisterFlag::ZERO;
		}
		else if (value < 0) {
			registerBank.CPSR = RegisterFlag::NEGATIVE;
		}
		else if (value > 0) {
			registerBank.CPSR = RegisterFlag::POSITIVE;
		}
	}
};
