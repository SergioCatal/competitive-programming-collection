//Lotito Francesco 100/100
#include<fstream>
#include<iostream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int mat[500][500];
int N, M;
int solR[500];
int solC[500];

void leggi()
{
    in>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            in>>mat[i][j];
        }
    }
}

int risolvi()
{
    //RIGHE
    for(int i=0;i<N;i++)
    {
        int cont=0;
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==1) cont++;
        }
        //se più della metà accese, attivo
        if(cont>M/2)
        {
            for(int j=0;j<M;j++)
            {
                if(mat[i][j]==1)
                    mat[i][j]=0;
                else
                    mat[i][j]=1;
            }
            solR[i]=1;
        }
        else
        {
            solR[i]=0;
        }
    }
    //COLONNE
    for(int i=0;i<M;i++)
    {
        int cont=0;
        for(int j=0;j<N;j++)
        {
            if(mat[j][i]==1) cont++;
        }
        //se più della metà accese, attivo
        if(cont>N/2)
        {
            for(int j=0;j<N;j++)
            {
                if(mat[j][i]==1)
                    mat[j][i]=0;
                else
                    mat[j][i]=1;
            }
            solC[i]=1;
        }
        else
        {
            solC[i]=0;
        }
    }
    //CONTROLLO
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(mat[i][j]==1) return 0;
        }
    }
    return 1;
}

int main()
{
    leggi();
    int ris=risolvi();
    if(ris==1)
    {
        for(int i=0;i<N;i++) out<<solR[i];
        out<<endl;
        for(int i=0;i<M;i++) out<<solC[i];
        out<<endl;
    }
    else
    {
        for(int i=0;i<N;i++) out<<"0";
        out<<endl;
        for(int i=0;i<M;i++) out<<"0";
        out<<endl;
    }
}
