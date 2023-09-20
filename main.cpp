#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<direct.h>
#include<conio.h>

/*
* BOOK MANAGEMENT SYSTEM
* 
* Main Functions: Add Book, Delete Book, Update book, List books
* 
* Additional Function: Database of Books, Content of the Book in .txt file
*/

//Global variables
int ID = 0;


class Book
{
public:
	Book(std::string, std::string);
	~Book();

private:
	int BookID;
	std::string Name;
	std::string Author;
public:
	void Display();
	void ChangeName(std::string InputName);
	int GetID();
	void ChangeAuthor(std::string InputAuthor);
};
Book::Book(std::string InputName,std::string InputAuthor)
{
	this->Author = InputAuthor;
	this->Name = InputName;
	ID++;
	this->BookID = ID;
}
Book::~Book()
{

}
void Book::Display()
{
	std::cout << "Bood ID: " << this->BookID;
	std::cout << "\nName: " << this->Name;
	std::cout << "\nAuthor: " << this->Author;
	std::cout << "\n";

}
void Book::ChangeAuthor(std::string InputAuthor)
{
	this->Author = InputAuthor;
}
void Book::ChangeName(std::string InputName)
{
	this->Name = InputName;
}
int Book::GetID()
{
	return this->BookID;
}
//Global variable
std::vector<Book*> library;
void ListBooks()
{
	system("cls");
	std::cout << "HERE IS THE LIST OF BOOKS \n";
	for (int i = 0; i < library.size(); i++)
	{
		library[i]->Display();
		std::cout << "\n";
	}
}
void AddBook()
{
	std::string BookAuthor;
	std::string BookName;
	system("cls");
	std::cout << "PLEASE ENTER BOOK AUTHOR: ";
	std::cin.ignore(1,'\n');
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
		if(library[i]->GetID() == choice)
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
void Menu()
{
	int choice;
	while (1)
	{
		system("cls");
		std::cout << "\t\t\t\ WELCOME TO THE BOOKSHOP MANAGEMENT SYSTEM \n";
		std::cout << "\n\n\n";
		std::cout << "1. ADD BOOK \n\n";
		std::cout << "2. DELETE BOOK \n\n";
		std::cout << "3. UPDATE BOOK \n\n";
		std::cout << "4. AVAILABLE BOOKS  \n\n";
		std::cout << "5. EXIT \n\n";
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
				exit(0);
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

int main()
{
	//_mkdir("Library");
	Menu();
	//_rmdir("Library");
	return 0;
}