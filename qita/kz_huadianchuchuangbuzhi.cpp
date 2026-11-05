#include<iostream>
int A[101][101],B[101][101],C[101][101],D[101];
int main(){
	using namespace std;
	int f,v,i,j,k,s=-999999;
	cin>>f>>v;
	for(i=1;i<=f;i++){
		for(j=1;j<=v;j++){
			cin>>A[i][j];
			B[i][j]=-999999;
		}
	}
	for(i=1;i<=v;i++){
		B[1][i]=A[1][i];
	}
	for(i=2;i<=f;i++){
		for(j=i;j<=v;j++){
			for(k=i-1;k<=j-1;k++){
				s = B[i-1][k]+A[i][j];
				if(s>B[i][j]){
					C[i][j]=k;
					B[i][j]=s;
				}
			}
		}
	}
	s=-999999;
	for(i=f;i<=v;i++){
		if(B[f][i]>s){
			s = B[f][i];
			k=i;
		}
	}
	cout<<s<<endl;
	j=f;
	D[f]=k;
	while(j>1){
		D[j-1]=C[j][k];
		k = C[j][k];
        j--;
	}
	for(i=1;i<=f;i++){
		cout<<D[i]<<' ';
	}
	return 0;
}