#include<bits/stdc++.h>
using namespace std;



void solve(){
	
	string s;
	cin >> s;
	vector<int> count(26, 0);
	
	for(int i=0; i<s.length(); i++) count[s[i] - 'a']++;
	
	int max_count = 0;
	for(int i=0; i<count.size(); i++) max_count = max(max_count, count[i]);
	
	int cnt = (int)s.length() - max_count;
	
	cout << (cnt >= max_count - 1? 1 : -1) << endl;
	
	
}

int main(){
	
	int test = 1;
	cin >> test;
	while(test--) solve();
	
}
