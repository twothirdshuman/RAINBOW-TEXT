#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>


void RepeatTextRainbow(const char* text)
{

    char* outputText = (char*)malloc(strlen(text) + 14 /*the rest of my string*/);

    while (1)
    {
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

        for (int n = 30; n <= 37; n++)
        {
            
             sprintf(outputText, "\033[1;%dm%s\033[0m ", n, text);
             printf("%s", outputText);
             fflush(stdout);
             usleep(2000);
        }
    }
}

int main(int in1, char** in2) 
{

    const char* text = "YOUR TEXT HERE";

    RepeatTextRainbow(text);

    return 0;
}
