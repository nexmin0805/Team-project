// 삭제
int remove(phone* fri, int* cou) // cou: 사람 수
{
    char who[NAME];
    printf("삭제할 이름 : ");
    scanf("%s", who);

    for (int i = 0; i < 100; i++) // 최대 저장수를 100으로 가정
    {
        if (strcmp(who, fri[i].name) == 0)
        {
            for (int j = i; j < 100; j++) // 최대 저장수를 100으로 가정, 삭제한 항목 다음 항목부터 하나씩 당겨오기
            {
                strcpy(fri[j].name, fri[j + 1].name);
                strcpy(fri[j].number, fri[j + 1].number);
            }
            printf("삭제 완료 \n\n");
            (*cou)--;
        }
    }
    return 0;
}
