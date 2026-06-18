#include <iostream>
#include "cube.h"
using namespace std;
/*MAPPING IN A CUBE:
0 = Up
1 = Down
2 = Front
3 = Back
4 = Left
5 = Right*/
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
/*face[0] indicates the top face containing 9 stickers we passed into
cw void f containing array of 9 elements*/
void Cube::U() {
    // rotate UP face itself CW
    rotatefaceclockwise(face[0]);

    char temp[3];

    // store Front top row
    temp[0] = face[2][0];
    temp[1] = face[2][1];
    temp[2] = face[2][2];

    // Front <- Left
    face[2][0] = face[4][0];
    face[2][1] = face[4][1];
    face[2][2] = face[4][2];

    // Left <- Back
    face[4][0] = face[3][0];
    face[4][1] = face[3][1];
    face[4][2] = face[3][2];

    // Back <- Right
    face[3][0] = face[5][0];
    face[3][1] = face[5][1];
    face[3][2] = face[5][2];

    // Right <- Front (saved)
    face[5][0] = temp[0];
    face[5][1] = temp[1];
    face[5][2] = temp[2];
}
//rotate the cube U'(ACW)
void Cube::U_prime() {
    rotatefaceclockwise(face[0]);
    rotatefaceclockwise(face[0]);
    rotatefaceclockwise(face[0]);

    char temp[3];

    // store Front top row
    temp[0] = face[2][0];
    temp[1] = face[2][1];
    temp[2] = face[2][2];

    // Front <- Right
    face[2][0] = face[5][0];
    face[2][1] = face[5][1];
    face[2][2] = face[5][2];

    // Right <- Back
    face[5][0] = face[3][0];
    face[5][1] = face[3][1];
    face[5][2] = face[3][2];

    // Back <- Left
    face[3][0] = face[4][0];
    face[3][1] = face[4][1];
    face[3][2] = face[4][2];

    // Left <- Front
    face[4][0] = temp[0];
    face[4][1] = temp[1];
    face[4][2] = temp[2];
}