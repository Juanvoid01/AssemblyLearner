#pragma once

#include <bitset>

#define BLOCK_SIZE 32

enum class BlockType {
	NONE,
	INT,
	CHAR
};


class Block {

public:

	size_t size;
	std::bitset<BLOCK_SIZE> bitmap;

	Block(): size(BLOCK_SIZE) {}

	Block(const Block& other): size(BLOCK_SIZE){ bitmap = other.bitmap; }


	Block& operator=(const Block& other) {
		if (this!=&other) {
			bitmap = other.bitmap;
		}
		return *this;
	}

	BlockType type = BlockType::INT;

};