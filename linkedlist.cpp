#include <iostream>
using namespace std;
struct LinkedListNode {
  public: //node that the linked list conists of
    int data; //data in the list
    LinkedListNode* next; // memory address of the next node in the list
    LinkedListNode () { //makes an empty node if no data passed 
      this->data = NULL;
      this->next = NULL;
    }    
    LinkedListNode (int Data) { //if data specified sets it to the node's data
      this->data = Data;
      this->next = NULL;
    }
};
class LinkedList {
  public:
    //INITIALIZATION
    LinkedListNode* head; //memory address of the first node in the list

    LinkedList () {
      this->head = NULL; //makes an empty list if no node ptr is passed as argument
    }
    LinkedList (LinkedListNode* Head) { //if node ptr passed as an argument -> set to head (first item)
      head = Head;
    }



    void Append(int Data) { //
      LinkedListNode* newNode = new LinkedListNode(Data); //makes a node with the data passed to the function

      if (head == NULL) { //checks if list empty -> sets new node as the head
        this->head = newNode;
        return;
      }

      LinkedListNode* currentNode = head; //makes a temporary pointer to loop through all nodes
      while (currentNode->next != NULL) { //loops thorugh the nodes until reaches the end
        currentNode = currentNode->next; //moves to next node
      }
      currentNode->next = newNode; //currentnode is now last node and its next ptr is set to the ptr to the new node
    }


    void PrintList() { //PRINTS THE WHOLE LIST TO THE CONSOLE
      if (head == NULL) { //checks if list empty -> exits
        return;
      }

      LinkedListNode* currentNode = head; //temp ptr to loop through all nodes
      cout << currentNode->data << endl; //prints head
      while (currentNode->next != NULL) { //loops until last node
        currentNode = currentNode->next; //moves to next node
        cout << currentNode->data << endl; //prints node data
      }
    }


    void DeleteItem(int rmIndex) { //DELETES ITEM AT CERTAIN INDEX
      if (head == NULL) { //checks if list empty -> exits (nothing can be deleted)
        return;
      }
      LinkedListNode* delNode; //node to be deleted

      LinkedListNode* currentNode = head; //temp ptr to loop trough nodes
      int currentIndex = 0; //keeps track of current index for comparison to index passed to func
      if (rmIndex == 0) { 
        delNode = head;
        head = head->next; //the ptr incremented by one if first node to be deleted
        delete delNode; //deletes node
        return;
      }
      while (currentNode->next != NULL) { //loops trough nodes
        if (currentIndex == rmIndex - 1) { //checks if the next node is the one to be removed
          delNode = currentNode->next;
          currentNode->next = (currentNode->next)->next; //sets the ptr of the next node to the one after it
          delete delNode; 
          return;
        }
        currentNode = currentNode->next; //if the function doesnt exit, node incremented
        currentIndex++; 
      }
    }


    void Insert(int Data, int index) { //INSERTS A NEW NODE TO A SPECIFIED INDEX (everything shifted, not deleted)
      LinkedListNode* newNode = new LinkedListNode(Data); //ptr of the new node
      LinkedListNode* tempAddr; 
      if (head==NULL && index == 0) { //checks if list empty and inserting to first place
        head = newNode; 
        return;
      }
      if (index == 0) { //if index is 0 -> sets the new node ptr to head and new node's next to old head
        tempAddr = head;
        head = newNode;
        head->next = tempAddr;
        return;
      }

      LinkedListNode* currentNode = head; //temp ptr to loop trough nodes
      int currentIndex = 0; //keeps track of current index for comparison to index passed to func
      while (currentNode->next != NULL) { //loops trough
        if (currentIndex == index - 1) { //checks if index of next node is the desired index
          newNode->next = currentNode->next; //inserts the new node
          currentNode->next = newNode;
          return;
        }
        currentNode = currentNode->next;
        currentIndex++;
      }
      if (index - 1 == currentIndex) { //if the desired index is the last one -> next of last node to ptr of new node
        currentNode->next = newNode;
      }
    }

    int Len() { //RETURNS LENGTH OF LIST
      if (head == NULL) { //if list empty -> returns 0
        return 0;
      }
      int count = 1; //count is 1 because there is atleast 1 item in list if gets past last if statement
      LinkedListNode* currentNode = head; //temp ptr to loop trough nodes
      while (currentNode->next != NULL) { //loops through list
        count++; //adds 1 to len
        currentNode = currentNode->next; //moves to next node
      }
      return count;
    }
};
int main() {
  LinkedList newlist = LinkedList();
  return 0;
}