#include<iostream>
int main(){
	using namespace std;
	int n,*p1,*p2,i,d,m,a,p;
	cin>>n;
	p1 = new int[n+1];
	p2 = new int[n+1];
	for(i=0;i<=n;i++){
		p1[i]=0;p2[i]=0;
	}
	d = 1;
	for(i=2;i<=n;i++){
		cin>>a>>p;
		if (p==0){
			p2[i]=a;
			p1[i]=p1[a];
			p2[p1[a]] = i;
			p1[a] = i;
			if(a==d){
				d = i;
			}
		}
		else{
			p1[i] = a;
			p2[i] = p2[a];
			p1[p2[a]] = i;
			p2[a] = i;
		}
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>a;
		if (d==a){
			d = p2[a];
		}
		p2[p1[a]] = p2[a];
		p1[p2[a]] = p1[a];
		p1[a] = 0;
		p2[a] = 0;
	}
	while(d!=0){
		cout<<d<<' ';
		d = p2[d];
	}
	return 0;
}
