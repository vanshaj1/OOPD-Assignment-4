#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


class past_records_database{
  public:
     string Car_Number[500];
     string Type_of_report[500];
     string Report_Location[500];
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
                   this->Car_Number[i] = vehicleNo.substr(1,vehicleNo.length()-2);
                }else if(j == 3){
                   this->Type_of_report[i] = word;
                }else if(j == 4){
                   this->Report_Location[i] = word.substr(1,word.length()-2);
                }
                j++;
            }
            i++;
        }
     }

     int findIdx(string Vno){
        for(int i = 0;i < 500;i++){
            if(Car_Number[i] == Vno){
                return i;
            }
        }
        return -1;
     } 

    string getSourceofVoilation(string vno){
        int idx = findIdx(vno);
        if(idx == -1){
            // cout<<"\nVehicle with this vehicle no doesn't exists";
            return "NA";
        }
        return this->Type_of_report[idx]; 
    }
    string getLocationOfVoilation(string vno){
         int idx = findIdx(vno);
        if(idx == -1){
            // cout<<"\nVehicle with this vehicle no doesn't exists";
            return "NA";
        }
        return this->Report_Location[idx];
    }
};
class person{
    public:
        string name;
        string gender;
        int age;
        string address;

        friend ostream& operator<<(ostream& os,const person& p){
            os << p.name << " "<<p.gender<<" "<<p.age<<" "<<p.address;
            return os;
        }
};

class evidence{
    public:
        vector<person> witnesses;
        string type_of_source;
        string report_Location;
        string responseOfPerson;

        friend ostream& operator<<(ostream& os,const evidence& e){
            os << " 1." << e.witnesses[0] <<" 2. "<<e.witnesses[1]<<" 3."<<e.witnesses[2] <<" "<<e.type_of_source<<" "<<e.report_Location<<" "<<e.responseOfPerson;
            return os;
        }
};

class challeges_on_notices{
  public:
    vector<string> vehicle_no;
    vector<person> complainant;
    vector<evidence> evidences; 
    past_records_database pastRecords; 
    challeges_on_notices(){
      pastRecords.readFromCsv("A4-Q2.csv");  
    }

    int findIdx(string Vno){
        for(int i = 0;i < vehicle_no.size();i++){
            if(vehicle_no[i] == Vno){
                return i;
            }
        }
        return -1;
    } 
    void showDataBase(){
        for(int i = 0; i < vehicle_no.size();i++){
            cout<<"\n"<<vehicle_no[i]<<" "<<complainant[i]<<" "<<evidences[i]<<" "<<"past records:- "<<pastRecords.getSourceofVoilation(vehicle_no[i])<<" "<<pastRecords.getLocationOfVoilation(vehicle_no[i]);
        }
    }
    void getEvidences(string vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"\nRecord Not exists for this vehicle no";
            return;
        }
        cout<<evidences[idx];
    }
    void getComplianant(string vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"\nRecord Not exists for this vehicle no";
            return;
        }
        cout<<complainant[idx];
    }
    void getPastRecords(string vno){
        cout<<"\nPast records for this vehicle no "<<vno<<" is:- "<<pastRecords.getSourceofVoilation(vno)<<" "<<pastRecords.getLocationOfVoilation(vno);
    }
    void changeVehicleNo(string vno,string newVno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"\nDetails with this vehicle no does'nt exists in database";
            return;
        }
        vehicle_no[idx] = newVno;
        cout<<"\nVehicle no is update to "<<newVno<<" from "<<vno;
    }
    void changeEvidence(){
       int ch = -1;
       cout<<"\n0 - change report source\n1 - change report location\n2 - response of person\n3 - witness_1\n4 - witness_2\n5 - witness_3\n6 - Exit";
       cout<<"\nenter your choice: ";
       cin>>ch;
       switch(ch){
         case 0:{
            string vno;
            string type_of_source;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new Report Source";
            cin>>type_of_source;
            evidences[idx].type_of_source = type_of_source;
            cout<<"\nReport source has been changed for vehicle no "<<vno;
            break;
         }
         case 1:{
            string vno;
            string report_location;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new Report Location";
            cin>>report_location;
            evidences[idx].report_Location = report_location;
            cout<<"\nReport Location has been changed for vehicle no "<<vno;
            break;
         }
         case 2:{
            string vno;
            string response_of_person;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new response of the person";
            cin.ignore();
            getline(cin,response_of_person);
            evidences[idx].responseOfPerson = response_of_person;
            cout<<"\nResponse of person has been changed for vehicle no "<<vno;
            break;
         }
         case 3:{
            string vno;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            string name,address,gender;
            int age;
            cout<<"\nEnter name of the new witness 1: ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nEnter address of the new witness 1: ";
            cin.ignore();
            getline(cin,address);
            cout<<"\nEnter gender of the new witness 1: ";
            cin.ignore();
            getline(cin,gender);
            cout<<"\nEnter age of the new witness 1: ";
            cin>>age;
            if(!name.empty()){
                evidences[idx].witnesses[0].name = name;
            }
            if(!address.empty()){
                evidences[idx].witnesses[0].address = address;
            }
            if(!gender.empty()){
                evidences[idx].witnesses[0].gender = gender;
            }
            if(age > 0){
                evidences[idx].witnesses[0].age = age;
            }
            cout<<"\nWitness 1 has been updated for vehicle no "<<vno;
            break;
         }
         case 4:{
            string vno;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            string name,address,gender;
            int age;
            cout<<"\nEnter name of the new witness 2: ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nEnter address of the new witness 2: ";
            cin.ignore();
            getline(cin,address);
            cout<<"\nEnter gender of the new witness 2: ";
            cin.ignore();
            getline(cin,gender);
            cout<<"\nEnter age of the new witness 2: ";
            cin>>age;
            if(!name.empty()){
                evidences[idx].witnesses[1].name = name;
            }
            if(!address.empty()){
                evidences[idx].witnesses[1].address = address;
            }
            if(!gender.empty()){
                evidences[idx].witnesses[1].gender = gender;
            }
            if(age > 0){
                evidences[idx].witnesses[1].age = age;
            }
            cout<<"\nWitness 2 has been updated for vehicle no "<<vno;
            break;
         }
         case 5:{
            string vno;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            string name,address,gender;
            int age;
            cout<<"\nEnter name of the new witness 3: ";
            cin.ignore();
            getline(cin,name);
            cout<<"\nEnter address of the new witness 3: ";
            cin.ignore();
            getline(cin,address);
            cout<<"\nEnter gender of the new witness 3: ";
            cin.ignore();
            getline(cin,gender);
            cout<<"\nEnter age of the new witness 3: ";
            cin>>age;
            if(!name.empty()){
                evidences[idx].witnesses[2].name = name;
            }
            if(!address.empty()){
                evidences[idx].witnesses[2].address = address;
            }
            if(!gender.empty()){
                evidences[idx].witnesses[2].gender = gender;
            }
            if(age > 0){
                evidences[idx].witnesses[2].age = age;
            }
            cout<<"\nWitness 3 has been updated for vehicle no "<<vno;
            break;
         }
         case 6:{
            exit(1);
         }
       }
    }
    void changeComplainant(){
       int ch = -1;
       cout<<"\n0 - change name\n1 - change gender\n2 - change age\n3 - address\n4 - Exit";
       cout<<"\nenter your choice: ";
       cin>>ch;
       switch(ch){
         case 0:{
            string vno;
            string name;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new name : ";
            cin.ignore();
            getline(cin,name);
            complainant[idx].name = name;
            cout<<"\nComplaiant name has been changed for vehicle no "<<vno;
            break;
         }
         case 1:{
            string vno;
            string gender;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new gender : ";
            cin>>gender;
            complainant[idx].gender = gender;
            cout<<"\nComplaiant gender has been changed for vehicle no "<<vno;
            break;
         }
         case 2:{
            string vno;
            int age;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new age of the person";
            cin>>age;
            complainant[idx].age = age;
            cout<<"\nComplainant age has been changed for vehicle no "<<vno;
            break;
         }
         case 3:{
            string vno;
            string address;
            cout<<"\nEnter vno: ";
            cin>>vno;
            int idx = findIdx(vno);
            if(idx == -1){
                cout<<"\nDetails with this vehicle no does'nt exists in database";
                return;
            }
            cout<<"\nEnter new address of the person";
            cin.ignore();
            getline(cin,address);
            complainant[idx].address = address;
            cout<<"\nComplainant address has been changed for vehicle no "<<vno;
            break;
         }
         case 6:{
            exit(1);
         }
       }
    }
    void enterDetailsOfCase(string vno,string name,string gender,int age,string address,person witness1,person witness2,person witness3,string responseOfPerson,string Location,string source){
        vehicle_no.push_back(vno);
        person p;
        p.name = name;
        p.gender = gender;
        p.age = age;
        p.address = address;
        complainant.push_back(p);
        evidence e;
        e.witnesses.push_back(witness1);
        e.witnesses.push_back(witness2);
        e.witnesses.push_back(witness3);
        e.responseOfPerson = responseOfPerson;
        e.report_Location = Location;
        e.type_of_source = source;
        evidences.push_back(e);

        cout<<"\nDetails are entered in the database";
    }
};

int main(){
    challeges_on_notices dataBase;
    dataBase.showDataBase();
    while(true){
        cout<<"\nchoose from the following option:-\n0 - show challenges database\n1 - change Vehicle no\n2 - change Evidence info\n3 - change Complaiant info\n4 - Enter new challenge by a person\n5 - get past records\n6 - getComplaiant details\n7 - get evidence\n8 - exit\n";
        cout<<"\nEnter your choice:- ";
        int ch;
        cin>>ch;
        switch(ch){
            case 0:{
                dataBase.showDataBase();
                break;
            }
            case 1:{
                string vno, new_vno;
                cout<<"\nEnter Current Vehicle no: ";
                cin>>vno;
                cout<<"\nEnter New Vehcile no: ";
                cin>>new_vno;
                dataBase.changeVehicleNo(vno,new_vno);
                break;
            }
            case 2:{
                dataBase.changeEvidence();
                break;
            }
            case 3:{
                dataBase.changeComplainant();
                break;
            }
            case 4:{
                string vno, name, gender,address,responseOfPerson, Location,source;
                person witness1, witness2, witness3;
                int age;

                cout<<"Enter vehicle no: ";
                cin>>vno;
                cout<<"\nEnter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"\nEnter gender: ";
                cin>>gender;
                cout<<"\nEnter address: ";
                cin.ignore();
                getline(cin,name);

                cin.ignore();
                cout<<"\nEnter response of the person: ";
                getline(cin,responseOfPerson);

                cout<<"\nEnter Location: ";
                cin>>Location;

                cout<<"\nEnter source: ";
                cin>>source;

                cout<<"\nEnter name of witness 1: ";
                cin.ignore();
                getline(cin,witness1.name);
                cout<<"\nEnter gender of witness 1: ";
                cin>>witness1.gender;
                cout<<"\nEnter address of witness 1: ";
                cin.ignore();
                getline(cin,witness1.address);
                cout<<"\nEnter age of witness 1: ";
                cin>>witness1.age;

                cout<<"\nEnter name of witness 2: ";
                cin.ignore();
                getline(cin,witness2.name);
                cout<<"\nEnter gender of witness 2: ";
                cin>>witness2.gender;
                cout<<"\nEnter address of witness 2: ";
                cin.ignore();
                getline(cin,witness2.address);
                cout<<"\nEnter age of witness 2: ";
                cin>>witness2.age;

                cout<<"\nEnter name of witness 3: ";
                cin.ignore();
                getline(cin,witness3.name);
                cout<<"\nEnter gender of witness 3: ";
                cin>>witness3.gender;
                cout<<"\nEnter address of witness 3: ";
                cin.ignore();
                getline(cin,witness3.address);
                cout<<"\nEnter age of witness 3: ";
                cin>>witness3.age;

                dataBase.enterDetailsOfCase(vno,name,gender,age,address,witness1,witness2,witness3,responseOfPerson,Location,source);
                break;
            }
            case 5:{
                string vno;
                cout<<"\nEnter Vehicle no: ";
                cin>>vno;
                dataBase.getPastRecords(vno);
                break;
            }
            case 6:{
                string vno;
                cout<<"\nEnter Vehicle no: ";
                cin>>vno;
                dataBase.getComplianant(vno);
                break;
            }
            case 7:{
                string vno;
                cout<<"\nEnter Vehicle no: ";
                cin>>vno;
                dataBase.getEvidences(vno);
                break;
            }
            case 8:{
                exit(0);
            }
        }
    }
    return 0;
}