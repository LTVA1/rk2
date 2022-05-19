#include <QCoreApplication>
#include <iostream>
#include "tasks_rk2.h"

void task_1(void)
{
	Graph gr(4);

	//gr.buildTreeBFS(4);

	gr.BFS();
}

void task_2(void)
{
	int test[11] = {1, 3, 5, 6, 7, 10, 20, 69, 420, 666, 667};

	std::pair<int, int> one = binSearch(test, 11, 3);
	std::pair<int, int> two = binSearch(test, 11, 420);

	std::cout << one.first << ";" << one.second << " " << two.first << ";" << two.second << "\n\n";
}

void task_3(void)
{
	Filo<double> fl(10);

	fl.push_back(5.456);
	fl.push_back(0.42345);
	fl.push_back(23.4356);
	fl.push_back(3456.902122);

	std::cout << "In the stack are: 5.456, 0.42345, 23.4356, 3456.902122\nNow let's pop_back() more than we should to see if the first element in the pair becomes 0:\n";

	for(int i = 0; i < 10; ++i)
	{
		std::pair<int, double> test = fl.pop_back();

		std::cout << test;
	}

	std::cout << "\n";
}

void task_4(void)
{
	std::pair<int, double> test1 = std::make_pair(10, 40.67565);
	std::cout << test1 << "\n";
}

void task_5(void)
{
	const char* right_brackets = "{()}";
	const char* unholy_brackets = "{(})[{]}";

	CheckBrackets<char> br;

	std::cout << "The string is all good, so here should be 1: " << br.checkBrackets(right_brackets) << ", but this string is wrong so here should be -1: " << br.checkBrackets(unholy_brackets) << "\n\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //std::cout << argc << " " << argv[0] << std::endl;

	//task 1
	task_1();

	//task 2
	task_2();

	//task 3
	task_3();

	//task 4
	task_4();

	//task 5
	task_5();

	return a.exec();
}
