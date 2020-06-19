#include "product.h"

product::product()
{
	this->name = "";
	this->info = "";
	this->price = 0;
	this->quantity = 0;
}

product::product(string name, string info, size_t quantity, size_t price)
{
	setName(name);
	setInfo(info);
	setQuantity(quantity);
	setPrice(price);
}

bool product::setName(string name)
{
	size_t textLenght = name.length();
	size_t tempLenght = 0;
	if (!(textLenght >= MIN_NAME_LENGHT && MAX_NAME_LENGHT <= MAX_NAME_LENGHT))
		return false;
	else
		for (size_t i = 0; i < textLenght; i++)
			if ((name[i] >= '+' && name[i] <= ';') ||
				(name[i] >= 'A' && name[i] <= 'Z') ||
				(name[i] >= 'a' && name[i] <= 'z') ||
				name[i] >= ' ')
				tempLenght++;

	if (textLenght == tempLenght)
	{
		this->name = name;
		return true;
	}
	return false;
}

bool product::setInfo(string info)
{
	size_t textLenght = info.length();
	if (textLenght >= MIN_INFO_LENGHT && textLenght <= MAX_INFO_LENGHT)
	{
		this->info = info;
		return true;
	}
	else
		return false;
}

bool product::setQuantity(size_t quantity)
{
	if (quantity >= MIN_QUANTITY && quantity <= MAX_QUANTITY)
	{
		this->quantity = quantity;
		return true;
	}
	else
		return false;
}

bool product::setPrice(size_t price)
{
	if (price >= MIN_PRICE && price <= MAX_PRICE)
	{
		this->price = price;
		return true;
	}
	else
		return false;
}

string product::getName() const
{
	return this->name;
}

string product::getInfo() const
{
	return this->info;
}

size_t product::getQuantity() const
{
	return this->quantity;
}

size_t product::getPrice() const
{
	return this->price;
}

void product::operator--(int none)
{
	if (this->quantity - 1 >= MIN_QUANTITY)
		this->quantity--;
}

void product::operator++(int none)
{
	if (this->quantity + 1 <= MAX_QUANTITY)
		this->quantity++;
}

void product::delivery(size_t quantity)
{
	if (this->quantity + quantity <= MAX_QUANTITY)
		this->quantity += quantity;
}

void product::wholesale(size_t quantity)
{
	if (this->quantity - quantity >= MIN_QUANTITY)
		this->quantity -= quantity;
}

void product::print()
{
	cout << "#\tPRODUCT\t#\n";
	cout << "Name: " << this->name << endl;
	if (!this->info.empty())
		cout << "Info: " << this->info << endl;
	cout << "Cost: " << this->price << endl;
	cout << "Count: " << this->quantity << endl;
}

product::~product()
{
}