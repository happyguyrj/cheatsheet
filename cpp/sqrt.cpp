/*

sqrt - 10^18
*/

#include <iostream>

using namespace std;


long findSqrt(long long number) {
    if(number < 0)
        return -1;

    if(number < 2) {
        return number;
    }

    long long start = 1;
    long long end = number;
    long long mid = (start + end)/2;

    while(start < end) {
        mid = (start + end)/2;
        if(mid == number/mid || mid < number/mid && (mid+1) > number/(mid+1)) {
            return mid;
        } else if (mid < number/mid) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    return mid;
}

int main() {

   cout << findSqrt(35) << endl;
   cout << findSqrt(37) << endl;
   cout << findSqrt(36) << endl;
   cout << findSqrt(1000000000000000000) << endl;
   cout << findSqrt(333) << endl;
   cout << findSqrt(-35) << endl;

   return 0;
}