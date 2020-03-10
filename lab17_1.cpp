//Write your code here
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

string Toupper(string t){
    string x;
    for(int i=0;i<t.size();i++){
        if(t[i]>=97 && t[i]<=133)
            x+=t[i] - 32;
        else
            x+=t[i];
    }
    return x;
}


int main(){
    ifstream inputfile("name_score.txt");
    string line;
    vector<string>v_name;
    char format[]="%[^:]:%d %d %d";
    char name[100];
    string n;
    int a,b,c;
    int i=0;
    vector<string>grade;
    vector<string> vh_name;
    string vh;
   
    while(getline(inputfile,line)){

        int result = 0;
        char GPA;

       sscanf(line.c_str(),format,name,&a,&b,&c);
       v_name.push_back(name);

       result = a+b+c;

        if(result>=80)      grade.push_back("A");
        else if(result>=70)   
        grade.push_back("B");
        else if(result>=60)
        grade.push_back("C");
        else if(result>=50)
        grade.push_back("D");
        else grade.push_back("F");

    }

    for(int i = 0; i<v_name.size(); i++){

        while(true){
        vh = Toupper(v_name[i]);
        i++;
        if(i==v_name.size())break;
    }
    }
     
    while(true){
    string command;
    cout<<"Please input your command :";
    getline(cin,command);
    string na;
    for(int i = 0; i<command.size(); i++){

        while(true){
        na = Toupper(command);
        i++;
        if(i==command.size())break;
    }
    }
    
    int idx = command.find_first_of(" ");
    string command1= Toupper(command.substr(0,idx));

    string command2= Toupper(command.substr(idx+1,command1.size()));
 
    if(command1=="NAME"){

        for(int i=0;i<v_name.size();i++){
            if(vh_name[i]==command2)
            cout<<v_name[i]<<"'s grade "<<grade[i]<<endl;
        }
    }
    else if(command1=="GRADE")
        for(int i=0; i<v_name.size(); i++){

            if(grade[i] == command2){

                cout<<v_name[i]<<endl;
            }
        }
    else if(command1=="EXIT") break;
    else cout<<"Invalid command. "<<endl;
    }
    


    return 0;
}

