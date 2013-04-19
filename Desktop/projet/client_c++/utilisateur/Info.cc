#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Info.h"
using namespace std;
////////////////////Constructeur////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Info::Info():nom(""){}
Info::Info(const string name):nom(name){}
Info::Info(const char* information){
  int i=0;
  int positionDebut=0;
  while(information[i]!='&'){
    i++;
  }
  char pseudoChar[20]="";
  strncpy(pseudoChar,information,i);
  nom=string(pseudoChar);
  i++;
  positionDebut=i;
  while(information[i]!='&'){
    i++;
  }
  char argentChar[20]="";
  strncpy(argentChar,information+positionDebut,i);
  argent=atof(argentChar);
  i++;
  for(int j=0;j<8;j++){
    positionDebut=i;
    while(information[i]!='&'){
      i++;
    }
    char aConvertirEnString[100]="";
    strncpy(aConvertirEnString,information+positionDebut,i-positionDebut);
    switch(j){
    case 0:
      {
	email=string(aConvertirEnString);
	break;
      }
    case 1:
      {
	dOB=string(aConvertirEnString);
      break;
      }
    case 2:
      {
	gender=string(aConvertirEnString);
	break;
      }
    case 3:
      {
	lName=string(aConvertirEnString);
	break;
      }
    case 4:
      {
	fName=string(aConvertirEnString);
	break;
      }
    case 5:
      {
	adress=string(aConvertirEnString);
	break;
      }
    case 6:
      {
	city=string(aConvertirEnString);
	break;
      }
    case 7:
      {
	zipCode=string(aConvertirEnString);
	break;
      }
    } 
    i++;
  }
  char convertirPays[100]="";
  strncpy(convertirPays,information+i,strlen(information));
  country=string(convertirPays);
  cout<<country<<endl;
  
  
}
/**********************************************************************************************************************************************************************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Assceseurs///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string Info::getNom()const{return nom;}
float Info::getArgent()const{return argent;}
string Info::getEmail()const{return email;}
string Info::getDOB()const{return dOB;}
string Info::getGender()const{return gender;}
string Info::getLName()const{return lName;}
string Info::getFName()const{return fName;}
string Info::getAdress()const{return adress;}
string Info::getCity()const{return city;}
string Info::getZipCode()const{return zipCode;}
string Info::getCountry()const{return country;}

void Info::setArgent(const float argent){this->argent=argent;}
void Info::setEmail(const string email){this->email=email;}
void Info::setDOB(const string dOB){this->dOB=dOB;}
void Info::setGender(const string gender){this->gender=gender;}
void Info::setLName(const string lName){this->lName=lName;}
void Info::setFName(const string fName){this->fName=fName;}
void Info::setAdress(const string adress){this->adress=adress;}
void Info::setCity(const string city){this->city=city;}
void Info::setZipCode(const string zipCode){this->zipCode=zipCode;}
void Info::setCountry(const string country){this->country=country;}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////Methode d'affichage/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string Info::toString()const{
  string affiche="Votre pseudo est "+getNom()+". Votre adresse email est: "+getEmail()+".Vous vous appelez "+getLName()+" "+getFName()+" née le "+getDOB()+". Vous vivez en "+getCountry()+" à la ville de "+getCity()+" qui à comme code postale "+getZipCode()+". Votre adresse est "+getAdress()+" et vous êtes un/une "+getGender();
							    
  return affiche;
  
}

/**********************************************************************************************************************************************************************************************************************************************/
