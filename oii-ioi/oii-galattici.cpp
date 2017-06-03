//Lotito Francesco 5/5
#include <iostream>
#include <fstream>
using namespace std;
char s[12];

struct tripletta
{
	int i,j;
	char c;
};

tripletta t[102];

int main ()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int m, n, k;
	in>>m>>n>>k;

	int i;
	for(i=1;i<k+1;i++)
	{
		in>>s[i];
	}

	for(i=1;i<m+1;i++)
	{
		in>>t[i].i;
		in>>t[i].j;
		in>>t[i].c;
	}
	int q=1;
	int j;
	for(i=1;i<k+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			if(s[i]==t[j].c && q==t[j].i)
			{
				q=t[j].j;
			}
		}
	}
	out<<q;
	in.close();
	out.close();
	return 0;
}
