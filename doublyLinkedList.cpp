#include <iostream>
using namespace std;
class DoublyLinkedListNode {
  public: //node initialization
    DoublyLinkedListNode* prev;
    int data;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode () { //struct function for no data
      this->prev = NULL;
      this->data = NULL;
      this->next = NULL;
    }    
    DoublyLinkedListNode (int Data) { //struct function for data
      this->prev = NULL;
      this->data = Data;
      this->next = NULL;
    }
};
class DoublyLinkedList {
  public: //linked list class initialization
    DoublyLinkedListNode* head;

    DoublyLinkedList () { //struct function
      this->head = NULL;
    }

    void Push (int Data) { //adds a node at the beginning of the list
      DoublyLinkedListNode* newNode = new DoublyLinkedListNode (Data);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    void Append (int Data) { //adds a node at the end of the list
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

    void Insert(int Data, int Index) { //adds a node to the list at a given index 

      if (Index == 0) { //if index == 0 -> calls push function
        Push(Data);
      }

      DoublyLinkedListNode* newNode = new DoublyLinkedListNode (Data);

      DoublyLinkedListNode* currentNode = head;
      int currentIndex = 0;
      while (currentNode->next != NULL) { //loops through list until end or given index
        if (currentIndex == Index - 1) { //checks if index of next is the desired index
          newNode->next = currentNode->next;
          (currentNode->next)->prev = newNode;
          newNode->prev = currentNode; //connects the nodes so the new node is in between
          currentNode->next = newNode;
          return;
        }
        currentNode = currentNode->next; //increment
        currentIndex++;
      }

      if (currentIndex == Index - 1) {
        currentNode->next = newNode; //if list reaches end, and the desired index is the one after the last current item -> node appended
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

    int GetItem(int Index) { //returns the data at a given index
      if (Index == 0) { //returns the head if index is 0 before initializing the function
        return head->data;
      }

      DoublyLinkedListNode* currentNode = head;
      int currentIndex = 0; //initializes the variables for the function


      while (currentNode->next != NULL) { //loops through the nodes 
        if (currentIndex == Index) { //if the node index is the current index -> returns the data
          return currentNode->data;
        }
        currentNode = currentNode->next;
        currentIndex++; //increment
      }
      if (currentIndex == Index) { //if loop reaches end, and the index is the last node -> returns data
        return currentNode->data;
      }
      return NULL; //returns null if out of range
    }



    int IndexOf(int Data) { //returns the index of the first occurence of a number

      if (head->data == Data) { //returns index if the data is at the first index 
        return 0;
      }

      DoublyLinkedListNode* currentNode = head; //initializes the variables for the function
      int currentIndex = 0;


      while (currentNode->next != NULL) { //loops through the nodes 
        if (currentNode->data == Data) { //if the node's data matches the input -> returns index
          return currentIndex;
        }
        currentNode = currentNode->next;
        currentIndex++; //increment
      }
      if (currentNode->data == Data) { //if loop reaches end, and the last node's data matches -> returns last index
        return currentIndex;
      }
      return NULL; //returns null if out of range
    
    }

};

int main() {
  DoublyLinkedList newList = DoublyLinkedList ();
  return 0;
}