#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool is_alpha(string st);
char get_key(string key_arg, int j);
string encode(string text, string key_arg);


int main(int argc, string argv[])
{   
    if (argc != 2 || is_alpha(argv[1]) <= 0)
    {   
        printf("usage: keyword\n");
        return 1;
    }
    else
    {
        string key_arg = argv[1];
        string text = get_string("plaintext: ");
        string etext = encode(text, key_arg);
        printf(">>> ciphertext: %s\n", etext);
    }
}    

string encode(string text, string key_arg)
{
    int j = 0;   // counts up to shift the key argument by 1
    int n = strlen(text);   // length of string.
    for (int i = 0; i < n; i++)
    {
        char ch = text[i];
        if (isalpha(ch))
        {
            // yields a shifted key argument each iteration.
            char key = get_key(key_arg, j);
            if (isupper(ch))    
            {
                // rotates a given char.
                ch = ch % 'A';
                ch = (ch + key) % 26;
                text[i] = ch + 'A';
            }
            else     //lowercase
            {
                // rotates a given char.
                ch = ch % 'a';
                ch = (ch + key) % 26;
                text[i] = ch + 'a';
            }
            j++;   // updating the counter.
        }
        else if (ispunct(ch) || isspace(ch))
        {
            text[i] = ch;   // does nothing when not alphabet.
        }
    }
    return text;
}

char get_key(string key_arg, int j)
{
    // shifting limit before resetting.
    int key_len = strlen(key_arg);
    // reset j after full cycle prevents it from floating.
    j = j != 0 && j % key_len == 0 ? 0 : j % key_len;  
    // returning the jth char index of the key argument.
    char key_buff = key_arg[j];
    // returns the rank of the key char wether upper or lower case.
    char key = isupper(key_buff) ? key_buff % 'A' : key_buff % 'a';
    return key;
}

bool is_alpha(string st)
{
    int cnt = 0;
    for (int i = 0, n = strlen(st); i < n; i++)
    {
        cnt = isalpha(st[i]) ? cnt + 1 : 0; 
    }
    return (cnt == strlen(st)) ? true : false;
}