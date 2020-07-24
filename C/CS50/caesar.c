#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encode(string txt, int key);
bool is_digit(string st);
int main(int argc, string argv[])
{
    int key = 0;
    
    if (argc == 2 && is_digit(argv[1]))
    {   
        // cast string to int
        key = atoi(argv[1]);   
    }
    else
    {
        printf("usage: ");
        for (int i = 0; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 1;
    }
           
//     char ch = get_char("char: ");
//     printf("panc state: %i\n", isalpha(ch));
    string text = get_string("plaintext: ");
    string etext = encode(text, key);
    printf("ciphertext: %s\n", etext);
 
}


string encode(string txt, int key)
{
    // takes string text and returns rotated chars string
    int buff = 0;   // buffer to carry current char changes
    int n = strlen(txt);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(txt[i]))    // if char is alphabet
        {
            if (isupper(txt[i]))    // uppercase char
            {
                buff = txt[i] % 'A';
                buff = (buff + key) % 26;
                txt[i] = buff + 'A';
            }
            else     //lowercase char
            {
                //  get the rank of the lowercase chars ascii(char) - ascii(a)
                buff = txt[i] % 'a';
                //  % 26 used to limit chars between (a[0] : z[25]) 26 char
                buff = (buff + key) % 26;  
                //  after rotating the rank convert back to ascii(char)
                txt[i] = buff + 'a';
            }
        }
        else if (ispunct(txt[i]) || isspace(txt[i]))
        {
            // copy the chars like {',', '.', ';', ':', ' '} as they are 
            txt[i] = txt[i];
        }
    }
    return txt;
}

bool is_digit(string st)
{
    int cnt = 0;   // counts only digit chars in a string
    for (int i = 0, n = strlen(st); i < n; i++)
    {
        cnt = (st[i] >= '0' && st[i] <= '9') ? cnt + 1 : 0; 
    }
    return (cnt == strlen(st)) ? true : false;
}