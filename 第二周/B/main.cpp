#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int mod = 100003;
int n, k;
int ans[1111111];

int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        ans[0] = 1;
        // TODO: µÝÍÆµÃµ½ ans[n]
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++){
                if(i-j<0)
                {
                    break;
                }
                ans[i]+=ans[i-j];
            }
            if(ans[i]>0)
            {
                ans[i]%=mod;
            }

        }


        //ans[n]=ans[n-1]+ans[n-k];
        printf("%d\n", ans[n]);
    }
    return 0;
}
