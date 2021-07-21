#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
#include<cstring>
#include<map>
using namespace std;
#define pii pair<int,int>
string s;
vector<string> ans;
int dd[1000], fost;
bool check_ky_tu(string gan) {
	if (gan[0] != '(' && gan[0] != ')'&&gan.size()==1) return false;
	return true;
}
void check(int x) {
	string gan;
	stack<char> kt;
	for (int i = 0; i < s.length(); i++) {
		if (dd[i] == 0) gan += s[i];
	}
	int t = 0;
	for (int i = 0; i < gan.length(); i++) {
		if (!kt.empty() && kt.top() == '(' && gan[i] == ')') kt.pop();
		else  if (gan[i] == '(' || gan[i] == ')') kt.push(gan[i]);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == gan) {
			t++;
			break;
		}
	}
	t += kt.size();
	if (t == 0 &&check_ky_tu(gan)) {
		ans.push_back(gan);
	}
}
void up(int i, int t) {
	for (int j = i; j < s.length(); j++) {
		if (dd[j] == 0 && (s[j] == '(' || s[j] == ')')) {
			dd[j] = 1;
			if(t==fost) check(t);
			else if (t < fost) up(j + 1, t + 1);
			dd[j] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(dd, 0, sizeof(dd));
		ans.clear();
		cin >> s;
		fost = 0;
		stack<char>kt;
		for (int i = 0; i < s.length(); i++) {
			if (!kt.empty() && kt.top() == '(' && s[i] == ')') kt.pop();
			else if(s[i]=='('||s[i]==')') kt.push(s[i]);
		}
		fost += kt.size();
		int x = 0;
		if (fost < s.length() && fost) {
			up(0, 1);
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
				x++;
			}
			if (x == 0) cout << -1;
			cout << endl;
		}
		else {
			if (fost == 0&&check_ky_tu(s)) cout << s;
			else cout << -1;
			cout << endl;
		}
	}
	return 0;
}
