# include <iostream>

// TEST Verhalten Typkonvertierung bei Berechnungen mit unterschiedlichen Typen
int main (){

int two = 2;
double e = 3.5/two;
std::cout << "int / double 3.5/2 : " << e << "\n";


double g = 3/two;
std::cout << "int? / int 3 / 2 : " << g << "\n";

double f = two/3.5;
std::cout << "double / int 2 / 3.5 : " << f << "\n";

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

return 0;
}
