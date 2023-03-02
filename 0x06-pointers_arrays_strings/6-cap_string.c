
#include "main.h"


/**
 *
 *  * cap_string - Capitalizes all words of a string.
 *
 *   * @str: The string to be capitalized.
 *
 *    *
 *
 *     * Return: A pointer to the changed string.
 *
 *      */

char *cap_string(char *str)

{

	        int index = 0;


		        while (str[index])

				        {

						                while (!(str[index] >= 'a' && str[index] <= 'z'))

									                        index++;


								                if (str[index - 1] == ' ' ||

												                    str[index - 1] == '\t' ||

														                        str[index - 1] == '\n' ||

																	                    str[index - 1] == ',' ||

																			                        str[index - 1] == ';' ||

																						                    str[index - 1] == '.' ||

																								                        str[index - 1] == '!' ||

																											                    str[index - 1] == '?' ||

																													                        str[index - 1] == '"' ||

																																                    str[index - 1] == '(' ||

																																		                        str[index - 1] == ')' ||

																																					                    str[index - 1] == '{' ||

																																							                        str[index - 1] == '}' ||

																																										                    index == 0)

																																												                            str[index] -= 32;


										                index++;

												        }


			        return (str);

}








7-leet.c


#include "main.h"

/**
 *
 *  * leet - encode into 1337speak
 *
 *   * @n: input value
 *
 *    * Return: n value
 *
 *     */

char *leet(char *n)

{

	        int i, j;

		        char s1[] = "aAeEoOtTlL";

			        char s2[] = "4433007711";


				        for (i = 0; n[i] != '\0'; i++)

						        {

								                for (j = 0; j < 10; j++)

											                {

														                        if (n[i] == s1[j])

																		                        {

																						                                n[i] = s2[j];

																										                        }

																	                }

										        }

					        return (n);

}
