#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 36)
        sizeName = '!'; // May not be a valid size

    else if((cms >= 36) && (cms <= 38))
        sizeName = 'S';

    else if((cms >= 39) && (cms <= 41)) 
        sizeName = 'M';

    else if((cms >= 42) && (cms <= 44))
        sizeName = 'L';
        
    else 
        sizeName = '!'; // May not be a valid size
    return sizeName;
}

void testTshirtSize() {
    assert(size(-2) == '!');
    assert(size(20) == '!');
    assert(size(36) == 'S');
    assert(size(37) == 'S');
    assert(size(38) == 'S');
    assert(size(39) == 'M');
    assert(size(40) == 'M');
    assert(size(41) == 'M');
    assert(size(42) == 'L');
    assert(size(43) == 'L');
    assert(size(44) == 'L');
    assert(size(50) == '!');
}

int main() {
    testTshirtSize();
    
    printf("All is well (maybe!)\n");
    return 0;
}
