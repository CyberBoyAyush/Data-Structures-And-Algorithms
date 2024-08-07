// Print Pascal’s Triangle
// https://www.naukri.com/code360/problems/print-pascal-s-triangle_6917910?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
vector<int> genRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col<row;col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;

}

vector<vector<int>> pascalTriangle(int N) {
    vector<vector <int>> ans;
    for(int i = 1; i<=N; i++){
        ans.push_back(genRow(i));
    }
    return ans;
}