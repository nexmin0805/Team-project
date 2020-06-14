// 삭제

void remove()
{
    int i = 0;
    int n;
    char r[NAME];
    printf("삭제하고자 하는 이름을 입력하시오.: ");
    scanf("%s",r);

    for(i=0; i<n; i++)
    {
        // 마지막 사람 삭제된 자리로 옮기기
        name[i] = name[n-1];
        number[i] = number[n-1];
        // 저장된 사람수 감소 시킴
        n--;
        printf("%s의 정보가 삭제 되었습니다.",r);
        return;
    }
    printf("존재하지 않는 정보입니다.");
}
