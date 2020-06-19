#include "shop.h"

void shop::out()
{
	this->curentUser = nullptr;
}

void shop::Menu()
{
	shop shop;
	bool menuWork = true;
	size_t temp;

	char choice;

	do
	{
		ShowMenu();

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			temp = shop.login(EnterUserData());

			if (temp == 1)
				UserMenu(shop);
			else if (temp == 2)
				AdminMenu(shop);

			break;
		case '2':
			shop.registration();
			break;
		case '0':
			menuWork = false;
			break;
		}
	} while (menuWork);

	exit(0);
}

void shop::print()
{
	system("cls");

	for (size_t i = 0; i < this->productList.getSize(); i++)
		this->productList[i].print();

	system("pause");
	system("cls");
}

void shop::ShowMenu()
{
	cout << "#\tLOGIN MENU\t#\n";
	cout << "1 - Login\n";
	cout << "2 - Registration\n";
	cout << "0 - Exit\n";
}

void shop::ShowUserMenu()
{
	cout << "#\tUSER MENU\t#\n";
	cout << "1 - Show shop\n";
	cout << "2 - Buy product\n";
	cout << "3 - Buy many products\n";
	cout << "4 - Refill balance\n";
	cout << "5 - Options\n";
	cout << "0 - Sign out\n";
}

void shop::ShowUserOptionsMenu()
{
	cout << "#\tUSER OPTIONS MENU\t#\n";
	cout << "1 - Change name";
	cout << "2 - Change email\n";
	cout << "3 - Change phone number\n";
	cout << "4 - Change password\n";
	cout << "0 - Return\n";
}

void shop::ShowAdminMenu()
{
	cout << "#\tADMIN MENU\t#\n";
	cout << "1 - Add product\n";
	cout << "2 - Remove product\n";
	cout << "3 - Edit product\n";
	cout << "4 - Options\n";
	cout << "0 - Sign out\n";
}

void shop::ShowAdminOptionsMenu()
{
	cout << "1 - Change username\n";
	cout << "2 - Change password\n";
	cout << "0 - Return\n";
}

UserData shop::EnterUserData()
{
	string email;
	string password;

	cout << "Enter email: ";
	cin >> email;
	cout << "Enter password: ";
	cin >> password;

	return { email, password };
}

void shop::UserMenu(shop& shop)
{
	bool menuWork = true;

	do
	{
		ShowUserMenu();

		char choice;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '0':
			menuWork = false;
			shop.out();
			break;
		case '1':
			shop.print();
			break;
		case '2':
			shop.buyProduct();
			break;
		case '3':
			shop.buyManyProducts();
			break;
		case '4':
			shop.refillBalance();
			break;
		case '5':
			UserOptionsMenu(shop);
			break;
		}
	} while (menuWork);

	system("cls");
	return;
}

void shop::UserOptionsMenu(shop& shop)
{
	system("cls");

	bool menuWork = true;

	do
	{
		ShowUserOptionsMenu();

		char choice;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '0':
			menuWork = false;
			break;
		case '1':
			shop.changeName();
			break;
		case '2':
			shop.changeEmail();
			break;
		case '3':
			shop.changePhone();
			break;
		case '4':
			shop.changePassword();
			break;
		}
	} while (menuWork);

	system("cls");
	return;
}

void shop::AdminMenu(shop& shop)
{
	bool menuWork = true;

	do
	{
		ShowAdminMenu();
		char choice;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '0':
			menuWork = false;
			break;
		case '1':
			shop.addProduct();
			break;
		case '2':
			shop.deleteProduct();
			break;
		case '3':
			shop.editProduct();
			break;
		case '4':
			AdminOptionsMenu();
			break;
		}
	} while (menuWork);

	system("cls");
	return;
}

void shop::AdminOptionsMenu()
{
	bool menuWork = true;

	do
	{
		ShowAdminOptionsMenu();

		char choice;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '0':
			menuWork = false;
			break;
		case '1':
			ChangeAdminName();
			break;
		case '2':
			ChangeAdminPass();
			break;
		}
	} while (menuWork);

	system("cls");
	return;
}
