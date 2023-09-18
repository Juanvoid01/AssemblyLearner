#pragma once
#include "../model/SimulatorObserver.hpp"

class MainView : public SimulatorObserver{

public:


	MainView();

	void render();


	void onAdvance() override{}
	void onAddInstruction() override {}
	void onDeleteInstruction() override {}
	void onReset() override {}
	void onRegister() override {}
	void onMemoryChange(int index, BlockType type) override {}
	void onRegisterChange(bool specialChange, int index, BlockType type) override {}
private:

};
