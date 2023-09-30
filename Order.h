#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include<vector>
#include "Book.h"
#include "Client.h"



class Order
{
private:
	std::string OdrderID;
	std::vector<Book*> OrderedBooks;
	Client OrderedClient;
public:
	void AddBook(Book Book);
	void GenerateShipment();
	Order(Book Book, Client Client);
	~Order();
};
#endif // !ORDER_H

