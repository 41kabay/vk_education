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
ListNode* mergeLists(ListNode* l1, ListNode* l2) 
{
    ListNode dummy(0); 
    ListNode *tail = &dummy; 
    while (l1 != nullptr && l2 != nullptr) 
	{
        if (l1->val < l2->val) 
		{
            tail->next = l1;
            l1 = l1->next;
        } 
			else 
			{
            	tail->next = l2;
            	l2 = l2->next;
        	}
        tail = tail->next;
    }

    if (l1 != nullptr) 
	{
        tail->next = l1;
    } 
		else 
		{
        	tail->next = l2;
    	}
    return dummy.next; 
}

signed main() 
{
    ListNode *l1 = createList();
    ListNode *l2 = createList();
	ListNode *mergedList = mergeLists(l1, l2);
    printList(mergedList);
    return 0;
}

