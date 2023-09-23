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
	Book(std::string, std::string);
	~Book();
	void Display();
	void ChangeName(std::string InputName);
	int GetID();
	void ChangeAuthor(std::string InputAuthor);
};
#endif // !BOOK_H

