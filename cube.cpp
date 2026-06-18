#include <iostream>
#include "cube.h"
using namespace std;
//face[0] indicates the top face containing 9 stickers we passed into
//cw void f containing array of 9 elements
void rotatefaceclockwise(char f[9]){
    char temp[9];
    temp[0] = f[6];
    temp[1] = f[3];
    temp[2] = f[0];
    temp[3] = f[7];
    temp[4] = f[4];
    temp[5] = f[1];
    temp[6] = f[8];
    temp[7] = f[5];
    temp[8] = f[2];

    for(int i=0;i<9;i++){
        f[i]=temp[i];
    }


}
   

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
void Cube::U(){
    rotatefaceclockwise(face[0]);
}








