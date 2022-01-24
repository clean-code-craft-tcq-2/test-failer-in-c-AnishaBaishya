#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Struct_ColourCode
{
    char majorColour[25];
    char minorColour[25];  
    char colourCode;
};

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMapStub(void (*Fn_Ptr_printColourPairAndCode)(int,int,  char*,  char* ));
Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex);
void printColourPairAndCodeStub(int colorCode, char* majorColor, char* minorColor);
 
int ColorCodePairNoToBePrintedInConsole = 1;

// Source Code 
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

// Dependency Injection
int printColorMapStub(void (*Fn_Ptr_printColourPairAndCode)(int,int, char*,  char* ))
{

    int majorColourIndex = 0; 
    int minorColourIndex = 0;
    Struct_ColourCode ColourInfo;
    for(majorColourIndex = 0; majorColourIndex < 5; majorColourIndex++) 
    {
        for(minorColourIndex = 0; minorColourIndex < 5; minorColourIndex++) 
        {
            ColourInfo = CopyColourInfo(majorColourIndex,minorColourIndex);
            Fn_Ptr_printColourPairAndCode(majorColourIndex,minorColourIndex,ColourInfo.majorColour,ColourInfo.minorColour);
        }
    }

    return (minorColourIndex * majorColourIndex);
}

Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex)
{
   
    Struct_ColourCode ColourInfo;
    strcpy(ColourInfo.majorColour, majorColor[majorColourIndex]);
    strcpy(ColourInfo.minorColour, minorColor[minorColourIndex]);
    ColourInfo.colourCode = (5 * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairAndCodeStub(int majorColourIndex, int minorColourIndex,  char* majorColor,  char* minorColor)
{
    printf("%d | %s | %s\n", majorColourIndex * 5 + minorColourIndex, majorColor, minorColor);
    ColorCodePairNoToBePrintedInConsole++;
}


int main() {
    Struct_ColourCode test_colourInfo;
    int test_majorColourIndex = 0;
    int test_minorColourIndex = 0;
    int test_expectedColourCode = 0;
    void (*Fn_Ptr)(int,int,  char*,  char*) = printColourPairAndCodeStub;
    test_colourInfo = CopyColourInfo(test_majorColourIndex,test_minorColourIndex);
    test_expectedColourCode = (test_majorColourIndex * 5 + test_minorColourIndex);
    assert(test_colourInfo.colourCode == test_expectedColourCode);
    assert(strcmp(test_colourInfo.majorColour,majorColor[test_majorColourIndex]) == 0);
    assert(strcmp(test_colourInfo.minorColour,minorColor[test_minorColourIndex]) == 0);
    int result = printColorMapStub(Fn_Ptr);
    assert(result == ColorCodePairNoToBePrintedInConsole);
    printf("All is well (maybe!)\n");
    return 0;
}
