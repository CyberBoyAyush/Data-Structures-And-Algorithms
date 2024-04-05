// Maximum Consecutive Ones
// https://www.naukri.com/code360/problems/traffic_6682625?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
int traffic(int n, int m, vector<int> vehicle) {

    // Write your code here.

    int i=0, j=0, noZeros=0,maxLen=0;

    while(j<n){

        if(vehicle[j]==0){

            noZeros++;

        }

        while(noZeros>m){

              if(vehicle[i]==0)

                noZeros--;

                i++;

        }

        maxLen=max(maxLen,(j-i+1));

        j++;

    }

    return maxLen;

}
