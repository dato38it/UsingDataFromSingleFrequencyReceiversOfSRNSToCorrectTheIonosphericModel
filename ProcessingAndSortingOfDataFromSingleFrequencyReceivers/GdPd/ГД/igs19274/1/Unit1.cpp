//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
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
        ifstream in ("igs19274.txt");
        ofstream out ("out.txt");

        string stroka;
        for (int i=0; i<=3190; i++){
                getline(in,stroka);
                out << stroka << endl;
        }
}
//---------------------------------------------------------------------------
