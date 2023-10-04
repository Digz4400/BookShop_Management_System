#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include<vector>
#include "Book.h"
#include "Client.h"



class Order
{
private:
	std::string OrderID;
	std::vector<Book*> OrderedBooks;
	Client OrderedClient;
public:
	void AddBook(Book Book);
	void GenerateShipment();
	void Display();
	Order(Book &Book, Client Client);
	~Order();
};
#endif // !ORDER_H

