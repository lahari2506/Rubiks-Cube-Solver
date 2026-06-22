#ifndef CUBE_H
#define CUBE_H
class Cube{
  public:
  char face[6][9];
  Cube();
  void display();
  void U();
  void R();
  void L();
  void F();
  void U_prime();
  void R_prime();
  void L_prime();
  void F_prime();
};
#endif
