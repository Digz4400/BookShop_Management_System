#ifndef ORDER_H
#define ORDER_H
#include "Book.h"
#include "Client.h"

extern int OrderID = 0;

class Order
{
private:
	std::string OdrderID;
	Book OrderedBook;
	Client OrderedClient;
public:
	void GenerateShipment();
	Order(Book &Book, Client Client);
	~Order();
};
#endif // !ORDER_H

