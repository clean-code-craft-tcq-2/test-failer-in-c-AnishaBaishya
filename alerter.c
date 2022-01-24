#include <stdio.h>
#include <assert.h>

#define MAX_THRESHOLD 200
#define MIN_THRESHOLD 150
    
int alertFailureCount = 0;
int checkPerformedCount = 0;
int checkFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    checkPerformedCount +=1;
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius >= MIN_THRESHOLD && celcius <=MAX_THRESHOLD)
        return 200;
    else
        checkFailureCount +=1;
        return 500;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(checkPerformedCount == 2);
    assert(alertFailureCount == checkFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
