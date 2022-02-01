#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Struct_ColourCode
{
    const char *majorColor;
    const char *minorColor;  
    char colourCode;
};

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap(void (*Fn_Ptr_printColourPairStub)(Struct_ColourCode));
Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex);
void printColourPairStub(Struct_ColourCode);
 

// Source Code 
int printColorMap(void (*Fn_Ptr_printColourPairStub)(ColorPair)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColourPairStub(CopyColourInfo(i,j));
        }
    }
    return i * j;
}

Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex)
{
   
    Struct_ColourCode ColourInfo;
    strcpy(ColourInfo.majorColour, majorColor[majorColourIndex]);
    strcpy(ColourInfo.minorColour, minorColor[minorColourIndex]);
    ColourInfo.colourCode = (5 * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairStub(Struct_ColourCode ColorPairReceived)
{
    printf("%d | %s | %s\n", ColorPairReceived.colourCode, ColorPairReceived.majorColor, ColorPairReceived.minorColor);
}


int main() {
    void (*Fn_Ptr)(Struct_ColourCode) = printColourPairStub;
    int result = printColorMap(Fn_Ptr);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
