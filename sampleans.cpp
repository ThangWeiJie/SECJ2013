#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node {
private:
	char ch;
public:
	Node* next;
	Node(char c) : ch(c), next(nullptr) {};
	char getChar() { return ch; }
};

class List {
private:
	Node* head;
public:
	List() { head = nullptr; }
	bool isEmpty() { return head == nullptr; }

	void insertNode(Node*);
	void deleteNode();
	string findNode(char);
	void displayList();
};

void List::insertNode(Node* newNode) {
	if (isEmpty()) {
		head = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = head;
		
		Node* nodePtr = head;
		while (nodePtr->next != head) {
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
		head = newNode;
	}
}

void List::deleteNode() {
	if (isEmpty()) {
		cout << "No nodes to delete.\n";
	}
	else if (head->next == head) {
		Node* tempNode = head;
		head = nullptr;
		delete tempNode;
	}
	else {
		Node* nodePtr = head;

		while ((nodePtr->next)->next != head) {
			nodePtr = nodePtr->next;
		}

		Node* nodeToDelete = nodePtr->next;
		nodePtr->next = head;
		delete nodeToDelete;
	}
}

string List::findNode(char target) {
	if (head->getChar() == target) {
		return "True";
	}

	Node* nodePtr = head->next;

	while (nodePtr != head) {
		if (nodePtr->getChar() == target) {
			return "True";
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	return "False";
}

void List::displayList() {
	if (isEmpty()) {
		cout << "Nothing to display.\n";
	}
	else {
		Node* nodePtr = head;

		if (nodePtr->next == head) {
			cout << nodePtr->getChar() << endl;
		}
		else {
			cout << nodePtr->getChar() << " -> ";
		}

		nodePtr = nodePtr->next;
		while (nodePtr != head) {
			if (nodePtr->next == head) {
				cout << nodePtr->getChar() << endl;
			}
			else {
				cout << nodePtr->getChar() << " -> ";
			}

			nodePtr = nodePtr->next;
		}
	}
}

int main() {
	List listObj;

	listObj.deleteNode();

	Node* nodeA = new Node('A');
	listObj.insertNode(nodeA);
	listObj.displayList();

	Node* nodeZ = new Node('Z');
	listObj.insertNode(nodeZ);
	listObj.displayList();

	cout << "Z found in the list? " << listObj.findNode('Z') << endl;

	listObj.deleteNode();
	listObj.displayList();

	listObj.deleteNode();
	listObj.displayList();
}
