#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int head[N],to[N<<1],nex[N<<1],ent;
int dfm[N],top[N],siz[N],deep[N],son[N],fa[N];
int dfn,n;
int edge[N][3];
int tree[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
int chaxun(int p,int pl,int pr,int l,int r){
	if(r<pl || l>pr){return 0;}
	if(l<=pl && r>=pr){return tree[p];}
	int mid=(pl+pr)>>1,ans=0;
	ans = max(chaxun(ls(p),pl,mid,l,r),ans);
	ans = max(chaxun(rs(p),mid+1,pr,l,r),ans);
	return ans;
}
void update(int p,int pl,int pr,int x,int d){
	if(pl==pr){
		tree[p]=d;
		return ;
	}
	int mid=(pl+pr)>>1;
	if(x<=mid) update(ls(p),pl,mid,x,d);
	else update(rs(p),mid+1,pr,x,d);
	push_up(p);
}
void adde(int u,int v){
	ent++;
	to[ent]=v;
	nex[ent]=head[u];
	head[u]=ent;
}
void dfs1(int s,int f){
	int i;
	deep[s]=deep[f]+1;
	fa[s]=f;
	siz[s]=1;
	for(i=head[s];i;i=nex[i]){
		if(to[i]==f){continue;}
		dfs1(to[i],s);
		siz[s]+=siz[to[i]];
		if(siz[to[i]]>siz[son[s]])son[s]=to[i];
	}
}
int query(int a,int b){
	int ans = 0;
	while(top[a]!=top[b]){
		if(deep[top[a]]<deep[top[b]]){swap(a,b);}
		ans = max(ans,chaxun(1,1,n,dfm[top[a]],dfm[a]));
		a = fa[top[a]];
	}
	if(deep[a]>deep[b]){swap(a,b);}
	ans = max(ans,chaxun(1,1,n,dfm[a]+1,dfm[b]));
	return ans;
}
void dfs2(int s,int topx){
	int i;
	top[s]=topx;
	dfm[s]=++dfn;
	if(son[s]){dfs2(son[s],topx);}
	for(i=head[s];i;i=nex[i]){
		if(to[i]==fa[s] || to[i]==son[s])continue;
		dfs2(to[i],to[i]);
	}
}
int main(){
	int i,a,b;
	char s[10];
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge[i][2]);
		adde(edge[i][0],edge[i][1]);
		adde(edge[i][1],edge[i][0]);
	}
	dfs1(1,1);
	dfs2(1,1);
	for(i=1;i<n;i++){
		if(fa[edge[i][1]]=edge[i][0]){swap(edge[i][0],edge[i][1]);}
		update(1,1,n,dfm[edge[i][0]],edge[i][2]);
	}
	while(1){
		scanf("%s",s);
		if(s[0]=='D')break;
		else{
			scanf("%d %d",&a,&b);
			if(s[0]=='Q')printf("%d\n",query(a,b));
			else update(1,1,n,dfm[edge[a][0]],b);
		}
	}
	return 0;
}
