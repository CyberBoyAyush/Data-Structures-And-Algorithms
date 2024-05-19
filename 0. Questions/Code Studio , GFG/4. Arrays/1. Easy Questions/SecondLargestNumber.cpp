// Second Largest Number
// https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> arr) {
    
    int largest = arr[0];
    int s_largest = -1;
    int smallest = arr[0];
    int s_smallest = arr[1];

    for(int i = 0;i<n; i++){
        //for second largest
        if (arr[i]>largest){
            s_largest = largest;
            largest= arr[i];
        }
        if(arr[i]>s_largest&&arr[i]<largest){
            s_largest= arr[i];
        }

        //for second smallest
        if(arr[i]<smallest){
            s_smallest = smallest;
            smallest=arr[i];
        }
        if (arr[i] < s_smallest && arr[i] > smallest) {
            s_smallest = arr[i];
        }
    }
    return {s_largest,s_smallest};
}
