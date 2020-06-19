#include "shop.h"

shop::shop()
{
}

void shop::addUser(user newUser)
{
	this->usersList.push_back(newUser);
}

bool shop::deleteUser(string email, string password)
{
	if (this->usersList.getSize() > 0)
	{
		size_t index = searchUser(email);

		if (index == -1)
		{
			cout << "User not found\n";
			return false;
		}

		Hash temp(password);

		if (this->usersList[index].getPasswordHash() == temp.getHash())
		{
			this->usersList.remove(index);
			cout << "Remove successfully\n";
		}
	}
}

bool shop::addProduct()
{
	product tempProduct;
	string tempStr;
	size_t tempNum;
	bool correct = false;

	cout << "Enter name of product (min 1 symbols, max 60):\n";
	do
	{
		getline(cin, tempStr);
		if (!tempProduct.setName(tempStr))
		{
			cout << "Error! Enter name of product again\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter info of product\n(optional, just click \"Enter\") (max 200 symbols):\n";
	do
	{
		getline(cin, tempStr);
		if (tempStr == "\n")
		{
			tempProduct.setInfo("");
				correct = true;
		}
		if (!tempProduct.setInfo(tempStr))
		{
			cout << "Error! Enter info of product again\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter price of product (min 0, max 4 294 967 295):\n";
	do
	{
		cin >> tempNum;
		if (!tempProduct.setPrice(tempNum))
		{
			cout << "Error! Enter price of product again\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter quantity of product (min 0, max 4 294 967):\n";
	do
	{
		cin >> tempNum;
		if (!tempProduct.setQuantity(tempNum))
		{
			cout << "Error! Enter quantity of product again\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	this->productList.push_back(tempProduct);
	return correct;
}

int shop::searchProduct(string name)
{
	for (size_t i = 0; i < this->productList.getSize(); i++)
		if (this->productList[i].getName() == name)
			return i;

	return -1;
}

void shop::buyProduct()
{
	string title;
	cout << "Enter product title: ";
	cin >> title;

	size_t index = searchProduct(title);

	if (index == -1)
	{
		system("cls");
		cout << "Product not found\n";
		system("pause");
		system("cls");
		return;
	}

	buy(this->curentUser, this->productList, index);

}


void shop::buyManyProducts()
{
	string title;
	size_t count;

	cout << "Enter product title: ";
	cin >> title;

	cout << "enter product quantity: ";
	cin >> count;

	size_t index = searchProduct(title);

	if (index == -1)
	{
		system("cls");
		cout << "Product not found\n";
		system("pause");
		system("cls");
		return;
	}

	for (size_t i = 0; i < count; i++)
		buy(this->curentUser, this->productList, index);
}

bool shop::editProduct()
{
	string name;

	cout << "Enter the name of the product you want to change: \n";
	getline(cin, name);

	size_t index = searchProduct(name);

	if (index == -1)
	{
		system("cls");
		cout << "Product not found!\n";
		system("pause");
		system("cls");
		return false;
	}

	string tempStr;
	size_t tempNum;
	bool correct = false;
	cout << "Enter new name of product (min 1 symbols, max 60):\n";
	do
	{
		getline(cin, tempStr);
		if (!this->productList[index].setName(tempStr))
		{
			cout << "Error! Enter new name of product again:\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter new info of product\n(optional, just click \"Enter\") (max 200 symbols):\n";
	do
	{
		getline(cin, tempStr);
		if (tempStr == "\n")
		{
			this->productList[index].setInfo("");
			correct = true;
		}
		if (!this->productList[index].setInfo(tempStr))
		{
			cout << "Error! Enter new info of product again: \n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter new price of product (min 0, max 4 294 967 295):\n";
	do
	{
		cin >> tempNum;
		if (!this->productList[index].setPrice(tempNum))
		{
			cout << "Error! Enter new price of product again:\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	cout << "Enter new quantity of product (min 0, max 4 294 967):\n";
	do
	{
		cin >> tempNum;
		if (!this->productList[index].setQuantity(tempNum))
		{
			cout << "Error! Enter new quantity of product again:\n";
			correct = false;
		}
		else
			correct = true;
	} while (!correct);
	return correct;
}

bool shop::deleteProduct()
{
	string name;

	cout << "Enter the name of the product you want to delete: \n";
	getline(cin, name);

	size_t index = searchProduct(name);

	if (index == -1)
	{
		system("cls");
		cout << "Product not found!\n";
		system("pause");
		system("cls");
		return false;
	}
	this->productList.remove(index);
	return true;
}

bool shop::registration()
{
	string tempStr = "";
	user tempUser;
	bool correct;
	system("cls");

	correct = false;
	cout << "Enter name: \n";
	do
	{
		getline(cin, tempStr);

		if (!tempUser.setName(tempStr))
		{
			correct = false;
			cout << "Error! Enter name again: \n";
		}
		else
			correct = true;
	} while (!correct);

	system("cls");
	correct = false;
	cout << "Enter email (@gmail.com): \n";
	do
	{
		getline(cin, tempStr);
		if (!tempUser.setEmail(tempStr))
		{
			correct = false;
			cout << "Error! Enter email again: \n";
		}
		else
			correct = true;
	} while (!correct);

	system("cls");
	correct = false;
	cout << "Enter password(min 8 symbol, max 60 symbols): \n";
	do
	{
		getline(cin, tempStr);
		if (!tempUser.setPassword(tempStr))
		{
			correct = false;
			cout << "!Error! Password does not match, enter password again: \n";
		}
		else
			correct = true;
	} while (!correct);

	system("cls");
	correct = false;
	cout << "Repeat password: \n";
	do
	{
		getline(cin, tempStr);
		Hash tempHash(tempStr);
		if (tempHash.getHash() != tempUser.getPasswordHash())
		{
			correct = false;
			cout << "!Error! Passwords do not match, try again: \n";
		}
		else
			correct = true;
	} while (!correct);

	system("cls");
	correct = false;
	cout << "Enter phone number(withot \"+\")\n(optional, just click \"Enter\"): \n";
	do
	{
		getline(cin, tempStr);
		if (tempStr == "")
		{
			tempUser.setPhoneNumber("NONE");
			correct = true;
			break;
		}
		if (!tempUser.setPhoneNumber(tempStr))
		{
			correct = false;
			cout << "!Error! enter phone again: \n";
		}
		else
			correct = true;
	} while (!correct);
	return correct;
}

size_t shop::login(UserData userData)
{
	system("cls");

	ifstream file("config.cfg");
	string adminName;
	size_t adminHash;
	file >> adminName;
	file >> adminHash;

	if (adminName == userData.email)
	{
		Hash hash(userData.password);

		if (hash.getHash() == adminHash)
		{
			cout << "Admin login successfully\n"; // потім буде адмін панель запускатися
			system("pause");
			system("cls");
			return 2;
		}
		return 0;
	}
	else
	{
		size_t index = searchUser(userData.email);

		if (index == -1)
		{
			cout << "User not found\n";
			system("pause");
			system("cls");
			return 0;
		}

		Hash temp(userData.password);

		if (this->usersList[index].getPasswordHash() == temp.getHash())
		{
			cout << "Login successfully\n";
			this->curentUser = &usersList[index];
			system("pause");
			system("cls");
			return 1;
		}
	}

	file.close();
}

int shop::searchUser(string email)
{
	for (size_t i = 0; i < this->usersList.getSize(); i++)
		if (this->usersList[i].getEmail() == email)
			return i;

	return -1;
}

void shop::refillBalance()
{
	this->curentUser->refillBalance();
}

void shop::changePassword()
{
	system("cls");
	bool correct = false;
	string tempStr;
	cout << "Enter new password(min 8 symbol, max 60 symbols): \n";
	do
	{
		getline(cin, tempStr);
		if (!this->curentUser->setPassword(tempStr))
		{
			correct = false;
			cout << "!Error! New password does not match, enter password again: \n";
		}
		else
			correct = true;
	} while (!correct);
}

void shop::changeEmail()
{
	system("cls");
	bool correct = false;
	string tempStr;
	cout << "Enter new email (@gmail.com): \n";
	do
	{
		getline(cin, tempStr);
		if (!this->curentUser->setEmail(tempStr))
		{
			correct = false;
			cout << "Error! Enter new email again: \n";
		}
		else
			correct = true;
	} while (!correct);
}

void shop::changeName()
{
	
	system("cls");
	string tempStr;
	bool correct;
	cout << "Enter new name: \n";
	do
	{
		getline(cin, tempStr);

		if (!this->curentUser->setName(tempStr))
		{
			correct = false;
			cout << "Error! Enter new name again: \n";
		}
		else
			correct = true;
	} while (!correct);

}

void shop::changePhone()
{
	system("cls");
	string tempStr;
	bool correct;
	cout << "Enter new phone number(withot \"+\")\n(optional, just click \"Enter\"): \n";
	do
	{
		getline(cin, tempStr);
		if (tempStr == "\n")
		{
			this->curentUser->setPhoneNumber("NONE");
			correct = true;
			break;
		}
		if (!this->curentUser->setPhoneNumber(tempStr))
		{
			correct = false;
			cout << "!Error! Enter new phone number again: \n";
		}
		else
			correct = true;
	} while (!correct);
}


void shop::ChangeAdminName()
{
	ifstream fileIn("config.cfg");
	string adminName;
	string adminHash;
	fileIn >> adminName;
	fileIn >> adminHash;

	fileIn.close();

	ofstream fileOut("config.cfg");

	cout << "Enter new admin name: ";
	cin >> adminName;

	fileOut << adminName << endl;
	fileOut << adminHash << endl;

	fileOut.close();
}

void shop::ChangeAdminPass()
{
	ifstream fileIn("config.cfg");
	string adminName;
	string adminHash;
	fileIn >> adminName;

	fileIn.close();

	ofstream fileOut("config.cfg");
	string tempStr;

	cout << "Enter new admin pass: ";
	getline(cin, tempStr);
	Hash tempHash(tempStr);

	fileOut << adminName << endl;
	fileOut << tempHash.getHash() << endl;

	fileOut.close();
}

void shop::buy(user* curentUser, List<product>& productList, size_t index)
{
	if (curentUser->getBalance() >= productList[index].getPrice() && productList[index].getQuantity() > 0)
	{
		curentUser->setBalance(curentUser->getBalance() - productList[index].getPrice());
		productList[index]--;
		cout << "Product was buyed!!\n";
		system("pause");
		system("cls");
		return;
	}

	cout << "You don`t have a lot of money or shop don`t have products\n";
	system("pause");
	system("cls");
	return;
}

shop::~shop()
{
}
