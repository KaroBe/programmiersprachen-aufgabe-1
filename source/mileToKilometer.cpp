# define CATCH_CONFIG_RUNNER
# include <catch.hpp>
# include <iostream>
# include <string>

double mileToKilometer(double miles)
{
	return miles * 1.61;
}

TEST_CASE (" describe_mileToKilometer ", "[mileToKilometer]")
{
	REQUIRE(mileToKilometer(1) == 1.61);
}

int main(int argc, char* argv[])
{
	std :: cout << " Eingabe in Meilen: \n " ;
	double miles ;
	std :: cin >> miles ;
	std :: cout << " Das sind " << mileToKilometer(miles) 
				<< " Kilometer.\n" ;

	return Catch::Session().run(argc, argv);
}