#include<bits/stdc++.h>
using namespace std;

void solution(){
	
	int n, m;
	cin >> n >> m;
	vector<int> v1(n), v2(m);
	
	set<int> st1, st2;
	
	for(int i=0; i<n; i++){
		cin >> v1[i];
		st1.insert(v1[i]);
	}
	
	for(int i=0; i<m; i++){
		cin >> v2[i];
		if(st1.find(v2[i]) != st1.end()){
			st2.insert(v2[i]);
		}
		else st1.insert(v2[i]);
	}
	
	for(auto x: st1) cout << x << " ";
	cout << endl;
	for(auto x: st2) cout << x << " ";
	cout << endl;
	
}



int main(){

	int test = 1;
	cin >> test;
	while(test--) solution();
	
}
