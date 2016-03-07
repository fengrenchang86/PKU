#include<iostream.h>
#include<math.h>
#include<iomanip.h>
int main()
{
	double x1,y1,r1,x2,y2,r2,r,a,b,c,d,e,f,s1,s2,s3,s4,s;
	while(cin>>x1>>y1>>r1>>x2>>y2>>r2)
	{
		r=pow((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),0.5);
		if(r>=r1+r2)
			cout<<"0.000"<<endl;
		else if(r<=fabs(r1-r2))
		{
			r=r1<=r2?r1:r2;
			s=3.14159265358*r*r;
			cout<<setiosflags(ios::fixed)<<setprecision(3)<<s<<endl;
		}
			else
			{
				a=(r2*r2+r*r-r1*r1)/(2*r2*r);
				c=pow(1-a*a,0.5);
				s2=r2*a*r2*c;
				e=acos(a);
				e*=2;
				s1=e*r2*r2/2;
				b=(r1*r1+r*r-r2*r2)/(2*r1*r);
				d=pow(1-b*b,0.5);
				s4=r1*b*r1*d;
				f=acos(b);
				f*=2;
				s3=f*r1*r1/2;
				s=s1-s2+s3-s4;
				cout<<setiosflags(ios::fixed)<<setprecision(3)<<s<<endl;
			}
	}
	return 1;
}