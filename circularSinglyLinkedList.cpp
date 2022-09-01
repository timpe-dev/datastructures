#include <iostream>
using namespace std;
class CircularSinglyLinkedListNode {
  public:
    int data;
    CircularSinglyLinkedListNode* next;
    CircularSinglyLinkedListNode () {
      this->data = NULL;
      this->next = NULL;
    }

    CircularSinglyLinkedListNode (int Data) {
      this->data = Data;
      this->next = NULL;
    }
};
class CircularSinglyLinkedList {
  public:
    CircularSinglyLinkedListNode* head;
    CircularSinglyLinkedList () {
      this->head = NULL;
    }

    void Push (int Data) { //adds a node at the beginning of the list
      CircularSinglyLinkedListNode* newNode = new CircularSinglyLinkedListNode (Data);
      CircularSinglyLinkedListNode* currentNode = head;
      CircularSinglyLinkedListNode* oldHead = head;
      if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
      }

      newNode->next = head;
      head = newNode;
      while (currentNode->next != oldHead) {
        currentNode = currentNode->next;
      }
      currentNode->next = head;
    }

    void Append(int Data) {
      CircularSinglyLinkedListNode* currentNode = head;
      CircularSinglyLinkedListNode* newNode = new CircularSinglyLinkedListNode (Data);
      while (currentNode->next != head) {
        currentNode = currentNode->next;
      }
      newNode->next = head;
      currentNode->next = newNode;
    }

    void Insert(int Data, int Index) {
      if (Index == 0) {
        Push(Data);
      }
      CircularSinglyLinkedListNode* currentNode = head;
      CircularSinglyLinkedListNode* newNode = new CircularSinglyLinkedListNode (Data);
      int currentIndex = 0;
      while (currentNode->next != head) {
        if (currentIndex == Index - 1) {
          newNode->next = currentNode->next;
          currentNode->next = newNode;
          return;
        }
        currentNode = currentNode->next;
        currentIndex++;
      }
      if (currentIndex == Index - 1) {
          newNode->next = currentNode->next;
          currentNode->next = newNode;
          return;
      }
    }

    void PrintList() {
      if (head->data == NULL) {
        return;
      }
      CircularSinglyLinkedListNode* currentNode = head;

      while (currentNode->next != head) {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
      }
      cout << currentNode->data << endl;
    }

    void DeleteItem(int Index) {
      CircularSinglyLinkedListNode* currentNode = head;
      CircularSinglyLinkedListNode* delNode;
      if (Index == 0) {
        if (head == head->next) {
          head = new CircularSinglyLinkedListNode();
          return;
        }
        if (currentNode->next == NULL) {
          head = NULL;
          head->next = NULL;
          return;
        }
        delNode = head;
        while (currentNode->next != head) {
          currentNode = currentNode->next;
        }
        head = head->next;
        currentNode->next = head;
        delete delNode;
        return;
      }
      int currentIndex = 0;
      while (currentNode->next != head) {
        if (currentIndex == Index - 1) {
          delNode = currentNode->next;
          currentNode->next = delNode->next;
          delete delNode;
          return;
        }
        currentNode = currentNode->next;
        currentIndex++;
      }
      if (currentIndex == Index - 1) {
          delNode = currentNode->next;
          currentNode->next = delNode->next;
          delete delNode;
          return;
      }
    }

    int Len() {
      if (head->data == NULL) {
        return
         0;
      }
      CircularSinglyLinkedListNode* currentNode = head;
      int count = 1;
      while (currentNode->next != head) {
        currentNode = currentNode->next;
        count++;
      }
      return count;
    }

    int GetItem(int Index) {
      if (head->data == NULL) {
        return NULL;
      }
      CircularSinglyLinkedListNode* currentNode = head;
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
      CircularSinglyLinkedListNode* currentNode = head;
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


};

int main () {
  CircularSinglyLinkedList newlist = CircularSinglyLinkedList ();
  return 0;
}