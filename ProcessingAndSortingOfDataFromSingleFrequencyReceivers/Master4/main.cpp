#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    string b = " ";
    string a ="";
    if(b.size()>=30){
        a=b.substr(17,13);
    }
    double num = 0;
    int tochka=-1;
    int chislo=0;
    for (int i=0; i<a.size(); i++){
        if (a[i]>='0' && a[i]<='9'){
            num = num *10 + (a[i]-'0');
        }
        else {
            if(a[i]== '.') {
               tochka=i;
            }
        }
    }
    if(tochka != -1){
    chislo = a.size()-1 - tochka;
    chislo = pow(10,chislo);
    num=num/chislo;
    }

    cout << setprecision(13) << num;

    return 0;
}
