#ifndef BOOK_H
#define BOOK_H
#include<iostream>
class Book
{
private:
	int BookID;
	std::string Name;
	std::string Author;
public:
	Book() = default;
	Book(std::string, std::string);
	~Book();
	void Display();
	void ChangeName(std::string InputName);
	int GetID();
	void ChangeAuthor(std::string InputAuthor);
	std::string GetName();
	std::string GetAuthor();
};
#endif // !BOOK_H

