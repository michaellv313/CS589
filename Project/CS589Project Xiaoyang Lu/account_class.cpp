
class account
{
public:
account();
int open(int, int, int);
int deposit (int) ;
int withdraw (int);
int balance();
int lock(int);
int unlock(int);
int login(int);
int logout();
int pin(int);
int show_balance(){return x1;};//testing oriented method

private:
	int x1;		//balance
	int x2;		
	int x3;		//pin #
	int x4;		
	int x5;		// account #
	int x6;		// penalty
	int x7;		// minimum balance
	int k;
	int num;	//maximum # of attempts with incorrect pin
};

account::account(){
	x2=0;
	x4=-1;
	x6=10;
	x7=1000;
	k=0;
	num=2;
}

int account::open(int x, int y, int z){
	if ((x>0)&&(x4==-1)) {
		x1=x;
		x3=y;
		x5=z;
		x4=0;
		return 0;
	};
	return -1;
}

int account::pin(int x) {
	if (x4!=1) return -1;
	if (x==x3) {x4=2; return 0;}
	else k++;
	if (k>=num) x4=0;
	return -1;
}


int account::logout() {
	if ((x4==0)||(x2==1)) return -1;
	x4=0;
	return 0;
}

int account::login(int x) {
	if (x4!=0) return -1;
	if (x5==x) {x4=1; k=0; return 0;}
	return -1;
}

int account::balance() {
	if (x4!=2) return -1;
	return x1;
}

int account::lock(int x) {
	if (x4!=2) return -1;
	if (x!=x3) return -1;
	if (x2==0) {x2=1; return 0;}
	else return -1;
}

int account::unlock(int x) {
	if (x4!=2) return -1;
	if ((x2)&&(x==x3)) {x2=0;
	return 0;}
	else return -1;
}

int account::deposit(int d) {
	if (x4!=2) return -1;
	if (x2) {return -1;};
	if ((x1<x7)&&(d>0)) {
		x1=x1+d-x6;
		return 0;}
	else { if (d>0) {
		x1=x1+d;
		return 0; }
     }
 return -1;
}

int account::withdraw(int w) {
if (x4!=2) return -1;	
if (x2) {return -1;};
if ((x1>w)&&(w>0)) {
	if (x1<x7) {return -1;}
	else {x1=x1-w;};
	if (x1<x7) x1=x1-x6;
  return 0;}
return -1;
}

