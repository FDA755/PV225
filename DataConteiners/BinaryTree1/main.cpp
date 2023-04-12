#define _CRT_SECURE_NO_WARNINGS
#define CLOCKS_PER_SEC
#include<iostream>
#include<ctime>

using namespace std;

#define DEBUG
#define delimiter "\n-----------------------------------------------------------------------------\n"
class Tree
{protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		bool isLeaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		friend class UniqTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
#ifdef DEBUG
		cout << "Tconstructor:\t" << this << endl;
#endif // DEBUG
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int i : il)insert(i);
	}
	Tree(const Tree& other) :Tree()
	{
		Copy(other.Root);
	}
	~Tree()
	{
#ifdef DEBUG
		Clear(Root);
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG

	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void erase(int Data)
	{
		erase(Data, Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int count()const
	{
		return count(Root);
	}
	int Sum()const
	{
		return Sum(Root);
	}
	double Avg()
	{
		return (double)Sum(Root) / count(Root);
	}
	int Depth()const
	{
		return Depth(Root);
	}
	void Clear()
	{
		Clear(Root);
	}
	void Copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data, this->Root);
		Copy(Root->pLeft);
		Copy(Root->pRight);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root -> pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->isLeaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (count(Root->pLeft) > count(Root->pRight))
				{
					Root->Data=maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}
	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
	/*	if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pRight == nullptr)return Root->Data;
		return maxValue(Root->pRight);*/
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int Depth(Element* Root)const
	{
		/*if (Root == nullptr) return 0;
		if (Depth(Root->pLeft) + 1 > Depth(Root->pRight) + 1)return Depth(Root->pLeft) + 1;
		else return Depth(Root->pRight) + 1;*/

		if (Root == nullptr) return 0;
		/*return (Depth(Root->pLeft) + 1 > Depth(Root->pRight)) ? Depth(Root->pLeft) + 1 : Depth(Root->pRight) + 1;*/
		int l_depth = Depth(Root->pLeft) + 1;
		int r_depth = Depth(Root->pRight) + 1;
		return l_depth < r_depth ? r_depth : l_depth;
	}
	void Clear(Element* Root)
	{
		if (Root == nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	int count(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int Sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return Sum(Root->pLeft) + Sum(Root->pRight)+Root->Data;
	}
};
class UniqTree :public Tree
{
public:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
//public:
//	void insert(int Data)
//	{
//		insert(Data, Root);
//	}
};

//#define TIME_MESUREMENT
//#define BASE_CHECK
#define DEPTH_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();  cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
	cout << "Количество элементов в дереве: " << tree.count() << endl;
	cout << "Сумма элементов в дереве: " << tree.Sum() << endl;
	cout << "Среднее значение элементов в дереве: " << tree.Avg() << endl;
	cout << "Глубина элементов в дереве: " << tree.Depth() << endl;

#ifdef TIME_MESUREMENT
	time_t start = time(NULL);
	time_t end = time(NULL);
	cout << "Время подсчета: " << difftime(end, start) / CLOCKS_PER_SEC << "\tсекунд" << endl;
#endif // TIME_MESUREMENT

	UniqTree tree2;
	for (int i = 0; i < n; i++) tree2.insert(rand() % 100, tree2.getRoot());
	//while (tree2.count(tree2.getRoot()) < n) tree2.insert(rand()%100,tree2.getRoot());
	tree2.print();  cout << endl;
	cout << "Минимальное значение в дереве: " << tree2.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree2.maxValue() << endl;
	cout << "Количество элементов в дереве: " << tree2.count() << endl;
	cout << "Сумма элементов в дереве: " << tree2.Sum() << endl;
	cout << "Среднее значение элементов в дереве: " << tree2.Avg() << endl;
	cout << "Глубина элементов в дереве: " << tree2.Depth() << endl;
#endif // BASE_CHECK

#ifdef DEPTH_CHECK
	Tree tree = { 50,25,75,16,32,64,80 ,48,49,85,91,58,68,67 };
	tree.print();
	cout << "Глубина дерева: " << tree.Depth() << endl;

	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();
	/*Tree tree2 = tree;
	tree2.print();*/
#endif // DEPTH_CHECK

}

