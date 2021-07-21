#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll data;
	node * left;
	node * right;
};
node * insert(node * l, ll x){
	if(l == NULL){
		node * temp = new node;
		temp -> data = x;
		temp -> left = NULL;
		temp -> right = NULL;
		return temp;
	}
	else{
		if(x < l -> data){
			l -> left = insert(l -> left, x);
		}
		else l -> right = insert(l -> right, x);
	}
	return l;
}
void print_tree(node * l){
	if(l != NULL){
		cout << l -> data << " ";
		print_tree(l -> left);
		print_tree(l -> right);
		
	}
}
int level_tree(node * l){
	if(l == NULL) return -1;
	else return 1 + max(level_tree(l -> left), level_tree(l -> right));
}
int count_mid_tree(node * l){
	if(l == NULL) return 0;
	if(l -> left == NULL && l -> right == NULL) return 0;
	int x = 0, y = 0;
	return 1 + count_mid_tree(l -> left) + count_mid_tree(l -> right);
}
void solution(){
	ll n; cin >> n;
	ll x;
	node * l = NULL;
	for(ll i = 0; i < n; i++){
		cin >> x;
		l = insert(l, x);
	}
	 print_tree(l);

}
int main(){
	ll test; cin >> test;
	cin.ignore();
	while(test--){
		solution();
		cout << endl;
	}
	return 0;
}

