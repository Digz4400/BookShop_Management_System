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
	std::string Status;
public:
	void AddBook(Book Book);
	void GenerateShipment();
	void Display();
	void ChangeStatus(std::string InputStatus);
	Order(Book &Book, Client Client);
	~Order();
};
#endif // !ORDER_H

