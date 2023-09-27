#include<iostream>
#include<string>
#include<algorithm>
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
	this->LDAP = ClientName[0];
	this->LDAP += ClientSurename[0];
	this->LDAP += "_";
	this->LDAP += std::to_string(ClientID);
	std::transform(LDAP.begin(), LDAP.end(), LDAP.begin(), ::toupper);
}

void Client::Display()
{
	std::cout << this->LDAP << "\t" << this->ClientName << "\t" << this->ClientSurename << "\t" << this->ClientCity << "\t" << this->ClientStreet << "\n";
}

std::string Client::GetLDAP()
{
	return this->LDAP;
}

void Client::ChangeCity(std::string City)
{
	this->ClientCity = City;
}

void Client::ChangeStreet(std::string Street)
{
	this->ClientStreet = Street;
}
