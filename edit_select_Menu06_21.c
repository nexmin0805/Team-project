#include <stdio.h>
#include <string.h>
#define NAME 100

typedef struct phone{
    char name[NAME];
    int number[15];
}phone;

char name[NAME];
char number[11];
void select_Menu();
phone input_number(); //번호입력
void output_all(); //모든 정보 출력
void s_name(); // 이름검색
/*int search(phone* fri);//검색
int remove(phone* fri, int* cou); //삭제        // cou: 사람 수
int s_phone(char *number); //번호검색
void output(phone *data); //특정정보 하나만 출력*/
int main()
{
    phone friend;
    /*input_number();
    strcpy(friend.number, number);
    printf("%s", friend.number); */

    select_Menu();
    return 0;
}

void select_Menu()
{
    int answer;
    printf("\n"); //한줄 띄웁니다.
    printf("====MENU==== \n");
    printf( "목록보기 : 1 \n");
    printf( "입력하기 : 2 \n");
    printf( "검색하기 : 3 \n");
    printf( "종료하기 : 4 \n");
    printf( "============ \n");
    printf( "MENU를 선택하세요 : ");
    scanf("%d", &answer);
     /* 사용자의 입력이 잘 못 되면 반복해서 다시 받는다. */
    while(1){
        if(answer == 1)
            output_all();
        if(answer == 2)
            input_number();
        if(answer == 3)
            s_name();
        if(answer == 4)
            break;
        select_Menu();
    }
}
// 이름 검색
void s_name()
{
    FILE *fp; 
    char find_name[NAME]; char name[NAME];
    char phone_num[11];
    char c;
    printf("검색할 이름을 입력하시오: ");
    scanf("%s", &name);

    fp = fopen("address.txt", "r");
    if(fp == NULL)
    {
        printf("존재하지 않는 정보입니다.");
        return;
    }

    while( !feof(fp) ) {
            fscanf(fp, "%s\t%s\n", find_name, phone_num);

            if( !strcmp(name, find_name) )
            {
                printf("name: %s, phone_number: %s\n", find_name, phone_num);
            }
    }

    fclose(fp);
}

//모든 정보 출력
void output_all()
{
    FILE *fp;
    char c;
    fp = fopen("address.txt", "r");
    if(fp == NULL)
    {
        printf("존재하지 않는 정보입니다.");
        return;
    }
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);
}

//이름, 번호 입력
phone input_number()
{
    FILE *fp;
    fp = fopen("address.txt", "at");
    phone friend;
    char name[NAME];
    printf("지정할 이름을 입력하세요\n");
    scanf("%s", friend.name);

    printf("새로운 전화번호를 입력하세요\n");
    scanf("%s", friend.number);

    fprintf(fp, "%s\t%s\n", friend.name, friend.number);

    printf("입력완료\n");
    fclose(fp);
}

