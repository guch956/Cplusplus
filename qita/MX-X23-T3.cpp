#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500003;
char s1[N],s2[N];
int num1[3],num2[3];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
inline int get(char c){
	switch (c){
		case 'R':return 0;
		case 'P':return 1;
		case 'S':return 2;
	}
}
int main(){
	int n,m,d,i,ans=0,s,j;
	scanf("%d %d",&n,&m);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	d = gcd(m,n);
	for(i=1;i<=d;i++){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(j=i;j<=n;j+=d)num1[get(s1[j])]++;
		for(j=i;j<=m;j+=d)num2[get(s2[j])]++;
		s = min(num1[0]+num2[1]+num2[2],min(num1[1]+num2[0]+num2[2],num1[2]+num2[0]+num2[1]));
		s = min(s,min(num2[0]+num1[1]+num1[2],min(num2[1]+num1[0]+num1[2],num2[2]+num1[0]+num1[1])));
		ans+=s;
	}
	printf("%d",ans);
	return 0;
}
