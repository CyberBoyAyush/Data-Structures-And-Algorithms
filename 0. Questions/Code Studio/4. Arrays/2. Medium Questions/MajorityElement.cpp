// Majority Element
// https://www.naukri.com/code360/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
int majorityElement(vector<int> v) {
	int cnt = 0;
	int el;

	for(int i = 0;i<v.size();i++){
		if(cnt ==0){
			cnt =1;
			el = v[i];
		}
		else if(v[i]==el){
			cnt ++;
		}
		else{
			cnt--;
		}
	}

	int cnt1=0;

	for(int i = 0;i<v.size();i++){
		if(v[i]==el){
			cnt1++;
		}
		if(cnt1>(v.size()/2)){
			return el;
		}
	}
	return -1;
}