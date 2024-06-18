#include<iostream>
using namespace std;

bool isPresent(int arr[], int size, int key){
    for(int i = 0; i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int key;
    cin>>key;
    int num[10] = {11,24,53,-45,1,0,66,3,4,69};
    
    bool find = isPresent(num,10,key);
    if(find){
        cout<<"Key is present"<<endl;
    }
    else{
        cout<<"Key is not present"<<endl;
    }

}
