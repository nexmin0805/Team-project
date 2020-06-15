// 검색

void find()
{
    int i = 0;
    int n = 0;
    char f[NAME];
    printf("검색하려는 이름을 입력하시오.: ");
    scanf("%s",f);

    while(i<n)
    {
        // 두 개의 문자열이 일치할 경우 0 리턴
        if(strcmp(name[i],f) == 0)
        {
            printf("이름 : %s", name[i]);
            printf("번호 : %s", number[i]);
            return;
        }
        i++
    }
    printf("존재하지 않는 정보입니다.");
}
