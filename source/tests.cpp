#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

/**********
** GCD
**********/

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

/**********
** Checksum
**********/

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

/**********
** sumMultiples
**********/

int sumMultiples (int a)
{
	int sum = 0;
	for (int i = 1; i<=a; ++i)
	{
		if (i % 3 == 0 or i % 5 == 0)
		{
			sum += i;
		}
	}
	return sum;
}

TEST_CASE (" describe_sumMultiples ", "[sumMultiples]")
{
	REQUIRE (sumMultiples(10) == 3+6+9+5+10);
	REQUIRE (sumMultiples(1000) == 234168);
}

/**********
** fract
**********/

float fract (float a)
{
	if (a == 1)
	{
		return 0.0f;
	}
	else if (a < 1)
	{
		return a;
	}
	else
	{
		while (a > 1)
		{
			a -= 1;
		}
		return fract(a);
	}
}

TEST_CASE (" describe_fract ", "[fract]")
{
	REQUIRE (fract(10.5f) == Approx(0.5f));
	REQUIRE (fract(10.0f) == Approx(0.0f));
}

/*************************
** Zylinder Berechnungen
*************************/

float zylinder_vol (float r, float h)
{
	return M_PI * pow(r,2) * h;
}

TEST_CASE (" describe_zylinder_vol ", "[zylinder_vol]")
{
	REQUIRE (zylinder_vol(2.0f, 3.0f) == Approx(37.69911184f));
}

float zylinder_surf (float r, float h)
{
	return 2 * M_PI * r * (h + r);
}

TEST_CASE (" describe_zylinder_surf ", "[zylinder_surf]")
{
	REQUIRE (zylinder_surf(2.0f, 3.0f) == Approx(62.83185307f));
}

/***********************
** Binomialkoeffizient
***********************/

int fakultaet (int a)
{
	int x = 1;
	for (int i = 1; i <= a; ++i)
	{
		x *= i;
	}
	return x;
}

TEST_CASE (" describe_fakulataet ", "[fakultaet]")
{
	REQUIRE (fakultaet(5) == 120);
	REQUIRE (fakultaet(3) == 6);
	REQUIRE (fakultaet(2) == 2);

}

int binomial (int n, int k)
{
	// für n, k nichtnegative ganze Zahlen, n>=k
	//	n!/k! *(n-k)!;

	if (n < k or n < 0 or k < 0)
	{
		return -1;
	}
	else
	{
		return fakultaet(n) / (fakultaet(k) * fakultaet(n-k));
	}
}

TEST_CASE (" describe_binomial ", "[binomial]")
{
	REQUIRE (binomial(5,3) == 10);
	REQUIRE (binomial(2,1) == 2);
	REQUIRE (binomial(2,0) == 1);
	REQUIRE (binomial(0,1) == -1);
}

/***********************
** Binomialkoeffizient
***********************/

bool is_prime (int a)
{
	if (a < 2){return false;}
	if (a == 2){return true;}

	bool is_prime = true;
	for (int i = 2; i<a and is_prime == true; ++i)
	{
		if (a % i == 0)
		{
			is_prime = false;
		}
	}
	return is_prime;
}

TEST_CASE (" describe_is_prime ", "[is_prime]")
{
	REQUIRE (is_prime(0) == false);
	REQUIRE (is_prime(1) == false);
	REQUIRE (is_prime(2) == true);
	REQUIRE (is_prime(3) == true);
	REQUIRE (is_prime(4) == false);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
