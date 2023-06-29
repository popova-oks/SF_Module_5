#include "SnackSlot.h"

void SnackSlot::addSnack(Snack* snack)
{	
	if (snacks_.size() < MAX_SIZE)
	{
		snacks_.push_back(snack);
		counter_Snacks_++;
	}
	else
	{
		std::cout << "Slot is full. Snack can't add.\n";
	}
}

int SnackSlot::get_numSnacks() const
{
	return counter_Snacks_;
}

void SnackSlot::displaySnacks()
{
	if (!snacks_.empty())
	{
		std::cout << "The number of snacks is: " << counter_Snacks_ << ".\n";
		for (Snack* snack: snacks_)
		{
			std::cout << "\tSnack: " << snack->get_name() << " - price: " << snack->get_price() << " rub, " << "\n";
		}
	}
}

std::vector<Snack*> SnackSlot::get_snacks()
{
	return snacks_;
}

void SnackSlot::delete_snack(Snack* snack)
{
	Snack* curr_snack = nullptr;
	for (int i = 0; i < snacks_.size(); i++)
	{
		curr_snack = snacks_.at(i);
		if (curr_snack == snack)
		{
			snacks_.erase(snacks_.begin() + i);
			counter_Snacks_--;
			return;
		}
	}
}
