#include<bits/stdc++.h>
using namespace std;

void multiplyMatrices( vector<vector<int>> & mat1, vector<vector<int>> &mat2, vector<vector<int>> &res)
{
    int m =  mat1.size(); // matrix 1 ka size
    int k =  mat1[0].size(); // mat 1 ka column size
    int n = mat2[0].size(); // mat 2 ka column size

     // Check for dimension compatibility
    if (k != mat2.size()) {
        cout << "Matrix multiply not valid" << endl;
        return;
    }

    for (int index = 0; index < m * n * k; ++index)
    {
        int i = index / (n * k); 
        int j = (index / k) % n;
        int p = index % k;

        res[i][j] +=  mat1[i][p] * mat2[p][j];
    }
}

int main()
{
    vector<vector<int>>  mat1 = {{1, 2, 3},
                            {4, 5, 6}, {4, 5, 6}};

    vector<vector<int>> mat2 = {{7, 8,11},
                            {9, 10,10}};
    int m =  mat1.size();
    int n = mat2[0].size();

    vector<vector<int>> res(m, vector<int>(n));

    multiplyMatrices( mat1, mat2, res);


//PRINT KE LIYE
    for (int index = 0; index < m * n; ++index) {
        int i = index / n;    
        int j = index % n;
        cout << res[i][j] << " ";
    }

    return 0;
}
