#include<bits/stdc++.h>
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define ll long long
using namespace std;
const int MAX = 1e6+5;
int A[MAX];
int main(){
	int test; cin >> test;
	while(test--){
		ll n, SUM; cin >> n >> SUM;
		bool zero = false;
		FOR(i, 0, n){
			cin >> A[i];
			if(A[i] == 0) zero = true;
		}
		if(SUM == 0 && zero){
			cout << "YES" << endl;
			continue;
		}
		else if(SUM == 0 && !zero){
			cout << "NO" << endl;
			continue;
		}
		ll sum = 0;
		int local = 0;
		bool check = false;
		FOR(i, 0, n){
			sum += A[i];
			while(sum > SUM) sum -= A[local++];
			if(sum == SUM){
				check = true;
				break;
			}
		}
		cout << (check? "YES" : "NO") << endl;
	}
}
