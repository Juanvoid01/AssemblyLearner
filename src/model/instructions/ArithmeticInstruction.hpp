#pragma once
#include "Instruction.hpp"

enum class ArithmeticOp {
	ADD,
	SUB,
	MUL,
	DIV,
	ABS,
	MOD,
	INCREMENT,
	DECREMENT
};

class ArithmeticInstruction : public Instruction {
public:
	int dest;
	int op1;
	int op2;
	OpMode op1Mode;
	OpMode op2Mode;
	ArithmeticOp arithmeticOp;

	ArithmeticInstruction(ArithmeticOp arithmeticOp, int dest, int op1, int op2, OpMode op1Mode, OpMode op2Mode)
		:dest(dest), op1(op1), op2(op2), op1Mode(op1Mode), op2Mode(op2Mode), arithmeticOp(arithmeticOp)
	{

	}

	void execute(Ram& ram, RegisterBank& registerBank) override {

		opProcess(op1, op1Mode, ram, registerBank);
		opProcess(op2, op2Mode, ram, registerBank);

		int value = 0;

		switch (arithmeticOp)
		{
		case ArithmeticOp::ADD: value = op1 + op2;
			break;
		case ArithmeticOp::SUB: value = op1 - op2;
			break;
		case ArithmeticOp::MUL: value = op1 * op2;
			break;
		case ArithmeticOp::DIV: value = op1 / op2;
			break;
		case ArithmeticOp::ABS: value = op1 >= 0 ? op1 : -op1;
			break;
		case ArithmeticOp::MOD: value = op1 % op2;
			break;
		case ArithmeticOp::INCREMENT: value = op1++;
			break;
		case ArithmeticOp::DECREMENT: value = op1--;
			break;
		default:
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
