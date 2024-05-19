//Square Root of a number
// https://www.naukri.com/code360/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dstriver&utm_medium=website&utm_campaign=a_zcoursetuf

int floorSqrt(int n) {


  if (n == 0)

    return 0;

  int low = 0, high = n;

 

  while (low <= high) {

    long long mid = (low + high) / 2;

    long long val = mid * mid;

    if (val <= n) {

      low = mid + 1;

    } 

    else {

      high = mid - 1;

    }

  }

  return high;

};