#include<iostream>
int main(){
	using namespace std;
	int n=1,m=1,p[22][22],q1[22],q2[22],i,j,k,g,s[22],x1,y1,x2,y2,a,b,c,A[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
	char d;
	while(1){
		cin>>m>>n;
		if(m==0 && n==0){
			break;
		}
		for(i=1;i<=m;i++){
			p[i][0] = 0;
			p[i][n+1] = 0;
			for(j=1;j<=n;j++){
				cin>>d;
				if(d=='.') p[i][j] = 1;
				else if(d=='@'){
					p[i][j] = 1;
					x1 = i;y1 = j;
				}
				else if(d=='#') p[i][j] = 0;
				else if(d=='*'){
					p[i][j] = 1;
					x2 = i;y2 = j;
				}
			}
		}
		for(i=0;i<=n+1;i++){
			p[0][i] = 0;
			p[m+1][i] = 0;
		}
		g = 0;
		k = 1;
		/*for(i=0;i<=m+1;i++){
			for(j=0;j<=n+1;j++){
				cout<<p[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;*/
		q1[0] = x1;
		q2[0] = y1;
		s[0] = 1;
		while(g!=k){
			a = 0;
			if(p[q1[g]][q2[g]]){
				for(i=0;i<=3;i++){
					b = q1[g]+A[i][0];c = q2[g]+A[i][1];
					if(p[b][c]){
						q1[k] = b;q2[k] = c;s[k] = s[g]+1;
						if(b==x2 && c==y2){
							a=1;
							break;
						}
						k = k==21?0:k+1;
					}
				}
				p[q1[g]][q2[g]] = 0;
			}
			if(a){
				break;
			}
			g = g==21?0:g+1;
			/*for(i=0;i<=m+1;i++){
			for(j=0;j<=n+1;j++){
				cout<<p[i][j]<<' ';
			}
			cout<<endl;
		}
			cout<<endl;*/
		}
		if(g!=k){
			cout<<s[k]-1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
