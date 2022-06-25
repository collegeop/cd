#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int  main()
{
   ifstream infile("file1.txt");

    string line;
    int line_num=0;
    int line_err;
    int i;
    bool flag = false;
    
    while(getline(infile,line)){
     line_num++;
     if(!flag){
         for(i=0;i<line.length();i++)
	 {
          
	   if(line[i] =='"')
	   {		 
              flag = true;
	      line_err= line_num;
	      break;
	   }

	 }
     }
     i++;
     if(flag){
       for(;i<line.length();i++){
           if(line[i] == '"'){
 		flag = false;
		break;

	   } 
       }
     }


    }
    if(!flag){
     cout<<"no error at line "<<line_num<<" :: string vaild"<<endl;
    }else{
     cout<<"string opened at : "<<line_err<<"but not closeed \n"<<endl;
    }
}
