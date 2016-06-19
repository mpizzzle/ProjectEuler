#include <boost/multiprecision/cpp_dec_float.hpp>

#include "Euler.h"

namespace mp = boost::multiprecision;

typedef mp::number<mp::cpp_dec_float<120>> cpp_dec_float_120;

int Euler::SquareRootDigitalExpansion()
{
	int total = 0;

	for (cpp_dec_float_120 i = 1; i <= 100; ++i)
	{	
		std::stringstream buffer;
		buffer << std::setprecision(std::numeric_limits<cpp_dec_float_120>::digits) << mp::sqrt(i);

		std::string irrational = buffer.str();

		if (irrational.size() > 2)
		{
			total += irrational[0] - '0';

			for (int i = 2; i < 101; ++i)
				total += irrational[i] - '0';
		}
	}

	return total;
}