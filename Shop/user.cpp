#include "user.h"

user::user()
{
	this->name = "";
	this->password;
	this->email = "";
	this->phoneNumber = "";
	this->balance = 0;
}

user::user(string name, string email, string password, string phoneNumber, size_t balance)
{
	setName(name);
	setPassword(password);
	setEmail(email);
	setPhoneNumber(phoneNumber);
	setBalance(balance);
}

bool user::setName(string name)
{
	int tempLenght = 0;
	size_t nameLenght = name.length();
	for (size_t i = 0; i < nameLenght; i++)
		if (CHECK(name))
			tempLenght++;

	if (nameLenght == tempLenght)
	{
		this->name = name;
		return true;
	}
	return false;
}

bool user::setPassword(string password)
{
	int tempLenght = 0;
	size_t passwordLenght = password.length();

	if (passwordLenght < MIN_LEN || passwordLenght > MAX_LEN)
		return false;
	for (size_t i = 0; i < passwordLenght; i++)
		if ((password[i] >= '!' && password[i] <= '}') && password[i] != ' ')
			tempLenght++;

	if (passwordLenght == tempLenght)
	{
		this->password.setHash(password);
		return true;
	}
	return false;
}

bool user::setEmail(string email)
{
	int tempLenght = 0;
	size_t emailLenght = email.length();
	if (email.find("@gmail.com") == -1)
		return false;

	for (size_t i = 0; i < emailLenght; i++)
	{
		if ((email[i] >= '0' && email[i] <= '9') &&
			(email[i] >= '@' && email[i] <= 'Z') &&
			(email[i] >= 'a' && email[i] <= 'z') && email[i] != ' ')
			tempLenght++;
	}
}

bool user::setPhoneNumber(string phoneNumber)
{
	if (phoneNumber == "NONE")
	{
		this->phoneNumber = "NONE";
		return true;
	}
	if (this->checkNum(phoneNumber))
	{
		this->phoneNumber = phoneNumber;
		return true;
	}
	return false;
}

bool user::setBalance(size_t balance)
{
	if (balance > MIN_BALANCE && balance <= MAX_BALANCE)
	{
		this->balance = balance;
		return true;
	}
	return false;
}

string user::getName() const
{
	return this->name;
}

size_t user::getPasswordHash() const
{
	return this->password.getHash();
}

string user::getEmail() const
{
	return this->email;
}

string user::getPhoneNumber() const
{
	return this->phoneNumber;
}

size_t user::getBalance() const
{
	return this->balance;
}

string user::generateNum() const
{
	srand(unsigned(time(nullptr)));

	string number;
	number += "380";

	switch (rand() % 13)
	{
	case 0:
		number += "73";
		break;
	case 1:
		number += "67";
		break;
	case 2:
		number += "68";
		break;
	case 3:
		number += "66";
		break;
	case 4:
		number += "50";
		break;
	case 5:
		number += "63";
		break;
	case 6:
		number += "99";
		break;
	case 7:
		number += "98";
		break;
	case 8:
		number += "95";
		break;
	case 9:
		number += "97";
		break;
	case 10:
		number += "96";
		break;
	case 11:
		number += "93";
		break;
	case 12:
		number += "39";
		break;
	}

	for (size_t i = 0; i < 7; i++)
		number += char(rand() % 10 + 48);

	return number;
}

void user::generateName()
{
	size_t numNames;
	string tempName;
	std::ifstream file("names.txt");

	if (!file.is_open())
	{
		this->name = "No name";
		return;
	}

	numNames = rand() % 40 + 1;
	for (int i = 0; i < numNames; i++)
		getline(file, tempName);
	file.close();
	setName(tempName);

}

bool user::checkNum(string number) const
{
	if (number.length() != PHONE_SIZE)
		return false;

	size_t count = 0;

	for (size_t i = 0; i < PHONE_SIZE; i++)
		if (CHECK_NUMBER)
			count++;

	if (count == PHONE_SIZE)
		return true;

	return false;
}

void user::operator=(const user& user)
{
	setName(user.getName());
	setEmail(user.getEmail());
	this->password = user.getPasswordHash();
	setPhoneNumber(user.getPhoneNumber());
}

void user::refillBalance()
{
	size_t money;
	bool correct = false;
	cout << "Enter quantity of money: ";
	do
	{
		cin >> money;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again:\n";
			correct = false;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			correct = true;
		}
	} while (!correct);
	setBalance(getBalance() + money);
}

user::~user()
{
}
