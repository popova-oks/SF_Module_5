#pragma once
#include <iostream>
#include <string>

class Snack
{
public:
	Snack(const std::string& snackName, int price) : name_{ snackName }, price_{ price } {};
	std::string get_name() const;
	int get_price() const;

private:
	std::string name_;
	int price_;
};

