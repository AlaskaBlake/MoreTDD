//tests.cpp
//Blake Caldwell
//March 10, 2020
//tests the kata function

#define CATCH_CONFIG_MAIN
#include "kata.h"
#include "catch.hpp"

TEST_CASE("String of zero"){
	{
		INFO("The empty string should return 0.");
		REQUIRE(stringCalc("") == 0);
	}
}

TEST_CASE("String containing one number") {
	{
		INFO("The return value should be the input number.");
		REQUIRE(stringCalc("87") == 87);
		REQUIRE(stringCalc("1") == 1);
		REQUIRE(stringCalc("10") == 10);
	}
	{
		INFO("Negative single number input should return the number.");
		REQUIRE(stringCalc("-10") == -10);
		REQUIRE(stringCalc("-1") == -1);
		REQUIRE(stringCalc("-33") == -33);
	}
}

TEST_CASE("Two numbers seperated by a comma sum.") {
	{
		INFO("Positive numbers seperated by a comma returns proper sum.");
		REQUIRE(stringCalc("0,0") == 0);
		REQUIRE(stringCalc("1,0") == 1);
		REQUIRE(stringCalc("0,1") == 1);
		REQUIRE(stringCalc("5,12") == 17);
		REQUIRE(stringCalc("8,52") == 60);
	}
	{
		INFO("Negative numbers seperated be a comma returns proper sum.");
		REQUIRE(stringCalc("0,-1") == -1);
		REQUIRE(stringCalc("-1,0") == -1);
		REQUIRE(stringCalc("-5,-3") == -8);
		REQUIRE(stringCalc("-23,-6") == -29);
	}
	{
		INFO("Combinations of positive and negative numbers should return the proper sum.");
		REQUIRE(stringCalc("1,-1") == 0);
		REQUIRE(stringCalc("-6,10") == 4);
		REQUIRE(stringCalc("28,-42") == 28 - 42);
		REQUIRE(stringCalc("-100,72") == -28);
	}
}

TEST_CASE("Two numbers seperated by a newline returns the sum.") {
	{
		INFO("Two positive numbers seperated by a newline.");
		REQUIRE(stringCalc("0\n0") == 0);
		REQUIRE(stringCalc("1\n0") == 1);
		REQUIRE(stringCalc("0\n1") == 1);
		REQUIRE(stringCalc("5\n3") == 8);
		REQUIRE(stringCalc("23\n45") == 68);
		REQUIRE(stringCalc("176\n195") == 176 + 195);
	}
	{
		INFO("Two negative numbers seperated by a newline.");
		REQUIRE(stringCalc("-1\n0") == -1);
		REQUIRE(stringCalc("0\n-1") == -1);
		REQUIRE(stringCalc("-7\n-9") == -16);
		REQUIRE(stringCalc("-83\n-12") == -95);
		REQUIRE(stringCalc("-176\n-195") == -176 - 195);
	}
	{
		INFO("Mix positive and negative numbers seperated by a new line.");
		REQUIRE(stringCalc("-5\n5") == 0);
		REQUIRE(stringCalc("67\n-83") == 67 - 83);
		REQUIRE(stringCalc("-189\n78") == -189 + 78);
	}
}

TEST_CASE("Two numbers not seperated by a newline or comma does not return sum.") {
	{
		INFO("Do not short cut by default adding the numbers.");
		REQUIRE(stringCalc("5/9") != 14);
		REQUIRE(stringCalc("-6^3") != -3);
		REQUIRE(stringCalc("187&-16") != 171);
	}
}

TEST_CASE("Three numbers seperated either way returns sum."){
	{
		INFO("Three positive numbers with a comma or newline seperating them return the sum.");
		REQUIRE(stringCalc("0,0,0") == 0);
		REQUIRE(stringCalc("0\n0\n0") == 0);
		REQUIRE(stringCalc("1,0,1") == 2);
		REQUIRE(stringCalc("1\n6,4") == 11);
		REQUIRE(stringCalc("6\n67\n98") == 98 + 67 + 6);
		REQUIRE(stringCalc("176,652\n16") == 176 + 652 + 16);
	}
	{
		INFO("Three negative numbers with a comma or newline seperating them return the sum.");
		REQUIRE(stringCalc("-1,-1,-1") == -3);
		REQUIRE(stringCalc("-1\n-9,-87") == -1 - 9 - 87);
		REQUIRE(stringCalc("-786,-82\n-67") == -786 - 82 - 67);
		REQUIRE(stringCalc("-56\n-93\n-12") == -56 - 93 - 12);
	}
	{
		INFO("Three negative or positive numbers with a comma or newline seperating them return the sum.");
		REQUIRE(stringCalc("-1,1,-1") == -1);
		REQUIRE(stringCalc("-1\n-9,56") == -1 - 9 + 56);
		REQUIRE(stringCalc("874,-82\n24") == 874 - 82 + 24);
		REQUIRE(stringCalc("23\n765\n-12") == 23 + 765 - 12);
	}
}