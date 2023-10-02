#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<direct.h>
#include<conio.h>
#include "Book.h"
#include "Client.h"
#include "Order.h"

//Global variable
std::vector<Book*> library;
std::vector<Client*> DBClient;
std::vector<Order*> Orders;

//BookMenu Functions
void ListBooks()
{
	system("cls");
	std::cout << "HERE IS THE LIST OF BOOKS \n";
	std::cout << "BookID\tName\tAuthor\n";
	for (int i = 0; i < library.size(); i++)
	{
		library[i]->Display();
	}
}
void AddBook()
{
	std::string BookAuthor;
	std::string BookName;
	system("cls");
	std::cout << "PLEASE ENTER BOOK AUTHOR: ";
	std::cin.ignore(1, '\n');
	getline(std::cin, BookAuthor);
	std::cout << "PLEASE ENTER BOOK NAME: ";
	getline(std::cin, BookName);
	library.push_back(new Book(BookName, BookAuthor));

}
void DeleteBook()
{
	system("cls");
	int choice;
	ListBooks();
	std::cout << "INPUT ID OF A BOOK YOU WANT TO DELETE: ";
	std::cin >> choice;
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i]->GetID() == choice)
		{
			library[i]->Display();
			std::cout << "BOOK ERASE \n";
			library.erase(library.begin() + i);
		}
	}
}
void UpdateBook()
{
	int choice;
	std::string input;
	ListBooks();
	std::cout << "INPUT ID OF A BOOK YOU WANT TO UPDATE: ";
	std::cin >> choice;
	for (int i = 0; i < library.size(); i++)
	{
		if (library[i]->GetID() == choice)
		{
			system("cls");
			library[i]->Display();
			std::cout << "1. UPDATE AUTHOR \n";
			std::cout << "2. UPDATE NAME \n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				std::cout << "NEW AUTHOR: ";
				std::cin.ignore(1, '\n');
				std::getline(std::cin, input);
				library[i]->ChangeAuthor(input);
				std::cout << "NEW DATA \n";
				library[i]->Display();
				break;
			}
			case 2:
			{
				std::cout << "NEW NAME: ";
				std::cin.ignore(1, '\n');
				std::getline(std::cin, input);
				library[i]->ChangeName(input);
				std::cout << "NEW DATA \n";
				library[i]->Display();
				break;
			}
			default:
			{
				std::cout << "INVALID CHOICE";
			}
			}
		}
	}
}

//CustomerMenu Functions
void ListCustomer()
{
	system("cls");
	std::cout << "HERE IS THE LIST OF CUSTOMERS \n";
	std::cout << "LDAP\tClientName\tClientSurename\tClientCity\tClientStreet\n";
	for (int i = 0; i < DBClient.size(); i++)
	{
		DBClient[i]->Display();
	}
}
void AddCustomer()
{
	std::string ClientSurename;
	std::string ClientName;
	std::string ClientCity;
	std::string ClientStreet;
	system("cls");
	std::cout << "PLEASE ENTER CUSTOMER NAME: ";
	std::cin.ignore(1, '\n');
	getline(std::cin, ClientName);
	std::cout << "PLEASE ENTER CUSTOMER SURENAME: ";
	getline(std::cin, ClientSurename);
	std::cout << "PLEASE ENTER CUSTOMER CITY: ";
	getline(std::cin, ClientCity);
	std::cout << "PLEASE ENTER CUSTOMER STREET: ";
	getline(std::cin, ClientStreet);
	DBClient.push_back(new Client(ClientName, ClientSurename, ClientCity, ClientStreet));
}
void DeleteCustomer()
{
	system("cls");
	std::string choice;
	ListCustomer();
	std::cout << "INPUT LDAP OF A CUSTOMER YOU WANT TO DELETE: ";
	std::cin >> choice;
	for (int i = 0; i < DBClient.size(); i++)
	{
		if (DBClient[i]->GetLDAP() == choice)
		{
			DBClient[i]->Display();
			std::cout << "CUSTOMER ERASE \n";
			DBClient.erase(DBClient.begin() + i);
		}
	}
}
void UpdateCustomer()
{
	std::string choiceLDAP;
	std::string input;
	int choice;
	ListCustomer();
	std::cout << "INPUT LDAP OF A CUSTOMER YOU WANT TO UPDATE: ";
	std::cin >> choiceLDAP;
	for (int i = 0; i < DBClient.size(); i++)
	{
		if (DBClient[i]->GetLDAP() == choiceLDAP)
		{
			system("cls");
			DBClient[i]->Display();
			std::cout << "1. UPDATE CITY \n";
			std::cout << "2. UPDATE STREEP \n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				std::cout << "NEW CITY: ";
				std::cin.ignore(1, '\n');
				std::getline(std::cin, input);
				DBClient[i]->ChangeCity(input);
				std::cout << "NEW DATA \n";
				DBClient[i]->Display();
				break;
			}
			case 2:
			{
				std::cout << "NEW NAME: ";
				std::cin.ignore(1, '\n');
				std::getline(std::cin, input);
				DBClient[i]->ChangeStreet(input);
				std::cout << "NEW DATA \n";
				DBClient[i]->Display();
				break;
			}
			default:
			{
				std::cout << "INVALID CHOICE";
			}
			}
		}
	}
}

//OrderMenu Functions
void CreateOrder()
{

}
void ChangeStatus()
{

}
void CheckOrders()
{

}

//Menu Functions
void MenuInventory()
{
	int choice;
	while (true)
	{
		system("cls");
		std::cout << "\t\t\t WELCOME TO THE INVENTORY \n";
		std::cout << "\n\n\n";
		std::cout << "1. ADD BOOK \n\n";
		std::cout << "2. DELETE BOOK \n\n";
		std::cout << "3. UPDATE BOOK \n\n";
		std::cout << "4. AVAILABLE BOOKS  \n\n";
		std::cout << "5. RETURN \n\n";
		std::cout << "YOUR CHOICE: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1:
			{
				AddBook();
				break;
			}
			case 2:
			{
				DeleteBook();
				break;
			}
			case 3:
			{
				UpdateBook();
				break;
			}
			case 4:
			{
				ListBooks();
				break;
			}
			case 5:
			{
				return;
				break;
			}
			default: 
			{
				std::cout << "INVALID CHOICE";
				break;
			}
		}
		std::cout << "PRESS ANY KEY";
		_getch();
	}
}
void MenuOrder()
{
	int choice;
	while (true)
	{
		system("cls");
		std::cout << "\t\t\t WELCOME TO THE OORDER MENU \n";
		std::cout << "\n\n\n";
		std::cout << "1. CREATE ORDER \n\n";
		std::cout << "2. CHANGE ORDER STATUS \n\n";
		std::cout << "3. CHECK ORDERS \n\n";
		std::cout << "4. RETURN \n\n";
		std::cout << "YOUR CHOICE: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			CreateOrder();
			break;
		}
		case 2:
		{
			ChangeStatus();
			break;
		}
		case 3:
		{
			CheckOrders();
		}
		case 4:
		{
			return;
			break;
		}
		default:
			std::cout << "INVALID CHOICE";
			break;
		}

	}
}
void MenuCustomer()
{
	int choice;
	while (true)
	{
		system("cls");
		std::cout << "\t\t\t WELCOME TO THE CUSTOMER MENU \n";
		std::cout << "\n\n\n";
		std::cout << "1. ADD CUSTOMER \n\n";
		std::cout << "2. DELETE CUSTOMER \n\n";
		std::cout << "3. UPDATE CUSTOMER \n\n";
		std::cout << "4. AVAILABLE CUSTOMER  \n\n";
		std::cout << "5. RETURN \n\n";
		std::cout << "YOUR CHOICE: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			AddCustomer();
			break;
		}
		case 2:
		{
			DeleteCustomer();
			break;
		}
		case 3:
		{
			UpdateCustomer();
			break;
		}
		case 4:
		{
			ListCustomer();
			break;
		}
		case 5:
		{
			return;
			break;
		}
		default:
		{
			std::cout << "INVALID CHOICE";
			break;
		}
		}
		std::cout << "PRESS ANY KEY";
		_getch();
	}

}
void MainMenu()
{

	int choice;
	while (true)
	{
		system("cls");
		std::cout << "\t\t\t WELCOME TO THE BOOKSHOP MANAGEMENT SYSTEM \n";
		std::cout << "\n\n\n";
		std::cout << "1. CREATE ORDER \n\n";
		std::cout << "2. CUSTOMER BASE \n\n";
		std::cout << "3. INVENTORY \n\n";
		std::cout << "4. EXIT \n\n";
		std::cout << "YOUR CHOICE: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			MenuOrder();
			break;
		}
		case 2:
		{
			MenuCustomer();
			break;
		}
		case 3:
		{
			MenuInventory();
			break;
		}
		case 4:
		{
			return;
		}
		default:
			break;
		}
	}
}
int main()
{
	_mkdir("Orders");
	MainMenu();
	_rmdir("Orders");
	//AddCustomer();
	return 0;
}