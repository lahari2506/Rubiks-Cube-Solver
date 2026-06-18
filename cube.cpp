#include <iostream>
#include "cube.h"
using namespace std;

Cube::Cube(){
    char colors[6]={'W','Y','G','B','O','R'};
    for(int i=0;i<6;i++){
        for(int j=0;j<9;j++){
            face[i][j]=colors[i];
        }
    }
}
void Cube::display(){
    for(int i=0;i<6;i++){
        cout<<"Face"<<i<<": ";
        for(int j=0;j<9;j++){
            cout<<face[i][j]<<" ";
        }
        cout<<endl;
    }
}







