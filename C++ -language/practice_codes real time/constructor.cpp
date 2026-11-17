#include<iostream>
using namespace std;
class Constructor{
	public:int x,y,z;
	public:Constructor(){
		x=10;
		y=20;
		cout<<"default constructor is calling"<<endl;
	}
	public:Constructor(int a,int b){
		x=a;
		y=b;
		cout<<"paramitarised constructor is calling"<<endl;
	}
	int sum(){
		z=x+y;
		cout<<"x+y= "<<z<<endl;
	}
	~Constructor(){
		cout<<"distructor is calling"<<endl;
	}
};
int main(){
	int a,b;
	cout<<"enter the a and b"<<endl;
	cin>>a>>b;
	Constructor obj,obj1(a,b);
	obj.sum();
	obj1.sum();
}
