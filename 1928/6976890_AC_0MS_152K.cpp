#include <iostream>  
#include <stdlib.h>  
using namespace std;  
struct ac  
{  
    int x, y, num;  
}v[3000];  
int n, m, t;  
int cmp(const void*a, const void*b)  
{  
    struct ac *c = (ac*)a;  
    struct ac *d = (ac*)b;  
    return d->num - c->num;  
}  
int main()  
{  
int tc;
scanf("%d", &tc);
while(tc--)
{
    int i, j, data, k;  
    scanf("%d %d %d", &n, &m, &t);  
    k = 0;  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
        {  
            scanf("%d", &data);  
            if (data > 0)  
            {  
                v[k].x = i;  
                v[k].y = j;  
                v[k].num = data;  
                k++;  
            }  
        }  
    }  
    qsort(v, k, sizeof(v[0]), cmp);  
    m = k;  
    k = 0;  
    int x = -1, y = v[0].y;  
    int ans = 0;  
    for(i = 0; i < m; i++)  
    {  
        k += abs(v[i].x - x) + abs(v[i].y-y);  
        if (k + v[i].x + 2 <= t)  
        {  
            k++;  
            ans += v[i].num;  
            x = v[i].x;  
            y = v[i].y;  
        }  
        else  
        {  
            break;  
        }  
    }  
    printf("%d\n", ans); 
} 
    return 0;  
}  