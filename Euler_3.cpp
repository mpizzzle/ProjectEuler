#include <algorithm>

#include "Euler.h"

llui lpf(llui x)
{
	bool is_prime;

	llui count = 1;
	llui my_prime = 2; //set to first prime

	for(llui i = 3; count < x; i += 2)
	{
		is_prime = true;

		for(llui j = 3; j * j <= i && is_prime; j += 2)
			if(i % j == 0) is_prime = false;

		if(is_prime) {
			if (x % i == 0)
				return i;

			++count;
			my_prime = i;
		}
	}

	return 0; //prime factor does not exist (1 does not count as prime)
}

llui Euler::LargestPrimeFactor()
{
	std::vector<llui> primes;

	primes.push_back(1);

	llui x = 600851475143;

	while (x > 1)
	{
		x /= primes.back();

		llui y = lpf(x);

		if (y != 0)
			primes.push_back(y);
	}

	std::sort (primes.begin(), primes.end());

	return primes.back();
}