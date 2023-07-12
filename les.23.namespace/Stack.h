#include <iostream>
#include <time.h>
using namespace std;

namespace stck
{

	class Stack
	{
		// Нижняя и верхняя границы стека
		enum { EMPTY = -1, FULL = 20 };
		// Массив для хранения данных
		char st[FULL + 1];
		// Указатель на вершину стека
		int top;

	public:
		// Конструктор
		Stack();

		// Добавление элемента
		void Push(char c);

		// Извлечение элемента
		char Pop();

		// Очистка стека
		void Clear();

		// Проверка существования элементов в стеке
		bool IsEmpty();

		// Проверка на переполнение стека
		bool IsFull() const;

		// Количество элементов в стеке
		int GetCount();

		void Output();

		char GetTop() const;
	};

}
