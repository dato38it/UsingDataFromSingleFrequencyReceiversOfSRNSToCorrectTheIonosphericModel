//---------------------------------------------------------------------------
#include <iostream>
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
	ifstream in ("sp3_docu.txt");
        ofstream out ("igs19236.txt");
        string name;
        for (int i=0; i<=113950; i++){
                getline(in,name);
                out << name << endl;
        }
}
//---------------------------------------------------------------------------


