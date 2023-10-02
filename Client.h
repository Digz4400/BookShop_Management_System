#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
class Client
{
private:
	std::string LDAP;
	std::string ClientName;
	std::string ClientSurename;
	std::string ClientCity;
	std::string ClientStreet;
public:
	Client() = default;
	Client(std::string Name,std::string SureName,std::string City,std::string Street);
	~Client();
	void CreateLogin();
	void Display();
	std::string GetClientName();
	std::string GetClientSurename();
	std::string GetClientCity();
	std::string GetClientStreet();
	std::string GetLDAP();
	void ChangeCity(std::string);
	void ChangeStreet(std::string);
};
#endif // !CLIENT_H
