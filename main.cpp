#include<iostream>
#include "cube.h"
using namespace std;
int main(){
    Cube c;
    cout<<"Initial Cube:\n";
    c.display();
    c.U(); //after top rotation
    cout<<"\n After U move\n";
    c.display();
    return 0;
}
