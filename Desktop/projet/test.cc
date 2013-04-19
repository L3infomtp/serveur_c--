#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <winsock.h>
#include <mysql/mysql.h>
using namespace std;

int main(){
  MYSQL mysql;
  mysql_init(&mysql);
  const char* option="option";
  mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,option);
  if(mysql_real_connect(&mysql,"localhost","root","azertySQL","pokerL3",0,NULL,0)){
    mysql_query(&mysql, "SELECT * FROM Utilisateur");
    MYSQL_RES * result = NULL;
    MYSQL_ROW row;
    
    unsigned int i=0;
    unsigned int nb_champs=0;
    
    result = mysql_store_result(&mysql);
    
    nb_champs=mysql_num_fields(result);

    
    while((row = mysql_fetch_row(result))){
      unsigned long *taille;
      taille=mysql_fetch_lengths(result);
      for(i=0;i<nb_champs;i++)
	{
	  if(row[i]==test){
	    printf("[%.*s] ", (int) taille[i], row[i] ? row[i] : NULL);
	  }
	}
      cout<<endl;
    }
    mysql_free_result(result);
    mysql_close(&mysql);
  }
  else{
    cout<<"Erreur"<<endl;
  }
  return 0;
}
