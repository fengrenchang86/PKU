#include <iostream>
#include <stack>
using namespace std;
struct ac
{
	int x,y;
	int k;
}t[30],v,u;
stack<ac> st;
int main ()
{
	int i,j,n,x,y;
	bool ok = true;
	int sum = 0;
	char ch,a[1000];
	cin>>n;
	for ( i = 1; i <= n; i++ )
	{
		cin>>ch>>x>>y;
		t[ch-'A'].x = x;
		t[ch-'A'].y = y;
	}
	while ( cin>>a )
	{
		ok = true;
		sum = 0;
		while ( st.size() != 0 )
			st.pop();
		for ( i = 0; a[i] != NULL; i++ )
		{
			j = a[i]-'A';
			if ( a[i] >= 'A' && a[i] <= 'Z' )
			{
				if ( st.size() != 0 )
					v = st.top();
				else
				{
					v.x = t[j].x;
					v.y = t[j].y;
					v.k = 1;
					st.push(v);
					continue;
				}
				if ( v.k == 1 )
				{
					if ( v.y != t[j].x )
					{
						ok = false;
						break;
					}
					sum += v.x*v.y*t[j].y;
					v.y = t[j].y;
					v.k = 1;
					st.pop();
					st.push(v);
				}
				else
				{
					v.x = t[j].x;
					v.y = t[j].y;
					v.k = 1;
					st.push(v);
				}
			}
			else if ( a[i] == '(' )
			{
				v.k = 0;
				st.push(v);
			}
			else
			{
				v = st.top();
				st.pop();
				if ( v.k == 0 )
				{
					st.pop();
				}
				else
				{
					st.pop();
					if ( st.size() != 0 )
					{
						u = st.top();
						st.pop();
					}
					else
						continue;
					if ( u.k == 1 )
					{
						if ( u.y != v.x )
						{
							ok = false;
							break;
						}
						sum += u.x*u.y*v.y;
						u.y = v.y;
						st.push(u);
					}
					else
					{
						st.push(v);
						st.push(u);
					}
				}
			}
		}
		if ( ok == true )
			cout<<sum<<endl;
		else
			cout<<"error"<<endl;
	}
	return 0;
}