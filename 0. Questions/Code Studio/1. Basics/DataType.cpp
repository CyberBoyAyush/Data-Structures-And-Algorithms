// https://www.naukri.com/code360/problems/data-type_8357232?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
using namespace std;
int dataTypes(string datatype) {
	// char datatype;
	// cin>>datatype;

	if(datatype=="Long" || datatype=="Double"){
		return 8;
	}
	else if(datatype=="Integer" || datatype=="Float"){
		return 4;
	}
	else{
		return 1;
	}
}
