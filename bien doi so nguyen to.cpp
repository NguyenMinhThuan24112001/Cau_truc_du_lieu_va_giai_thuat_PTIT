#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int m, n;
vector<int> v;
void fullPrime(){
	bool B[10009];
	for(int i=0; i<10009; i++) B[i] = true;
	for(int i=2; i<10000; i++){
		if(B[i]){
			for(int j=2*i; j<10000; j+=i){
				B[j] = false;
			}
		}
	}
	for(int i=1000; i<=9999; i++){
		if(B[i]) v.push_back(i);
	}
}
bool oneDigit(int a, int b){
	int res = 0;
	while(a > 0 && b > 0){
		if(a % 10 != b % 10) res++;
		a/=10; b/=10;
	}
	if(res == 1) return true;
	return false;
}
int main(){
	fullPrime();
	int test; cin >> test;
	while(test--){
		cin >> m >> n;
		if(m == n){
			cout << 0 << endl;
			continue;
		}
		queue<int> q;
		int B[v.size() + 9];
		for(int i=0; i<v.size() + 9; i++) B[i] = 0;
		q.push(m);
		int count = 0;
		bool check = false;
		while(!check){
			count++;
			int t = 0, len = q.size();
			while(t < len){
				bool rt = false;
				int tmp = q.front(); q.pop();
				for(int i=0; i<v.size(); i++){
					if(B[i] == 0){
						if(oneDigit(v.at(i), tmp)){
							B[i] = 1; q.push(v.at(i));
							if(v.at(i) == n){
								check = true;
								rt = true;
								break;
							}
						}
					}
				}
				if(rt) break;
				t++;
			}
		}
		cout << count << endl;
	}
}
