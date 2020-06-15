// 번호검색

int s_phone(char *number)
{
    phone *i;
    int num = 0;
    i = head;

    while(i != NULL)
    {
        if(strstr(i -> number, number))
        {
            output(i);
            num++;
        }
        i = i-> next;
    }
    return num;
}
