#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include<string.h>
using namespace std;
class Client{
 private:
  int descClient;
  string nom;
  int argent;
  string email;
  string dOB;
  string gender;
  string lName;
  string fName;
  string adress;
  string city;
  string zipCode;
  string country;

 public:
  Client();
  Client(int);
  Client(int,string,int);
  Client(int,string,int,string,string,string,string,string,string,string,string,string);
  
  int getDescClient()const;
  string getNom()const;
  int getArgent()const;
  string getEmail()const;
  string getDOB()const;
  string getGender()const;
  string getLName()const;
  string getFName()const;
  string getAdress()const;
  string getCity()const;
  string getZipCode()const;
  string getCountry()const;

  void setArgent(const int);
  void setEmail(const string);
  void setDOB(const string);
  void setGender(const string);
  void setLName(const string);
  void setFName(const string);
  void setAdress(const string);
  void setCity(const string);
  void setZipCode(const string);
  void setCountry(const string);
 
 
  
};
#endif
