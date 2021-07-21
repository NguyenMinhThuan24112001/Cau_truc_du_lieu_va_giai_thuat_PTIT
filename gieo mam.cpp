#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORD(i, m, n) for(int i=m; i>=n; i--)
#define reset(A) memset(A, 0, sizeof(A));
#define ll long long
#define mp make_pair
#define f first
#define pb push_back
#define s second
using namespace std;
const int MAX = 505;

int A[MAX][MAX] = {0};
bool B[MAX][MAX] = {0};
vector<pair<int, int>> v;
int cnt = 0, limit = 0;
vector<pair<int, int>> v1 = {{-1, 0}, {0,-1}, {1,0}, {0,1}};
queue<pair<int, int>> q;

void findLocal(int x, int y, queue<pair<int, int>> &q){
	FOR(i, 0, v1.size()){
		auto pr = v1[i];
		if(A[x + pr.f][y + pr.s] == 1 && !B[x + pr.f][y + pr.s]){
			B[x + pr.f][y + pr.s] = true;
			q.push(mp(x + pr.f, y + pr.s));
			limit++;
		}
	}
}
int BFS(){
	reset(B);
	int res = 0;
	while(!q.empty()){
		int len = q.size();
		int num = 0;
		while(num < len){
			int x = q.front().f, y = q.front().s; 
			q.pop();
			findLocal(x, y, q);
			num++;
		}
		res++;
		if(limit == cnt) return res;
	}
	return -1;
}
int main(){
	int test; cin >> test;
	while(test--){
		v.clear();
		reset(A);
		reset(B);
		queue<pair<int, int>> qt;
		q = qt;
		int n, m;
		cnt = 0; limit = 0;
		cin >> n >> m;
		FOR(i, 1, n+1){
			FOR(j, 1, m+1){
				cin >> A[i][j];
				if(A[i][j] == 2) q.push(mp(i, j));
				else if(A[i][j] == 1) cnt++;
			}
		}

		cout << BFS() << endl;
	}
	
}
