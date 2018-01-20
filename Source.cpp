#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//---------------------------------------------------------------
struct miestas {
	string pav;
	int plot;
	int gyv;
};
struct gal_m {
	string pav;
	int tankis;
	string valst;
};
//---------------------------------------------------------------
const char CDfv1[] = "Valstybe1.txt";
const char CDfv2[] = "valstybe2.txt";
const char CRfv[] = "Rezultatai.txt";
const int CMax = 256;
//ifstream fd(CDfv);
ofstream fr(CRfv);
//---------------------------------------------------------------
void read (const char CDfv[] ,miestas V[], int & n, string & P);
void rast (miestas V[], int n, string P, gal_m Va[], int & ng, int x);
bool Raktas (gal_m A, gal_m B);
void rik  (gal_m Va[], int ng);
void print (gal_m Va[], int ng);
//---------------------------------------------------------------
int main()
{
	miestas V1[100], V2[100];
	gal_m Va[100];
	string P1, P2;
	int x, n1=0, n2=0, ng=0;;

	read (CDfv1, V1, n1, P1);
	read (CDfv2, V2, n2, P2);

	cout << " iveskite x : " <<endl;
	cin >> x;

	rast (V1, n1, P1, Va, ng, x);
	rast (V2, n2, P2, Va, ng, x);
	
	rik (Va, ng);
	print (Va, ng);

	return 0;
}
//---------------------------------------------------------------
void print (gal_m Va[], int ng)
{
	for ( int i = 0; i < ng; i++)
		fr << Va[i].pav << "  " << Va[i].tankis << " "<< Va[i].valst <<endl;
}
bool Raktas (gal_m A, gal_m B)
{
	if (A.tankis > B.tankis) return true;
	else return false;
}
void rik  (gal_m Va[], int ng)
{
	int mini;
	gal_m b;
	for (int i = 0; i < ng - 1; i++) {
		mini = i;
		for ( int j = i + 1; j < ng; j++)
			if (Raktas(Va[j], Va[mini]) )
			mini = j;
			b = Va[i];
			Va[i] = Va[mini];
			Va[mini] = b;

			}
}
//---------------------------------------------------------------
void rast (miestas V[], int n, string P, gal_m Va[], int & ng, int x)
{
	for ( int i = 0; i < n; i++)
	{
		
		int tank = V[i].gyv / V[i].plot;
		if (tank > x)
		{
			Va[ng].pav = V[i].pav;
			Va[ng].tankis = tank;
			Va[ng].valst = P;
			ng++;
		}
	}
}
//---------------------------------------------------------------
void read (const char CDfv[] ,miestas V[], int & n, string & P)
{
	ifstream fd(CDfv);

	fd >> P;

	while ( !fd.eof() )
	{
		fd >> V[n].pav >> V[n].plot >> V[n].gyv;
		n++;
	}
	fd.close();
}
//---------------------------------------------------------------