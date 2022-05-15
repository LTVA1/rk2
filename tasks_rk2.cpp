#include "tasks_rk2.h"
#include <cstring>
#include <vector>
#include <list>
#include <iostream>

//task 1

//task 2
std::pair<int/*index el*/, int /*count call*/> binSearchInner(int* ar, int first, int last, int el, int count_call)
{
	//std::cout << "Call number: " << count_call << ", first " << first << ", last: " << last << "\n";

	if(last - first <= 1)
	{
		if(ar[last] == el)
		{
			return std::make_pair(last, count_call);
		}

		if(ar[first] == el)
		{
			return std::make_pair(first, count_call);
		}

		else
		{
			return std::make_pair(-1, count_call);
		}
	}

	int mid_el = ar[(last + first) / 2];

	if(mid_el >= el)
	{
		binSearchInner(ar, first, (last + first) / 2, el, count_call + 1);
	}

	else if(mid_el <= el)
	{
		binSearchInner(ar, (last + first) / 2, last, el, count_call + 1);
	}
}

std::pair<int/*index el*/, int /*count call*/> binSearch(int* ar, int sizeAr, int el)
{
	return binSearchInner(ar, 0, sizeAr - 1, el, 1);
}

//task 3
template<class T>
int Filo<T>::push_back(T el)
{
	if (countData == size)
	{
		return 0;
	}

	ar[countData] = el;

	countData++;

	return 1;
}

template<class T>
std::pair<int, T> Filo<T>::pop_back()
{
	if (countData == 0)
	{
		return std::make_pair(0, 0);
	}

	countData--;

	return std::make_pair(1, ar[countData]);
}

//task 4
/*template <typename T>
std::ostream& operator<< (std::ostream& output, const std::pair<int, T>& p)
{
	output << "(" << p.first << ", " << p.second << ")\n";
	return output;
}*/

//task 5

template<>
bool CheckBrackets<char>::is_open_bracket(char c)
{
	return (c == '(' || c == '[' || c == '{');
}

template<>
char CheckBrackets<char>::find_pair(char c)
{
	if (c == ')')
	{
		return '(';
	}

	if (c == ']')
	{
		return '[';
	}

	if (c == '}')
	{
		return '{';
	}

	return 0;
}

template<>
int CheckBrackets<char>::checkBrackets(const char* Brackets)
{
	int length = strlen(Brackets);

	if ((length & 1) != 0)
	{
		return -1;
	}

	for (int i = 0; i < length; i++)
	{
		if (is_open_bracket(Brackets[i]))
		{
			push_back(Brackets[i]);
		}

		else
		{
			std::pair<int, char> p = pop_back();

			if (p.first == 0 || p.second != find_pair(Brackets[i]))
			{
				return -1;
			}
		}
	}

	return 1;
}
