#pragma once
#include "Instruction.hpp"

enum class BitWiseOp {
	OR,
	AND,
	XOR,
	NOT,
	LEFTSHIFT,
	RIGHTSHIFT
};

class BitwiseInstruction : public Instruction {
public:
	int dest;
	int op1;
	int op2;
	OpMode op1Mode;
	OpMode op2Mode;
	BitWiseOp bitWiseOp;

	BitwiseInstruction(BitWiseOp bitWiseOp, int dest, int op1, int op2, OpMode op1Mode, OpMode op2Mode)
		:dest(dest), op1(op1), op2(op2), op1Mode(op1Mode), op2Mode(op2Mode), bitWiseOp(bitWiseOp)
	{
		
	}

	void execute(Ram& ram, RegisterBank& registerBank) override {

		opProcess(op1, op1Mode, ram, registerBank);
		opProcess(op2, op2Mode, ram, registerBank);

		int value = 0;

		switch (bitWiseOp)
		{
		case BitWiseOp::OR: value = op1 | op2;
			break;
		case BitWiseOp::AND: value = op1 & op2;
			break;
		case BitWiseOp::XOR: value = op1 ^ op2;
			break;
		case BitWiseOp::NOT: value = ~op1;
			break;
		case BitWiseOp::LEFTSHIFT: value = op1 << 0;
			break;
		case BitWiseOp::RIGHTSHIFT: value = 0 >> op1;
			break;
		default: value = -1;
			break;
		}

		if (value == 0) {
			registerBank.CPSR = RegisterFlag::ZERO;
		}
		else if (value < 0) {
			registerBank.CPSR = RegisterFlag::NEGATIVE;
		}
		else if (value > 0) {
			registerBank.CPSR = RegisterFlag::POSITIVE;
		}

		registerBank.setInt(dest, value);
	}

};
