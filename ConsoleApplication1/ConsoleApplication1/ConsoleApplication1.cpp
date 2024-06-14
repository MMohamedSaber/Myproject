#include <iostream>
#include <vector>


using namespace std;



class Node {

public:


    int Value;
    Node* next;
    Node* prev;
};

void InsertBegginng(Node* &head,int value)
{
    Node* new_Node = new Node();

    new_Node->Value = value;
    new_Node->next = head;
    new_Node->prev = NULL;



    if (head != NULL)
    {
        head->prev = new_Node;
    }

    head = new_Node;
}

void InsertAfter(Node* &Current, int item)
{

    Node* newNode = new Node();
    newNode->Value = item;
    newNode->next = Current->next;
    newNode->prev = Current;
    Current->next = newNode;
    if (Current->next == NULL)
    {
        newNode->next->prev = newNode;
    }
}

Node* Find(Node* head, int item)
{
   
    

    while (head!=NULL )
    {
        if (head->Value == item)
        {
            return head;
        }
        head= head->next;
    }
    return NULL;
}


void InsertEnd(Node* &head,int Item)
{
    Node* newNode = new Node();
    newNode->Value = Item;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {


        Node* Temp = head;
        while (Temp->next != NULL)
        {
            Temp = Temp->next;

        }

        newNode->next = NULL;
        Temp->next = newNode;
    }



}

void DeleteNode(Node*& head, Node*& NodeToDelete) {


    

    // if empty
    if (head == NULL || NodeToDelete == NULL) {
        return;
    }

    // if NodeToDelete is the only one in the list 
    if (head == NodeToDelete) 
    {
        head = NodeToDelete->next;
    }

    //not only there are Nodes after it 
    if (NodeToDelete->next != NULL) {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }

    // there are nodes befor it 
    if (NodeToDelete->prev != NULL) {
        NodeToDelete->prev->next = NodeToDelete->next;
    }
    delete NodeToDelete;
}


void PrintList(Node* head)
{

    while (head != NULL)
    {
        cout << head->Value<< "  ";
        head = head->next;

    }
    cout << endl << endl;


}
int main()
{

    Node* head = NULL;


    InsertBegginng(head, 5);
    InsertBegginng(head, 4);
    InsertBegginng(head, 3);
    InsertBegginng(head, 2);
    InsertBegginng(head, 1);
    PrintList(head);
    
    Node* N1 = Find(head, 4);

    DeleteNode(head, N1);
    PrintList(head);

    system("pause>0");

    return 0;
}