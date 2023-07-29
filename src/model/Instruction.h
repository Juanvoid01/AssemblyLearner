#pragma once

#define _UNITIALIZE -2147483648;

enum class InstructionName {
	NONE,
	ADD,
	SUB,
	LOAD,
	STORE,
	B,
	BEQ,
	BNE,
	BGT,
	BLT,
	CMP,
	END

};

struct Instruction {

	int op1 = _UNITIALIZE;
	int op2 = _UNITIALIZE;
	int op3 = _UNITIALIZE;

	InstructionName name = InstructionName::NONE;

};