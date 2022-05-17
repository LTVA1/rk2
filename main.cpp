#include <QCoreApplication>
#include <iostream>
#include "tasks_rk2.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//task 1
	//Node(3);

	Graph gr;

	gr.buildTreeBFS(7);

	gr.BFS();

	//task 2
	int test[11] = {1, 3, 5, 6, 7, 10, 20, 69, 420, 666, 667};

	std::pair<int, int> one = binSearch(test, 11, 3);
	std::pair<int, int> two = binSearch(test, 11, 420);

	std::cout << one.first << ";" << one.second << " " << two.first << ";" << two.second << "\n\n";

	//task 4

	std::pair<int, double> test1 = std::make_pair(10, 40.67565);
	std::cout << test1 << "\n";

	//task 5
	const char* right_brackets = "{()}";
	const char* unholy_brackets = "{(})[{]}";

	CheckBrackets<char> br;

	std::cout << "The string is all good, so here should be 1: " << br.checkBrackets(right_brackets) << ", but this string is wrong so here should be -1: " << br.checkBrackets(unholy_brackets) << "\n\n";

	return a.exec();
}
