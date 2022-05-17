#include "tasks_rk2.h"
#include <cstring>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

//task 1
int factorial (int x)
{
	if(x == 0) return 1;
	return x * factorial(x - 1);
}

Node::Node(int nameNode)
{
	int n = nameNode;

	std::list<Node*> generate_list;

	for (int i = 1; i < factorial(n) * n + 1; ++i)
	{
		Node* buf = new Node;
		buf->name = i;
		generate_list.push_back(buf);
	}

	int k = 0;
	auto iter = generate_list.begin();

	int b = n;
	int c = n - 1;

	auto iter_2 = generate_list.begin();

	for (int i = 0; i < n; ++i)
	{
		iter_2++;
	}

	while (b - k > 1)
	{
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < n-k-1; ++j)
			{
				iter.operator*()->listChilds.push_back(iter_2.operator*());
				iter.operator*()->countNodes = n - k - 1;
				iter_2.operator*()->parent = iter.operator*();
				iter_2.operator*()->countNodes = n - k - 2;
				iter_2++;
			}

			iter++;
		}

		b = b * c;
		c = c - 1;
		k++;
	}

	if (b - k == 1)
	{
		for (int i = 0; i < b * n; ++i)
		{
			for (int j = 0; j < 1; ++j)
			{
				iter.operator*()->listChilds.push_back(iter_2.operator*());
				iter.operator*()->countNodes = 1;
				iter_2.operator*()->parent = iter.operator*();
				iter_2.operator*()->countNodes=0;
				iter_2++;
			}

			iter++;
		}
	}

	iter = generate_list.begin();

	k = 0;
	iter = generate_list.begin();

	b = n;
	c = n - 1;
	iter_2 = generate_list.begin();

	for (int i = 0; i < n; ++i)
	{
		iter_2++;
	}

	while (b - k > 1)
	{
		for (int i = 0; i < b; ++i)
		{
			std::cout << iter.operator*()->name << "{";

			for (int j = 0; j < n - k - 1; ++j)
			{
				std::cout << iter_2.operator*()->name;

				if (j != n - k - 2)
				{
					std::cout << ",";
				}

				iter_2++;
			}

			std::cout << "} ";
			iter++;
		}

		b = b * c;
		c = c - 1;
		k++;
	}

	if (b - k == 1)
	{
		for (int i = 0; i < b*n; ++i)
		{
			std::cout << iter.operator*()->name << "{";

			for (int j = 0; j < 1; ++j)
			{
				std::cout << iter_2.operator*()->name;

				std::cout << ",";
				iter_2++;
			}

			std::cout <<"} ";
			iter++;
		}
	}
}

int Graph::buildTreeBFS(int countNodes)
{
	return -1;
}

int Graph::buildTreeDFS(int countNodes)
{
	int n = countNodes;
	int r = n - 1;
	int q = n;
	node_num = n;

	while(r != 0)
	{
		node_num += q * r;
		q = q * r;
		r--;
	}

	std::list<Node*> generate_list;

	for (int i = 1; i < factorial(n) * n + 1; ++i)
	{
		Node* buf  = new Node();
		buf->name = i;
		generate_list.push_back(buf);
	}

	int k = 0;
	auto iter = generate_list.begin();

	int b = n;
	int c = n - 1;
	auto iter_2 = generate_list.begin();

	for (int i = 0; i < n; ++i)
	{
		iter_2.operator*()->parent = head;
		iter_2++;
	}

	while (b - k > 1)
	{
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < n-k-1; ++j)
			{
				iter.operator*()->listChilds.push_back(iter_2.operator*());
				iter_2.operator*()->parent = iter.operator*();
				iter_2++;

			}

			iter++;
		}

		b = b * c;
		c = c - 1;
		k++;
	}

	if (b - k == 1)
	{
		for (int i = 0; i < b*n; ++i)
		{
			for (int j = 0; j < 1; ++j)
			{
				iter.operator*()->listChilds.push_back(iter_2.operator*());
				iter_2.operator*()->parent = iter.operator*();
				iter_2++;
			}

			iter++;
		}
	}

	iter = generate_list.begin();

	for (int i = 0; i < countNodes; ++i)
	{
		//std::cout << "d" << std::endl;
		head->listChilds.push_back(iter.operator*());

		iter.operator*()->parent = head;

		iter++;
	}

	node_ar = generate_list;

	return countNodes;
}

void Graph::BFS()
{
	std::ofstream fileout("bfs_res");
	int k = 0;
	auto iter = node_ar.begin();
	auto iter_2 = iter;

	for (int i = 0; i < head->listChilds.back()->name; ++i)
	{
		iter_2++;
	}

	int n = head->listChilds.back()->name;

	auto head_iter = head->listChilds.begin();

	fileout << "0{";

	for(auto head_iter = head->listChilds.begin(); head_iter != head->listChilds.end(); ++head_iter)
	{
		fileout << (head_iter == head->listChilds.begin() ? "" : ",") << head_iter.operator*()->name;
	}

	fileout << "}\n";

	int b = n;
	int c = n - 1;

	while (b - k > 1 && c > 0)
	{
		for (int i = 0; i < b; ++i)
		{
			fileout << iter.operator*()->name << "{";

			for (int j = 0; j < n - k - 1; ++j)
			{
				fileout << iter_2.operator*()->name;

				if (j != n - k - 2)
				{
					fileout << ",";
				}

				iter_2++;
			}

			iter_2--;

			if (node_num != iter_2.operator*()->name)
			{
				fileout<<"}\n";
			}

			if (node_num == iter_2.operator*()->name)
			{
				fileout<<"}";
			}

			iter_2++;
			iter++;
		}

		b = b * c;
		c = c - 1;
		k++;
	}

	if (b - k == 1)
	{
		for (int i = 0; i < b*n; ++i)
		{
			fileout << iter.operator*()->name << "{";

			for (int j = 0; j < 1; ++j)
			{
				fileout << iter_2.operator*()->name << ",";
				iter_2++;
			}

			fileout << "} ";
			iter++;
		}
	}

	fileout.close();
}


std::pair<bool, std::list<int>>Graph::searchBFS(int nameNode)
{
	int k = 0;
	auto iter = node_ar.begin();

	for (int i = 0; i < node_num; ++i)
	{
		if (iter.operator*()->name == nameNode)
		{
			k++;
			break;
		}

		iter++;
	}

	std::list<int> out;

	while (iter.operator*()->name != head->name)
	{
		out.push_back(iter.operator*()->name);
		iter.operator*() = iter.operator*()->parent;
	}

	if (k == 0)
	{
		out.push_back(0);
		std::pair<bool, std::list<int>> a;

		make_pair(0, out);
		return (a);
	}

	else
	{
		std::pair<bool, std::list<int>> a;
		make_pair(1, out);
		return (a);
	}
}

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
