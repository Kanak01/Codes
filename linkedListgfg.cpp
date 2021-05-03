#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//----------------------------------------------------------------
//     Linked list using class
//----------------------------------------------------------------
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
// -------------Print function------------------//
void printList(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
}
//  -------------Print function Reccursive------------------//
void printListRec(node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    return printListRec(head->next);
}
//  -------------Searching------------------------//
int search(node *head, int x)
{

    int position = 0;
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return position;
        }
        else
        {
            curr = curr->next;
            position++;
        }
    }
    return -1;
}
//  -------------Searching Recursively------------------//
int recursiveSearch(node *head, int x)
{
    int position = 0;
    if (head == NULL)
        return -1;
    if (head->data == x)
        return position;
    position++;
    return recursiveSearch(head->next, x);
}
//  -------------Insert at Head------------------------//
node *insertAtStart(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}
//  -------------Insert at End------------------------//
node *insertAtEnd(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        return temp;
    }
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
//  -------------Delete at Head------------------//
node *deleteHead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *curr = head->next;
    delete head;
    return curr;
}
//  -------------Delete at Tail------------------//
node *deleteTail(node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}
//  -------------Insert at Specific position----------------//
node *InsertAtPos(node *head, int position, int x)
{
    node *temp = new node(x);
    if (position == 1)
    {
        temp->next = head;
        return temp;
    }
    node *curr = head;
    for (int i = 1; i <= position - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
//  -------------Insert Elements in a Sorted Way-----------------//
node *insertSorted(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        return temp;
    }
    if (head->data > x)
    {
        temp->next = head;
        return temp;
    }
    node *curr = head;
    while (curr->next != NULL && curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
//  -------------Middle of LinkedList------------------//
void middleOfList(node *head)
{
    int position = 1;
    if (head == NULL)
        return;
    node *slow = head, *fast = head;
    while (fast!= NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << (slow->data) <<endl; 
}
//  -------------Printing nth Node from last----------------//
void printNode(node * head, int x){

    //  ---------Naive Approach------------- //

    // int length = 0;
    // node *curr = head;
    // while (curr->next != NULL){
    //     length++;
    //     curr = curr->next;
    // }
    // if(length<x) return;
    // curr = head;
    // for(int i = 0; i<(length-x+1); i++){
    //     curr = curr->next;
    // }
    // cout << curr->data <<endl;

    //  --------------Two pointer Approach-------------- //

    if(head == NULL) return;

    node* first = head;
    for(int i = 0; i < n; i++){
        if(first == NULL) return;
        first = first->next;
    }
    node* second = head;
    while(first!= NULL){
        second = second->next;
        first = first->next;
    }
    cout <<(second->data)<<endl; 
}

//  -------------Reverse the List--------------  //

node *reverse(node *head){
    node *prev = head;
    node *curr = head;
    while(curr != NULL){
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // NEW Head
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
    { // Creating a Link List
        // node *head = new node(50);
        // node *temp1 = new node(20);
        // node *temp2 = new node(30);
        // node *temp3 = new node(40);
        // head->next = temp1;
        // temp1->next = temp2;
        // temp2->next = temp3;
        node *head = NULL;
        head = insertAtStart(head, 30);
        head = insertAtStart(head, 20);
        head = insertAtStart(head, 10);
        printListRec(head);
        insertAtEnd(head, 40);
        cout << endl;
        printList(head);
        cout << endl;
        head = deleteHead(head);
        printListRec(head);
        cout << endl;
        head = deleteTail(head);
        printListRec(head);
        cout << endl;
        head = InsertAtPos(head, 2, 70);
        printListRec(head);
        head = insertSorted(head, 10);
        head = insertSorted(head, 25);
        head = insertSorted(head, 67);
        head = insertSorted(head, 39);
        cout << endl;
        printListRec(head);
        cout << endl;
        printNode(head,3);
        middleOfList(head);
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}