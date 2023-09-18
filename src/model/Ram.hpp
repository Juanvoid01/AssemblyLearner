#pragma once

#include "Block.hpp"

class Ram
{
public:

	Ram(size_t ram_size):ramSize(ram_size) { blocks = new Block[ram_size]; }
	
	Ram(const Ram& other);

	Ram(Ram&& other) noexcept;

	char getChar(int index);
	int getInt(int index);
	void setChar(int index, char value);
	void setInt(int index, int value);
	BlockType getType(int index);
	size_t getSize() { return ramSize; }
	void reset();

	//assignment operator
	Ram& operator=(const Ram& other);

	//move operator
	Ram& operator=(Ram&& other) noexcept;

	~Ram() { delete[] blocks; }

private:

	bool isValid(int index) { return index >= 0 && index < ramSize; }

	Ram() :ramSize(0) { blocks = nullptr; }

private:
	
	Block* blocks;
	size_t ramSize;

};

