// convert 2 binary

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> convert2Binary(int n){
    vector<int> Bin;

    int i =0;

    while(n> 0){
        Bin.push_back(n % 2);
        n = n / 2;
        i++;
    }

    return Bin;
}

int main(){
    int n;
    cin >> n;

    vector<int> Bin = convert2Binary(n);

    for(int i = Bin.size()-1; i>=0; i--){
        cout << Bin[i];
    }

    return 0;
}