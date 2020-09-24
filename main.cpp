#include <iostream>
#include <chrono>
#include <ctime>

#include "Euler.h"

int main() {
    Euler e;
    std::clock_t start = std::clock();

    //std::cout << "problem 1: " << e.SumOfMultiplesOf3And5Ceiling1000() << std::endl;
    //std::cout << "problem 2: " << e.SumOfEvenFibonacciNumbersCeiling4m() << std::endl;
    //std::cout << "problem 3: " << e.LargestPrimeFactor() << std::endl;
    //std::cout << "problem 4: " << e.LargestPalindromeFrom3DigitProduct() << std::endl;
    //std::cout << "problem 5: " << e.DivisibleBy1To20() << std::endl;
    //std::cout << "problem 6: " << e.DifferenceSumOfSquaresSquareOfSum100() << std::endl;
    //std::cout << "problem 7: " << e.Get10001stPrime() << std::endl;
    //std::cout << "problem 8: " << e.FindGreatestProductOf13AdjacentDigits() << std::endl;
    //std::cout << "problem 9: " << e.SpecialPythagoreanTriplet() << std::endl;
    //std::cout << "problem 10: " << e.SumOfPrimesUnder2m() << std::endl;
    //std::cout << "problem 11: " << e.LargestProductInGrid() << std::endl; //wrong
    //std::cout << "problem 12: " << e.TriangleNoWithGreaterThan500Divisors() << std::endl;
    //std::cout << "problem 13: " << e.LargeSum() << std::endl;
    //std::cout << "problem 14: " << e.CollatzConjecture() << std::endl;
    //std::cout << "problem 15: " << e.LatticePaths() << std::endl;
    //std::cout << "problem 16: " << e.DigitSum() << std::endl;
    //std::cout << "problem 17: " << e.LetterCounter() << std::endl;
    //std::cout << "problem 18: " << e.MaximumPathSum() << std::endl;
    //std::cout << "problem 19: " << e.SundayCount() << std::endl;
    //std::cout << "problem 20: " << e.FactorialDigitSum() << std::endl;
    //std::cout << "problem 21: " << e.AmicableNumbers() << std::endl;
    //std::cout << "problem 22: " << e.NameScores() << std::endl;
    //std::cout << "problem 23: " << e.NonAbundantSums() << std::endl;
    //std::cout << "problem 24: " << e.LexicographicPermutations() << std::endl;
    //std::cout << "problem 25: " << e.ThousandDigitFibonacciNumber() << std::endl;
    //std::cout << "problem 26: " << e.ReciprocalCycles() << std::endl;
    //std::cout << "problem 27: " << e.QuadraticPrimes() << std::endl;
    //std::cout << "problem 28: " << e.SpiralDiagonals() << std::endl;
    //std::cout << "problem 29: " << e.DistinctPowers() << std::endl;
    //std::cout << "problem 30: " << e.DigitFifthPowers() << std::endl;
    //std::cout << "problem 31: " << e.CoinSums() << std::endl;
    //std::cout << "problem 32: " << e.PanDigitalProducts() << std::endl;
    //std::cout << "problem 33: " << e.DigitCancellingFractionsDenominator() << std::endl;
    //std::cout << "problem 34: " << e.DigitFactorials() << std::endl;
    //std::cout << "problem 35: " << e.NoOfCircularPrimes() << std::endl;
    //std::cout << "problem 36: " << e.DoubleBasedPalindromes() << std::endl;
    //std::cout << "problem 37: " << e.TruncatablePrimes() << std::endl;
    //std::cout << "problem 38: " << e.PanDigitalMultiples() << std::endl;
    //std::cout << "problem 39: " << e.MaximumRightAngledTriangles() << std::endl;
    //std::cout << "problem 40: " << e.ChampernowneConstant() << std::endl;
    //std::cout << "problem 41: " << e.PanDigitalPrime() << std::endl;
    //std::cout << "problem 42: " << e.CodedTriangleNumbers() << std::endl; //wrong
    //std::cout << "problem 43: " << e.SubStringDivisibility() << std::endl;
    //std::cout << "problem 44: " << e.MinimizedPentagonalDifference() << std::endl;
    //std::cout << "problem 45: " << e.TriangularPentagonalHexagonal() << std::endl;
    //std::cout << "problem 46: " << e.GoldbachsOtherConjecture() << std::endl;
    //std::cout << "problem 47: " << e.DistinctPrimeFactors() << std::endl;
    //std::cout << "problem 48: " << e.SelfPowers() << std::endl;
    //std::cout << "problem 49: " << e.PrimePermutations() << std::endl;
    //std::cout << "problem 50: " << e.ConsecutivePrimeSum() << std::endl;
    //std::cout << "problem 51: " << e.PrimeDigitReplacements() << std::endl;
    //std::cout << "problem 52: " << e.PermutedMultiples() << std::endl;
    //std::cout << "problem 53: " << e.CombinatoricSelections() << std::endl;
    //std::cout << "problem 54: " << e.PokerHands() << std::endl;
    //std::cout << "problem 55: " << e.LychrelNumbers() << std::endl;
    //std::cout << "problem 56: " << e.PowerfulDigitSum() << std::endl;
    //std::cout << "problem 57: " << e.SquareRootConvergents() << std::endl;
    //std::cout << "problem 58: " << e.SpiralPrimes() << std::endl;
    //std::cout << "problem 59: " << e.xorDecryption() << std::endl; //wrong
    //std::cout << "problem 60: " << e.PrimePairSets() << std::endl;
    //std::cout << "problem 61: " << e.CyclicFigurateNumbers() << std::endl;
    //std::cout << "problem 62: " << e.CubicPermutations() << std::endl;
    //std::cout << "problem 63: " << e.PowerfulDigitCounts() << std::endl;
    //std::cout << "problem 64: " << e.OddPeriodSquareRoots() << std::endl;
    //std::cout << "problem 65: " << "(skipped)" << std::endl; //<< e.ConvergentsOfE() << std::endl;
    //std::cout << "problem 66: " << "(skipped)" << std::endl; //<< e.Diophantine() << std::endl;
    //std::cout << "problem 67: " << e.MaximumPathSum() << std::endl;
    //std::cout << "problem 68: " << e.Magic5GonRing() << std::endl;
    //std::cout << "problem 69: " << e.EulerTotient() << std::endl;
    //std::cout << "problem 70: " << e.TotientPermutation() << std::endl;
    //std::cout << "problem 71: " << e.OrderedFractions() << std::endl;
    //std::cout << "problem 72: " << e.CountingFractions() << std::endl;
    //std::cout << "problem 73: " << e.CountingRangedFractions() << std::endl;
    //std::cout << "problem 74: " << e.DigitFactorialChains() << std::endl;
    //std::cout << "problem 75: " << e.UniquePerimeterRightAngledTriangles() << std::endl;
    //std::cout << "problem 76: " << "(skipped)" << std::endl; //<< e.CountingSums() << std::endl;
    //std::cout << "problem 77: " << e.PrimeSummations() << std::endl;
    //std::cout << "problem 78: " << "(skipped)" << std::endl; //<< e.CoinPartitions() << std::endl;
    //std::cout << "problem 79: " << e.PasscodeDerivation() << std::endl; //wrong
    //std::cout << "problem 80: " << e.SquareRootDigitalExpansion() << std::endl;
    std::cout << "problem 86: " << e.CuboidRoute() << std::endl;
    //std::cout << "problem 87: " << e.PrimePowerTriples() << std::endl;

    std::cout << "duration: " << 1000.0 * (std::clock() - start) / CLOCKS_PER_SEC << "ms" << std::endl;
    return 0;
}
