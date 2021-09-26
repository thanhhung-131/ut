#include <iostream>
using namespace std;
int main()
{
    int n, A, B, C, a, b, c, count = 0;
    cin >> n;
    for (a = 1; a < 1000; a++)
    {
        for (b = 1; b < a; b++)
        {
            c = (3 * n) / 4;
            if (n == 2 * c - b && n == 2 * c - a)
            {
                count++;
                if (count = 1)
                {
                    A = a;
                    B = b;
                    C = c;
                }
            }
        }
    }
    if (count != 1)
        cout << "NO";
    else
        cout << A << " " << B << " " << C << endl;
    return 0;
}
