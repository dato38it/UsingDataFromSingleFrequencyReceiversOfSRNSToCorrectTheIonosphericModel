//---------------------------------------------------------------------------
#include <fstream>
#include <iostream>

#include <vector>

#include <cmath>

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
        ifstream in ("irkm3500.txt");
        ofstream out ("out.txt");
//////// ���������� �� �� END OF HEADER
        string a;

        while(true) {
                getline (in,a);

                if(a == "                                                            END OF HEADER") {
                        break;
                }
        }
//////// ������� ������� � ���������
        // ����
        int temp;
        double temp2;
        int countSputnik;

        vector <string> Sputnik;
        vector <vector <double> > info;

        for(int i=0; i<2880; i++){
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp2;
                in >> temp;
                in >> countSputnik;
//              out << countSputnik << endl; // ������� ���������� ���������
////////////// �������� ��������
                // ����
                string name;
                getline(in,name);
                int index=-1;
                string tempName = "";
                vector <string> allSputnik;

                allSputnik.resize(0);
                index=-1;
                tempName = "";
                // ��������� ������ ������
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
                // ��������� �� ����� (��������� �������)
                if(tempName != "") {
                        allSputnik.push_back(tempName);
                        tempName="";
                }
/*
                for(int i=0; i<allSputnik.size(); i++){
                        out << allSputnik[i] << endl; // ������� �������� � ������ ������
                }
*/
/*
                // ��������� ������ ������
                if(index <= countSputnik-1) {
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
                // ��������� �� ����� (��������� �������)
                if(tempName != "") {
                        allSputnik.push_back(tempName);
                        tempName="";
                }
*/
/*
                for(int i=0; i<allSputnik.size(); i++){
                        out << allSputnik[i] << endl; // ������� ��� ��������
                }
*/
//////////////// ��������� ��� ��������������� ��� ���� ��������� ��� ������ �����
                vector <double> tempVector;
                tempVector.resize(70); // ������� ����� ��������

                info.push_back(tempVector);
                for(int i = 0; i<allSputnik.size(); i++) {
                        double dalnost=0;
                        string b = "";

                        getline (in, b);
//                        out << b << endl; // ������� ������ �������� ���� ����� ������

                        a ="";
                        if(b.size()>=65){
                                a=b.substr(65,15); // �������� ������ ��
//                                out << a << endl; // ������� ������ ��
                        }


                        // ����
                        int tochka=-1;
                        int chislo=0;

                        for (int i=0; i<a.size(); i++){
                                if (a[i]>='0' && a[i]<='9'){
                                        dalnost = dalnost *10 + (a[i]-'0');
                                }
                                else {
                                        if(a[i]== '.') {
                                                tochka=i;
                                        }
                                }
                        }


//                        out << dalnost << endl; // ������� ������ �� ������ � �����������
                        if(tochka != -1){
                                chislo = a.size()-1 - tochka;
                                chislo = (int) pow(10, (double)chislo);
                                dalnost=dalnost/chislo;
                        }   
                        getline (in,name);
//                        out << name << endl; // ������� ������ �������� ���� ����� ������

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
         }

//////// ������� ������� ������
        for(int j=0; j<Sputnik.size(); j++) {
                out << setw(15) << Sputnik[j] << " "; // ������� �������� ��������� � ������
        }
        out << endl;
        
        for(int i=0; i<info.size(); i++) {
                for(int j=0; j<info[i].size(); j++) {
                        out << setw(15)  << setprecision(15) << info[i][j] << " "; // ������� �� � ������ � ��������� � ��
                }
                out << endl;
        }
        out << endl;

//////// ���� �� ����� ������� �� ������ ��� ������ ��� ���� ���������
       /* for(int i=0; i<info.size(); i++){
                out << setw(13) << setprecision(13) << info[i][0]/1000/* << setw(14) << info[i][1]*/ /*<< endl;
        }                */

}
//---------------------------------------------------------------------------
