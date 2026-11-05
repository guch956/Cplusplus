#include <iostream>
int p(int ,int ); 
int main(){
	using namespace std;
	int m,n;
	cin >> n >> m;
	n = p(n,m);
	cout << n;
	return 0;
}
int p(int n,int k){
	if (k==1){
		return 1;
	}
	else{
		int i,j,t=0;
		j = n/k;
		for(i=0;i<j;i++){
			t+=p(n-k*i-1,k-1); 
		}
		return t;	
	}
}
