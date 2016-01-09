// gauss.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

#define N 4

using namespace std;
double A[N][N + 1];

int swap(double &a, double &b){
  double t = a;
  a = b;
  b = t;
  return 0;
}

int swap_column(int i1, int i2){
  for (int i = 0; i < N; i++){
    swap(A[i1][i], A[i2][i]);
  }
  return 0;
}

int div_equation(int i1, double d){
  for (int i = 0; i < N + 1; i++){
    A[i1][i] /= d;
  }
  return 0;
}

int sum_equation(int i1, int i2, double d){
  if (d == 0){
    return 0;
  }
  for (int i = 0; i < N + 1; i++){
    A[i1][i] -= d * A[i2][i];
  }
  return 0;
}


int _tmain(int argc, _TCHAR* argv[]){
  ifstream input;
  ofstream output;
  input.open("input.txt", ios::in);
  double t = 0;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N + 1; j++){
      
      input >> t;
      A[i][j] = t;
    }
  }
  input.close();

  for (int k = 0; k < N; k++){
    int r = k;
    while (A[r][k] == 0 && r < N){
      r++;
    }
    if (k != r){
      swap_column(k, r);
    }
    div_equation(k, A[k][k]);
    for (int i = 0; i < N; i++){
      if (i != k){
        sum_equation(i, k, A[i][k]);
      }
    }
  }

  output.open("output.txt");

  for (int i = 0; i < N; i++){
    output << A[i][N] << endl;
  }
  output.close();
	return 0;
}

