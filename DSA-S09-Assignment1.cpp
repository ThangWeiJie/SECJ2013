//Program 1
/*  Group Member List
    Member Name 1: Thang Wei Jie
    Matric Number: A23CS0280
    Section: 09

    Member Name 2: Tan Hui Qun
    Matric Number: A22EC0279
    Section: 09

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std; 

class ItemNode {
public:
    string name;
    float price;
    ItemNode* aft; // Pointer to the next node
    ItemNode* bef; // Pointer to the previous node

    // Constructor with default arguments
    ItemNode(string name = "", float price = 0.0) {
        this->name = name;
        this->price = price;
       // this->aft = nullptr;
       // this->bef = nullptr;
    }
};


class List {
private:
    ItemNode* head; // Pointer to the head node
    ItemNode* tail; // Pointer to the tail node

public:
    // Constructor
    List() {
        head = nullptr;
        tail = nullptr;
    }
    
    void task1(ItemNode*);
    void task2(ItemNode*);
    void task3();
    void task4(ItemNode*, int);
    void task5(int);
    void task6();
};

// Task 1: Insert a new item node into an empty list.
void List::task1(ItemNode* newNode) {
    /*if (!head) {
            head = tail = node;
        } else {
      if (!head) { // If the list is empty
        head = node; // The new node becomes the head
        tail = node; // The new node also becomes the tail
        node->bef = nullptr; // No previous node (bef points to nullptr)
        node->aft = nullptr; // No next node (aft points to nullptr)
    } else {
        // If the list is not empty (not applicable for this task)
        tail->aft = node;
        node->bef = tail;
        tail = node;
    }      tail->aft = node;
            node->bef = tail;
            tail = node;
        }*/
        
         head = newNode;
         tail = newNode;

         newNode->aft = newNode->bef = nullptr;
    }

// Task 2: Insert a new item node infront of the list.
void List::task2(ItemNode* newNode) {
    
    ItemNode* nodePtr = head;
    ItemNode* prevNode = nodePtr->bef;

    prevNode = newNode;
    newNode->bef = nullptr;
    newNode->aft = nodePtr;

    nodePtr->bef = newNode;
    nodePtr->aft = nullptr;

    head = newNode;
     /*  if (!head) { // If the list is empty
          task1(newNode); // Use task1 to handle empty list case
       } else {
          newNode->aft = head;      // Point newNode's aft to the current head
          newNode->bef = nullptr;  // Since it's the first node, bef is nullptr
          head->bef = newNode;     // Update the current head's bef to point to newNode
          head = newNode;          // Update head to point to the newNode
       } */
    }

// Task 3: Display and print all data in the list in backward order.
void List::task3() {
   /* if (tail == nullptr) { // Check if the list is empty
        cout << "The list is empty." << endl;
        return;
    }*/

    ItemNode* nodePtr = tail; // Start from the last node
    cout << "Print backward:" <<endl;
    while (nodePtr) {
        cout << "[" << nodePtr->name << "\t" << nodePtr->price << "]\t";
        nodePtr = nodePtr->bef; // Move to the previous node
    }
    cout << endl << endl;
}


// Task 4: Insert node at the middle of the list.
void List:: task4(ItemNode* newNode, int position) {
    // Insert at the head
    if (position == 1) { 
        task2(newNode);
        return;
    }

    ItemNode* current = head;
    int count = 1;

    // Traverse to the node just before the desired position
    while (current != nullptr && count < position - 1) {
        current = current->aft;
        count++;
    }
    
    // Invalid position
    if (current == nullptr) { 
        cout << "Position out of range" << endl;
        return;
    }

    // Insert the new node at the position
    newNode->aft = current->aft;
    if (current->aft != nullptr) {
        current->aft->bef = newNode;
    }
    current->aft = newNode;
    newNode->bef = current;

    // If the new node is inserted at the tail, update the tail pointer
    if (newNode->aft == nullptr) {
        tail = newNode;
    }
}


// Task 5: Delete node at the middle of the list.
void List::task5(int position) {
    // If the list is empty
    if (head == nullptr) { 
        cout << "The list is empty. Cannot delete." << endl;
        return;
    }

    // Special case: delete the head node
    if (position == 1) { 
        ItemNode* temp = head;
        head = head->aft;
        
        // Update the new head's previous pointer
        if (head != nullptr) { 
            head->bef = nullptr;
        } 
        
        // If the list is now empty, update the tail as well
        else { 
            tail = nullptr;
        }
        delete temp;
        return;
    }

    ItemNode* current = head;
    int count = 1;

    // Traverse to the node at the desired position
    while (current != nullptr && count < position) {
        current = current->aft;
        count++;
    }

    if (current == nullptr) { // Invalid position
        cout << "Position out of range" << endl;
        return;
    }

    // Delete the node at the position
    
    // If it's not the last node
    if (current->aft != nullptr) { 
        current->aft->bef = current->bef;
    } 
    
    // If it's the last node, update the tail
    else { 
        tail = current->bef;
    }
    
    // If it's not the first node
    if (current->bef != nullptr) { 
        current->bef->aft = current->aft;
    }

    delete current;
}


// Task 6: Delete the last node in the list.
void List::task6() {
    
    // If the list is empty
    if (tail == nullptr) { 
        cout << "The list is empty. Cannot delete." << endl;
        return;
    }
    
    // If there's only one node
    if (tail == head) { 
        delete tail;
        head = tail = nullptr;
        return;
    }

    ItemNode* temp = tail; // Get the last node
    tail = tail->bef;      // Move the tail pointer to the previous node
    tail->aft = nullptr;   // Update the new tail's next pointer
    delete temp;           // Delete the last node
}



int main()
{
    List ItemList;
    ItemNode *n1 = new ItemNode("Book", 9.59);
    ItemNode *n2 = new ItemNode("Ruler", 3.45);
    ItemNode *n3 = new ItemNode("Pen", 5.69);
    ItemNode *n4 = new ItemNode("Eraser", 2.25);
    
    
    ItemList.task1(n1);
    ItemList.task2(n2);
    ItemList.task3();
    ItemList.task4(n3, 2);
    ItemList.task4(n4, 2);
    ItemList.task3();
    ItemList.task5(3);
    ItemList.task3();
    ItemList.task6();
    ItemList.task3();
    
    system("pause");
}