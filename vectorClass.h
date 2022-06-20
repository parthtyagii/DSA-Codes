class vector
{
    int cs;
    int ms;
    int *arr;

public:
    vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[1];
    }

    void push_back(int i)
    {
        if (cs == ms)
        {
            int *oldarr = arr;
            arr = new int[2 * ms];

            ms = 2 * ms;
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldarr[i];
            }

            delete[] oldarr;
        }

        arr[cs] = i;
        cs++;
    }

    int operator[](int i)
    {
        return arr[i];
    }
};