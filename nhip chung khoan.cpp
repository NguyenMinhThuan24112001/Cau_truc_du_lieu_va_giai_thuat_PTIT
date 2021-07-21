#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int test; cin >> test;
	while(test--){
		int n; cin >> n;
		int A[n+1];
		for(int i=0; i<n; i++) cin >> A[i];
		stack<int> stc, stc1;
		for(int i=0; i<n; i++){
			bool check = false;
			int count = 1;
			if(stc.empty()) stc.push(A[i]);
			else{
				while(stc.top() <= A[i]){
					count += stc1.top(); stc1.pop();
					check = true;
					stc.pop();
					if(stc.empty() || stc1.empty()) break;
				}
				stc.push(A[i]);
			}
			cout << count << " ";
			stc1.push(count);
		}
		cout << endl;
	}
}
