#include<iostream>
#include"ClientC.h"
using namespace std;

int main(int argc, char* argv[]){
  cout<<"test"<<endl;
  ClientC c= ClientC(argv[1]);
  c.lanceClient();
}
