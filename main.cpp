#include <iostream>
#include <ctime>

#include "Euler.h"

int main() {
	Euler e;
	std::clock_t start = std::clock();

	std::cout << e.SumOfMultiplesOf3And5Ceiling1000() << std::endl;
	std::cout << e.SumOfEvenFibonacciNumbersCeiling4m() << std::endl;
	std::cout << e.LargestPrimeFactor() << std::endl;
	std::cout << e.LargestPalindromeFrom3DigitProduct() << std::endl;
	std::cout << e.DivisibleBy1To20() << std::endl;
	std::cout << e.DifferenceSumOfSquaresSquareOfSum100() << std::endl;
	std::cout << e.Get10001stPrime() << std::endl;
	std::cout << e.FindGreatestProductOf13AdjacentDigits() << std::endl;
	std::cout << e.SpecialPythagoreanTriplet() << std::endl;
	std::cout << e.SumOfPrimesUnder2m() << std::endl;
	//std::cout << e.LargestProductInGrid() << std::endl;
	//std::cout << e.TriangleNoWithGreaterThan500Divisors() << std::endl;
	//std::cout << e.LargeSum() << std::endl;
	//std::cout << e.CollatzConjecture() << std::endl;
	//std::cout << e.LatticePaths() << std::endl;
	//std::cout << e.DigitSum() << std::endl;
	//std::cout << e.LetterCounter() << std::endl;
	//std::cout << e.MaximumPathSum() << std::endl;
	//std::cout << e.SundayCount() << std::endl;
	//std::cout << e.FactorialDigitSum() << std::endl;
	//std::cout << e.AmicableNumbers() << std::endl;
	//std::cout << e.NameScores() << std::endl;
	//std::cout << e.NonAbundantSums() << std::endl;
	//std::cout << e.LexicographicPermutations() << std::endl;
	//std::cout << e.ThousandDigitFibonacciNumber() << std::endl;
	//std::cout << e.ReciprocalCycles() << std::endl;
	//std::cout << e.QuadraticPrimes() << std::endl;
	//std::cout << e.SpiralDiagonals() << std::endl;
	//std::cout << e.DistinctPowers() << std::endl;
	//std::cout << e.DigitFifthPowers() << std::endl;
	//std::cout << e.CoinSums() << std::endl;
	//std::cout << e.PanDigitalProducts() << std::endl;
	//std::cout << e.DigitCancellingFractionsDenominator() << std::endl;
	//std::cout << e.DigitFactorials() << std::endl;
	//std::cout << e.NoOfCircularPrimes() << std::endl;
	//std::cout << e.DoubleBasedPalindromes() << std::endl;
	//std::cout << e.TruncatablePrimes() << std::endl;
	//std::cout << e.PanDigitalMultiples() << std::endl;
	//std::cout << e.MaximumRightAngledTriangles() << std::endl;
	//std::cout << e.ChampernowneConstant() << std::endl;
	//std::cout << e.PanDigitalPrime() << std::endl;
	//std::cout << e.CodedTriangleNumbers() << std::endl;
	//std::cout << e.SubStringDivisibility() << std::endl;
	//std::cout << e.MinimizedPentagonalDifference() << std::endl;
	//std::cout << e.TriangularPentagonalHexagonal() << std::endl;
	//std::cout << e.GoldbachsOtherConjecture() << std::endl;
	//std::cout << e.DistinctPrimeFactors() << std::endl;
	//std::cout << e.SelfPowers() << std::endl;
	//std::cout << e.PrimePermutations() << std::endl;
	//std::cout << e.ConsecutivePrimeSum() << std::endl;
	//std::cout << e.PrimeDigitReplacements() << std::endl;
	//std::cout << e.PermutedMultiples() << std::endl;
	//std::cout << e.CombinatoricSelections() << std::endl;
	//std::cout << e.PokerHands() << std::endl;
	//std::cout << e.LychrelNumbers() << std::endl;
	//std::cout << e.PowerfulDigitSum() << std::endl;
	//std::cout << e.SquareRootConvergents() << std::endl;
	//std::cout << e.SpiralPrimes() << std::endl;
	//std::cout << e.xorDecryption() << std::endl;
	//std::cout << e.PrimePairSets() << std::endl;
	//std::cout << e.CyclicFigurateNumbers() << std::endl;
	//std::cout << e.CubicPermutations() << std::endl;
	//std::cout << e.PowerfulDigitCounts() << std::endl;
	//std::cout << e.OddPeriodSquareRoots() << std::endl;
	//std::cout << e.ConvergentsOfE() << std::endl;
	//std::cout << e.Diophantine() << std::endl;
	//std::cout << e.Magic5GonRing() << std::endl;
	//std::cout << e.EulerTotient() << std::endl;
	//std::cout << e.TotientPermutation() << std::endl;
	//std::cout << e.OrderedFractions() << std::endl;
	//std::cout << e.CountingFractions() << std::endl;
	//std::cout << e.CountingRangedFractions() << std::endl;
	//std::cout << e.DigitFactorialChains() << std::endl;
	//std::cout << e.UniquePerimeterRightAngledTriangles() << std::endl;
	//std::cout << e.CountingSums() << std::endl;
	//std::cout << e.PrimeSummations() << std::endl;
	//std::cout << e.CoinPartitions() << std::endl;
	//std::cout << e.PasscodeDerivation() << std::endl;
	//std::cout << e.SquareRootDigitalExpansion() << std::endl;

	std::cout << "duration: " << std::clock() - start << "ms" << std::endl;
	return 0;
}
