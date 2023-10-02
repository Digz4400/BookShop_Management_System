#include <iostream>
#include "Book.h"
#include "Global.h"

int ID = 0;
Book::Book(std::string InputName, std::string InputAuthor) 
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
	std::cout << this->BookID << "\t" << this->Name << "\t" << this->Author<< "\n";
}
void Book::ChangeAuthor(std::string InputAuthor)
{
	this->Author = InputAuthor;
}
std::string Book::GetName()
{
	return this->Name;
}
std::string Book::GetAuthor()
{
	return this->Author;
}
void Book::ChangeName(std::string InputName)
{
	this->Name = InputName;
}
int Book::GetID()
{
	return this->BookID;
}

