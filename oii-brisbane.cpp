//Lotito Francesco, 5/5
#include<fstream>
#include<vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int N, A, Mg, Mb, Mt;
int attrazioni[1001];
bool vis[1001];
typedef struct arco { int a,b, tipo; };
vector<arco> archi;
vector<int> grafo[1001];

void dfs(int nodo)
{
     if(!vis[nodo])
     {
                   vis[nodo]=true;
                   for(int i=0;i<grafo[nodo].size();i++) dfs(grafo[nodo].at(i));
     }
}

int ris(int tipo)
{
    for(int i=0;i<N;i++)vis[i]=false;
    for(int i=0;i<N;i++)grafo[i].clear();
    for(int i=0;i<Mg+Mb+Mt;i++)
    {
            if(archi[i].tipo==1) { grafo[archi[i].a].push_back(archi[i].b); grafo[archi[i].b].push_back(archi[i].a);}
            if(archi[i].tipo==tipo) { grafo[archi[i].a].push_back(archi[i].b); grafo[archi[i].b].push_back(archi[i].a);}
            if(tipo==4) { grafo[archi[i].a].push_back(archi[i].b); grafo[archi[i].b].push_back(archi[i].a);}
    }
    dfs(0);
    int sol=0;
    for(int i=0;i<A;i++)
    {
            if(vis[attrazioni[i]])sol++;
    }
    return sol;
}

int main()
{
   in>>N>>A>>Mg>>Mb>>Mt; 
   for(int i=0;i<A;i++) in>>attrazioni[i];
   for(int i=0;i<Mg;i++) { arco t; in>>t.a>>t.b; t.tipo=1; archi.push_back(t);}
   for(int i=0;i<Mb;i++) { arco t; in>>t.a>>t.b; t.tipo=2; archi.push_back(t);}
   for(int i=0;i<Mt;i++) { arco t; in>>t.a>>t.b; t.tipo=3; archi.push_back(t);}
   out<<ris(1)<<endl;
   out<<ris(2)<<endl;
   out<<ris(3)<<endl;
   out<<ris(4)<<endl;
   in.close();
   out.close();
}


