#include "RegisterBank.hpp"

RegisterBank::RegisterBank(const RegisterBank& other):registerSize(other.registerSize) {
	blocks = new Block[registerSize];
	for (int i = 0; i < registerSize;i++) {
		blocks[i] = other.blocks[i];
	}
}


RegisterBank::RegisterBank(RegisterBank&& other) noexcept :registerSize(other.registerSize) {
	blocks = other.blocks;
	other.blocks = nullptr;
}

char RegisterBank::getChar(int index) {

	if (!isValid(index)) return ' ';

	// Extract the lower 8 bits as an integer value.
	int lower8Bits = static_cast<int>(blocks[index].bitmap.to_ulong() & 0xFF);

	// Cast the integer value to a char.
	return static_cast<char>(lower8Bits);
}

int RegisterBank::getInt(int index) {
	if (!isValid(index)) return 0;

	// Extract the lower 32 bits as an integer value.
	int lower32Bits = static_cast<int>(blocks[index].bitmap.to_ulong());

	return static_cast<int>(lower32Bits);
}

void RegisterBank::setChar(int index, char value) {
	if (!isValid(index)) return;

	blocks[index].type = BlockType::CHAR;
	blocks[index].bitmap.reset();

	// Set the lower 8 bits of the bitset using bitwise OR.
	blocks[index].bitmap |= static_cast<unsigned char>(value);
}

void RegisterBank::setInt(int index, int value) {
	if (!isValid(index)) return;

	blocks[index].type = BlockType::INT;
	blocks[index].bitmap.reset();

	// Set the lower 8 bits of the bitset using bitwise OR.
	blocks[index].bitmap |= static_cast<unsigned char>(value);
}

BlockType RegisterBank::getType(int index) {
	if (!isValid(index)) return BlockType::NONE;

	return blocks[index].type;
}

void RegisterBank::reset() {
	for (int i = 0; i < registerSize; i++) {
		blocks[i].type = BlockType::INT;
		blocks[i].bitmap.reset();
	}
}

//assignment operator
RegisterBank& RegisterBank::operator=(const RegisterBank& other) {

	if (this != &other) {
		delete[] blocks;
		registerSize = other.registerSize;
		blocks = new Block[registerSize];
		for (int i = 0; i < registerSize; i++) {
			blocks[i] = other.blocks[i];
		}
	}
	return *this;
}

//move operator
RegisterBank& RegisterBank::operator=(RegisterBank&& other) noexcept {

	if (this != &other) {

		registerSize = other.registerSize;
		blocks = other.blocks;
		other.blocks = nullptr;
	}

	return *this;
}