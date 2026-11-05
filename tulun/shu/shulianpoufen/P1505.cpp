#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
struct {
	int ma;
	int mi;
	int sum;
	int tag;
}t[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){
	t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
	t[p].ma=max(t[ls(p)].ma,t[rs(p)].ma);
	t[p].mi=min(t[ls(p)].mi,t[rs(p)].mi);
}
inline void addtag(int p){
	t[p].tag^=1;
	t[p].sum=-t[p].sum;
	swap(t[p].ma,t[p].mi);
	t[p].ma=-t[p].ma;
	t[p].mi=-t[p].mi;
}
inline void push_down(int p){
	if(t[p].tag){
		addtag(ls(p));
		addtag(rs(p));
		t[p].tag=0;
	}
}
void update1(int p,int pl,int pr,int x,int d){
	if(pl==pr){
		t[p].ma=t[p].mi=t[p].sum=d;
		return ;
	}
	int mid=(pl+pr)>>1;
	push_down(p);
	if(x<=mid) update1(ls(p),pl,mid,x,d);
	else update1(rs(p),mid+1,pr,x,d);
	push_up(p);
}
int querymax(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){return t[p].ma;}
	int mid=(pl+pr)>>1,ans = -INF;
	push_down(p);
	if(l<=mid) ans = max(ans,querymax(ls(p),pl,mid,l,r));
	if(r>mid) ans = max(ans,querymax(rs(p),mid+1,pr,l,r));
	return ans;
}
int querymin(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){return t[p].mi;}
	int mid=(pl+pr)>>1,ans = INF;
	push_down(p);
	if(l<=mid) ans = min(ans,querymin(ls(p),pl,mid,l,r));
	if(r>mid) ans = min(ans,querymin(rs(p),mid+1,pr,l,r));
	return ans;
}
int querysum(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){return t[p].sum;}
	int mid=(pl+pr)>>1,ans = 0;
	push_down(p);
	if(l<=mid) ans = ans+querysum(ls(p),pl,mid,l,r);
	if(r>mid) ans = ans+querysum(rs(p),mid+1,pr,l,r);
	return ans;
}
void update2(int p,int pl,int pr,int l,int r){
	if(l<=pl && r>=pr){
		addtag(p);
		return ;
	}
	int mid=(pl+pr)>>1;
	push_down(p);
	if(l<=mid) update2(ls(p),pl,mid,l,r);
	if(r>mid) update2(rs(p),mid+1,pr,l,r);
	push_up(p);
}
int head[N],to[N<<1],nex[N<<1],ent;
int edge[N][3];
int dfm[N],deep[N],siz[N],son[N],fa[N],top[N];
int dfn,n;
void adde(int u,int v){
	ent++;
	to[ent]=v;
	nex[ent]=head[u];
	head[u]=ent;
}
void dfs1(int s,int f){
	int i;
	fa[s]=f;
	deep[s]=deep[f]+1;
	siz[s]=1;
	for(i=head[s];i;i=nex[i]){
		if(to[i]==f)continue;
		dfs1(to[i],s);
		siz[s]+=siz[to[i]];
		if(siz[to[i]]>siz[son[s]])son[s]=to[i];
	}
}
void dfs2(int s,int topx){
	int i;
	dfm[s]=++dfn;
	top[s]=topx;
	if(son[s])dfs2(son[s],topx);
	for(i=head[s];i;i=nex[i]){
		if(to[i]==fa[s] || to[i]==son[s])continue;
		dfs2(to[i],to[i]);	
	}
}
int chaxunmax(int a,int b){
	int ans=-INF;
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]]){swap(a,b);}
		ans = max(ans,querymax(1,1,n,dfm[top[a]],dfm[a]));
		a = fa[top[a]];
	}
	if(deep[a]>deep[b]){swap(a,b);}
	if(a!=b) ans = max(ans,querymax(1,1,n,dfm[a]+1,dfm[b]));
	return ans;
}
int chaxunmin(int a,int b){
	int ans=INF;
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]]){swap(a,b);}
		ans = min(ans,querymin(1,1,n,dfm[top[a]],dfm[a]));
		a = fa[top[a]];
	}
	if(deep[a]>deep[b]){swap(a,b);}
	if(a!=b) ans = min(ans,querymin(1,1,n,dfm[a]+1,dfm[b]));
	return ans;
}
int chaxunsum(int a,int b){
	int ans=0;
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]]){swap(a,b);}
		ans = ans+querysum(1,1,n,dfm[top[a]],dfm[a]);
		a = fa[top[a]];
	}
	if(deep[a]>deep[b]){swap(a,b);}
	if(a!=b) ans = ans+querysum(1,1,n,dfm[a]+1,dfm[b]);
	return ans;
}
void update(int a,int b){
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]]){swap(a,b);}
		update2(1,1,n,dfm[top[a]],dfm[a]);
		a = fa[top[a]];
	}
	if(deep[a]>deep[b]){swap(a,b);}
	if(a!=b) update2(1,1,n,dfm[a]+1,dfm[b]);
}
int main(){
	int i,q,a,b;
	char s[5];
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
		edge[i][0]++;edge[i][1]++;
		adde(edge[i][0],edge[i][1]);
		adde(edge[i][1],edge[i][0]);
	} 
	dfs1(1,1);
	dfs2(1,1);
	for(i=1;i<n;i++){
		if(edge[i][0]==fa[edge[i][1]])swap(edge[i][0],edge[i][1]);
		update1(1,1,n,dfm[edge[i][0]],edge[i][2]);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%s",s);
		scanf("%d %d",&a,&b);
		a++;b++;
		switch (s[0]){
			case 'C':update1(1,1,n,dfm[edge[a-1][0]],b-1);break;
			case 'N':update(a,b);break;
			case 'S':printf("%d\n",chaxunsum(a,b));break;
			case 'M':{
				if(s[1]=='A')printf("%d\n",chaxunmax(a,b));
				else printf("%d\n",chaxunmin(a,b));
				break;
			}
		}
	}
	return 0;
}
