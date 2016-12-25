//
//  main.cpp
//  FileManager
//
//  Created by Richard Igbiriki on 11/2/16.
//  Copyright © 2016 Richard Igbiriki. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Files{
    string username, domain,date,time,category,id,message,object,access;
    struct Files *next;
};
class FileManager {
public:
    FileManager(string fileName){
    #define error_msg "Sorry, Couldn't Open File";
        do{
            inputFile.open(fileName);
            if(tried){
                cout<<error_msg;
                cout<<"Enter another file: ";
                cin>>fileName;
            }
            tried=true;
        }while(!inputFile.is_open());
        tried=false;
        cout<<"File was opened Successfully!!! \n";
        openReader();
    }
    void printAll(){
        curr=head;
        while(curr->next != NULL){
            cout<<"Event ID: "<<curr->id;
            cout<<endl;
            cout<<"Category: "<<curr->category;
            cout<<endl;
            cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
            cout<<endl;
            cout<<"Event Message: "<<curr->message<<endl;
            cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
            if(curr->id != "5140" && curr->id != "4624"){
                cout<<"Object Name: "<<curr->object<<endl;
                cout<<"Access: "<<curr->access<<endl;
            }
            curr=curr->next;
        }
        cout<<"Event ID: "<<curr->id;
        cout<<endl;
        cout<<"Category: "<<curr->category;
        cout<<endl;
        cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
        cout<<endl;
        cout<<"Event Message: "<<curr->message<<endl;
        cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
        if(curr->id != "5140" && curr->id != "4624"){
            cout<<"Object Name: "<<curr->object<<endl;
            cout<<"Access: "<<curr->access<<endl;
        }
    }
    void printDate(string date){
        curr=head;
        while(curr->next != NULL){
            if(curr->date == date){
                cout<<"Event ID: "<<curr->id;
                cout<<endl;
                cout<<"Category: "<<curr->category;
                cout<<endl;
                cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
                cout<<endl;
                cout<<"Event Message: "<<curr->message<<endl;
                cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
                if(curr->id != "5140" && curr->id != "4624"){
                    cout<<"Object Name: "<<curr->object<<endl;
                    cout<<"Access: "<<curr->access<<endl;
                }

            }
            curr=curr->next;
        }
        if(curr->date==date){
            cout<<"Event ID: "<<curr->id;
            cout<<endl;
            cout<<"Category: "<<curr->category;
            cout<<endl;
            cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
            cout<<endl;
            cout<<"Event Message: "<<curr->message<<endl;
            cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
            if(curr->id != "5140" && curr->id != "4624"){
                cout<<"Object Name: "<<curr->object<<endl;
                cout<<"Access: "<<curr->access<<endl;
            }

        }
        
    }
    void printEvent(string ID){
        curr=head;
        while(curr->next != NULL){
            if(curr->id == ID){
                cout<<"Event ID: "<<curr->id;
                cout<<endl;
                cout<<"Category: "<<curr->category;
                cout<<endl;
                cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
                cout<<endl;
                cout<<"Event Message: "<<curr->message<<endl;
                cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
                if(curr->id != "5140" && curr->id != "4624"){
                    cout<<"Object Name: "<<curr->object<<endl;
                    cout<<"Access: "<<curr->access<<endl;
                }
            }
            curr=curr->next;
        }
        if(curr->id == ID){
            cout<<"Event ID: "<<curr->id;
            cout<<endl;
            cout<<"Category: "<<curr->category;
            cout<<endl;
            cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
            cout<<endl;
            cout<<"Event Message: "<<curr->message<<endl;
            cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
            if(curr->id != "5140" && curr->id != "4624"){
                cout<<"Object Name: "<<curr->object<<endl;
                cout<<"Access: "<<curr->access<<endl;
            }
        }
        
    }
    void printUser(string user){
        cout<<"SORTING ACCORDING TO USERNAME\n";
        curr=head;
        while(curr->next != NULL){
            if((curr->username).find(user)){
                cout<<"Event ID: "<<curr->id;
                cout<<endl;
                cout<<"Category: "<<curr->category;
                cout<<endl;
                cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
                cout<<endl;
                cout<<"Event Message: "<<curr->message<<endl;
                cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
                if(curr->id != "5140" && curr->id != "4624"){
                    cout<<"Object Name: "<<curr->object<<endl;
                    cout<<"Access: "<<curr->access<<endl;
                }

            }
            curr=curr->next;
        }
        if(curr->username==user){
            cout<<"Event ID: "<<curr->id;
            cout<<endl;
            cout<<"Category: "<<curr->category;
            cout<<endl;
            cout<<"Date: "<<curr->date<<"\t\tTime: "<<curr->time;
            cout<<endl;
            cout<<"Event Message: "<<curr->message<<endl;
            cout<<"Username: "<<curr->username<<"\t\tDomain: "<<curr->domain<<endl;
            if(curr->id != "5140" && curr->id != "4624"){
                cout<<"Object Name: "<<curr->object<<endl;
                cout<<"Access: "<<curr->access<<endl;
            }

        }
    }
private:
    string level, time,source, category,eventID, date,message;
    Files *structure, *curr, *head;
    string user,domain,object,accessRights;
    string secondFile="/Users/richardigbiriki/Downloads/Compiler/temp.txt";
    ifstream inputFile;
    ofstream outPutFile;
    string ids[6]={"5140","4624","4656","4659","4663","4660"};
    bool tried=false;
    ofstream temp;
    //Find Event IDs
    void findID(string line){
        for(int i=0; i<6; i++){
            if(line.find(ids[i]) != -1){
                temp.open(secondFile);
                temp<<line;
                temp.close();
                readTemporaryFile(secondFile);
                tried=true;
            }
        }
        
    }
    
    //Find Account
    void findAccount(string line){
        if(line.find("Account Name") !=-1){
            temp.open(secondFile);
            temp<<line;
            temp.close();
            readUser(secondFile);
        }
        if(line.find("Account Domain") !=-1){
            temp.open(secondFile);
            temp<<line;
            temp.close();
            readDomain(secondFile);
        }
       
    }
    
    //Find Accessed Objects
    
    void accessedObject(string line){
        if(line.find("Object Name") !=-1){
            temp.open(secondFile);
            temp<<line;
            temp.close();
            readObject(secondFile);
        }
        if(line.find("Accesses") !=-1){
            temp.open(secondFile);
            temp<<line;
            temp.close();
            readAccess(secondFile);
        }
    }
    //Open Input File
    void openReader(){
        string line;
        structure = new Files;
        head=curr=structure;
        int numstruct=1;
        while(!inputFile.eof()){
            //Find EventID's and other needed information
            //structure = new Files;
            getline(inputFile, line, '\n');
            findID(line);
            findAccount(line);
            accessedObject(line);
            if(tried){
                insertElement(numstruct);
                numstruct++;
            }
            tried=false;
        }
    }
    void insertElement(int position){
        if(position==1){
            structure->id=eventID;
            structure->category=category;
            structure->date=date;
            structure->time=time;
            structure->message=message;
            structure->domain=domain;
            structure->access=accessRights;
            structure->object=object;
            structure->username=user;
            structure->next=NULL;
        }else{
            structure=new Files;
            structure->id=eventID;
            structure->category=category;
            structure->date=date;
            structure->time=time;
            structure->message=message;
            structure->domain=domain;
            structure->access=accessRights;
            structure->object=object;
            structure->username=user;
            structure->next=NULL;
            curr->next=structure;
            curr=structure;
        }
    }
    void readUser(string file){
        ifstream inFile;
        inFile.open(file);
        string acc,acc1,acc2;
        while (!inFile.eof()) {
            getline(inFile, acc, '\t');
            getline(inFile, acc1, '\t');
            getline(inFile, acc2, '\n');
            if(acc2.length() > 2 ){
                user=acc2;
            }
            
        }
        inFile.close();
    }
    void readDomain(string file){
        ifstream inFile;
        inFile.open(file);
        string acc,acc1,acc2;
        while (!inFile.eof()) {
            getline(inFile, acc, '\t');
            getline(inFile, acc1, '\t');
            getline(inFile, acc2, '\n');
            if(acc2.length() > 2 ){
                domain=acc2;
            }
            
        }
        inFile.close();
    }
    void readObject(string file){
        ifstream inFile;
        inFile.open(file);
        string acc,acc1,acc2;
        while (!inFile.eof()) {
            getline(inFile, acc, '\t');
            getline(inFile, acc1, '\t');
            getline(inFile, acc2, '\n');
            string ob=acc2;
            object=ob;
    }
        inFile.close();
    }
    void readAccess(string file){
        ifstream inFile;
        inFile.open(file);
        string acc,acc1,acc2;
        while (!inFile.eof()) {
            getline(inFile, acc, '\t');
            getline(inFile, acc1, '\t');
            getline(inFile, acc2, '\n');
            string access=acc2;
            accessRights=access;
    }
        inFile.close();
}
    void readTemporaryFile(string file){
        ifstream inFile;
        inFile.open(file);
            string fLine;
            while(!inFile.eof()){
                getline(inFile, level, '\t');
                getline(inFile,time , '\t');
                getline(inFile,source , '\t');
                getline(inFile,eventID , '\t');
                getline(inFile,category , '\t');
                getline(inFile,message , '\n');
                string::size_type pos = time.find(' ');
                date=time.substr(0,pos);
                time=time.substr(pos+1, time.length());
         }
        inFile.close();
    }
    int countFiles(){
        int index=1;
        curr=head;
        while(curr->next != NULL){
            index++;
            curr=curr->next;
        }
        return index;
    }
};
int main(int argc, const char * argv[]) {
    string fileName="/Users/richardigbiriki/Downloads/Compiler/Events.txt";
    cout<<"\t\t\t\t Events Filter\n";
    cout<<"Choose an option below: \n";
    cout<<"1. Use default file\n";
    cout<<"2. Enter a filename\n";
    int op;
    cin>>op;
    if(op==2){
       cout<<"Enter a File Name: ";
        cin>>fileName;
    }
    string date, eventID, username;
    FileManager myFile(fileName);
    while(true){
        int choice;
        cout<<"Choose an option below: \n";
        cout<<"1. Show all events \n";
        cout<<"2. Filter with an event ID\n";
        cout<<"3. Filter according to a date \n";
        cout<<"4. Filter by username \n";
        cin>>choice;
        switch (choice) {
            case 1:
                myFile.printAll();
                break;
            case 2:
                cout<<"Enter eventID: ";
                cin>>eventID;
                myFile.printEvent(eventID);
                break;
            case 3:
                cout<<"Enter date (m/dd/yyyy): ";
                cin>>date;
                myFile.printDate(date);
                break;
            case 4:
                cout<<"Enter username: ";
                cin>>username;
                myFile.printUser(username);
                break;
            default:
                break;
        }
        string ans;
        cout<<"Try another filter? (Y/N) ";
        cin>>ans;
        if(ans=="n" || ans=="N")
            break;
    }
    return 0;
}
