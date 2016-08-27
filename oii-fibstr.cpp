//Lotito Francesco 100/100

#include<fstream>
using namespace std;

pair<int,int> sol; //contiene inizio e fine stringa
ifstream in("input.txt"); ofstream out("output.txt");
char stringa[1000001]; //stringa input
string sfib; //stringa fib
int N; //lunghezza stringa
char tempx, tempy; //lettere per sostituire x e y
void read() { in>>N; for(int i=0;i<N;i++) in>>stringa[i]; in.close(); }
int generata;
char attesa;

//GENERA SEQUENZA GENERALIZZATA FIBONACCI
string fib(int n)
{
	if(n==0) return "y";
	if(n==1) return "x";
	return fib(n-1)+fib(n-2);
}

bool comp(char a)
{
	if(attesa=='x')
	{
		if(a==tempx) return true;
	}
	if(attesa=='y')
	{
		if(a==tempy) return true;
	}
	return false;
}

void solve()
{
	int inizio, fine;
	int pos;
	for(int i=0;i<N;i++)
	{
		pos=2;
		inizio=i;
		fine=i+2;
		tempx=stringa[i]; //x=a
		tempy=stringa[i+1]; //y=b
		if(tempx!=tempy)
		{
			if(sol.first==0&&sol.second==0)
			{
				sol=make_pair(inizio+1, inizio+2);
			}
			//comincio ricerca pattern
			attesa=sfib[pos];
			while(comp(stringa[fine])) //finché esiste match
			{
				pos++; //scalo nella stringa fib
				fine++; //scalo nella stringa data in input
				if(pos==sfib.length())
				{
					if(fine-inizio>sol.second-sol.first) sol=make_pair(inizio+1, fine);
					generata++;
					sfib=fib(generata); //allargo la stringa di fib
				}
				attesa=sfib[pos];
			}
			fine--;
		}
	}
}
	
int main()
{
	read();
	sol=make_pair(0,0);
	generata=3;
	sfib=fib(generata); //GENERO STRINGA FIB INIZIALE
	solve();
	out<<sol.first<<" "<<sol.second<<endl;
	out.close();
	return 0;
}
