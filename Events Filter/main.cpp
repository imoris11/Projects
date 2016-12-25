//
//  main.cpp
//  Events
//
//  Created by Richard Igbiriki on 10/26/16.
//  Copyright © 2016 Richard Igbiriki. All rights reserved.
//

/*
 Steps:
 1. Generate a temporary file
 2. Find the needed string in every line of the input file (EventID, Account Name, etc)
 3. If found, store the line in the temporary file
 4. Filter the temporary file for the needed information
 5. Store the filtered informtation in the output file
 6. Close the files
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Events{
public:
    Events(){
        ifstream inFile;
        //Macs require full file path
        string tmpFile ="/Users/richardigbiriki/Downloads/Compiler/tmp.txt";//TMP file to store lines for processing...
        
        outFile.open("/Users/richardigbiriki/Downloads/Compiler/output.txt");//Change file path as necessary...
        inFile.open("/Users/richardigbiriki/Downloads/Compiler/Events.txt", ios::in);
        ofstream tmp;
        
        if (inFile.fail())
        {
            cerr << "Error openning file";
            cout << "Press any key..."; cin.get(); exit(0);
        }
        while(getline(inFile, fLine, '\n')){
            //Find EventID's and other needed information
            if(fLine.find("5140") != -1||fLine.find("4624") !=-1 || fLine.find("4656") != -1 ||fLine.find("4659") !=-1 ||fLine.find("4663") !=-1|| fLine.find("4660") !=-1){
                tmp.open(tmpFile);
                tmp<<fLine;
                tmp.close();
                readFile(tmpFile,1);
            }
            if(fLine.find("Account Name") !=-1){
                tmp.open(tmpFile);
                tmp<<fLine;
                tmp.close();
                readFile(tmpFile,2);
            }
            if(fLine.find("Account Domain") !=-1){
                tmp.open(tmpFile);
                tmp<<fLine;
                tmp.close();
                readFile(tmpFile,3);
            }
            if(fLine.find("Object Name") !=-1){
                tmp.open(tmpFile);
                tmp<<fLine;
                tmp.close();
                readFile(tmpFile,4);
            }
            if(fLine.find("Accesses") !=-1){
                tmp.open(tmpFile);
                tmp<<fLine;
                tmp.close();
                readFile(tmpFile,5);
            }
            
        }
        inFile.close();
    }
    void readFile(string file, int i){
        ifstream inFile;
        inFile.open(file);
        if(i==1){
            string level, time,source, category,eventID, date,message;
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
                outFile<<"Event ID: "<<eventID<<endl;
                outFile<<"Category:  "<<category<<endl;
                outFile<<"Date: "<<date<<"\t Time: "<<time<<endl;
                outFile<<"Event Message: "<<message<<endl;
            }
        }else if(i==2){
            string acc,acc1,acc2;
            while (!inFile.eof()) {
                getline(inFile, acc, '\t');
                getline(inFile, acc1, '\t');
                getline(inFile, acc2, '\n');
                if(acc2.length() > 2 ){
                    outFile<<"Username: "<<acc2<<" ";
                }
                
            }
            
        }else if(i==3){
            string acc,acc1,acc2;
            while (!inFile.eof()) {
                getline(inFile, acc, '\t');
                getline(inFile, acc1, '\t');
                getline(inFile, acc2, '\n');
                if(acc2.length() > 2 ){
                    outFile<<"Domain: "<<acc2;
                }
                
            }
            cout<<endl<<endl;
            outFile<<endl<<endl;
        }else if(i==4){
            string acc,acc1,acc2;
            while (!inFile.eof()) {
                getline(inFile, acc, '\t');
                getline(inFile, acc1, '\t');
                getline(inFile, acc2, '\n');
                    outFile<<acc1<<" "<<acc2<<endl<<endl;
                
            }
        }else if(i==5){
            string acc,acc1,acc2;
            while (!inFile.eof()) {
                getline(inFile, acc, '\t');
                getline(inFile, acc1, '\t');
                getline(inFile, acc2, '\n');
                    outFile<<acc1<<" "<<acc2<<endl<<endl;
                
            }
        }
        inFile.close();
    }
private:
    ofstream outFile;
    string fLine;
};


int main(int argc, const char * argv[]) {
    Events event;
    return 0;
}
