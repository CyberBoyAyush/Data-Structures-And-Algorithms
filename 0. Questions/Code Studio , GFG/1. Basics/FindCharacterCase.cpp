// https://www.codingninjas.com/studio/problems/find-character-case_58513?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
using namespace std;

int main() {
	char alph;
	cin>>alph;

	if(alph>='A' && alph<='Z'){
		cout<< 1;
	}
	else if(alph>='a' && alph<='z'){
		cout<< 0;
	}
	else{
		cout<< -1;
	}
}
