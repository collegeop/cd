#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
  ifstream infile("MutiComment.cpp");
  int i;
  string line;
  int line_num = 0;
  int line_err;
  bool flag=false;
  
  while(getline(infile,line))
  {
	  line_num++;
	  if(!flag){
            for(i=0;i<line.length();i+=2){
              if(line[i]== '/' && line[i+1] == '*'){
                 flag=true;
		 line_err= line_num;
		 break;
	      }
	    }
	  }
	  if(flag){
		  for(;i<line.length();i+=2){
                   if(line[i] == '*' && line[i+1]=='/'){
                     flag = false;
		     break;
		   } 
		  }

	  }
  }
  if(!flag){
    cout<<"no error in muti comments all muticomments closed properly "<<endl;
  }else{
    cout <<"error at line : "<<line_err<<"muti comment not closed "<<endl;
  }
}
