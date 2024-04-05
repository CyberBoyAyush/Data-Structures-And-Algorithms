// Move Zero's to End
// https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
vector<int> moveZeros(int n, vector<int> arr) {
    int j =-1;
    for(int i = 0; i<n;i++){
      if (arr[i] == 0) {
          j = i;
          break;
      }
    }
    if(j == -1) return arr;

    for(int i = j +1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }

    }
    return arr;
}
