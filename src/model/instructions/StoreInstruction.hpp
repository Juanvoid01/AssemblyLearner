#pragma once
#include "Instruction.hpp"

class StoreInstruction : public Instruction {
public:
	int dest;
	int origin;
	OpMode originMode;
	OpMode destMode;

	StoreInstruction(int dest, int origin, OpMode originMode, OpMode destMode)
		:dest(dest), origin(origin), destMode(destMode), originMode(originMode)
	{

	}

	void execute(Ram& ram, RegisterBank& registerBank) override {

		opProcess(origin, originMode, ram, registerBank);
		opProcess(dest, destMode, ram, registerBank);


		ram.setInt(dest, origin);


	}
};
