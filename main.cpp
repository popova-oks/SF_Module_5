#include "VendingMachine.h"
#include "SnackSlot.h"
#include "Snack.h"
#include <iostream>

int main(int argc, char* argv[]) 
{
	Snack* bounty = new Snack("Bounty", 20);
	Snack* snickers = new Snack("Snikers", 25);
	Snack* chips = new Snack("Chips", 40);
	Snack* choc = new Snack("Chocolate", 80);
	
	int max_num_Snacks(10);
	SnackSlot* slot_1 = new SnackSlot(max_num_Snacks);
	SnackSlot* slot_2 = new SnackSlot(max_num_Snacks);
	SnackSlot* slot_3 = new SnackSlot(max_num_Snacks);
	SnackSlot* slot_4 = new SnackSlot(max_num_Snacks);
	SnackSlot* slot_5 = new SnackSlot(max_num_Snacks);

	slot_1->addSnack(bounty);
	slot_1->addSnack(snickers);
	slot_1->addSnack(snickers);
	slot_1->addSnack(chips);
	slot_1->addSnack(choc);

	slot_2->addSnack(bounty);
	slot_2->addSnack(snickers);
	slot_2->addSnack(snickers);
	slot_2->addSnack(snickers);
	slot_2->addSnack(choc);

	slot_3->addSnack(bounty);
	slot_3->addSnack(snickers);
	slot_3->addSnack(chips);
	slot_3->addSnack(chips);
	slot_3->addSnack(choc);	

	int num_Slots(5);
	VendingMachine* maсhine = new VendingMachine(num_Slots);

	maсhine->addSlot(slot_1);
	maсhine->addSlot(slot_2);
	maсhine->addSlot(slot_3);
	maсhine->addSlot(slot_4);
	maсhine->addSlot(slot_5);

	std::cout << "\n\t\t________________VENDING MACHINE WORKING_______________\n";

	while (true)
	{
		std::cout << "\nYou can pay for the following snacks:\n";
		maсhine->display_slots();
		std::cout << "\nThe number of empty slots is: " << maсhine->getEmptySlotsCount() << "\n";

		std::cout << "\nSelect an action:  p - pay for, q - quit: ";
		char key;
		std::cin >> key;

		if (key == 'q')
			break;
		
		switch (key)
		{
		case 'p':
		{
			std::cout << "\nEnter snack name: ";
			std::string snackName;
			std::cin >> snackName;
			std::pair <Snack*, SnackSlot*> snack_pair = maсhine->give_away_Snack(snackName);
			if (snack_pair.first != nullptr)
			{
				maсhine->give_away_Slot(snack_pair.second);
				std::cout << "\nThank you, there are your snack: " << snack_pair.first->get_name() <<"\n";
				snack_pair.second->delete_snack(snack_pair.first);
				maсhine->addSlot(snack_pair.second);
			}
			else
			{
				std::cout << "\nSorry, there isn't this snack.\n";
			}
			break;
		}
		default:
		{
			std::cout << "\nPlease try again.\n";
			break;
		}
		}
	}

	delete bounty;
	delete snickers;
	delete chips;
	delete choc;

	delete slot_1;
	delete slot_2;
	delete slot_3;
	delete slot_4;
	delete slot_5;
	
	delete maсhine;
	return 0;
}