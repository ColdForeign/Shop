#pragma once
#include "product.h"
#include "List.h"
#include "user.h"

struct UserData
{
	string email;
	string password;
};

class shop
{
public:
	shop();

	void addUser(user newUser);
	bool deleteUser(string email, string password);

	// product
	int searchProduct(string name);
	void buyProduct();
	void buyManyProducts();

	// user
	bool registration();
	size_t login(UserData userData);
	int searchUser(string email);
	void refillBalance();

	// change user data
	void changeName();
	void changeEmail();
	void changePassword();
	void changePhone();
	
	// menu other func
	void out();
	static void Menu();
	void print();

	~shop();

private:
	List<product>productList;
	List<user>usersList;
	user* curentUser = nullptr;

	//show
	static void ShowMenu();
	static void ShowUserMenu();
	static void ShowUserOptionsMenu();
	static void ShowAdminMenu();
	static void ShowAdminOptionsMenu();

	//other
	static UserData EnterUserData();
	static void UserMenu(shop& shop);
	static void UserOptionsMenu(shop& shop);
	static void AdminMenu(shop& shop);
	static void AdminOptionsMenu();

	//admin panel
	bool addProduct();
	bool deleteProduct();
	bool editProduct();
	static void ChangeAdminName();
	static void ChangeAdminPass();
	void buy(user* curentUser, List<product>& productList, size_t index);
};


