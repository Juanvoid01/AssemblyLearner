#include "Ram.hpp"

Ram::Ram(const Ram& other) :ramSize(other.ramSize)
{
	blocks = new Block[ramSize];
	for (int i = 0; i < ramSize; i++) {
		blocks[i] = other.blocks[i];
	}
}

Ram::Ram(Ram&& other) noexcept : ramSize(other.ramSize)
{
	blocks = other.blocks;
	other.blocks = nullptr;
}

char Ram::getChar(int index) {

	if (!isValid(index)) return ' ';
		
	// Extract the lower 8 bits as an integer value.
	int lower8Bits = static_cast<int>(blocks[index].bitmap.to_ulong() & 0xFF);

	// Cast the integer value to a char.
	return static_cast<char>(lower8Bits);
}

int Ram::getInt(int index) {
	if (!isValid(index)) return 0;

	// Extract the lower 32 bits as an integer value.
	int lower32Bits = static_cast<int>(blocks[index].bitmap.to_ulong());

	return static_cast<int>(lower32Bits);
}

void Ram::setChar(int index, char value) {
	if (!isValid(index)) return;

	blocks[index].type = BlockType::CHAR;
	blocks[index].bitmap.reset();

	// Set the lower 8 bits of the bitset using bitwise OR.
	blocks[index].bitmap |= static_cast<unsigned char>(value);
}

void Ram::setInt(int index, int value) {
	if (!isValid(index)) return;

	blocks[index].type = BlockType::INT;
	blocks[index].bitmap.reset();

	// Set the lower 8 bits of the bitset using bitwise OR.
	blocks[index].bitmap |= static_cast<unsigned char>(value);
}

BlockType Ram::getType(int index) {
	if (!isValid(index)) return BlockType::NONE;

	return blocks[index].type;
}

void Ram::reset() {
	for (int i = 0; i < ramSize; i++) {
		blocks[i].type = BlockType::INT;
		blocks[i].bitmap.reset();
	}
}

//assignment operator
Ram& Ram::operator=(const Ram& other)
{
	if (this != &other) {
		delete[] blocks;
		ramSize = other.ramSize;
		blocks = new Block[ramSize];
		for (int i = 0; i < ramSize; i++) {
			blocks[i] = other.blocks[i];
		}
	}
	return *this;
}

//move operator
Ram& Ram::operator=(Ram&& other) noexcept
{
	if (this != &other) {
		ramSize = other.ramSize;
		blocks = other.blocks;
		other.blocks = nullptr;
	}
	return *this;
}

