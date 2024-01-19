#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    bool setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

/** Inserts a word into the trie. */
void insert(string word, Node *root)
{
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
}

bool search(string word, Node *root)
{
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            return false;
        }
        node = node->get(word[i]);
    }
    return node->isEnd();
}

bool f(string str, Node *root)
{
    int n = str.size();
    if (n == 0)
        return true;
    for (int i = 1; i <= n; i++)
    {
        if (search(str.substr(0, i), root) && f(str.substr(i, n - i), root))
        {
            return true;
        }
    }
    return false;
}
bool wordBreak(string A, vector<string> &B)
{
    Node *root = new Node();
    for (auto str : B)
    {
        insert(str, root);
    }
    return f(A, root);
}

void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
