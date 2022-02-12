#include <iostream>
#include <numeric>
using namespace std;

int myfun(int x, int y) {
	return x * y;
}

// find out the sum of elements in a particular range or a complete array using
// a linear operation which requires adding all the elements in the range one by
// one and storing it into some variable after each iteration.
int main() {
	int sum = 1;
	int a[] = { 5, 10, 15 };

	cout << "\nResult using accumulate: " << accumulate(a, a + 3, sum);
	cout << "\nResult using accumulate with user-defined function: " << accumulate(a, a + 3, sum, myfun);
	cout << "\nResult using accumulate with pre-defined function: " << accumulate(a, a + 3, sum, std::minus<int>());

    string s = "ACVS";
    cout << "\nExcel column name to number: " << accumulate(begin(s), end(s), 0, [](int a, int b) {
        return 26*a + (b - 'A' +1);
    });
	return 0;
}
