#include <iostream>
#include <string>
#define max 50
using namespace std;
class Postfix
{
public:
	int Precedence(char ch)
	{
		switch (ch)
		{
		case '^':
			return 4;
		case '/':
		case '*':
			return 3;
		case '+':
		case '-':
			return 2;
		default:
			return 1;
		}
	}

	void Convert()
	{
		string infix;
		char poststack[max]={}, opstack[max]={};
		int i, o=-1, p=-1, len, length;
		cout<<"Enter a infix: ";
		cin>>infix;
		length=infix.length();
		len=length;
		for(i=0;i<=length;i++){
			if(infix[i]=='('){
				opstack[++o]=infix[i];
				len++;
			}
			else if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z')){
				poststack[++p]=infix[i];
			}
			else if(infix[i]==')'){
				len++;
				while(opstack[o]!='('){
					poststack[++p]=opstack[o];
					o--;
				}
			}
			else{
				if(Precedence(opstack[o])>=Precedence(infix[i])){
					poststack[++p]=opstack[o--];
					opstack[++o]=infix[i];
				}
				opstack[++o]=infix[i];
			}
//			cout<<"Opstack: "<<opstack<<endl; A+B^C*D/E
//			cout<<"poststack: "<<poststack<<endl;
		}
		
		while(o!=0){
			poststack[++p]=opstack[o];
			o--;
		}
		cout<<"Postfix: ";
		for(i=0;i<=len;i++){
			if(poststack[i]=='('||poststack[i]==')'){
				continue;
			}
			else
			cout<<poststack[i];
		}	
	}
};
int main()
{
	Postfix object;
	object.Convert();
	return 0;
}
