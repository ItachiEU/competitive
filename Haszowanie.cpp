//*** haszowanie ***
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn=1e5+5;
ll pot[maxn], P=263, MOD=1e9+7;
struct hasze
{
	vector <ll> Hasz;

	hasze (const string& s)
	{
		Hasz.resize(s.size()+1);
		for(int i=1; i<=s.size(); i++)
		{
			Hasz[i]=(Hasz[i-1]*P+s[i-1])%MOD;
		}
	}
	
	ll licz_hasze(int p, int k)
	{
		ll res=0;
		res=(Hasz[k+1]-Hasz[p]*pot[k-p+1])%MOD+MOD;
		if(res>=MOD)
		res-=MOD;
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	pot[0]=1;
	for(int i=1; i<maxn; i++)
	{
		pot[i]=(pot[i-1]*P)%MOD;
	}
	int t;
	cin>>t;
	bool bylo=false, znak=false;
	for(int i=0; i<t; i++)
	{
		string a, b,c,d;
		cin>>a;
		hasze tekst(a);
		
		cin>>b;	
		znak=false;
		int size=0, y=0, wynik=0;
		for(int x=0; x<b.size(); x++)
		{
			
			if(b[x]=='?')
			{
				znak=true;
				continue;
			}
			else
			if(znak!=true)
			c.push_back(b[x]);
			
			if(znak==true)
			{
				d.push_back(b[x]);
			}
		}
		hasze w1(c);
		hasze w2(d);
		
		ll test1=w1.licz_hasze(0, c.size()-1);
		ll test2=w2.licz_hasze(0, d.size()-1);
		for(int j=0; j<a.size()-c.size()-d.size()+1; j++)
		{
			//cout<<j<<" "<<j+b.size()-1<<endl;
			if(test1==tekst.licz_hasze(j, j+c.size()-1))
			{
				if(d.size()==0)
				{
					if(znak==true && j+c.size()-1==a.size()-1)
					continue;
					wynik++;
				}
				else
				if(test2==tekst.licz_hasze(j+c.size()+1,j+c.size()+1+d.size()-1))
				{
					if(j+c.size()+1+d.size()-1>a.size()-1)
					break;
					wynik++;
				}
			}
		}
		cout<<wynik<<"\n";
	}	
}
