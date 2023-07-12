#pragma once
#include <iostream>

using namespace std;

namespace lst
{

	template <typename T>
	class List
	{
	private:

		struct Node {

			T data;
			Node* next;
		};

		Node* head;
		int length;

	public:

		List()
			:head{ nullptr }, length{ 0 } {}

		~List() {

			RemoveAll();
		}

		void AddToHead(const T& data) {

			Node* node = new Node;

			node->data = data;
			node->next = head;

			head = node;

			length++;
		}

		void AddToTail(const T& data) {

			Node* node = new Node;

			node->data = data;
			node->next = nullptr;

			if (head == nullptr)
				head = node;

			else {

				Node* current = head;

				while (current->next != nullptr)
					current = current->next;

				current->next = node;
			}

			length++;
		}

		void RemoveFromHead() {

			if (length != 0) {

				Node* current = head;

				head = head->next;

				delete current;
				length--;
			}
		}

		void RemoveFromTail() {

			if (length != 0) {

				if (length == 1)
					RemoveFromHead();

				else {

					Node* current = head;
					Node* last = nullptr;

					while (current->next != nullptr) {

						last = current;
						current = current->next;
					}

					last->next = nullptr;

					delete current;
					length--;
				}
			}
		}

		void RemoveAll() {

			while (head != nullptr) {

				Node* current = head;

				head = head->next;

				delete current;
			}

			head = nullptr;
			length = 0;
		}

		void Display()
		{
			Node* current = head;

			while (current != nullptr) {

				cout << "data-> " << current->data << endl;
				cout << "node-> " << current << endl;
				cout << "next-> " << current->next << endl;
				cout << endl;

				current = current->next;
			}
		}

		void Insert(const T& data, int position) {

			if (position < 0 || position > length)
				return;

			if (position == 0) {

				AddToHead(data);
				return;
			}

			Node* newNode = new Node;
			newNode->data = data;

			Node* current = head;
			for (int i = 0; i < position - 1; i++)
				current = current->next;

			newNode->next = current->next;
			current->next = newNode;

			length++;
		}

		void RemoveAt(int position) {

			if (position < 0 || position >= length)
				return;

			if (position == 0) {

				RemoveFromHead();
				return;
			}

			Node* current = head;
			for (int i = 0; i < position - 1; i++)
				current = current->next;

			Node* nodeToRemove = current->next;
			current->next = nodeToRemove->next;

			delete nodeToRemove;
			length--;
		}

		int Find(const T& data) const {

			Node* current = head;
			int position = 0;

			while (current != nullptr) {

				if (current->data == data)
					return position;

				current = current->next;
				position++;
			}

			return -1;
		}

		int Replace(const T& oldData, const T& newData) {

			Node* current = head;
			int count = 0;

			while (current != nullptr) {

				if (current->data == oldData) {

					current->data = newData;
					count++;
				}

				current = current->next;
			}

			if (count > 0)
				return count;

			else
				return -1;
		}

		void Reverse() {

			Node* previous = nullptr;
			Node* current = head;
			Node* next = nullptr;

			while (current != nullptr) {

				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}

			head = previous;
		}
	};

}