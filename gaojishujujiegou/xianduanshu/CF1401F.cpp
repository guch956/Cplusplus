#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1<<20;
class segment{
	private:
		struct{
			ll sum;
			int ls;
			int rs;
			int tag;
		}t[N];
		int n;
		void push_up(int p){
			t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
		}
		void addtag(int p,int ta){
			t[p].tag=t[p].tag^ta;
		}
		void push_down(int p){
			if(t[p].tag&1){
				swap(t[p].ls,t[p].rs);
			}
			addtag(t[p].ls,t[p].tag>>1);
			addtag(t[p].rs,t[p].tag>>1);
			t[p].tag=0;
		}
		void build(int ,int ,int ,ll*);
		ll chaxun(int ,int ,int ,int ,int );
		void update(int ,int ,int ,int ,ll );
	public:
		segment(int ,ll*);
		ll run(int ,int ,int );
};
void segment::build(int p,int pl,int pr,ll* q){
	if(pl==pr){
		t[p].sum=q[pl];
		t[p].tag=0;
		return ;
	}
	int mid=(pl+pr)>>1;
	t[p].ls=p<<1;
	t[p].rs=p<<1|1;
	build(t[p].ls,pl,mid,q);
	build(t[p].rs,mid+1,pr,q);
	push_up(p);
}
segment::segment(int n1,ll* p){
	n=1<<n1;
	build(1,1,n,p);
}
ll segment::chaxun(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){return t[p].sum;}
	int mid=(pl+pr)>>1;
	ll ans = 0;
	push_down(p);
	if(l<=mid){ans+=chaxun(t[p].ls,pl,mid,l,r);}
	if(r>mid){ans+=chaxun(t[p].rs,mid+1,pr,l,r);}
	return ans; 
}
void segment::update(int p,int pl,int pr,int x,ll d){
	if(pl==pr){
		t[p].sum=d;
		return ;
	}
	int mid=(pl+pr)>>1;
	push_down(p);
	if(x<=mid){update(t[p].ls,pl,mid,x,d);}
	else{update(t[p].rs,mid+1,pr,x,d);}
	push_up(p);
}
ll segment::run(int type,int x,int y){
	if(type==2 || type==3){
		addtag(1,x);
		return 0;
	}
	else if(type==4){
		return chaxun(1,1,n,x,y);
	}
	else{
		update(1,1,n,x,y);
		return 0;
	}
}
ll A[N];
int main(){
	int n,q,m,i,l,r;
	ll ans;
	scanf("%d %d",&n,&q);
	m = 1<<n;
	for(i=1;i<=m;i++){
		scanf("%lld",&A[i]);
	}
	segment tree(n,A);
	while(q--){
		scanf("%d",&i);
		switch(i){
			case 1:case 4:
				scanf("%d %d",&l,&r);
				break;
			case 2:
				scanf("%d",&l);
				l = (1<<n)-(1<<(n-l));
				break;
			case 3:
				scanf("%d",&l);
				l = 1<<(n-1-l);
				break;
		}
		ans = tree.run(i,l,r);
		if(i==4){
			printf("%lld\n",ans);
		}
	}
	return 0;
}
