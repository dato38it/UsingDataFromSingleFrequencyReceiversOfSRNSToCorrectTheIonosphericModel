//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
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
    //���������� �� �� END OF HEADER
    while(true) {
        getline (in,a);
        if(a == "                                                            END OF HEADER") {
            break;
        }
    }

    string name;
    // ������� ������� � ���������
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


    getline(in,name);

//    cout<< name <<endl;
    vector <string> allSputnik;//  ������ ������ � ������� ����������

    int index=-1; //��������� ��������
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
    if(index != countSputnik -1) {  //��������� ��������� �� ����� ���� ��������
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
     for(int i=0; i<countSputnik; i++){
        out << allSputnik[i] << endl;
    }

    /*
    delete [] Sputnik;
// ���������� ��������������� ��� ����� �����
    double *information = new double [countSputnik];
    for(int i=0; i<countSputnik; i++){
        in >> information[i];
        getline (in,name);
       getline (in,name);
    }
    for(int i=0; i<countSputnik; i++){
        out << information[i] << endl;
    }
       */
/*
    double *information = new double [countSputnik];
    double information1;
    for(int i=0; i<countSputnik; i++){
        in >> information1;
        in >> information[i];
        getline (in,name);
        getline (in,name);
    }



    for(int i=0; i<countSputnik; i++){
        cout << information[i] << endl;
    }

*/
}
//---------------------------------------------------------------------------
 