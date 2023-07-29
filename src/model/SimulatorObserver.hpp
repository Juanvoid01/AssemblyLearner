#pragma once
class SimulatorObserver
{
public:
	virtual void onAdvance() = 0;
	virtual void onAddInstruction() = 0;
	virtual void onDeleteInstruction() = 0;
	virtual void onReset() = 0;
	virtual void onRegister() = 0;
};

