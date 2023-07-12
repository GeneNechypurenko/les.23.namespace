#include <iostream>

#include "List.h"
#include "Stack.h"

using namespace stck;

using namespace std;

int main()
{
	lst::List<std::string> l;
	l.AddToHead("test");
	l.Display();

	cout << "----------------------" << endl;

	Stack s;
	s.Push('A');
	s.Output();

	return 0;
}