/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-01 17:35:46
 * @LastEditTime: 2022-06-01 22:08:35
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

struct node{
    double x;
    double y;
}a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].x >> a[i].y;
    }

    double ans = 1e9;

    for(int i = 1;i <= n;i ++){
        for(int j = i + 1;j <= n;j ++){
            double temp = sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) +
                                (a[i].y - a[j].y)*(a[i].y - a[j].y));
            ans = min(ans,temp);
        }
    }
    cout << fixed << setprecision(4) << ans << endl;    


    return 0;
}