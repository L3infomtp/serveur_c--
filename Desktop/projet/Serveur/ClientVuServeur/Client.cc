
using namespace std;
#include "Client.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Constructeurs////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Client::Client(){
  descClient=0;
  nom="";
  argent=0;
}
Client::Client(int desc){
  descClient=desc;
  nom="";
  argent=0;
}
Client::Client(int desc, string nomClient,int argentReel){
  descClient=desc;
  nom=nomClient;
  argent=argentReel;
}
Client::Client(int desc,
	       string nom,
	       int argent,
	       string email,
	       string dOB,
	       string gender,
	       string lName,
	       string fName,
	       string adress,
	       string city,
	       string zipCode,
	       string country){
  this->descClient=desc;
  this->nom=nom;
  this->argent=argent;
  this->email=email;
  this->dOB=dOB;
  this->gender=gender;
  this->lName=lName;
  this->fName=fName;
  this->adress=adress;
  this->city=city;
  this->zipCode=zipCode;
  this->country=country;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Assceseurs///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Client::getDescClient()const{return descClient;}
string Client::getNom()const{return nom;}
int Client::getArgent()const{return argent;}
string Client::getEmail()const{return email;}
string Client::getDOB()const{return dOB;}
string Client::getGender()const{return gender;}
string Client::getLName()const{return lName;}
string Client::getFName()const{return fName;}
string Client::getAdress()const{return adress;}
string Client::getCity()const{return city;}
string Client::getZipCode()const{return zipCode;}
string Client::getCountry()const{return country;}

void Client::setArgent(const int argent){this->argent=argent;}
void Client::setEmail(const string email){this->email=email;}
void Client::setDOB(const string dOB){this->dOB=dOB;}
void Client::setGender(const string gender){this->gender=gender;}
void Client::setLName(const string lName){this->lName=lName;}
void Client::setFName(const string fName){this->fName=fName;}
void Client::setAdress(const string adress){this->adress=adress;}
void Client::setCity(const string city){this->city=city;}
void Client::setZipCode(const string zipCode){this->zipCode=zipCode;}
void Client::setCountry(const string country){this->country=country;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
