#include <fstream>
#include <numeric>
#include <regex>
#include <sstream>
#include <unordered_set>

#include "EulerUtility.h"

int EulerUtility::multiply(int x, int y)
{
    return x * y;
}

int EulerUtility::sumOfDivisors(int n)
{
    int prod = 1;

    for(int k = 2; k * k <= n; ++k)
    {
        int p = 1;

        while(n % k == 0)
        {
            p = p * k + 1;
            n /= k;
        }

        prod *= p;
    }

    if(n > 1)
        prod *= 1 + n;

    return prod;
}

std::vector<int> EulerUtility::getPrimesUnderCeiling(int ceiling)
{
    std::vector<int> primes;

    primes.push_back(2);
    primes.push_back(3);

    bool is_prime;

    for(int i = 5; i < ceiling; i += 2)
    {
        is_prime = true;

        for(int j = 3; j * j <= i && is_prime; j += 2)
            if(i % j == 0) is_prime = false;

        if(is_prime)
            primes.push_back(i);
    }

    return primes;
}

std::vector<int> EulerUtility::getPrimesUnderCeilingIndexed(int ceiling)
{
    std::vector<int> primes;

    primes.push_back(-1);
    primes.push_back(-1);
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(-1);

    bool is_prime;

    for(int i = 5; i < ceiling; i += 2)
    {
        is_prime = true;

        for(int j = 3; j * j <= i && is_prime; j += 2)
            if(i % j == 0) is_prime = false;

        if(is_prime)
        {
            primes.push_back(i);
            primes.push_back(-1);
        }
        else
        {
            primes.push_back(-1);
            primes.push_back(-1);
        }
    }

    return primes;
}

std::vector<int> EulerUtility::tokenizer(std::string s, char delim)
{
    std::istringstream split(s);
    std::vector<int> tokens;
    for (std::string each; std::getline(split, each, delim); tokens.push_back(atoi(each.c_str())));

    return tokens;
}

std::vector<std::string> EulerUtility::strTokenizer(std::string s, char delim)
{
    std::istringstream split(s);
    std::vector<std::string> tokens;
    for (std::string each; std::getline(split, each, delim); tokens.push_back(each));

    return tokens;
}

std::vector<int> EulerUtility::factorialDigits(int n)
{
    std::vector<int> digits(1, 1);

    for (int i = 1; i <= n; ++i)
    {
        for (unsigned j = 0; j < digits.size(); ++j)
            digits[j] *=i;

        for (unsigned j = 0; j < digits.size(); ++j)
        {
            if (digits[j] >= 10)
            {
                int carry = (digits[j] - (digits[j] % 10)) / 10;
                digits[j] = digits[j] % 10;

                if (j == digits.size() - 1)
                    digits.push_back(carry);
                else
                    digits[j + 1] += carry;
            }
        }
    }

    return digits;
}

std::vector<int> EulerUtility::powerDigits(int n, int p)
{
    std::vector<int> digits = intToDigits(n);
    std::reverse(digits.begin(), digits.end());

    for (int i = 1; i < p; ++i)
    {
        for (unsigned j = 0; j < digits.size(); ++j)
            digits[j] *=n;

        for (unsigned j = 0; j < digits.size(); ++j)
        {
            if (digits[j] >= 10)
            {
                int carry = (digits[j] - (digits[j] % 10)) / 10;
                digits[j] = digits[j] % 10;

                if (j == digits.size() - 1)
                    digits.push_back(carry);
                else
                    digits[j + 1] += carry;
            }
        }
    }

    return digits;
}

/*BigInteger EulerUtility::bigFactorial(BigInteger n) 
{
    if (n == 0)
        return 1;
    return n * bigFactorial(n - 1);
}*/

int EulerUtility::factorial(int n) 
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

/*BigInteger EulerUtility::choose(int n, int k)
{
    return EulerUtility::bigFactorial(n) / (EulerUtility::bigFactorial(k) * EulerUtility::bigFactorial(n - k));
}*/

bool EulerUtility::isPerfectSquare(llui n)
{
    if (n < 0)
        return false;

    llui tst = (llui)(sqrt(n) + 0.5);
    return tst*tst == n;
}

bool EulerUtility::isPerfectCube(llui n)
{
    if (n < 0)
        return false;

    llui tst = (llui)std::floor(std::pow(n, 1/3.) + 0.5);
    return n == tst * tst * tst;
}

std::vector<int> EulerUtility::intToDigits(int n)
{
    std::vector<int> digitArray;

    while (n != 0)
    {
        digitArray.push_back(n % 10);
        n /= 10;
    }

    std::reverse(digitArray.begin(), digitArray.end());

    return digitArray;
}

std::vector<int> EulerUtility::lluiToDigits(llui n)
{
    std::vector<int> digitArray;

    while (n != 0)
    {
        digitArray.push_back(n % 10);
        n /= 10;
    }

    std::reverse(digitArray.begin(), digitArray.end());

    return digitArray;
}

/*std::vector<int> EulerUtility::BigIntToDigits(BigInteger n)
{
    std::vector<int> digitArray;

    while (n != 0)
    {
        digitArray.push_back((n % 10).toInt());
        n /= 10;
    }

    std::reverse(digitArray.begin(), digitArray.end());

    return digitArray;
}*/

int EulerUtility::digitsToInteger(std::vector<int> d)
{
    std::stringstream ss;

    for (int i : d)
        ss << i;

    int integer;
    ss >> integer;

    return integer;
}

llui EulerUtility::digitsTollui(std::string s)
{
    std::stringstream ss;

    for (char c : s)
        ss << c;

    llui digits;
    ss >> digits;

    return digits;
}

bool EulerUtility::hasUniqueDigits(int n, bool allowZero)
{
    std::vector<int> digits = EulerUtility::intToDigits(n);

    std::unordered_set<int> uniqueDigits;

    for (int digit : digits)
    {
        if (digit == 0 && !allowZero)
            return false;

        uniqueDigits.insert(digit);
    }

    return digits.size() == uniqueDigits.size();
}

/* 
* calculates (a * b) % c taking into account that a * b might overflow 
*/
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x + y) % mod;

        y = (y * 2) % mod;
        b /= 2;
    }

    return x % mod;
}

/* 
* modular exponentiation
*/
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;

        y = (y * y) % mod;
        exponent = exponent / 2;
    }

    return x % mod;
}

/*
* Miller-Rabin primality test, iteration signifies the accuracy
*/
bool EulerUtility::isPrime(ll p, int iteration)
{
    if ((p < 2) || (p != 2 && p % 2 == 0))
        return false;

    ll s = p - 1;

    while (s % 2 == 0)
        s /= 2;

    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);

        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }

        if (mod != p - 1 && temp % 2 == 0)
            return false;
    }

    return true;
}

bool EulerUtility::isTriangle(int n)
{
    return std::floor(sqrt(2 * n + 0.25) - 0.5) == sqrt(2 * n + 0.25) - 0.5;
}

bool EulerUtility::isPentagonal(llui n)
{
    return isPerfectSquare((24 * n) + 1) && ((llui)sqrt((24 * n) + 1) + 1) % 6 == 0;
}

std::vector<std::string> EulerUtility::openWordFile(std::string filename)
{
    std::ifstream file;
    std::vector<std::string> names;
    std::string name;
    file.open(filename);

    while(getline(file, name, ','))
        names.push_back(name.substr(1, name.size() - 2));

    return names;
}

/*BigInteger EulerUtility::power(BigInteger i, int p)
{
    if (p <= 0)
        return 1;

    return i * power(i, p - 1);
}*/

int EulerUtility::digitalRoot(int n)
{
    std::vector<int> digits = intToDigits(n);
    int digitSum = std::accumulate(digits.begin(), digits.end(), 0);

    if (digitSum > 9)
        return digitalRoot(digitSum);

    return digitSum;
}

/*int EulerUtility::digitalRoot(BigInteger n)
{
    std::vector<int> digits = BigIntToDigits(n);
    int digitSum = std::accumulate(digits.begin(), digits.end(), 0);

    if (digitSum > 9)
        return digitalRoot(digitSum);

    return digitSum;
}*/

std::vector<int> EulerUtility::intersect(std::vector<int>& a, std::vector<int>& b)
{
    std::vector<int> v(a.size() + b.size());
    v.resize(std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin()) - v.begin());
    return v;
}

std::vector<int> EulerUtility::getFigurates(int sides, int floor, int ceiling)
{
    std::vector<int> figurates;

    if (sides < 3)
        return figurates;

    for (int i = 0; i < ceiling; ++i)
    {
        int figurate = (sides & 1) ? (i * ((i * (sides - 2)) + 4 - sides)) / 2 : i * ((((sides / 2) - 1) * i) - ((sides / 2) - 2));

        if (figurate >= floor && figurate < ceiling)
            figurates.push_back(figurate);

        if (figurate > ceiling)
            return figurates;
    }

    return figurates;
}

llui EulerUtility::gcd(llui a, llui b)
{
    while (b != 0)
    {
       llui t = b; 
       b = a % b; 
       a = t; 
    }
    return a;
}

llui EulerUtility::phi(int n, std::vector<int> &primes, std::vector<int> &primesIndexed)
{
    // Base case
    if (n < 2)
        return 0;

    // Lehmer's conjecture
    if (primesIndexed[n] != -1)
        return n - 1;

    // Even number?
    if (n & 1 == 0)
    {
        int m = n >> 1;
        return !(m & 1) ? EulerUtility::phi(m, primes, primesIndexed) << 1 : EulerUtility::phi(m, primes, primesIndexed);
    }

    // For all primes ...
    for (std::vector<int>::iterator p = primes.begin(); p != primes.end() && *p <= n; ++p)
    {
        int m = *p;
        if (n % m) continue;

        // phi is multiplicative
        int o = n / m;
        int d = EulerUtility::gcd(m, o);
        return (d == 1) ? EulerUtility::phi(m, primes, primesIndexed) * EulerUtility::phi(o, primes, primesIndexed) : EulerUtility::phi(m, primes, primesIndexed) * EulerUtility::phi(o, primes, primesIndexed) * d / EulerUtility::phi(d, primes, primesIndexed);
    }
}
