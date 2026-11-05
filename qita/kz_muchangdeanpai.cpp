#include<iostream>
#include<bitset>
bool judge(int x){
    int c = x,d,p=0;
    while(c>0){
        d = c%2;
        if(p&&d == 1){
            break;
        }
        else{
            p = d;
            c = c>>1;
        }
    }
    if(c==0){
        return 1;
    }
    return 0;
}
int main(){
    using namespace std;
    int m,n,i,j,a=1,size,*p,*q,**r,*s;
    cin>>m>>n;
    s = new int[n+2];
    s[0] = 0;
    s[1] = 1;
    for(i=1;i<=n;i++){
    	a = a*2;
	}
	p = new int[a];
	p[0] = 0;size = 1;
	a = 1;
	if(n>1){
		p[1] = 1;size++;
		
	}
	for(i=2;i<=n;i++){
		for(j=0;j<s[i-1];j++){
			p[size] = a+p[j];
			size++;
		}
		s[i+1] = size;
		a = a*2;
	}
	for(i=0;i<size;i++){
		cout<<bitset<8>(p[i])<<endl;
	}
    return 0;
}
