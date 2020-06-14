// 검색
int search(phone* fri)
{
    char who[NAME];

    printf("검색할 이름 : ");
    scanf("%s", who);

    for (int i = 0; i < 100; i++) // 저장 가능한 사람을 100명으로 가정
        {
            if (!strcmp(who, fri[i].name))
            {
                printf("번호 : %s \n\n", fri[i].number);
                return 0;
            }
        }
    return 0;
}
