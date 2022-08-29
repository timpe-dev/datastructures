#include <iostream>
using namespace std;
class DoublyLinkedListNode {
  public:
    DoublyLinkedListNode* prev;
    int data;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode () {
      this->prev = NULL;
      this->data = NULL;
      this->next = NULL;
    }    
    DoublyLinkedListNode (int Data) {
      this->prev = NULL;
      this->data = Data;
      this->next = NULL;
    }
};
class DoublyLinkedList {
  public:
    DoublyLinkedListNode* head;

    DoublyLinkedList () {
      this->head = NULL;
    }

    void Push (int Data) {
      DoublyLinkedListNode* newNode = new DoublyLinkedListNode (Data);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    void Append (int Data) {
      DoublyLinkedListNode* newNode = new DoublyLinkedListNode (Data);
      if (head == NULL) {
        head = newNode;
        return;
      }
      DoublyLinkedListNode* currentNode = head;
      while (currentNode->next != NULL) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
      newNode->prev = currentNode;
    }

    void Insert(int Data, int Index) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode (Data);

      if (Index == 0) {
        if (head == NULL) {
          head = newNode;
          return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
      }
      DoublyLinkedListNode* currentNode = head;
      int currentIndex = 0;
      while (currentNode->next != NULL) {
        cout << currentNode->data <<  currentNode->next  << " " << currentIndex << endl;
        if (currentIndex = Index - 1) {
          cout << currentNode->data << endl;
          newNode->next = currentNode->next;
          (currentNode->next)->prev = newNode;
          newNode->prev = currentNode;
          currentNode->next = newNode;
          return;
        }
        currentNode = currentNode->next;
        currentIndex++;
      }
      cout << currentNode->data << currentNode->next << endl;

      if (currentIndex == Index - 1) {
        currentNode->next = newNode;
        newNode->prev = currentNode;
      }
    }

    int Len() { //RETURNS LENGTH OF LIST
      if (head == NULL) { //if list empty -> returns 0
        return 0;
      }
      int count = 1; //count is 1 because there is atleast 1 item in list if gets past last if statement
      DoublyLinkedListNode* currentNode = head; //temp ptr to loop trough nodes
      while (currentNode->next != NULL) { //loops through list
        count++; //adds 1 to len
        currentNode = currentNode->next; //moves to next node
      }
      return count;
    }

    void PrintList() { //PRINTS THE WHOLE LIST TO THE CONSOLE
      if (head == NULL) { //checks if list empty -> exits
        return;
      }

      DoublyLinkedListNode* currentNode = head; //temp ptr to loop through all nodes
      cout << currentNode->data << endl; //prints head
      while (currentNode->next != NULL) { //loops until last node
        currentNode = currentNode->next; //moves to next node
        cout << currentNode->data << endl; //prints node data
      }
    }

};

int main() {
  DoublyLinkedList newList = DoublyLinkedList ();
  newList.Append(2);
  newList.Append(7);
  newList.Push(1);
  newList.Insert(9, 1);
  //newList.PrintList();
  return 0;
}