//Lotito Francesco, 5/5
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int N, M, C, K; 
bool vis[31];
int distanze[31];
bool ossigeno[31];

typedef struct arco
{
       int peso;
       int arrivo; 
} arco;

typedef struct cabina {
        vector<arco> archi;
}cabina;

cabina grafo[31];

void dfs(int nodo, int o)
{
     if(o<20&&!ossigeno[nodo])return;
     if(!vis[nodo])
     {
                   if(ossigeno[nodo])o=20;
                   vis[nodo]=true;
                   for(int i=0;i<grafo[nodo].archi.size();i++)
                   {
                           //alg dijkstra
                           if(distanze[nodo]+grafo[nodo].archi[i].peso<distanze[grafo[nodo].archi[i].arrivo])
                           {
                                     distanze[grafo[nodo].archi[i].arrivo]=distanze[nodo]+grafo[nodo].archi[i].peso;
                                     vis[grafo[nodo].archi[i].arrivo]=false;                                                               
                           }
                           dfs(grafo[nodo].archi[i].arrivo, o);
                   }
     }
}

int main()
{
    fin>>N>>M>>C>>K;
    for(int i=0;i<K;i++) { int x; fin>>x; ossigeno[x]=true; }
    for(int i=0;i<M;i++)
    {
            int I, J, L;
            fin>>I>>J>>L;
            if(L<=20)
            {
                     arco a;
                     a.peso=L;
                     a.arrivo=J;
                     grafo[I].archi.push_back(a);
                     a.arrivo=I;
                     grafo[J].archi.push_back(a);
            }
    }
    for(int i=0;i<32;i++)distanze[i]=99999;
    distanze[1]=0;
    dfs(1, 20);
    fout<<distanze[C];
    fin.close();
    fout.close();    
}
