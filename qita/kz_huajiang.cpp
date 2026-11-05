#include<iostream>
void read(int &x){
	char c=getchar();x=0;int f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}
int main(){
    using namespace std;
    int n,*q,**p,i,j,s;
    read(n);
    q = new int[n];
    p = new int*[n];
    for(i=0;i<n;i++){
        read(q[i]);
        p[i] = new int[2];
    }
    p[0][0]=1;
    p[0][1]=1;
    for(i=1;i<n;i++){
        p[i][0]=1;p[i][1]=1;
        for(j=0;j<i;j++){
            if(q[j]<q[i]){
                p[i][0]=max(p[i][0],p[j][1]+1);
            }
            if(q[j]>q[i]){
                p[i][1]=max(p[i][1],p[j][0]+1);
            }
        }
    }
    s = 0;
    for(i=0;i<n;i++){
        s = max(s,p[i][0]);
        s = max(s,p[i][1]);
    }
    cout<<s;
    return 0;
}