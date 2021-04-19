#include <iostream>

using namespace std;

// A linked list is a data structure that consists of a list of nodes, where each node points to one other one.

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;

		Node<T>(){
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

		// Adds a node to the end of the list
		// NOTE: As we have a tail pointer, this function can be done in O(1) time.
		// Without a tail pointer, this would be done in O(n).
		void addLast(const T& data){
			Node<T>* newNode = new Node<T>();
			newNode->data = data;
			if(size() == 0){
				head == newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
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
			cout << endl;
		}

		void remove(const T& data){
			// Removes element based on data on first occurance
			Node<T>* current = head;
			Node<T>* previous = head;

			// If in case that current pointer is pointing at data to be removed
			if(current->data == data){
				head = current->next;
			} else {
				while(previous->next->data != data){
					if (previous->next->next == NULL)
						throw out_of_range("Node not in list.");
					previous = previous->next;
				}

				current = previous->next;
				previous->next = current->next;
			}
			// Deallocate memory of deleted node
			free(current);
			current = NULL;
		}

		void reverse(){
			// Reverses linked list
			Node<T>* current = head;
			Node<T>* previous = NULL;
			Node<T>* next = NULL;

			tail = current;
			while(current != NULL){
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}
			head = previous;
		}
};

int main(int argc, char*argv[]){

	LinkedList<string> test;

	test.add("Mike");
	test.add("Robin");
	test.add("John");
	test.add("Patty");
	test.add("Yelena");

	test.display();

	test.reverse();
	test.add("Elon");
	test.addLast("Teddy");
	test.display();

	// string name; 
	// cout << "Enter a name: ";
	// cin >> name; 
	// test.add(name);
	// test.display();

	// LinkedList<int> nums;

	// nums.add(43);
	// nums.add(83);
	// nums.add(31);
	// nums.add(91);
	// nums.add(53);
	// nums.add(38);
	// nums.add(11);
	// nums.display();

	// cout << "REMOVING A NODE" << endl;
	// nums.remove(91);
	// nums.display();

	// cout << "ADDING NODE TO END OF LIST" << endl;
	// nums.addLast(79);
	// nums.display();

	// cout << "REVERSING LINKED LIST" << endl;
	// nums.reverse();
	// nums.display();

	return 0;
}
