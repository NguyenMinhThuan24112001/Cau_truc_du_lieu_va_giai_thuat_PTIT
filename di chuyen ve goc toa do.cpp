#include<bits/stdc++.h>
typedef long long ll;
const int MAX = 28;
using namespace std;

int main() {
    int t;
    cin >> t;
    long long a[MAX][MAX] = {};
    int	A[MAX];
   	for (int i = 1; i < MAX; i++) 
	{
        a[i][1] = 1;
        a[1][i] = 1;
    }
//    for(int i = 0; i <= MAX; i++)
//	{
//		A[i] = MAX;
//			for(int m = 1; m <= MAX; m++)
//				A[m] = A[i];
//				 break;
//	}
    for (int i = 2; i < MAX; i++) 
	    for (int j = 2; j < MAX; j++) a[i][j] = a[i - 1][j] + a[i][j - 1];
    while (t--) {
        int h,c;
        cin >> h >> c;
        cout << a[h + 1][c + 1] << endl;
    }
    return 0;
}
