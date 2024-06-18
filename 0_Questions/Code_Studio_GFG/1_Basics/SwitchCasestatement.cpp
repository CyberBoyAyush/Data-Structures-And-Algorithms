// https://www.naukri.com/code360/problems/switch-case-statement_8357244?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

double areaSwitchCase(int ch, vector<double> a) {
	switch(ch){
		case 1 : 
		return 3.141592653589793238462643*a[0]*a[0];
		break;
		case 2: 
		return a[0]*a[1];
		break;
	}
}
