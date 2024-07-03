// Program to read 100 students record with following fields and display the record of B.Sc. IT faculty only.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    int roll,dd,mm,yy;
    char name[250],faculty[250];
};
void main(){
    struct student s[100];
    char c,d;
    for(int i=0;i<3;i++){
       
        printf("Enter the name of the student:");
        gets(s[i].name);
        printf("Enter the faculty of the student:");
        gets(s[i].faculty);
        printf("Enter the roll number of the student:");
        scanf("%d",&s[i].roll);
        printf("Enter the date of birth in dd-mm-yy format:");
        scanf("%d %d %d",&s[i].dd,&s[i].mm,&s[i].yy);
        strcpy(s[i].faculty,strlwr(s[i].faculty));
        getchar();
    //    fflush(stdin);
       
        
    }
            printf("Roll no.\t Name\t DOB(dd-mm-yy)\n");
    for(int i=0;i<100;i++){
        if(strcmp("b.sc. it",s[i].faculty)==0){
            printf("%d\t %s\t  %d   %d   %d\n",s[i].roll,s[i].name,s[i].dd,s[i].mm,s[i].yy);
        }
    }
}