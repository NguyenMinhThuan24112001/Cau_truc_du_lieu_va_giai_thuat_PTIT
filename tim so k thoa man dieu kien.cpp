#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
bool check(int n){
	set<int> s;
	while(n > 0){
		if(n % 10 > 5) return false;
		else if(s.find(n % 10) != s.end()) return false;
		else s.insert(n % 10);
		n /= 10;
	}
	return true;
}
int main(){
	int test; cin >> test;
	while(test--){
		int l, r;
		cin >> l >> r;
		int count = 0;
		for(int i=l; i<=r; i++){
			if(check(i)) count++;
		}
		cout << count << endl;
	}
}
