#include <fstream>

#include "Euler.h"

int Euler::MaximumPathSum()
{
	std::ifstream fin;
	std::vector<std::string> str_rows;

	fin.open("E:\\Euler Resources\\Euler 67.txt");

	std::string temp;
	while(std::getline(fin, temp))
		str_rows.push_back(temp);

	fin.close();

	std::vector<std::vector<int>> rows;

	for (std::string s :str_rows)
		rows.push_back(EulerUtility::tokenizer(s, ' '));

	for (int i = rows.size() - 2; i >= 0; --i)
		for (unsigned j = 0; j < rows[i].size(); ++j)
			rows[i][j] += (rows[i + 1][j] > rows[i + 1][j + 1]) ? rows[i + 1][j] : rows[i + 1][j + 1];

	return rows[0][0];
}