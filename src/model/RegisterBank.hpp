#pragma once

#include "Block.hpp"

enum class RegisterFlag {
	NONE,
	ZERO,
	NEGATIVE,
	POSITIVE,
};

class RegisterBank
{

public:

	int programCounter = 0;
	int linkRegister = 0;
	int stackPointer = 0;
	RegisterFlag CPSR = RegisterFlag::ZERO;

	RegisterBank() :registerSize(16) { blocks = new Block[registerSize]; }

	RegisterBank(const RegisterBank& other);

	RegisterBank(RegisterBank&& other) noexcept;

	char getChar(int index);
	int getInt(int index);
	void setChar(int index, char value);
	void setInt(int index, int value);
	BlockType getType(int index);
	size_t getSize() { return registerSize; }
	void reset();

	//assignment operator
	RegisterBank& operator=(const RegisterBank& other);

	//move operator
	RegisterBank& operator=(RegisterBank&& other) noexcept;

	~RegisterBank() { delete[] blocks; }



private:

	bool isValid(int index) { return index >= 0 && index < registerSize; }

private:


	size_t registerSize;

	Block* blocks;
};

