#include<iostream>
using namespace std;
void print(int n,int p[],int q[],int c){
	int i;
	if(c==n+1){
		for(i=1;i<=n;i++){
			cout<<q[i]<<' ';
		}
		cout<<endl;
	}
	else{
		for(i=1;i<=n;i++){
			if(!p[i]){
				p[i] = 1;
				q[c] = i;
				print(n,p,q,c+1);
				p[i] = 0;
			}
		}
	}
}
int main(){
	int n,*p,*q,k;
	cin>>n;
	p = new int[n+1];
	q = new int[n+1];
	for(k=0;k<=n;k++){
		p[k] = 0;
	}
	print(n,p,q,1);
	return 0;
}
