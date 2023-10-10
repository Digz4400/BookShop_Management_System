#include <iostream>
#include<fstream>
#include "Global.h"
#include "Order.h"
#include "Book.h"
#include "Client.h"

extern int OrderNumberID = 0;

void Order::AddBook(Book Book)
{
	this->OrderedBooks.emplace_back(&Book);
}
Order::Order(Book& Book, Client Client)
{
	OrderNumberID++;
	this->OrderedBooks.emplace_back(&Book);
	this->OrderedClient = Client;
	this->OrderID = "Order";
	this->OrderID += char(OrderNumberID);
	this->Status = "NEW";
}
void Order::GenerateShipment()
{
	std::string filename;
	filename = this->OrderID;
	filename += ".txt";
	std::ofstream outputfile(filename);
	outputfile << "Personal infomation: /n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n";
	outputfile << "Ordered Books: /n";
	for (auto i : this->OrderedBooks)
	{
		outputfile << i->GetID() << "/n" << i->GetName() << "/n" << i->GetAuthor() << "/n/n";
	}
	outputfile.close();
}

void Order::Display()
{
	std::cout << "Personal infomation: /n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n" << this->OrderedClient.GetClientName() << "/n";
	for (auto i : this->OrderedBooks)
	{
		std::cout << i->GetID() << "/n" << i->GetName() << "/n" << i->GetAuthor() << "/n/n";
	}
	std::cout << "Status: " << this->Status << "/n/n";
}

void Order::ChangeStatus(std::string InputStatus)
{
	this->Status = InputStatus;
	std::cout << "Order: " << this->OrderID << "/n";
	std::cout << "New Status: " << this->Status << "/n/n";
}

Order::~Order()
{
}
