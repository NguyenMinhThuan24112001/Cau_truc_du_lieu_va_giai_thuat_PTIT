#include<bits/stdc++.h>
using namespace std;

const int N = 6;

map<string, bool> vis;

string left(string s){
	string res;
	res += s[3]; res += s[0]; res += s[2]; res += s[4]; res += s[1]; res += s[5];
	return res;
}

string right(string s){
	string res;
	res += s[0];res += s[4]; res += s[1]; res += s[3]; res += s[5]; res += s[2];
	return res;
}

int bfs(string start, string fis){
	
	queue<pair<string, int>> q; // pair<cau hinh, so buoc>
	vis[start] = true;
	q.push({start, 0});
	
	while(!q.empty()){
		
		auto p = q.front(); q.pop();
		string status = p.first;
		int step = p.second;
		
		if(status == fis){
			return step;
		}
		
		string L = left(status);
		string R = right(status);
//		cout << L << " " << R << endl;
		q.push({L, step + 1});
		q.push({R, step + 1});
		
		
	}
	
	return -1;
}


void solve(){
	
	vis.clear();
	
	string start, fis;
	for(int i=0; i<N; i++){
		char c;
		cin >> c;
		start += c;
	}
	
	for(int i=0; i<N; i++){
		char c;
		cin >> c;
		fis += c;
	}
	
	
	cout << bfs(start, fis) << endl;
	
}


int main(){
	
	int test = 1;
	cin >> test;
	cin.ignore();
	while(test--) solve();
	
}
