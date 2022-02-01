#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Struct_ColourCode
{
    const char *majorColour;
    const char *minorColour;  
    char colourCode;
};

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap(void (*Fn_Ptr_printColourPairStub)(Struct_ColourCode));
Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex);
void printColourPairStub(Struct_ColourCode);
 

// Source Code 
int printColorMap(void (*Fn_Ptr_printColourPairStub)(Struct_ColourCode)) {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            Fn_Ptr_printColourPairStub(CopyColourInfo(i,j));
        }
    }
    return i * j;
}

Struct_ColourCode CopyColourInfo(int majorColourIndex, int minorColourIndex)
{
   
    Struct_ColourCode ColourInfo;
    ColourInfo.majorColour=majorColor[majorColourIndex];
    ColourInfo.minorColour=minorColor[minorColourIndex];
    ColourInfo.colourCode = (5 * majorColourIndex) + minorColourIndex + 1;
    return ColourInfo;   
}

void printColourPairStub(Struct_ColourCode ColorPairReceived)
{
    printf("%d | %s | %s\n", ColorPairReceived.colourCode, ColorPairReceived.majorColour, ColorPairReceived.minorColour);
}

void unitTestColorMapforRandomPairNumber(int expectedNumberPair) {
    int i = (expectedNumberPair-1)/5;
	int j = (expectedNumberPair-1)%5;
    
	Struct_ColourCode testColorpair = CopyColourInfo(i,j);
 	assert(testColorpair.colourCode == expectedNumberPair);
 	assert(testColorpair.majorColour == majorColor[i]);
 	assert(testColorpair.minorColour == minorColor[j]);
}


int main() {
    void (*Fn_Ptr)(Struct_ColourCode) = printColourPairStub;
    int result = printColorMap(Fn_Ptr);
    assert(result == 25);
    
    for(int i=1; i<=25; i++)
    unitTestColorMapforRandomPairNumber(i);
    
    printf("All is well (maybe!)\n");
    return 0;
}
