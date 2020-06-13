// 출력
void print(phone* fri, int* cou) // cou: 사람 수
{
    for (int i = 0; i < *cou; i++)
        {
            printf("이름 : %s \n", fri[i].name);
            printf("번호 : %s ", fri[i].number);
            printf("\n\n");
        }
}
