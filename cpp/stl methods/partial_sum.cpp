#include <iostream>
#include <numeric>
using namespace std;

int myfun(int x, int y) {
	return x * y;
}

// This function assigns a partial sum of the corresponding elements of an array to every position of the second array.
// It returns the partial sum of all the set of values lying between [first, last) and stores it in another array b.
// y0 = x0
// y1 = x0 + x1
// y2 = x0 + x1 + x2
// y3 = x0 + x1 + x2 + x3
// y4 = x0 + x1 + x2 + x3 + x4
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
    int b[5];

    // Default function
    partial_sum(a, a + 5, b);

    cout << "Partial Sum - Using Default function: ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << '\n';

    // Using user defined function
    partial_sum(a, a + 5, b, myfun);

    cout << "Partial sum - Using user defined function: ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << '\n';

    return 0;
}
