#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd (int a, int b)
{
	//test valid types

	if (a == b)
	{
		return a;
	}

	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	
	int r = a % b;

	if (r == 0)
	{
		return b;
	}
	else
	{
		return gcd(b,r);
	}
	
	return 1;
}

TEST_CASE (" describe_gcd ", "[gcd]")
{
	REQUIRE (gcd (2 ,4) == 2);
	REQUIRE (gcd (9 ,6) == 3);
	REQUIRE (gcd (3 ,7) == 1);
}

int checksum (int a)
{
	int sum = 0;

	while (a>0)
	{
		sum += a % 10;
		a = a/10;
	}

	return sum;
}

TEST_CASE (" describe_checksum ", "[checksum]")
{
	REQUIRE (checksum (5) == 5);
	REQUIRE (checksum (14) == 5);
	REQUIRE (checksum (10) == 1);
	REQUIRE (checksum (140) == 5);
	REQUIRE (checksum (117190) == 19);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
