// Find Nth Root Of M
// https://www.naukri.com/code360/problems/nth-root-of-m_1062679?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int func(int mid, int n , int m){
  long long int ans = 1;

  for(int i = 1 ; i<=n; i++){
    ans = ans * mid;
    if(ans > m) return 2;
    
      }
      if(ans == m) return 1;
      return 0;
}
int NthRoot(int n, int m) {
  int low = 1, high = m;
  while(low<=high){
    int mid = (low+high)/2;
    int midN = func(mid, n, m);
    if(midN == 1) return mid;
    else if (midN == 0){
      low = mid +1;
    }
    else{
      high = mid -1;
    }
  }
  return -1;
}