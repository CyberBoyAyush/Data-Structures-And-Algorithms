// https://www.naukri.com/code360/problems/hcf-and-lcm_840448?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// int calcGCD(int n, int m){
//     int gcd=1;
//     for(int i=1;i<=min(n,m);i++){
//         if(n%i==0 && m%i==0){
//             gcd = i;
//         }
//     }
//     return gcd;
// }


// Euclidean Algorithm
int calcGCD(int a, int b){
    while(a>0 && b >0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a==0) {
        return b;
    }
    else{
        return a;
    }
}