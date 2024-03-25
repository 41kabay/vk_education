#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define disturbed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define all(v) v.begin(),v.end()
const int N = 3*1e5 + 100;
const long double pi = 3.1415926536 ; 
int n;
int a[N], b[N];
int ans = 0;
int presolve(int n, int x, int y)
{
	int low = 0;
    int high = max(x, y) * n; // макс время
    while (low < high) 
	{
        int mid = low + (high - low) / 2;
        int copies = mid/x + mid/y;
        if (copies < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
void solve1()
{
	int x, y, n;
	cin >> n >> x >> y;
	int tek = min(x, y);
	int ans = presolve(n - 1, x , y); // учитываем что сначала есть только оригинал
	ans += tek;
	cout << ans << endl;
}
// нахождение корня
int sqrt(int n) 
{
    if (n <= 1) 
	return n; 
	
    int left = 0;
    int right = n;
    int result = 0;
    
while (left <= right) 
{
    int mid = left + (right - left) / 2;
    
    // если mid^2 равно n то mid корень n
    if (mid * mid == n) 
	{
    	return mid;
    }
    if (mid * mid < n) 
	{
    	left = mid + 1;
    	result = mid;
    }
    else 
	{
    	right = mid - 1;
    }
}
		return result;
}
// Палиндром стек
bool PalindromeStack(string str) 
{
    stack<char> st;
    string str0;
    str0 = str;
    int half = str0.size() / 2;
    for (int i = 0; i < half; i++) 
	{
        st.push(str0[i]);
    }

    for (int i = half + str0.size() % 2; i < str0.size(); i++) 
	{
        if (st.top() != str0[i]) 
		{
            return false;
        }
        st.pop();
    }
    return true;
}
// палиндром указатели
bool PalindromePointers(string str) 
{
    string cleanStr;
    string str0;
    str0 = str;
    int left = 0;
    int right = str0.size() - 1;
    while (left < right) 
	{
        if (str0[left] != str0[right]) 
		{
            return false;
        }
        left++;
        right--;
    }
    return true;
}
void solve3()
{
	string s;
	cin >> s;
	if (PalindromeStack(s)) 
	{
        cout << "True"<< endl;
    } 
		else 
		{
        	cout << "False" << endl;
    	}
}
void solve4()
{
	string s;
	cin >> s;
	if (PalindromePointers(s)) 
	{
        cout << "True"<< endl;
    } 
		else 
		{
        	cout << "False" << endl;
    	}
}
// подстрока
void solve5()
{
	string s,t;
	cin >> s >> t;
	int i = 0; 
    int j = 0;
    while (i < s.size() && j < t.size()) 
	{
        if (s[i] == t[j]) 
		{
            j++; // увеличиваем индекс t при совпадении символов
        }
        i++; // увеличиваем индекс s
    }
   if(j == t.size())
   {
   	 cout << "True"<< endl;
   }
   else 
   {
   		cout << "False" << endl;
   }
}
//удаление рядом стоящих
void solve6()
{
	string s;
	cin >> s;
	int n = s.size();
    int i = 0;
    while (i < n) 
	{
        if (s[i] == s[i + 1]) 
		{ 
            int j = i;
            while (s[j] == s[i]) 
			{ 
                s.erase(j, 1);
                n--; 
            }
            i = j;
        } 
		else 
			{
            	i++; 
        	}
    }
    cout << s << endl;
}
signed main()
{
	disturbed;
	solve6();
	return 0;
}
