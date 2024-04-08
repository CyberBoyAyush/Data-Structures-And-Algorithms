// Rotate The Matrix
// https://www.naukri.com/code360/problems/rotate-the-matrix_6825090?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat) {
  int n = mat.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }

  for (int i = 0; i < n; i++) {
    reverse(mat[i].begin(), mat[i].end());
  }
}