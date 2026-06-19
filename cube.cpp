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

    // Front - Left
    face[2][0] = face[4][0];
    face[2][1] = face[4][1];
    face[2][2] = face[4][2];

    // Left - Back
    face[4][0] = face[3][0];
    face[4][1] = face[3][1];
    face[4][2] = face[3][2];

    // Back - Right
    face[3][0] = face[5][0];
    face[3][1] = face[5][1];
    face[3][2] = face[5][2];

    // Right - Front (saved)
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

    // Front - Right
    face[2][0] = face[5][0];
    face[2][1] = face[5][1];
    face[2][2] = face[5][2];

    // Right - Back
    face[5][0] = face[3][0];
    face[5][1] = face[3][1];
    face[5][2] = face[3][2];

    // Back - Left
    face[3][0] = face[4][0];
    face[3][1] = face[4][1];
    face[3][2] = face[4][2];

    // Left - Front
    face[4][0] = temp[0];
    face[4][1] = temp[1];
    face[4][2] = temp[2];
}
void Cube::R() {
    rotatefaceclockwise(face[5]);

    char up[3], front[3], down[3];

    // save top,bottom,front rotated stickers due to R move
    up[0] = face[0][2];
    up[1] = face[0][5];
    up[2] = face[0][8];

    front[0] = face[2][2];
    front[1] = face[2][5];
    front[2] = face[2][8];

    down[0] = face[1][2];
    down[1] = face[1][5];
    down[2] = face[1][8];

    face[0][2] = front[0];
    face[0][5] = front[1];
    face[0][8] = front[2];

    face[2][2] = down[0];
    face[2][5] = down[1];
    face[2][8] = down[2];

    face[1][2] = face[3][6];
    face[1][5] = face[3][3];
    face[1][8] = face[3][0];

    face[3][6] = up[0];
    face[3][3] = up[1];
    face[3][0] = up[2];
}
void Cube::R_prime() {
    rotatefaceclockwise(face[5]);
    rotatefaceclockwise(face[5]);
    rotatefaceclockwise(face[5]);

char up[3], front[3], down[3], back[3];

// save top,bottom,front rotated stickers due to R' move
up[0] = face[0][2];
up[1] = face[0][5];
up[2] = face[0][8];

front[0] = face[2][2];
front[1] = face[2][5];
front[2] = face[2][8];

down[0] = face[1][2];
down[1] = face[1][5];
down[2] = face[1][8];

back[0] = face[3][6];
back[1] = face[3][3];
back[2] = face[3][0];

face[0][2] = back[0];
    face[0][5] = back[1];
    face[0][8] = back[2];

    face[3][6] = down[0];
    face[3][3] = down[1];
    face[3][0] = down[2];

    face[1][2] = front[0];
    face[1][5] = front[1];
    face[1][8] = front[2];

    face[2][2] = up[0];
    face[2][5] = up[1];
    face[2][8] = up[2];
}