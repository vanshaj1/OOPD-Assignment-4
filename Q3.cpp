#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class registered_Vehicles{
  public:
     string Vehicle_Number[999];
     string FirstName[1000];
     string LastName[1000];
     string gender[1000];
     string address[1000];
     int age[1000];
     void readFromCsv(string filename){
        string line;
        ifstream file(filename);
        getline(file,line);
        int i = 0;
        while(getline(file,line)){
            stringstream s(line);
            string word;
            int j = 1;
            string vehicleNo = "";
            while(getline(s,word,',')){
                if(j == 1){
                    vehicleNo += word;
                }else if(j == 2){
                    vehicleNo += word;
                    this->Vehicle_Number[i] = vehicleNo;
                }else if(j == 3){
                    this->FirstName[i] = word;
                }else if(j == 4){
                    this->LastName[i] = word;
                }else if(j == 5){
                    this->age[i] = stoi(word);
                }else if(j == 6){
                    this->gender[i] = word;
                }else if(j == 7){
                    this->address[i] = word;
                }
                j++;
            }
            i++;
        }
     }
     int findIdx(string Vno){
        for(int i = 0;i < 1000;i++){
            if(Vehicle_Number[i] == Vno){
                return i;
            }
        }
        return -1;
     }  
     void showDataBase(){
        for(int i = 0; i < 1000;i++){
            cout<<Vehicle_Number[i]<<" "<< FirstName[i]<<" "<< LastName[i]<<" "<< age[i]<<" "<< gender[i]<<" "<< address[i]<<endl;
        }
     }
};


class probable_address_Identifier{
  public:
    string FirstName[500];
    string LastName[500];
    string gender[500];
    string address[500];
    int age[500];
    registered_Vehicles registeredVehicleDb;
    probable_address_Identifier(){
       registeredVehicleDb.readFromCsv("A4-Q1.csv");
    }
     void readFromCsv(string filename){
        string line;
        ifstream file(filename);
        getline(file,line);
        int i = 0;
        while(getline(file,line)){
            stringstream s(line);
            string word;
            int j = 1;
            string vehicleNo = "";
            while(getline(s,word,',')){
                if(j == 1){
                    this->FirstName[i] = word;
                }else if(j == 2){
                    this->LastName[i] = word;
                }else if(j == 3){
                    this->age[i] = stoi(word);
                }else if(j == 4){
                    this->gender[i] = word;
                }else if(j == 5){
                    this->address[i] = word;
                }
                j++;
            }
            i++;
        }
     }
     vector<int> findIdx(string FirstName,string LastName){
        vector<int> indices;
        for(int i = 0;i < 500;i++){
            if(this->FirstName[i] == FirstName && this->LastName[i] == LastName){
                indices.push_back(i);
            }
        }
        return indices;
     }  
     void get_probable_address(string vno){
        int idx = registeredVehicleDb.findIdx(vno);
        string FirstName = registeredVehicleDb.FirstName[idx];
        string LastName = registeredVehicleDb.LastName[idx];
        vector<int> indices = this->findIdx(FirstName,LastName);
        cout<<"\nProbable addresses is:- ";
        for(int i = 0;i<indices.size();i++){
            cout<<"\n"<<this->address[i];
        }
    }
     void changeEntry(string vno,string fname, string lname, string gender , string addr, int age){
        int idx = registeredVehicleDb.findIdx(vno);
        string FirstName = registeredVehicleDb.FirstName[idx];
        string LastName = registeredVehicleDb.LastName[idx];
        int Age = registeredVehicleDb.age[idx];
        string Gender = registeredVehicleDb.gender[idx];
        vector<int> indices = this->findIdx(FirstName,LastName);
        for(int i = 0;i<500;i++){
            if(this->FirstName[i] == FirstName && this->LastName[i] == LastName && this->gender[i] == Gender && this->age[i] == Age){
                if(!fname.empty()){
                    this->FirstName[i] = fname;
                }
                if(!lname.empty()){
                    this->LastName[i] = lname;
                }
                if(!gender.empty()){
                    this->gender[i] = gender;
                }
                if(!addr.empty()){
                    this->address[i] = addr;
                }
                if(age > 0){
                     this->age[i] = age;
                }
                cout<<"\nNow the new entry is:- "<<" First Name: "<<this->FirstName[i]<<" Last Name: "<<this->LastName[i]<<" Gender: "<<this->gender[i]<<" address: "<<this->address[i]<<" age: "<<this->age[i]<<endl;
            }
        }
     }
     void showDataBase(){
        cout<<" | "<< "FirstName" <<" | "<< "LastName" <<" | "<< "age" <<" | "<< "gender" <<" | "<<"address"<<endl;
        for(int i = 0; i < 500;i++){
            cout<<" | "<< FirstName[i]<<" | "<< LastName[i]<<" | "<< age[i]<<" | "<< gender[i]<<" | "<< address[i]<<endl;
        }
     }
};

int main(){
    probable_address_Identifier probableDatabase;
    probableDatabase.readFromCsv("A4-Q3.csv");
    while(true){
        cout<<"\nchoose from the following option:-\n0 - show reference database\n1 - change Entry in database\n2 - get probable addresses\n3 - exit\n";
        cout<<"Enter your choice:- ";
        int ch;
        cin>>ch;
        switch(ch){
            case 0:{
                probableDatabase.showDataBase();
                break;
            }
            case 1:{
                string vno, fname,lname,address,gender;
                int age;
                cout<<"\nEnter Vehicle no: ";
                cin>>vno;
                cin.ignore();
                cout<<"\nEnter First name: ";
                getline(cin,fname);
                cin.ignore();
                cout<<"\nEnter Last name: ";
                getline(cin,lname);

                cin.ignore();
                cout<<"\nEnter gender: ";
                getline(cin,gender);

                cin.ignore();
                cout<<"\nEnter address: ";
                getline(cin,address);

                cout<<"\nEnter age: ";
                cin>>age;
                probableDatabase.changeEntry(vno,fname,lname,gender,address,age);
                break;
            }
            case 2:{
                string vno, source;
                cout<<"\nEnter Vehicle no: ";
                cin>>vno;
                probableDatabase.get_probable_address(vno);
                break;
            }
            case 3:{
                exit(0);
            }
        }
    }
    return 0;
}