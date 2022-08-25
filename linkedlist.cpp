#include <iostream>
using namespace std;
struct LinkedListNode {
  public:
    int data;
    LinkedListNode* next;
    LinkedListNode () {
      this->data = NULL;
      this->next = NULL;
    }    
    LinkedListNode (int Data) {
      this->data = Data;
      this->next = NULL;
    }
};
class LinkedList {
  public:
    LinkedListNode* head;

    LinkedList () {
      this->head = NULL;
    }
    LinkedList (LinkedListNode* Head) {
      head = Head;
    }
    void Append(int Data) {
      LinkedListNode* newNode = new LinkedListNode(Data);

      if (head == NULL) {
        this->head = newNode;
        return;
      }

      LinkedListNode* currentNode = head;
      while (currentNode->next != NULL) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
    void PrintList() {
      if (head == NULL) {
        return;
      }
      LinkedListNode* currentNode = head;
      cout << currentNode->data << endl;
      while (currentNode->next != NULL) {
        currentNode = currentNode->next;
        cout << currentNode->data << endl;
      }
    }
};
int main() {
  LinkedList newlist = LinkedList();
  newlist.Append(0);
  newlist.Append(1);
  newlist.Append(2);
  newlist.Append(3);
  newlist.PrintList();
  return 0;
}