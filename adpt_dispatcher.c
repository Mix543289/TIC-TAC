float compute_disorder(stack a)
{
    int mistakes = 0;
    int total_pairs = 0;
    int i;
    int j;
    int size;
    i =0;
    size = count(a)-1;
    while (i < size)
    {
        j = i+1;
        while (j<size)
        {
            total_pairs += 1;
        }
        if (a[i] > a[j])
            mistakes += 1;        
    }
    return(mistakes/total_pairs);
}


dispatcher(stack a)
{
    float percent;
    percent = compute_disorder(a);

    if (percent < 0.2 || NB(a) <= 5)
        simple;
    else if (percent >= 0.2 && percent < 0.5)
        medium;
    else if (percent >= 0.5)
        complex;  
}
