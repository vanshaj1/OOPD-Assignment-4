#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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


class Voilation_Identifier{
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

    void changeVehicleNo(string vno,string new_vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->Car_Number[idx] = new_vno;
        cout<<"Vehicle Number "<<vno<<" has been updated to "<<new_vno<<endl;
        cout<<"Now the new entry is:- "<<this->Car_Number[idx]<<" "<<this->Type_of_report[idx]<<" "<<this->Report_Location[idx]<<endl;
     }

    void changeSource(string vno,string source){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->Type_of_report[idx] = source;
        cout<<"Type of report has been updated for vehicle no "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Car_Number[idx]<<" "<<this->Type_of_report[idx]<<" "<<this->Report_Location[idx]<<endl;
     }

    void changeLocation(string vno,string Location){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->Report_Location[idx] = Location;
         cout<<"Report Location has been updated for vehicle no "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Car_Number[idx]<<" "<<this->Type_of_report[idx]<<" "<<this->Report_Location[idx]<<endl;
     }

    void getDetailsOfVoilation(string vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        cout<<"Details of voilation is:- "<<this->Car_Number[idx]<<" "<<this->Type_of_report[idx]<<" "<<this->Report_Location[idx]<<endl;
    }
    void getSourceofVoilation(string vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        cout<<"Source of voilation for "<<vno<<" is:- "<<this->Type_of_report[idx]<<endl; 
    }
    void getLocationOfVoilation(string vno){
         int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        cout<<"Location of voilation for "<<vno<<" is:- "<<this->Report_Location[idx]<<endl;
    }
    void showDataBase(){
        for(int i = 0; i < 500;i++){
            cout<<Car_Number[i]<<" "<< Type_of_report[i]<<" "<< Report_Location[i]<<endl;
        }
     }
};

int main(){
    Voilation_Identifier identifier;
    identifier.readFromCsv("A4-Q2.csv");
    identifier.showDataBase();
    while(true){
        cout<<"choose from the following option:-\n0 - show vehicles voilation's database\n1 - change Vehicle no\n2 - change source of report\n3 - change location of voilation\n4 - get details of voilation\n5 - get source of report\n6 - get location of voilation\n7 - exit\n";
        cout<<"Enter your choice:- ";
        int ch;
        cin>>ch;
        switch(ch){
            case 0:{
                identifier.showDataBase();
                break;
            }
            case 1:{
                string vno, new_vno;
                cout<<"Enter Current Vehicle no: ";
                cin>>vno;
                cout<<"Enter New Vehcile no: ";
                cin>>new_vno;
                identifier.changeVehicleNo(vno,new_vno);
                break;
            }
            case 2:{
                string vno, source;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New Source of report: ";
                cin>>source;
                identifier.changeSource(vno,source);
                break;
            }
            case 3:{
                string vno, location;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New Location of report: ";
                cin>>location;
                identifier.changeLocation(vno,location);
                break;
            }
            case 4:{
                string vno;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                identifier.getDetailsOfVoilation(vno);
                break;
            }
            case 5:{
                string vno;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                identifier.getSourceofVoilation(vno);
                break;
            }
            case 6:{
                string vno;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                identifier.getLocationOfVoilation(vno);
                break;
            }
            case 7:{
                exit(0);
            }
        }
    }
    return 0;
}