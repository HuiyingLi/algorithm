#include<iostream>
#include<sstream>
using namespace std;
int main(){
	int n;
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		ss>>n;
		cout<<"2 "<<n<<" "<<n<<endl;
		for(int i=0;i<n;i++){
			char c=(char)('A'+i);
			if(i>25)
				c+=6;
			for(int j=0;j<n;j++){
				cout<<c;
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j>25)
					cout<<(char)('A'+j+6);
				else
					cout<<(char)('A'+j);
			}
			cout<<endl;
		}
	}
	return 0;
}
