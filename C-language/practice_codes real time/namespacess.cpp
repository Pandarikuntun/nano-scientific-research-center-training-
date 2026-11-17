#include<iostream>
using namespace std;
namespace A{
	
	int x=8;
	void dis()
	{
		int y=30;
		cout<<y<<endl;
	}
}
namespace B{
	
	int x=80;
	void dis()
	{
	int	y=300;
		cout<<y<<endl;
	}
}
int main()
{
	cout<<A::x<<endl;
	cout<<B::x<<endl;
	A::dis();
	B::dis();
	return 0;
}
