#include<iostream>
using namespace std;
class devise{
	private: int status;
	public:devise(){
		status=0;
	}
	turnon(){
		status=1;
	}
	turnoff(){
		status=0;
	}
	showstatus(){
		if(status==0)
		cout<<"devise off"<<endl;
		else
		cout<<"devise on"<<endl;
	}
};
int main(){
	devise obj;
	obj.turnon();
	obj.showstatus();
	obj.turnoff();
	obj.showstatus();
}
