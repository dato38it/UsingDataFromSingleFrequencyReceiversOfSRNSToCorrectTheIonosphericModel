//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <iomanip.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
ifstream in ("IRKL1119.txt");
ofstream out ("output.txt");

    string a;
    //Пропускаем всё до END OF HEADER
    while(true) {
        getline (in,a);
        if(a == "                                                            END OF HEADER") {
            break;
        }
    }

    string name;
    // пропуск времени и состояния
    int temp;
    double temp2;
    in >> temp;
    in >> temp;
    in >> temp;
    in >> temp;
    in >> temp;
    in >> temp2;
    in >> temp;

    int countSputnik;
    in >> countSputnik;
    cout<< countSputnik<<endl ;

    vector <vector <double> > info;

    vector <double> tempVector;
    tempVector.resize(100);

    getline(in,name);

    vector <string> Sputnik;
    vector <string> allSputnik;//  массив вектор с именами спутниками

    int index=-1; //еачальные значения
    string tempName = "";  //
    for(int i=0; i< name.size(); i++) {
        if(name[i] == '-')
            break;
        if(name[i] >= 'A' && name[i] <= 'Z') {
            index++;
            if(tempName != "") {
               allSputnik.push_back(tempName);
               tempName="";
            }
        }
        if (name[i] != ' '){
            tempName = tempName + name[i];
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }
    tempName="";
    if(index <= countSputnik-1) {  //проверяем записсаны ли имена всех сутников
        //2 stroka
        getline(in,name);

        for(int i=0; i<name.size(); i++){
            if(name[i] >= 'A' && name[i] <= 'Z') {
                index++;
                if(tempName != "") {
                   allSputnik.push_back(tempName);
                   tempName="";
                }
            }
            if (name[i] != ' '){
                tempName = tempName + name[i];
            }
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }

    for(int i=0; i<allSputnik.size(); i++){
        out << allSputnik[i] << endl;
    }



    info.push_back(tempVector);
    for(int i = 0; i<allSputnik.size(); i++) {
         double dalnost;
         in >>  dalnost;
         in >>  dalnost;

         getline (in,name);
         getline (in,name);

         index=-1;
         for(int j=0; j<Sputnik.size(); j++) {
                if(allSputnik[i] == Sputnik[j]) {
                        index = j;
                        break;
                }
         }
         if(index == -1) {
                Sputnik.push_back(allSputnik[i]);
                info[info.size()-1][Sputnik.size()-1] = dalnost;
         }
         else {
                info[info.size()-1][index] = dalnost;
         }
    }
   /*
    out << endl;
    for(int j=0; j<Sputnik.size(); j++) {
        out << Sputnik[j] << " ";
    }
    out << endl;

    for(int i=0; i<info.size(); i++) {
        for(int j=0; j<info[i].size(); j++) {
                out << setprecision(12) << info[i][j] << " ";
        }
        out << endl;
    }
    */
 ////////////////////////////////////////////////////////////////////

        //getline(in, name);
        //out << endl << name << endl;
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp;
        in >> temp2;
        in >> temp;
        in >> countSputnik;
        out << countSputnik << endl;

        getline(in,name);

        allSputnik.resize(0);
        index=-1; //еачальные значения
        tempName = "";  //
        for(int i=0; i< name.size(); i++) {
        if(name[i] == '-')
            break;
        if(name[i] >= 'A' && name[i] <= 'Z') {
            index++;
            if(tempName != "") {
               allSputnik.push_back(tempName);
               tempName="";
            }
        }
        if (name[i] != ' '){
            tempName = tempName + name[i];
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }
    tempName="";
    if(index <= countSputnik-1) {  //проверяем записсаны ли имена всех сутников
        //2 stroka
        getline(in,name);

        for(int i=0; i<name.size(); i++){
            if(name[i] >= 'A' && name[i] <= 'Z') {
                index++;
                if(tempName != "") {
                   allSputnik.push_back(tempName);
                   tempName="";
                }
            }
            if (name[i] != ' '){
                tempName = tempName + name[i];
            }
        }
    }
    if(tempName != "") {
        allSputnik.push_back(tempName);
        tempName="";
    }

    for(int i=0; i<allSputnik.size(); i++){
        out << allSputnik[i] << endl;
    }
    info.push_back(tempVector);
    for(int i = 0; i<allSputnik.size(); i++) {
         double dalnost;
         in >>  dalnost;
         in >>  dalnost;

         getline (in,name);
         getline (in,name);

         index=-1;
         for(int j=0; j<Sputnik.size(); j++) {
                if(allSputnik[i] == Sputnik[j]) {
                        index = j;
                        break;
                }
         }
         if(index == -1) {
                Sputnik.push_back(allSputnik[i]);
                info[info.size()-1][Sputnik.size()-1] = dalnost;
         }
         else {
                info[info.size()-1][index] = dalnost;
         }
    }

    out << endl;
    for(int j=0; j<Sputnik.size(); j++) {
        out << setw(13) << Sputnik[j] << " ";
    }
    out << endl;

    for(int i=0; i<info.size(); i++) {
        for(int j=0; j<info[i].size(); j++) {
                out << setw(13) << setprecision(13) << info[i][j] << " ";
        }
        out << endl;
    }

}
//---------------------------------------------------------------------------
 