#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>


void RepeatTextRainbow(const char* text)
{

    const unsigned int textLength = strlen(text) + 1;

    char* outputText = (char*)malloc(textLength + 15 /*the rest of my string*/);

    //strcat()

    unsigned int numberPrinted = 0;

    while (1)
    {
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

        const unsigned int numberOfPossibelPrints = size.ws_col % textLength;

        for (int n = 30; n <= 37; n++)
        {
            if (numberOfPossibelPrints == numberPrinted)
            {
                printf("\n");
            }
            

             sprintf(outputText, "\033[1;%dm%s\033[0m ", n, text);
             printf("%s", outputText);
             fflush(stdout);
             numberPrinted++;
             usleep(2000);
        }
    }
}

int main(int in1, char** in2) 
{

    const char* text = "YOUR TEXT HERE";

    RepeatTextRainbow(text);
    //printf("\033[1;32m\033[0m\n");
    //printf("regular text\n");

    return 0;
}
