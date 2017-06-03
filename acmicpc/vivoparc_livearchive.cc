#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100+100;
const int inf=0x3fffffff;
const int mod=1000000000+7;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
int n,edge_cnt;
char str[MAXN];
int col[MAXN],head[MAXN],mp[MAXN][MAXN];
struct Edge{
    int v;
    int next;
}edge[MAXN*MAXN*20];
void init(){
    edge_cnt=0;
    memset(mp,0,sizeof(mp));
    memset(col,-1,sizeof(col));
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    edge[edge_cnt].v=v;
    edge[edge_cnt].next=head[u];
    head[u]=edge_cnt++;
}
bool dfs(int u){
    int c[5];
    memset(c,0,sizeof(c));
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(col[v])
            c[col[v]]++;
    }
    for(int k=1;k<=4;k++) if(!c[k]){
        col[u]=k;
        int flag=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(col[v] == -1){
                if(!dfs(v)){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            return true;
    }
    col[u]=-1;
    return false;
}
int main()
{
    //freopen("text","r",stdin);
    int kase=0;
    scanf("%d",&n);
    while(n){
        int tmp=0;
        if(kase)
            printf("\n");
        kase++;
        init();
        while(~scanf("%s",str)){
            int u=0,v=0,i=0,len=strlen(str);
            while(str[i] && str[i]!='-'){
                u=u*10+str[i]-'0';
                i++;
            }
            if(i == len){
                tmp=u;
                break;
            }
            i++;
            while(str[i]!='\0'){
                v=v*10+str[i]-'0';
                i++;
            }
            mp[u][v]=1; mp[v][u]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(mp[i][j])
                    addedge(i,j);
        for(int i=1;i<=n;i++)
            if(col[i]==-1)
                dfs(i);
        for(int i=1;i<=n;i++)
            printf("%d %d\n",i,col[i]);
        n=tmp;
    }
    return 0;
}  
