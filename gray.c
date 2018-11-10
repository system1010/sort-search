#include <stdio.h>
int  main(void){
int aj=0, a[8]={0}, f[9]={0,1,2,3,4,5,6,7,8};
label1:;
for (int i=0;i<8;++i)
printf("%i", a[i]);
printf("\n");
aj=f[0];f[0]=0;
if(aj>7) return 0;
else
f[aj]=f[aj+1];
f[aj+1]=aj+1;
a[aj]=(a[aj]-1)>=0 ? 0 : 1;
goto label1;
}
