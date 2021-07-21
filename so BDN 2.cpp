#include<bits/stdc++.h>

using namespace std;

#define ll long long


void solve(){
	
	ll n;
	cin >> n;
	
	queue<ll> q;
	q.push(1);
	
	long long ans;
	while(!q.empty()){
		
		ll number = q.front(); q.pop();
		if(number % n == 0){
			ans = number;
			break;
		}
		q.push(number * 10 + 0);
		q.push(number * 10 + 1);
		
	}
	
	cout << ans << endl;
	
}

int main(){
	
	int test = 1;
	cin >> test;
	while(test--) solve();
	
	
}
