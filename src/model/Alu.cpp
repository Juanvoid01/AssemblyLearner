#pragma once

#include "Alu.hpp"

Alu::Alu() {
	instructions.reserve(100);

}


void Alu::execute(int programCounter, Ram& ram, RegisterBank& registerBank) {
	if (validPC(programCounter))
	{
		instructions[programCounter]->execute(ram, registerBank);
	}
}

void Alu::add(std::unique_ptr<Instruction> instruction) {
	instructions.emplace_back(std::move(instruction));
}

void Alu::swap(int instruction1, int instruction2) {

}

void Alu::remove(int instructionNumber) {

}

bool Alu::validPC(int programCounter) {
	return programCounter > 0 && programCounter < instructions.size();
}


