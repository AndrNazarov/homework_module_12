#include<iostream>

void computeLPS(const std::string& str, int* lps)
{
	size_t j = 0;
	size_t i = 1;
	lps[0] = 0;
	
	while (i < str.length())
	{
		if (str[i] == str[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool isKPeriodic(const std::string& str, int K)
{
	int* lps = new int[str.length()];

	computeLPS(str, lps);

	if (K == str.length() - lps[str.length() - 1] && lps[K*2 - 1] == K || 

		lps[str.length() - 1] != 0 && str.length() % K == 0 && lps[str.length() - 1] % K != 0)
	{
		std::cout << "the string is a multiple of K" << std::endl;
		return true;
	}

	else
	{
		std::cout << "the string is NOT multiple of K!" << std::endl;
		return false;
	}

	delete[]lps;
}
	

int main()
{
	std::string str;
	int K;

	while (true)
	{
		std::cout << "Input your string or 0 for exit" << std::endl;

		std::cin >> str;

		if (str == "0")
		{
			return false;
		}

		std::cout << "Input K for checking string" << std::endl;

		std::cin >> K;

		if (K == 0)
		{
			return false;
		}

		isKPeriodic(str, K);
	}

	return 0;
}