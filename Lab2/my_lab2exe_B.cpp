/*
 *  my_lab2exe_B.cpp
 *  ENSF 614 Lab 2 Exercise B
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <cstring>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int);
/*  Duplicates strncat from <cstring>, except return type is void.
 *  REQUIRES
 *     dest points to the beginning of the first string.
 *     source points to the beginning of the second string.
 *     int indicates how many letters from the second string needs to be added to string 1
 *  PROMISES
 *     Returns the concatenated string.
 */

int my_strcmp(const char *str1, const char *str2);
/*  Duplicates strcmp from <cstring>, except return type is void.
 *  REQUIRES
 *     str1 points to the beginning of the first string.
 *     str2 points to the beginning of the second string.
 *  PROMISES
 *     Returns an integer to indicate the difference between str1 and str2 if they are different. 
 *     0 indicates both strings are the same.
 *     Positive means str1 is larger than str2 and vice versa.
 */

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    
    /* using strlen libarary function */
    length = (int) my_strlen(my_string);
    cout << "\nLine 1: my_string length is " << length;
  
    /* using sizeof operator */
    bytes = sizeof (my_string);
    cout << "\nLine 2: my_string size is " << bytes << " bytes.";
   
    /* using strcpy libarary function */
    strcpy(my_string, str1);
    cout << "\nLine 3: my_string contains: " << my_string;
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 4: my_string length is " << length << ".";
   
    my_string[0] = '\0';
    cout << "\nLine 5: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 6: my_string length is " <<  length << ".";
   
    bytes = sizeof (my_string);
    cout << "\nLine 7: my_string size is still " << bytes << " bytes.";
 
    /* strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    cout << "\nLine 8: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 9: my_string length is " << length << ".";
   
    my_strncat(my_string, str2,  4);
    cout << "\nLine 10: my_string contains:\"" << my_string << "\"";
    
    /* my_strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    cout << "\nLine 11: my_string contains:\"" << my_string << "\"";
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 12; my_string has " << length << " characters.";

    cout << "\n\nUsing strcmp - C library function: ";
    
    cout << "\n\"ABCD\" is less than \"ABCDE\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCDE");

    cout << "\n\"ABCD\" is less than \"ABND\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABND");
    
    cout << "\n\"ABCD\" is equal than \"ABCD\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCD");
 
    cout << "\n\"ABCD\" is less than \"ABCd\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCd");

    cout << "\n\"Orange\" is greater than \"Apple\" ... my_strcmp returns: " <<
    my_strcmp("Orange", "Apple") << endl;
    return 0;
}

int my_strlen(const char *s)
{
    int length = 0;
    
    while (s[length] != 0)
    {
        length++;
    }
    return length;
}

void my_strncat(char *dest, const char *source, int n)
{
    int end = 0;
    while (dest[end] != 0)
    {
        end++;
    }
    for (int i = 0; i < n; i++)
    {
        dest[end] = source[i];
        end++;
    }
    dest[end] = 0;
}

int my_strcmp(const char *str1, const char *str2)
{
    int length = 0;
    while (str1[length] != 0 || str2[length] != 0)
    {
        if (str1[length] == str2 [length])
        {
            length++;
        }
        else
        {
            return str1[length] - str2[length];
        }
    }
    return 0;
}