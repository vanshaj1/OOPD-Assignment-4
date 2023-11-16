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
            cout<<"Vehicle with this vehicle no doesn't exists";
            return "NA";
        }
        return this->Type_of_report[idx]; 
    }
    string getLocationOfVoilation(string vno){
         int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
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
            cout << " 1." << e.witnesses[0] <<" 2. "<<e.witnesses[1]<<" 3."<<e.witnesses[2] <<" "<<e.type_of_source<<" "<<e.report_Location<<" "<<e.responseOfPerson;
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
        for(int i = 0;i < 500;i++){
            if(vehicle_no[i] == Vno){
                return i;
            }
        }
        return -1;
    } 
    void showDataBase(){
        for(int i = 0; i < vehicle_no.size();i++){
            cout<<vehicle_no[i]<<" "<<complainant[i]<<" "<<evidences[i]<<" "<<"past records:- "<<pastRecords.getSourceofVoilation(vehicle_no[i])<<" "<<pastRecords.getLocationOfVoilation(vehicle_no[i]);
        }
    }
    void getEvidences(string vno){
        int idx = findIdx(vno);
        cout<<evidences[idx];
    }
    void getComplianant(string vno){
        int idx = findIdx(vno);
        cout<<complainant[idx];
    }
    void getPastRecords(string vno){
        cout<<"Past records for this vehicle no "<<vno<<" is:- "<<pastRecords.getSourceofVoilation(vno)<<" "<<pastRecords.getLocationOfVoilation(vno);
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
    }
};

int main(){
    challeges_on_notices dataBase;
    dataBase.showDataBase();
    // while(true){
    //     cout<<"choose from the following option:-\n0 - show vehicles voilation's database\n1 - change Vehicle no\n2 - change source of report\n3 - change location of voilation\n4 - get details of voilation\n5 - get source of report\n6 - get location of voilation\n7 - exit\n";
    //     cout<<"Enter your choice:- ";
    //     int ch;
    //     cin>>ch;
    //     switch(ch){
    //         case 0:{
    //             identifier.showDataBase();
    //             break;
    //         }
    //         case 1:{
    //             string vno, new_vno;
    //             cout<<"Enter Current Vehicle no: ";
    //             cin>>vno;
    //             cout<<"Enter New Vehcile no: ";
    //             cin>>new_vno;
    //             identifier.changeVehicleNo(vno,new_vno);
    //             break;
    //         }
    //         case 2:{
    //             string vno, source;
    //             cout<<"Enter Vehicle no: ";
    //             cin>>vno;
    //             cout<<"Enter New Source of report: ";
    //             cin>>source;
    //             identifier.changeSource(vno,source);
    //             break;
    //         }
    //         case 3:{
    //             string vno, location;
    //             cout<<"Enter Vehicle no: ";
    //             cin>>vno;
    //             cout<<"Enter New Location of report: ";
    //             cin>>location;
    //             identifier.changeLocation(vno,location);
    //             break;
    //         }
    //         case 4:{
    //             string vno;
    //             cout<<"Enter Vehicle no: ";
    //             cin>>vno;
    //             identifier.getDetailsOfVoilation(vno);
    //             break;
    //         }
    //         case 5:{
    //             string vno;
    //             cout<<"Enter Vehicle no: ";
    //             cin>>vno;
    //             identifier.getSourceofVoilation(vno);
    //             break;
    //         }
    //         case 6:{
    //             string vno;
    //             cout<<"Enter Vehicle no: ";
    //             cin>>vno;
    //             identifier.getLocationOfVoilation(vno);
    //             break;
    //         }
    //         case 7:{
    //             exit(0);
    //         }
    //     }
    // }
    return 0;
}