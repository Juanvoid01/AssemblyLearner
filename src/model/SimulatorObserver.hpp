#pragma once
#include "Block.hpp"

class SimulatorObserver
{
public:
	virtual void onAdvance() = 0;
	virtual void onAddInstruction() = 0;
	virtual void onDeleteInstruction() = 0;
	virtual void onReset() = 0;
	virtual void onRegister() = 0;
	virtual void onMemoryChange(int index, BlockType type) = 0;
	virtual void onRegisterChange(bool specialChange, int index, BlockType type) = 0;
	virtual ~SimulatorObserver() = default;
};

