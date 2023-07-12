#include <iostream>
#include <time.h>
using namespace std;

namespace stck
{

	class Stack
	{
		// ������ � ������� ������� �����
		enum { EMPTY = -1, FULL = 20 };
		// ������ ��� �������� ������
		char st[FULL + 1];
		// ��������� �� ������� �����
		int top;

	public:
		// �����������
		Stack();

		// ���������� ��������
		void Push(char c);

		// ���������� ��������
		char Pop();

		// ������� �����
		void Clear();

		// �������� ������������� ��������� � �����
		bool IsEmpty();

		// �������� �� ������������ �����
		bool IsFull() const;

		// ���������� ��������� � �����
		int GetCount();

		void Output();

		char GetTop() const;
	};

}
