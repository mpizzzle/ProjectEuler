#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp>

typedef long long unsigned int llui;
typedef long long int ll;

using namespace boost::multiprecision;

class EulerUtility
{
public:
    static int multiply(int x, int y);
    static std::vector<int> getPrimesUnderCeiling(int ceiling);
    static std::vector<int> getPrimesUnderCeilingIndexed(int ceiling);
    static std::vector<int> tokenizer(std::string s, char delim);
    static std::vector<std::string> strTokenizer(std::string s, char delim);
    static int sumOfDivisors(int n);
    static std::vector<int> factorialDigits(int n);
    static std::vector<int> powerDigits(int n, int p);
    static int factorial(int n);
    static cpp_int bigFactorial(cpp_int n);
    static cpp_int choose(int n, int k);
    static bool isPerfectSquare(llui n);
    static bool isPerfectCube(llui n);
    static std::vector<int> intToDigits(int n);
    static std::vector<int> lluiToDigits(llui n);
    static std::vector<int> BigIntToDigits(cpp_int n);
    static int digitsToInteger(std::vector<int> digits);
    static llui digitsTollui(std::string s);
    static bool hasUniqueDigits(int n, bool allowZero);
    static bool isPrime(ll n, int iteration);
    static bool isPrime(cpp_int& n);
    static bool isTriangle(int n);
    static bool isPentagonal(llui n);
    static std::vector<std::string> openWordFile(std::string filename);
    static cpp_int power(cpp_int i, int p);
    static int digitalRoot(int n);
    static int digitalRoot(cpp_int n);
    static std::vector<int> intersect(std::vector<int>& a, std::vector<int>& b);
    static std::vector<int> getFigurates(int sides, int floor, int ceiling);
    static llui gcd(llui a, llui b);
    static llui binary_gcd(llui a, llui b);
    static llui phi(int n, std::vector<int> &primes, std::vector<int> &primesIndexed);
};
