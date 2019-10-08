#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    char str[100001];
    vector<int> v;
    scanf("%s", str);
    int len = strlen(str);
    int sum = 0;
    int flag = 0;
    for(int i=0;i<len;i++){
        sum+=str[i]-'0';
        v.push_back(str[i]-'0');
        if(str[i]=='0'){
            flag = 1;
        }
    }
    if(sum%3!=0||!flag)
    {
        printf("-1");
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=len-1;i>=0;i--)
        printf("%d",v[i]);

    return 0;
}