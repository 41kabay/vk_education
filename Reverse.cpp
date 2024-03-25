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

ListNode* reverseList(ListNode* head) 
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr) 
	{
        next = current->next; // ��������� ������ �� ��������� ����
        current->next = prev; // ������ ����������� ��������� �������� ���� �� ����������
        prev = current; // �������� ��������� prev �� ������� ����
        current = next; // �������� ��������� current �� ��������� ����
    }
    return prev; // ����� ������� ������ ���������� ��������� ������� ������������� ������
}

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
signed main() {
    // ������� ������
    ListNode *head = createList();
    printList(head);
    // ������������� ������
    head = reverseList(head);
    printList(head);
    return 0;
}

