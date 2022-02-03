#include <stdio.h>
#include <assert.h>

#define MAX_THRESHOLD 200
#define MIN_THRESHOLD 150
    
int alertFailureCount = 0;
int checkFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius >= MIN_THRESHOLD && celcius <=MAX_THRESHOLD)
    {
        return 200;
    }
    else
    {
        checkFailureCount +=1;
        return 500;
    }
}

float ConvertFarenheitToCelsius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit,int (*Fn_Ptr_networkAlertStub)(float)) {
    float celcius = ConvertFarenheitToCelsius(farenheit);
    int returnCode = Fn_Ptr_networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    
    int (*Fn_Ptr)(float) = networkAlertStub;
    
    alertInCelcius(400.5,Fn_Ptr);
    alertInCelcius(303.6,Fn_Ptr);
    
    assert(alertFailureCount == checkFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
