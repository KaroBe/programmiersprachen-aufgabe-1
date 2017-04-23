# include <iostream>

int main (){

// BRUTE FORCE KGV Berechnug 1-20

bool foundit = false;
int div = 20;


while(foundit == false){
	foundit = true;
	for(int i = 1; i <=20; ++i){
			if (div % i != 0){
			foundit = false;
   		}
	}
	div = div + 20;
}
div = div-20;
std::cout << "GGT der Zahlen 1-20: " << div << "\n";
return 0;
}
