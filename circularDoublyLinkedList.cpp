#include <iostream>
using namespace std;
class CircularDoublyLinkedListNode {
  public: //node initialization
    CircularDoublyLinkedListNode* prev;
    int data;
    CircularDoublyLinkedListNode* next;

    CircularDoublyLinkedListNode () { //struct function for no data
      this->prev = NULL;
      this->data = NULL;
      this->next = NULL;
    }    
    CircularDoublyLinkedListNode (int Data) { //struct function for data
      this->prev = NULL;
      this->data = Data;
      this->next = NULL;
    }
};
class CircularDoublyLinkedList {
  public: //linked list class initialization
    CircularDoublyLinkedListNode* head;

    CircularDoublyLinkedList () { //struct function
      this->head = NULL;
    }

    void Append (int Data) { //adds a node at the end of the list
      CircularDoublyLinkedListNode* newNode = new CircularDoublyLinkedListNode (Data);

      CircularDoublyLinkedListNode* currentNode = head;

      CircularDoublyLinkedListNode* oldHead = head;

      if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
      }
      while (currentNode->next != head) {
        currentNode = currentNode->next;
      }
      newNode->prev = currentNode;
      currentNode->next = newNode;
      newNode->next = head;
      head->prev = newNode;    
    }

    int Len() { //RETURNS LENGTH OF LIST
      if (head == NULL) { //if list empty -> returns 0
        return 0;
      }
      int count = 1; //count is 1 because there is atleast 1 item in list if gets past last if statement
      CircularDoublyLinkedListNode* currentNode = head; //temp ptr to loop trough nodes
      while (currentNode->next != head) { //loops through list
        count++; //adds 1 to len
        currentNode = currentNode->next; //moves to next node
      }
      return count;
    }

    void Push(int Data) {
      CircularDoublyLinkedListNode* currentNode = head;
      CircularDoublyLinkedListNode* newNode = new CircularDoublyLinkedListNode (Data);
      if (head->data == NULL) {
        head = newNode;
        return;
      }
      newNode->next = head;
      head->prev = newNode;
      while (currentNode->next != head) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
      newNode->prev = currentNode;
      head = newNode;

    }

    void Insert(int Data, int Index) {
      if (Index == 0) {
        Push(Data);
        return;
      }
      CircularDoublyLinkedListNode* currentNode = head;
      CircularDoublyLinkedListNode* newNode = new CircularDoublyLinkedListNode (Data);
      int currentIndex = 0;
      while (currentNode->next != head) {
        if (currentIndex == Index - 1) {
          newNode->next = currentNode->next;
          currentNode->next->prev = newNode;
          newNode->prev = currentNode;
          currentNode->next = newNode;
          return;
        }
        currentNode = currentNode->next;
        currentIndex++;

      }
      if (currentIndex == Index - 1) {
          newNode->prev = currentNode;
          currentNode->next = newNode;
          newNode->next = head;
          head->prev = newNode;
          return;    
        }

    }

    void PrintList() { //PRINTS THE WHOLE LIST TO THE CONSOLE
      if (head == NULL) { //checks if list empty -> exits
        return;
      }
      CircularDoublyLinkedListNode* currentNode = head; //temp ptr to loop through all nodes
      cout << currentNode->data << endl; //prints head
      while (currentNode->next != head) { //loops until last node
        currentNode = currentNode->next; //moves to next node
        cout << currentNode->data << endl;
      }
    }

    int GetItem(int Index) {
      if (head->data == NULL) {
        return NULL;
      }
      CircularDoublyLinkedListNode* currentNode = head;
      int currentIndex = 0;
      if (Index == 0) {
        return head->data;
      }
      while (currentNode->next != NULL) {
        if (currentIndex == Index) {
          return currentNode->data;
        }
        currentNode = currentNode->next;
        currentIndex++;
      }
    }

    int IndexOf(int Data) {
      if (head->data == NULL) {
        return -1;
      }
      if (head->data == Data) {
        return 0;
      }
      CircularDoublyLinkedListNode* currentNode = head;
      int currentIndex = 0;
      while (currentNode->next != head) {
        if (currentNode->data == Data) {
          return currentIndex;
        }
        currentIndex++;
        currentNode = currentNode->next;
      }
      if (currentNode->data == Data) {
        return currentIndex;
      }
      return -1;
    } 

    void DeleteItem(int Index) {
      CircularDoublyLinkedListNode* delNode;
      if (head->data == NULL) {
        return;
      }
      CircularDoublyLinkedListNode* currentNode = head;
      int currentIndex = 0;
      if (Index == 0) {
        delNode = currentNode;
          delNode->prev->next = delNode->next;
          delNode->next->prev = delNode->prev;
        head = delNode->next;
          delete delNode;
          return;
      }
      while (currentNode->next != head) {
        if (currentIndex == Index) {
          delNode = currentNode;
          delNode->prev->next = delNode->next;
          delNode->next->prev = delNode->prev;
          delete delNode;
          return;
        }
        currentIndex++;
        currentNode = currentNode->next;
 
      }
      if (currentIndex == Index) {
        delNode = currentNode;
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        head = delNode->next;
        delete delNode;
        return;
      }
    }



};

int main() {
  CircularDoublyLinkedList newList = CircularDoublyLinkedList ();
  return 0;
}