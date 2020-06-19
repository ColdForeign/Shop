#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"
#include <ctime>
using std::cout;
using std::cin;
using std::string;
using std::endl;

#define CHECK(var) ((var[i] >= 65 && var[i] <= 90) || (var[i] >= 97 && var[i] <= 122) || var[i] >= ' ')
#define CHECK_NUMBER (number[i] >= '0' && number[i] <= '9')

class user
{
public:
	user();
	user(string name, string email, string password, string phoneNumber, size_t balance);

	bool setName(string name);
	bool setPassword(string password);
	bool setEmail(string email);
	bool setPhoneNumber(string phoneNumber);
	bool setBalance(size_t balance);

	string getName() const;
	size_t getPasswordHash() const;
	string getEmail() const;
	string getPhoneNumber() const;
	size_t getBalance() const;

	string generateNum() const;
	void generateName();
	bool checkNum(string number) const;
	void operator = (const user& user);

	void refillBalance();
	~user(); 
	const size_t PHONE_SIZE = 12;
private:
	enum Limits
	{
		MIN_LEN = 8,
		MAX_LEN = 60,
		MIN_BALANCE = 1,
		MAX_BALANCE = 1000000
	};
	string name;
	string email;
	Hash password;
	string phoneNumber;
	size_t balance;
};
