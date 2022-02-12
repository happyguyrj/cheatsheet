#include <iostream>

using namespace std;

double fetchElement(int X) {
    return 0.005*X + 0.00009*X*X;
}

bool numberExist(double target) {
    int jump = 10;
    int low = 0;

    while(fetchElement(high) < target) {
        high*=jump;
    }
    low = high/10;

    //cout << high << "\n";
    while(low <= high) {
        int mid = (low+high)/2;
        //cout << low << " " << mid << " " << high <<  " " << fetchElement(mid) - target << "\n";

        if(fetchElement(mid) == target) {
            return true;
        } else if(fetchElement(mid) > target) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return false;
}


int main()
{
  cout << numberExist(0.95) << "\n";
  cout << numberExist(0) << "\n";
  cout << numberExist(0.791) << "\n"; //25
  cout << numberExist(0.792) << "\n"; //25
  cout << numberExist(441350) << "\n"; //30

   cout << fetchElement(70000);
//   for (int i = ; i<70000;i++) {
//       cout << i << ": " << fetchElement(i) << "\n";
//   }
   return 0;
}