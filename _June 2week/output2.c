void output_all()
{
    phone *a;

    if(head = NULL)
    {
        printf("존재하지 않는 정보입니다.");
        return;
    }

    a = head;

    while(a != NULL)
    {
        output(a);
        a = a -> next;    
    }
}
