#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500003;
struct nod{
	int id;
	ll val;
	nod(int i,ll v){id = i;val = v;}
	bool operator<(const nod n1)const{
		return val<n1.val;
	}
};
struct node{
	ll a,b;
	double k;
};
bool bijiao(node & n1,node & n2){
	return n1.k<n2.k;
}
node * p[N];
ll pai[N];
int zhiz[N];
int siz[N];
int main(){
	int n,i,l,j,k;
	ll P=0,x,ans=0;
	priority_queue<nod> q;
	nod u(0,0);
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%lld %d",&x,&l);
		siz[i]=l;
		p[i] = new node[l];pai[i]=x;
		for(j=0;j<l;j++){
			scanf("%lld",&p[i][j].a);
			pai[i]*=p[i][j].a;
		}
		for(j=0;j<l;j++){
			scanf("%lld",&p[i][j].b);
			p[i][j].k=((double)p[i][j].a-(double)p[i][j].b)/(double)p[i][j].a;
		}
		sort(p[i],p[i]+l,bijiao);
		P+=pai[i];
		q.push(nod(i,pai[i]/p[i][0].a*p[i][0].b));
		zhiz[i]=0;
	}
	while(k--){
		u = q.top();
		q.pop();
		ans+=u.val;
		i = u.id;
		pai[i] = pai[i]-u.val;
		zhiz[u.id]++;
		if(zhiz[i]<siz[i])q.push(nod(i,pai[i]/p[i][zhiz[i]].a*p[i][zhiz[i]].b));
	}
	ans = P-ans;
	printf("%lld",ans);
	return 0;
}
