#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<sstream>
//6*4+2^5-(10-8)
//6+4*5-2*6
//6 + 6 -5
#define ll long long
//(4+5)-6
// 5+6-(7+(8-6))
// can ngoc binh
using namespace std;
int priorityOperator(char c){
	if(c == '(' || c == ')') return 1;
	if(c == '+' || c == '-') return 2;
	if(c == '*' || c == '/' || c == '%') return 3;
	if(c == '^') return 4;
}
ll stringtoInt(string s){
	stringstream ss(s);
	ll x; ss >> x;
	return x;
}
int main(){
	int test; cin >> test;
	while(test--){
		string s; cin >> s;
		stack<ll> num;
		stack<char> ope;
		ll res, tmp = 0;
		for(int i=0; i<s.length(); i++){
			if(s.at(i) == '('){
				ope.push(s.at(i));
			}
			else if(s.at(i) == ')'){
				while(ope.top() != '('){
					ll v2 = num.top(); num.pop();
					ll v1 = num.top(); num.pop();
					if(ope.top() == '+') tmp = v1 + v2;
					else if(ope.top() == '-') tmp = v1 - v2;
					else if(ope.top() == '*') tmp = v1 * v2;
					else if(ope.top() == '/') tmp = v1 / v2;
					else if(ope.top() == '%') tmp = v1 % v2;	
					num.push(tmp);
					ope.pop();
					if(ope.empty()) break;
				}
				if(ope.top() == '(') ope.pop();
			}
			else if(s.at(i) >= '0' && s.at(i) <= '9'){
				string str;
				while(s.at(i) >= '0' && s.at(i) <= '9'){
					str.push_back(s.at(i));
					i++;
					if(i >= s.length()) break;
				}
				num.push(stringtoInt(str));
				i--;
			}	
			else{
				if(ope.empty()){
					ope.push(s.at(i)); continue;
				}
				else{
					if(ope.top() != '('){
						while(priorityOperator(s.at(i)) <= priorityOperator(ope.top())){
							ll x2 = num.top(); num.pop();
							ll x1 = num.top(); num.pop();
							if(ope.top() == '+') res = x1 + x2;
							else if(ope.top() == '-') res = x1 - x2;
							else if(ope.top() == '*') res = x1 * x2;
							else if(ope.top() == '/') res = x1 / x2;
							else if(ope.top() == '^') res = pow(x1, x2);
							else if(ope.top() == '%') res = x1 % x2;
							num.push(res);
							ope.pop();
							if(ope.empty()) break;
						}
						ope.push(s.at(i));
						
					}
					else{
						ope.push(s.at(i));
					}
				}
			}		
		}
		while(num.size() > 1){
			ll x2 = num.top(); num.pop();
			ll x1 = num.top(); num.pop();
			if(ope.top() == '+') res = x1 + x2;
			else if(ope.top() == '-') res = x1 - x2;
			else if(ope.top() == '*') res = x1 * x2;
			else if(ope.top() == '/') res = x1 / x2;
			else if(ope.top() == '^') res = pow(x1, x2);
			else if(ope.top() == '%') res = x1 % x2;
			num.push(res);
			ope.pop();
		}
		cout << num.top() << endl;
	}
}
