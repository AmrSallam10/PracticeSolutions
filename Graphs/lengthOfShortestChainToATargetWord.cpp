#include<bits/stdc++.h>
using namespace std;

bool isValid (string &st1, string &st2)
{
    int c = 0;
    int n = st1.length();

    for (int i =0 ; i < n ; i++)
    {
        if (st1[i] != st2[i])
            c++;
        if (c > 1) return false;
    }

    return (c == 1)? true : false; 
}

struct QItem
{
    string word;
    int len;
};

int shortestChainLen(string &start, string &target, set<string> &s)
{
    queue<QItem> q;
    QItem item = {start, 1};
    q.push(item);

    while (!q.empty())
    {
        QItem cur = q.front();
        q.pop();
        set<string>::iterator it; 

        for (it = s.begin() ; it != s.end() ; it++)
        {
            string temp = *it;
            if (isValid(cur.word, temp))
            {
                item.word = temp;
                item.len = cur.len + 1;
                q.push(item);
                s.erase(temp);

                if (temp == target)
                    return item.len;
            }
        }
    }
    return 0;
}

int main()
{
    set<string> s;

    s.insert("poon");
    s.insert("plee");
    s.insert("same");
    s.insert("poie");
    s.insert("plie");
    s.insert("poin");
    s.insert("plea");

    string start = "toon";
    string target = "poon";
    cout<< shortestChainLen(start, target, s);

    return 0;
}