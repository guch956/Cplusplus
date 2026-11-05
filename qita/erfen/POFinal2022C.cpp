#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int zhan[40003];
int fx[4][2];
struct node{
    int x;
    int y;
    int f;
    node(int x1,int y1,int f1){
        x = x1;y = y1;f = f1;
    }
};
int main(){
    char **p;
    int **t;
    int **dis;
    int n,m,i,j,top=0,stax,stay,kinx,kiny,l,r,mid,x,y,x1,y1,u,d;
    char c;
    node v(0,0,0);
    queue<int> q;
    queue<node> qq;
    scanf("%d %d",&n,&m);
    fx[0][0]=1;
    fx[1][1]=1;
    fx[2][0]=-1;
    fx[3][1]=-1;
    p = new char*[n];
    t = new int*[n];
    dis = new int*[n];
    for(i=0;i<n;i++){
        p[i] = new char[m];
        t[i] = new int[m];
        dis[i] = new int[m];
        for(j=0;j<m;j++){
            c = getchar();
            while(c!='.' && c!='o' && c!='R' && c!='A' && c!='K'){c = getchar();}
            p[i][j]=c;
            if(c=='R'){
                zhan[++top]=i*m+j;
            }
            if(c=='A'){
                stax=i;
                stay=j;
            }
            if(c=='K'){
                kinx=i;
                kiny=j;
            }
        }
    }
    l = 1;r = m+n;
    while(l<r){
        mid = (l+r)>>1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                t[i][j]=0;
                dis[i][j]=0x3f3f3f3f;
            }
        }
        for(i=1;i<=top;i++){
            q.push(zhan[i]);
            dis[zhan[i]/m][zhan[i]%m]=0;
        }
        while(q.size()){
            u = q.front();
            q.pop();
            x = u/m;y = u%m;
            d = dis[x][y];
            t[x][y]=1;
            if(d==mid){continue;}
            for(i=0;i<4;i++){
                x1 = x+fx[i][0];
                y1 = y+fx[i][1];
                if(0<=x1 && x1<n && 0<=y1 && y1<m){
                    if(dis[x1][y1]>d+1){
                        dis[x1][y1]=d+1;
                        q.push(x1*m+y1);
                    }
                }
            }
        }
        for(i=0;i<4;i++){
            if(t[stax][stay]!=1){
                qq.push(node(stax,stay,i));
                t[stax][stay]=2;
            }
        }
        while(qq.size()){
            v = qq.front();
            qq.pop();
            x1 = v.x+fx[v.f][0];
            y1 = v.y+fx[v.f][1];
            if(0<=x1 && x1<n && 0<=y1 && y1<m && t[x1][y1]!=1){
                if(p[x1][y1]=='o'){
                    if(t[x1][y1]==0){
                        t[x1][y1]=2;
                        for(i=0;i<4;i++){
                            if((v.f+2)%4!=i){
                                qq.push(node(x1,y1,i));
                            }
                        }
                    }
                }
                else{
                    t[x1][y1]=2;
                    qq.push(node(x1,y1,v.f));
                }
            }
        }
        if(t[kinx][kiny]!=2){r = mid;}
        else{l = mid+1;}
    }
    printf("%d",l);
    return 0;
}