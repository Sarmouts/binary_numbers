#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<bool> bin;

void PrintBin(bin x)
{
	for (int i = x.size() - 1; i >= 0; i--)
	{
		std::cout << x[i];
	}
}
bin Add(bin x, int y)
{
	int a = 0;
	int count = 0;
	while (a < y)
	{
		for (int j = 0; j < x.size(); j++)
		{
			if (x[j] == 1)
			{
				count++;
				x[j] = 0;
				continue;
			}
			x[j] = 1;
			break;
		}
		a++;
		if (count == x.size())
			x.push_back(1);
		count = 0;
	}
	return x;
}
bin itbin(int y, int size = 0)
{
	int i = 0;
	int n = static_cast<int>(log2(y) + 1);
	if (size < n)
		size = n;
	bin x(size);
	while (y != 0)
	{
		x[i] = y % 2;
		y /= 2;
		i++;
	}
	return x;
}
int binti(bin x)
{
	int y = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 0)
			continue;
		y += pow(2, i);
	}
	return y;
}