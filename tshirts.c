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

int main() {
    assert(size(-2) == '!');
    assert(size(20) == '!');
    assert(size(37) == 'S');
    assert(size(38) == 'S');
    assert(size(40) == 'M');
    assert(size(41) == 'M');
    assert(size(42) == 'M');
    assert(size(43) == 'L');
    assert(size(50) == '!');
    printf("All is well (maybe!)\n");
    return 0;
}
