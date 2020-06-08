#include <stdio.h>
#include <string.h>
#define NAME 100

typedef struct {
    char name[NAME];
    char number[11];
}phone;

//typedef struct phone *phonePointer;
//typedef struct phone {
//    char name[NAME];
//    char number[11];
//    phonePointer link;
//};

phone frined;
char number[11];
void input_number();

int main()
{
    phone friend;
    input_number();
    strcpy(friend.number, number);
    printf("%s", friend.number);

    return 0;

}

void input_number()
{
    printf("새로운 전화번호를 입력하세요(공백없이 입력)\n");
    char num;
    for (int i = 0; num != ' ' ;i++ ){
        scanf("%c", &num);
        number[i] = num;
    }
}



 