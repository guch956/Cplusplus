#include <iostream>
void jisuanqian(int A[],int C[],int n);
int main(){
	using namespace std;
	int A[201];
	int E[201];
	int C[201]={0};
	int D[201]={0};
	int n,k,l,a;
	cin >>n;
	for (k=1;k<=n;k++){
		cin >> A[k];
		E[n+1-k] = A[k];
	}
	jisuanqian(A,C,n);
	jisuanqian(E,D,n);
	l = 0;
	for (k=1;k<=n;k++){
		a = C[k]+D[n+1-k]-1;
		if (a > l){
			l = a;
		}
	}
	cout << n-l << endl;
	return 0;
}
void jisuanqian(int A[],int C[],int n){
	int B[201]={0};
	int d=1,c,i,j,max;
	B[1] = A[1];
	C[1] = 1;
	for(i=2;i<=n;i++){
		max = 0;
		c = d;
		if (A[i]>B[c]){
			B[c+1] = A[i];
			max = c+1;
			d++;
		}
		for(j=c;j>=1;j--){
			if(A[i]>B[j-1]){
				if (j > max){
					max = j;
				}
				if (B[j]>A[i]){
					B[j] = A[i];
					}
					
			}
		}
		C[i] = max;
	}
}
