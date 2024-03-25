#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define disturbed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define nullptr NULL
const int N = 3*1e5 + 100;
const long double pi = 3.1415926536 ; 
int n, k;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функция для создания списка из введенных данных
ListNode* createList() 
{
    int n;
    cin >> n;
    ListNode *head = nullptr;
    ListNode *prev = nullptr;
    for (int i = 0; i < n; i++) 
	{
        int val;
        cin >> val;
        ListNode *node = new ListNode(val);
        if (prev == nullptr) 
		{
            head = node;
        } 
		else 
		{
            prev->next = node;
        }
        prev = node;
    }

    return head;
}

// Функция для вывода списка
void printList(ListNode* head) 
{
    while (head != nullptr) 
	{
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void deleteNode(ListNode* head, int val) 
{

    if (head == nullptr) 
	{
        return;
    }
    if (head->val == val) 
	{
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    ListNode *prev = head;
    while (prev->next != nullptr && prev->next->val != val) 
	{
        prev = prev->next;
    }
    if (prev->next != nullptr) 
	{
        ListNode *temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}
signed main() 
{
    ListNode *head = createList();
    int val;
	cin >> val;
    printList(head);
    deleteNode(head, val);
    printList(head);
    return 0;
}

