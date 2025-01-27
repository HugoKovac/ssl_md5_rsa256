#include "md5.h"

size_t iterOne(size_t i)
{
    return i;
}

size_t iterTwo(size_t i)
{
    return (5 * i + 1) % 16;
}

size_t iterThree(size_t i)
{
    return (3 * i + 1) % 16;
}

size_t iterFour(size_t i)
{
    return (7 * i + 1) % 16;
}

uint32_t combine(t_md5 *data)
{
    /*

    */
    return 0;
}

void move_to_prime(int32_t combined)
{
    /*
        B' = combined
        C' = B
        D' = C
        A' = D
    */
}

void move_to_cipher(t_md5 *data)
{
    /*
        A = A'
        B = B'
        C = C'
        D = D'
    */
}

int md5()
{
    t_md5 data = {0};

    data.message = (int32_t *)malloc(sizeof(data.message) * 16);
    if (!data.message)
    {
        perror("Error allocating memory for message");
        return -1;
    }
    data.cipher = (int32_t *)malloc(sizeof(data.cipher) * 4);
    if (!data.cipher)
    {
        perror("Error allocating memory for cipher");
        return -1;
    }

    data.a = data.message;
    data.b = data.message + 1;
    data.c = data.message + 2;
    data.d = data.message + 3;

    *(data.a) = 0x67452301;
    *(data.b) = 0xefcdab89;
    *(data.c) = 0x98badcfe;
    *(data.d) = 0x10325476;

    data.index_functions[0] = &iterOne;
    data.index_functions[1] = &iterTwo;
    data.index_functions[2] = &iterThree;
    data.index_functions[3] = &iterFour;

    printf("%x\n", data.message[0]);
    printf("%x\n", data.message[1]);
    printf("%x\n", data.message[2]);
    printf("%x\n", data.message[3]);

    // todo: input check and padding

    for (size_t i = 0; i < 4; i++)
    {
        for (; data.counter < 16; data.counter++)
        {
            size_t index = data.index_functions[data.counter](i);

            move_to_prime(combine(&data));
            move_to_cipher(&data);
        }
    }

    return 0;
}
