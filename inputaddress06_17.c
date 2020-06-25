#include <stdio.h>
#include <string.h>
#define NAME 100

typedef struct phone{
    char name[NAME];
    int number[15];
}phone;

phone frined;
char name[NAME];
char number[11];
void select_Menu();
phone input_number(); //번호입력
/*int search(phone* fri);//검색
int remove(phone* fri, int* cou); //삭제        // cou: 사람 수
int s_phone(char *number); //번호검색
int s_name(char *name); //이름검색
void output(phone *data); //특정정보 하나만 출력
void output_all(); //모든 정보 출력*/

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
    int ans;
    printf("\n"); //한줄 띄웁니다.
    printf("====MENU==== \n");
    printf( "목록보기 : 1 \n");
    printf( "입력하기 : 2 \n");
    printf( "검색하기 : 3 \n");
    printf( "종료하기 : 4 \n");
    printf( "============ \n");
    printf( "MENU를 선택하세요 : ");
    scanf("%d", &ans);
     /* 사용자의 입력이 잘 못 되면 반복해서 다시 받는다. */
    while ((ans != 1) && (ans != 2) && (ans != 3) && (ans != 4))
        select_Menu();
    //if(ans == 1)
    if(ans == 2)
        input_number();
    /*if(ans == 3)
        s_phone(*number); //번호검색
        s_name( *name); //이름검색
        //search(* fri);//검색 */
    if(ans == 4){
        printf("종료하겠습니다\n");
    }
}

//이름, 번호 입력
/*phone input_number()
{
    phone friend;
    char num;
    printf("지정할 이름을 입력하세요\n");
    scanf("%s", friend.name);

    printf("새로운 전화번호를 입력하세요(공백없이 입력)\n");
    scanf("%s", friend.number);

    return friend;
}*/

//이름, 번호 입력
phone input_number()
{
    FILE *fp;
    fp = fopen("address.txt", "at");
    phone friend;
    char name[NAME];
    printf("지정할 이름을 입력하세요\n");
    scanf("%s", friend.name);

    fprintf(fp, "\n이름: ");
    fprintf(fp, "%s", friend.name);

    printf("새로운 전화번호를 입력하세요\n");
    scanf("%s", friend.number);

    fprintf(fp, "\n전화번호: ");
    fprintf(fp, "%s", friend.number);

    printf("입력완료\n");
}

