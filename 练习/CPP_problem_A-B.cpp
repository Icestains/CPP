#include <iostream>
#include <string>
using namespace std;

void process(string&a, string&b)
{
    int p[200] = { 0 };
    int q[200] = { 0 };
    int cura = 0,curb = 0;

    for (int i = a.length() - 1; i >= 0; i--)
    {
        p[cura] = a[i]-'0';
        cura++;
    }

    for (int i = b.length() - 1; i >= 0; i--)
    {
        q[curb] = b[i]-'0';
        curb++;
    }

    int cur = 0;

    while (cur < 199)
    {
        p[cur] -= q[cur];
        if (p[cur] < 0)
        {
            p[cur + 1]--;
            p[cur] += 10;
        }
        cur++;
    }

    for (; cur >= 0; cur--)
        if (p[cur] != 0) break;

    for ( ; cur >= 0; cur--)
        cout << p[cur];

    cout << endl;
}

int main()
{
    string a, b;

    while (cin >> a >> b)
    {
        process(a, b);
    }

    return 0;
}

