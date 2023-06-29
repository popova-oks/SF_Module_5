#include "VendingMachine.h"

void VendingMachine::addSlot(SnackSlot* slot)
{
	Slots_.push_back(slot);
}

void VendingMachine::display_slots()
{
	int i(0);
	for (SnackSlot* slot : Slots_)
	{
		if (slot->get_numSnacks() != 0)
		{
			i++;
			std::cout << "\nSlot - " << i << ".\n";
			slot->displaySnacks();
		}
	}	
}

int VendingMachine::getEmptySlotsCount()
{
	int i(0);
	for (SnackSlot* slot : Slots_)
	{
		if (slot->get_numSnacks() == 0)
		{
			i++;
		}
	}
	return i;
}

std::pair <Snack*, SnackSlot*>  VendingMachine::give_away_Snack(const std::string& nameSnack)
{
	SnackSlot* curr_slot = nullptr;
	Snack* curr_snack = nullptr;
	std::pair <Snack*, SnackSlot*> curr_pair{ curr_snack, curr_slot };

	for (SnackSlot* curr_slot: Slots_)
	{
		if (curr_slot->get_numSnacks() != 0)
		{
			for (Snack* curr_snack : curr_slot->get_snacks())
			{
				if (nameSnack == curr_snack->get_name())
				{
					curr_pair.first = curr_snack;
					curr_pair.second = curr_slot;
					return curr_pair;
				}
			}
		}
	}
	return curr_pair;
}

void VendingMachine::give_away_Slot(SnackSlot* slot)
{
	SnackSlot* curr_slot = nullptr;
	int i = 0;
	for (; i < Slots_.size(); i++)
	{
		curr_slot = Slots_.at(i);
		if (curr_slot == slot)
		{
			Slots_.erase(Slots_.begin()+i);
		}
	}
}

