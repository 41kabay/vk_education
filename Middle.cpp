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

// ������� ��� �������� ������ �� ��������� ������
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

// ������� ��� ������ ������
void printList(ListNode* head) 
{
    while (head != nullptr) 
	{
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* findMiddle(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) 
	{
        return head; 
    }

    ListNode *slow = head; 
    ListNode *fast = head; 

    
    while (fast != nullptr && fast->next != nullptr) 
	{
        slow = slow->next; 
        fast = fast->next->next; 
    }
    return slow; 
}

signed main() 
{
    // ������� ������
    ListNode *head = createList();
    printList(head);
    ListNode *middle = findMiddle(head);
	cout << middle->val << endl;

    return 0;
}

