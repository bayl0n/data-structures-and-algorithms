#include <iostream>

using namespace std;

// A linked list is a data structure that consists of a list of nodes, where each node points to one other one.

template <typename T>
class Node{
	public:
		T data;
		Node* next;

		Node(){
			next = NULL;
		}
};

template <typename T>
class LinkedList{
	public:
		Node<T>* head;
		Node<T>* tail;

		LinkedList(){
			head = NULL;
			tail = NULL;
		}

		size_t size(){
			Node<T>* current = head;
			size_t iter = 0;

			while(current != NULL){
				current = current->next;
				iter++;
			}
			return iter;
		}

		void add(const T& data){
			// Create a new node on the stack (dynamically)
			Node<T>* newNode = new Node<T>();
			newNode->data = data; 
			if(size() == 0){
				head = newNode;
				tail = newNode;
				return;
			} else {
				newNode->next = head;
				head = newNode;
			}
		}

		void display(){
			Node<T>* current = head;

			while(current != NULL){
				if(current->next  == NULL){
					cout << "[" << current->data << "]";
				} else {
					cout << "[" << current->data << "]->";
				}
				current = current->next;
			}
		}

};

int main(int argc, char*argv[]){

	LinkedList<string> test;

	cout << test.size() << endl;

	test.add("Mike");
	test.add("Robin");
	test.add("John");
	test.add("Patty");
	test.add("Yelena");

	test.display();

	return 0;
}
