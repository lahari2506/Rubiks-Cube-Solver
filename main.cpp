#include<iostream>
#include "cube.h"
using namespace std;
int main(){
    Cube c;
    cout<<"Initial Cube:\n";
    c.display();
//test U move:
     c.U(); //after top rotation
    cout<<"\n After U move\n";
    c.display();
    c.U_prime();
    cout << "\nAfter U' (should match initial):\n";
    c.display();

//RESET CUBE:
   Cube c2;
//test R move:
    cout<<"Initial cube for R test:\n";
    c2.display();
    c2.R();
    cout<<"after R move\n";
    c2.display();
    c2.R_prime();
    cout << "\nAfter R' (should match initial):\n";
    c2.display();
    

    return 0;
}
