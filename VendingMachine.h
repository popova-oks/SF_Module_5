#pragma once
#include <map>
#include <vector>
#include "SnackSlot.h"
#include "Snack.h"

class VendingMachine
{
public:
	VendingMachine(int num_Slots) : num_Slots_{ num_Slots }, cash_{ 0 } { };
	void addSlot(SnackSlot *slot);
	void display_slots();
	int getEmptySlotsCount();
	std::pair <Snack*, SnackSlot*> give_away_Snack(const std::string& nameSnack);
	void give_away_Slot(SnackSlot* slot);	
	
private:
	int num_Slots_;
	int cash_;
	std::vector <SnackSlot*> Slots_;	
};

