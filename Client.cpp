#include<iostream>
#include<string>
#include "Client.h"
#include "Global.h"

int ClientID = 0;

Client::Client(std::string Name, std::string SureName, std::string City, std::string Street)
{
	this->ClientCity = City;
	this->ClientStreet = Street;
	this->ClientName = Name;
	this->ClientSurename = SureName;
	CreateLogin();
}

Client::~Client()
{
}

void Client::CreateLogin()
{
	ClientID++;
	this->LDAP = std::strcat(&this->ClientName.front(), &this->ClientSurename[0]) + std::to_string(ClientID);
	std::cout << this->LDAP + " " + this->ClientName[0]+ " " + this->ClientName[0];
}

void Client::Display()
{
	std::cout << this->LDAP << "\t" << this->ClientName << "\t" << this->ClientSurename << this->ClientCity << "\t" << this->ClientStreet << "\n";
}

std::string Client::GetLDAP()
{
	return this->LDAP;
}
