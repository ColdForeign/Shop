#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class product
{
public:
	product();
	product(string name, string info, size_t quantity, size_t price);

	bool setName(string name);
	bool setInfo(string info);
	bool setQuantity(size_t quantity);
	bool setPrice(size_t price);

	string getName() const;
	string getInfo() const;
	size_t getQuantity() const;
	size_t getPrice() const;

	void operator --(int none);
	void operator ++(int none);

	void delivery(size_t quantity);
	void wholesale(size_t quantity);

	void print();

	~product();
private:
	enum Limits
	{
		MIN_NAME_LENGHT = 1,
		MAX_NAME_LENGHT = 60,

		MIN_INFO_LENGHT = 0,
		MAX_INFO_LENGHT = 200,

		MIN_PRICE = 0,
		MAX_PRICE = 4294967295,

		MIN_QUANTITY = 0,
		MAX_QUANTITY = 4294967,
	};
	string name;
	string info;
	size_t price;
	size_t quantity;
	
};
