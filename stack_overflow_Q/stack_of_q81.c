#include<stdio.h>
#include<string.h>

int main()
{
FILE *f1ptr,*f2ptr,*f3ptr;
f1ptr=fopen("1stfile.txt","r");
f2ptr=fopen("2ndfile.txt","r");
f3ptr=fopen("3rdfile.txt","w");
char arr1[100],arr2[100];

while(fgets(arr1, sizeof arr1, f1ptr) )   
    {
        printf( "[%s]", arr1);
    int flag=1;
    rewind(f2ptr);
    while(fgets(arr2,sizeof arr2, f2ptr))
        {
        if(strcmp(arr1,arr2) ==0)
            {
            flag=0;//flag=0 means i will not store this string into file
            }
        }
       if(flag)
        fprintf(f3ptr,"%s",arr1);
    }
fclose(f1ptr);
fclose(f2ptr);
fclose(f3ptr);

return 0;
}