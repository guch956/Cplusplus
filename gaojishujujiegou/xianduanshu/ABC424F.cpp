#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
const int INF=0x3f3f3f3f;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
struct node{
	int ma;
	int mi;
	node(){ma = -INF;mi=INF;}
}t[N<<2];
node hebing(node n1,node n2){
	node c;
	c.ma=max(n1.ma,n2.ma);
	c.mi=min(n1.mi,n2.mi);
	return c;
}
void push_up(int p){
	t[p]=hebing(t[ls(p)],t[rs(p)]);
}
node chaxun(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){return t[p];}
	int mid=(pl+pr)>>1;
	node ans;
	if(l<=mid){ans = hebing(ans,chaxun(ls(p),pl,mid,l,r));}
	if(r>mid){ans = hebing(ans,chaxun(rs(p),mid+1,pr,l,r));}
	return ans;
}
void update(int p,int pl,int pr,int x,node & c){
	if(pl==pr){
		t[p]=hebing(t[p],c);
		return ;
	}
	int mid=(pl+pr)>>1;
	if(x<=mid){update(ls(p),pl,mid,x,c);}
	else{update(rs(p),mid+1,pr,x,c);}
	push_up(p);	
} 
int main(){
	int n,q,i,a,b;
	node t1;
	scanf("%d %d",&n,&q);
	while(q--){
		scanf("%d %d",&a,&b);
		if(a<b-1){
			t1 = chaxun(1,1,n,a+1,b-1);
			if(t1.ma>b || t1.mi<a){
				printf("No\n");
			}
			else{
				t1 = node();t1.mi=a;
				update(1,1,n,b,t1);
				t1 = node();t1.ma=b;
				update(1,1,n,a,t1);
				printf("Yes\n");
			}
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
}
