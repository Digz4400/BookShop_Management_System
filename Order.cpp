#include <iostream>
#include "Global.h"
#include "Order.h"
#include "Book.h"
#include "Client.h"

extern int OrderID = 0;

void Order::AddBook(Book Book)
{
	this->OrderedBooks.emplace_back(Book);
}

void Order::GenerateShipment()
{

}

Order::Order(Book Book, Client Client)
{
	OrderID++;
	this->OrderedBooks.emplace_back(Book);
	this->OrderedClient = Client;
}

Order::~Order()
{
}
