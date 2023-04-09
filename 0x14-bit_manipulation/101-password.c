#include <stdio.h>
#include <string.h>

int check_password(char* password)
{
    
if (strcmp(password, "Hol") == 0)
{
return 1;
}
return 0;
}

int main(int argc, char** argv)
{
if (argc != 2) 
{
printf("Usage: %s [password]\n", argv[0]);
return 1;
}

if (check_password(argv[1]))
{
printf("Congratulations!\n");
}
else 
{
printf("Access Denied.\n");
}

return 0;
}

