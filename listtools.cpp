#include "listtools.h"
using namespace std;

template<class T>
class MyList {
public:
	MyList() : head(nullptr) {}
	~MyList() {
		while (head != nullptr) {
			Node<T>* temp = head;
			head = head->getLink();
			delete temp;
		}
	}

	void insertHead(T theData) {
		headInsert(head, theData);
	}

	T deleteHead() {
		if (head == nullptr) {
			throw std::runtime_error("List is empty");
		}
		T data = head->getData();
		deleteFirstNode(head);
		return data;
	}
	bool search(T &target) {
		return search(head, target) != nullptr;
	}

	void display() {
		display(head);
	}

private:
	Node<T>* head;
};