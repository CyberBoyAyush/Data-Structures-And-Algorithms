// convert to decimal

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

int convert2Decimal(vector<int> Bin){
    int power = 1;
    int decimal = 0;

    for(int i = 0; i<Bin.size(); i++){
        decimal += Bin[i]*power;
        power *= 2;
    }
    return decimal;
}

int main(){
    int n;
    cin >> n;

    vector<int> Bin;
    int temp = n;
    while(temp > 0){
        Bin.push_back(temp % 10);
        temp = temp / 10;
    }

    cout << convert2Decimal(Bin);
    return 0;
}