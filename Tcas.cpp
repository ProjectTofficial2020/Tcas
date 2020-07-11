//Tcas a computer algebra system in ProjectT
//claim:
//Tcas is a computer algebra system under GPL3.0 liscense.
//Author: ProjectToffcial2020@github, projectt2020@gmail.com
//the real author(which by the way is me) doesn't want any one to know who he is,
//but would also don't want any one to commit crime or do something bad, so to vertify who I am, check the public key:
/*-----BEGIN PUBLIC KEY-----
MIICITANBgkqhkiG9w0BAQEFAAOCAg4AMIICCQKCAgBqGMAddzF/rRNRHwR1HXjt
hWVfjENXPf91Ygc/a5kNuwygImUtt3F/0af0lWWbYGrciCMmHZHnuMEuLVtPQ0ZV
1+q/R4PTW2+EZd/6MBwbpsaGyN5i8bC+Do0NL5fKp/X3ZMXGVccb0iKwmkSFgUV8
l87caYNFUfr4TXhxArab9IQiox9Ec9/QVaY5bTBoTQrh3N6Y5IMj3dd7l90xxocS
9nYVQncizFF7ZEQkPg2NSbraCtI56VHxzrdX1XZEp9wVr2W0JCa7napkFsw7gm0V
Fa3wb+8HjVT0ria+BUxrOes0i/zc2BltCUV2eo5QiinGomAinQfvK4gLDCuX9onL
RuljsBkPXGia9hITQ70NhfOh6/U29OX1TFn82GGSocIz/ps4ptjSsaoy9lI0mEQL
VwKtN4A+V+SJV7q3HoucehxNzICqm0Vq1tZLbE8Amxd95TkZ3un8O+yYG6UD3fy6
3v64hhYa4t5UEZcpr9jfvn75BYo0PqrR1jlvb7kMFyy30NHeOTwb+Wji2Cv0D724
K0VoFf87I6N7YMUpavMyAUewV832Ffmu6qkfIGNEcQPvq3/69FjeNWYzFhdiTsnn
PZkmnamO7uGPj8uChLN6tFik1oKStdAalA/fKgLOHnzKnO38LaTp7O01vmtBUKas
ABRUSD6UM/5M1i+A94po3QIDAQAB
-----END PUBLIC KEY-----*/
//ask someone who claim that he is the author to encode the time+projecttoffial with the private key.

//here's the main code, I'll keep it simple and filled with comments as I possibly can.
//this is the CLI version(or the core version, if you want), so there's no GUI, check github repo the find the GUI version

//headers required, no need to explain
#include<iostream>
#include<regex>
#include<string>
//use in debug
#include<stdlib.h>

using namespace std;

//vars defined.


//this is ued only when init
bool solve_when_init = 1;
//this is used several times
bool solve_when_cal = 0;


// 
class Tcas {
public:
	//operator +
	Tcas operator+(Tcas &input) {
		Tcas tmp;
		tmp.val = 0;
		tmp.exp = this->exp + "+" + input.exp;
		this->simpflify();
		if (solve_when_cal) {
			tmp.val = tmp.solve();
			tmp.check = 1;
		}
		return tmp;
	}
	//a tcas value is stored like e+2(in exp),4.7182818284590452353602874713527(in val)
	string exp=string("0");
	double val=0;
	//this check value represents if the exp value is equal to val(with in error)
	bool check = 0;
	//there's actually a conflict about exp doesn't match with val
	//the soultion is when init, only get the exp, not the val, when a val is required, solve it
	void __init__(string iexp) {
		this->val = 0;
		this->check = 0;
		this->exp = iexp;
		if (solve_when_init) {
			//the var named solve_when_init is used only here
			this->val = solve();
			this->check = 1;
		}
	}
	Tcas simpflify() {
		Tcas tmp;
		//TODO: simpfily the expression;
		tmp.exp = this->exp;
		return tmp;
	}
	//get the value from exp, return the value of exp to val
	double solve() {
		//debug mode
		return atoi(this->exp.c_str());
	}
};
int main() {
	//the var expression is used to store the chars given, create a Tcas var called tmp with expression
	string expression;
	Tcas tmp;
	while (1) {
		try {
			//this is when the program runs smoothly
			cin >> expression;
			tmp.__init__(expression);
			tmp.solve();
			cout << tmp.val << endl;
		}
		catch (const char* e) {
			cout << e<<endl;
		}
	}
	return 0;
}
