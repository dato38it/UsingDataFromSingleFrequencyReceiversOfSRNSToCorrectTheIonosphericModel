//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

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
        ifstream in ("igs19236-1.txt");
        ofstream out ("out.txt");  
// ���������� �� ORB:CMB CLK:CMB
        string stroka;
        for (int i=0; i<22; i++)
        {
                getline (in,stroka);
        }
// ��������� �����
        string epoha;
        getline(in,epoha);
        //out << epoha << endl;
        /*char zvezda;
        int data;
        int vremia;
        double sostoianie;
        in >> zvezda;
        in >> data;
        in >> data;
        in >> data;
        in >> vremia;
        in >> vremia;
        in >> sostoianie;
        //out << sostoianie;*/
// ��������� ������� ���� ��������� � �� ����������
/*
        string position; // ��� ���� ������
        getline (in,position);
        out << position << endl;
*/
/*//������ �������   +
        string sputnik; //������� ��������
        string e; // EOF � *  2016 11 19
        string x;
        string y;
        string z;
        string signali; //������ �������
        for (int j=0; j<96; j++){ //��� ���� ��������� � ��� ���� ����
                for (int i=0; i<32; i++){ //��� ���� ��������� � ��� ����� �����
                        in >> sputnik >> x >> y >> z;
                        getline (in, signali);
                        out << sputnik << " " << x << " " << y << " " << z << " " << endl;
                }
                getline (in, e); // ��������� EOF � *  2016 11 19
        }*/
/* //������ �������  -
        int b;
        //getline (in,position);
        //out << position << endl;
        
        string *info = new string [b];
        for (int i=0; i<b; i++)
        {
                info[i]="";
        }
        int index=-1;
        for(int i=0; i< position.size(); i++) {
                if(position[i] >= 'A' && position[i] <= 'Z') {
                        index++;
                }
                if (position[i] !=' '){
                        info[index] = info[index] + position[i];
                }
        }
        for(int i=0; i<b; i++)
        {
                out << " " << info[i] << " " << endl;
        }
        delete [] info;
*/
/*
        double *information = new double [b];

        for(int i=0; i<b; i++)
        {
                in >> information[i];
                //getline (in,position);
                //getline (in,position);
        }
        for(int i=0; i<b; i++){
                out << information[i] << endl;
        }
*/
        string position; // ��� ���� ������
        getline (in,position); // ����������� ��� ������ �������
        //out << position << endl;
// ������� ������ ������� ���� ������
        vector <string> infa; // ������� ������ ������ � ����� ������� �����
        int index=-1; // ��������� ��������
        string infaPosition = ""; // ������ ������� ��� ������ ��������
        for(int i=0; i< position.size(); i++) {  // ��� ������ ���� ������� ����� �������
                if(position[i] >= 'A' && position[i] <= 'Z') { // 1 ���� ��������� �����
                        index++;  // �������� ���������
                        /*if(infaPosition != "") { // ����
                                infa.push_back(infaPosition);
                                infaPosition="";
                        } */
                }
                /*if (position[i] != ' '){
                        infaPosition = infaPosition + position[i];
                }*/
                out << position[i] << endl; // ������� � ������ ������ �������
        }

/*        string a;
        getline (in,a);
        out << a << endl;   
*/


}
//---------------------------------------------------------------------------




