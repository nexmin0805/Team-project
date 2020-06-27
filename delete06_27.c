#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
void delete(); //삭제  

int main()
{
    phone friend;
    select_Menu();
    return 0;
}

void select_Menu()
{/* 사용자의 입력이 잘 못 되면 반복해서 다시 받는다. */
    int answer;
    
    while(1){
        printf("\n"); 
        printf("====MENU==== \n");
        printf( "목록보기 : 1 \n");
        printf( "입력하기 : 2 \n");
        printf( "검색하기 : 3 \n");
        printf( "삭제하기 : 4 \n");
        printf( "종료하기 : 5 \n");
        printf( "============ \n");
        printf( "MENU를 선택하세요 : ");
        
        scanf("%d", &answer);

        if(answer == 1)
            output_all();
        else if(answer == 2)
            input_number();
        else if(answer == 3)
            s_name();
        else if(answer == 4)
            delete();
        else if(answer == 5)
            break;        
    }
    printf("프로그램을 종료\n");
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
// 삭제
void delete()
{
    char who[10];
    printf("삭제할 이름 : ");
    scanf("%s", who);

    FILE *fp;
    fp = fopen("address.txt", "rt+");
    if(fp == NULL)
    {
        printf("존재하지 않는 정보입니다.");
        return;
    }
      char address[116];
      rewind(fp);
        long seek, start;
        while(1)
        {
            seek = ftell(fp);
            if (fgets(address, 116, fp) == NULL) 
                break;
            if (strstr(address, who) != NULL)
                start = seek; 
            if (strstr(address, who) != NULL)
            {
                long last = filelength(fileno(fp))-ftell(fp);
                char *tmp = (char *)malloc(last);
                last = fread(tmp, 1, last, fp);
            
                fseek(fp, start, SEEK_SET);
                fwrite(tmp, 1, last, fp);
                fflush(fp);
                free(tmp);
                _chsize(fileno(fp), ftell(fp));
                     break;
            } 
        }
    rewind(fp);
    printf("\n삭제 완료\n");

    fclose(fp);
}
