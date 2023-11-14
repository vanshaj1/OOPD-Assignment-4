#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Voilation_Reports{
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
     void changeEntry(string vno, string fname, string lname, string gender , string addr, int age){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->Vehicle_Number[idx] = vno;
        this->FirstName[idx] = fname;
        this->LastName[idx] = lname;
        this->gender[idx] = gender;
        this->address[idx] = addr;
        this->age[idx] = age;
        cout<<"Entry in record has been updated for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }
     void changeVehicleNo(string vno,string new_vno){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->Vehicle_Number[idx] = new_vno;
        cout<<"Vehicle Number "<<vno<<" has been updated to "<<new_vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }  
     void changeFirstName(string vno,string fname){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->FirstName[idx] = fname;
        cout<<"First name has been updated in record for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     } 
     void changeLastName(string vno,string lname){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->LastName[idx] = lname;
        cout<<"Last name has been updated in record for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }
     void changeGender(string vno,string gender){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->gender[idx] = gender;
        cout<<"Gender has been updated in record for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }
     void changeAddress(string vno, string addr){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->address[idx] = addr;
        cout<<"Address has been updated in record for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }
     void changeAge(string vno, int age){
        int idx = findIdx(vno);
        if(idx == -1){
            cout<<"Vehicle with this vehicle no doesn't exists";
            exit(0);
        }
        this->age[idx] = age;
        cout<<"Age has been updated for the Vehicle Number "<<vno<<endl;
        cout<<"Now the new entry is:- "<<this->Vehicle_Number[idx]<<" "<<this->FirstName[idx]<<" "<<this->LastName[idx]<<" "<<this->gender[idx]<<" "<<this->address[idx]<<" "<<this->age[idx]<<endl;
     }
     void showDataBase(){
        for(int i = 0; i < 1000;i++){
            cout<<Vehicle_Number[i]<<" "<< FirstName[i]<<" "<< LastName[i]<<" "<< age[i]<<" "<< gender[i]<<" "<< address[i]<<endl;
        }
     }
};

int main(){
    registered_Vehicles dataBase;
    dataBase.readFromCsv("A4-Q1.csv");
    dataBase.showDataBase();
    while(true){
        cout<<"choose from the following option:-\n0 - show vehicle's database\n1 - change Vehicle no\n2 - change Firstname\n3 - change Lastname\n4 - change gender\n5 - change address\n6 - change age\n7 - change Entry\n8 - exit\n";
        cout<<"Enter your choice:- ";
        int ch;
        cin>>ch;
        switch(ch){
            case 0:{
                dataBase.showDataBase();
                break;
            }
            case 1:{
                string vno, new_vno;
                cout<<"Enter Current Vehicle no: ";
                cin>>vno;
                cout<<"Enter New Vehcile no: ";
                cin>>new_vno;
                dataBase.changeVehicleNo(vno,new_vno);
                break;
            }
            case 2:{
                string vno, fname;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New First name: ";
                cin>>fname;
                dataBase.changeFirstName(vno,fname);
                break;
            }
            case 3:{
                string vno, lname;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New Last name: ";
                cin>>lname;
                dataBase.changeLastName(vno,lname);
                break;
            }
            case 4:{
                string vno, gender;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New gender: ";
                cin>>gender;
                dataBase.changeGender(vno,gender);
                break;
            }
            case 5:{
                string vno, addr;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New address: ";
                cin>>addr;
                dataBase.changeAddress(vno,addr);
                break;
            }
            case 6:{
                string vno;
                int age;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter New age: ";
                cin>>age;
                dataBase.changeAge(vno,age);
                break;
            }
            case 7:{
                string vno, fname,lname,gender,addr;
                int age;
                cout<<"Enter Vehicle no: ";
                cin>>vno;
                cout<<"Enter new First name no: ";
                cin>>fname;
                cout<<"Enter new Last name no: ";
                cin>>lname;
                cout<<"Enter new gender no: ";
                cin>>gender;
                cout<<"Enter new address no: ";
                cin>>addr;
                cout<<"\nEnter New age: ";
                cin>>age;
                dataBase.changeEntry(vno, fname, lname, gender ,addr, age);
                break;
            }
            case 8:{
                exit(0);
            }
        }
    }
    return 0;
}