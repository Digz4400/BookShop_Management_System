#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<direct.h>
#include<conio.h>
#include "Book.h"
#include "Client.h"

//Global variable
std::vector<Book*> library;
std::vector<Client*> DBClient;


//BookMenu Function
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


//CustomerMenu Function
void AddCustomer()
{

}
void DeleteCustomer()
{

}
void UpdateCustomer()
{

}
void ListCustomer()
{

}

//OrderMenu Function
void CreateOrder()
{

}
void ChangeStatus()
{

}
void CheckOrders()
{

}

void MenuInventory()
{
	int choice;
	while (true)
	{
		system("cls");
		std::cout << "\t\t\t\ WELCOME TO THE INVENTORY \n";
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
		std::cout << "\t\t\t\ WELCOME TO THE OORDER MENU \n";
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
		std::cout << "\t\t\t\ WELCOME TO THE CUSTOMER MENU \n";
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
		std::cout << "\t\t\t\ WELCOME TO THE BOOKSHOP MANAGEMENT SYSTEM \n";
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
			exit(0);
		}
		default:
			break;
		}
	}
}
int main()
{
	MainMenu();
	//_mkdir("Library");
	//_rmdir("Library");
	return 0;
}