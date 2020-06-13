#define NAME 100

typedef struct{
    char name[NAME];
    char number[11];
}phone;

void search()
{
    char search[NAME], f;
    
    printf("찾을 이름을 입력하시오. : ");
    scanf("%s",search);

    f = find(search);

    if(f == -1)
    {
        printf("존재하지 않는 이름입니다.");
        return;
    }
    else
    {
        printf("이름 : %s", phone[f].name);
        printf("번호 : %s", phone[f].number);
    }

}

void find(char search[])
{
    int i;
    for(i=0; i<NAME; i++)
    {
        if(!strcmp(phone[i].name, search))
        return i;
    }
    return -1;
}
