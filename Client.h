#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
class Client
{
private:
	std::string ClientName;
	std::string ClientSurename;
	std::string ClientCity;
	std::string ClientStreet;
public:
	Client();
	~Client();
};
#endif // !CLIENT_H
