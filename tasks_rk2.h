#include <list>
#include <vector>
#include <iostream>

struct Node
{
	Node(){}

	Node(int nameNode);

	~Node()
	{
		if(parent != nullptr)
		{
			delete parent;
		}

		for(auto iter = listChilds.begin(); iter != listChilds.end(); iter++)
		{
			delete *(iter);
		}
	}

	Node* parent;
	std::list<Node*> listChilds;
	int name;
	int countNodes;
};

class Graph
{
	private:
		Node* head;
		std::list<Node*> node_ar;
		int node_num;
		//здесь можно писать любые функции, которые могут понадобиться

	public:
		Graph()
		{
			Node* buf = new Node;
			head = buf;
			head->name = 0;
			node_num = 0;
		}

		Graph(int countNodes);
		~Graph()
		{
			delete head;
		}

		/*
				output		:	-1 - функция не реализована
				author		:
				date		:
			*/
		int buildTreeBFS(int countNodes);


		/*
				output		:
							:	положительное число -- число узлов
				author		:
				date		:
			*/
		int buildTreeDFS(int countNodes);

		void BFS();
		void DFS();


		/*
				description	:	функция поиска узла по его имени
				input 		:	nameNode -- имя узла
				output		:	{bool -- узел найден, list<int> -- список имён узлов до необходимого}
				description	:	приставка DFS -- поиск в глубину, BFS -- поиск в ширину
				author		:
				date		:
			*/
		std::pair<bool, std::list<int>> searchDFS(int nameNode);
		std::pair<bool, std::list<int>> searchBFS(int nameNode);
};

std::pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

template<class T>
class Filo
{
	private:
		T* ar;	//массив
		int size;	//размер массива
		int countData;	//число элементов в массиве

	public:
		Filo()
		{
			size = 0;
			countData = 0;
			ar = nullptr;
		}

		Filo(int _size)
		{
			size = _size;
			ar = new T(size);
			countData = 0;
		}

		~Filo()
		{
			if(ar != nullptr)
			{
				delete[] ar;
			}
		}
		/*
				input		:	элемент который надо добавить
				output		:	1 - элемент добавлен, 0 - элемент не добавлен
				description	:	добавление элемента в конец массива
			*/
		int push_back(T el);
		/*
				input		:	элемент который надо извлечь
				output		:	пара значений:
									1ый аргумент пары -- 1 - элемент успешно извлечён, 0 - элементов в массиве нет
									2ой аргумент пары -- это извлечённый элемент
				description	:	извлечение элемента из массива
			*/
		std::pair<int,T> pop_back();
};

template <typename T>
std::ostream& operator<< (std::ostream& output, const std::pair<int, T>& p)
{
	output << "(" << p.first << ", " << p.second << ")\n";
	return output;
}

template<class T>
class CheckBrackets : public Filo<char>
{
	private:
		//можно объявлять любые переменные и функции
		char find_pair(char c);
		bool is_open_bracket(char c);
	public :
		CheckBrackets() : Filo<char>(3000000) { }
		~CheckBrackets() {}

		/*
			input		:	строка со скобками
			output		:	0 - всё хорошо, -1 - скобок не хватает
			description	:	проверка скобок,
		*/
		int checkBrackets(const char* strBrackets);
};
