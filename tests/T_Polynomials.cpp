﻿#include "gtest/gtest.h"
#include "Polynomials.h"
#include "MathUtils.h"

using namespace LNLib;

TEST(Test_Polynomials, All)
{
	int degree = 2;
	int error_degree = -4;
	int error_degree1 = 4;
	std::vector<double> coefficients = { 1,2,3 };
	EXPECT_THROW(Polynomials::Horner(coefficients, error_degree, 0.5), std::invalid_argument);
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::Horner(coefficients, degree, 0.5),2.75));
	EXPECT_THROW(Polynomials::Horner(coefficients, error_degree1, 0.5),std::invalid_argument);

	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::Bernstein(-1, degree, 0.5), 0));
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::Bernstein(degree + 1, degree, 0.5), 0));
	EXPECT_THROW(Polynomials::Bernstein(1, degree, 1.5), std::out_of_range);
	EXPECT_THROW(Polynomials::Bernstein(1, degree, -2), std::out_of_range);
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::Bernstein(0, degree, 0.5),1));
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::Bernstein(degree, degree, 0.5), 1));

	EXPECT_THROW(Polynomials::AllBernstein(-1,0.5), std::invalid_argument);
	EXPECT_THROW(Polynomials::AllBernstein(degree, 1.5), std::out_of_range);
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::AllBernstein(degree, 0.5)[0], 0.25));
	EXPECT_TRUE(MathUtils::IsAlmostEqualTo(Polynomials::AllBernstein(degree, 0.5)[degree], 0.25));
}