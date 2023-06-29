#pragma once
#include "Snack.h"
#include <vector>

class SnackSlot
{
public:
	SnackSlot (int size) : MAX_SIZE{ size }, counter_Snacks_{ 0 } {};
	void addSnack(Snack *snack);
	int get_numSnacks() const;	
	void displaySnacks();
	std::vector <Snack*> get_snacks();
	void delete_snack(Snack* snack);
		
private:
	int counter_Snacks_;	
	std::vector <Snack*> snacks_;
	const int MAX_SIZE;
};