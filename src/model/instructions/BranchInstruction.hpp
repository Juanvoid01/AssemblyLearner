#pragma once
#include "Instruction.hpp"

enum class BranchOp {
	B,
	BEQ,
	BNE,
	BGT,
	BLT,
	BGE,
	BLE,
	BL
};

class BranchInstruction : public Instruction {
public:
	int direction;
	BranchOp branchOp;
	OpMode dirMode;

	BranchInstruction(BranchOp branchOp, int direction, OpMode dirMode)
		:direction(direction), branchOp(branchOp), dirMode(dirMode)
	{

	}

	void execute(Ram& ram, RegisterBank& registerBank) override {


		opProcess(direction, dirMode, ram, registerBank);
		
		bool jump = false;

		switch (branchOp)
		{
		case BranchOp::B: jump = true;
			break;
		case BranchOp::BEQ: jump = registerBank.CPSR == RegisterFlag::ZERO ? true : false;
			break;
		case BranchOp::BNE: jump = registerBank.CPSR != RegisterFlag::ZERO ? true : false;
			break;
		case BranchOp::BGT: jump = registerBank.CPSR == RegisterFlag::POSITIVE ? true : false;
			break;
		case BranchOp::BLT: jump = registerBank.CPSR == RegisterFlag::NEGATIVE ? true : false;
			break;
		case BranchOp::BGE: jump = registerBank.CPSR == RegisterFlag::NEGATIVE ? false : true;
			break;
		case BranchOp::BLE: jump = registerBank.CPSR == RegisterFlag::POSITIVE ? false : true;
			break;
		case BranchOp::BL:  jump = true; registerBank.linkRegister = registerBank.programCounter;
			break;
		default:
			break;
		}
		if (jump) {
			registerBank.programCounter = direction;
		}
	}

};
