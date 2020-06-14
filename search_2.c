// 이름 검색

phone *head, *tail;
int s_name(char *name)
{
    phone *i;
    int num = 0;
    i = head;

    while(i != NULL)
    {
        if(strstr(i -> name, name))
        {
            output(i);
            num++;
        }
        i = i-> next;
    }
    return num;
}
