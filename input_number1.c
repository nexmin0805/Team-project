#include <stdio.h>
#define NAME 100

typedef struct phone{
    char name[NAME];
    char number[11];
}phone;

char name[NAME];
int number[11];

void input_number()
{
    printf("새로운 전화번호를 입력하세요(공백없이 입력)\n");
    char num;
    int count = 0;
    for (int i = 0; num != ' ' ; ){
        scanf("%c", &num);
        number[i] = num;
        count++;
        printf("%c", number[i]);
    }

    /*for (int i = 0; i < count; i++)
        printf("%c", number[i]); */
}


