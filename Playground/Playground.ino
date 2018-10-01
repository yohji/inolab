#include <stdarg.h>

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{
    delay(50);
}

//
// Support
//

float voltage(int analogPin)
{
    return (analogRead(analogPin) / 1023.0f) * 5.0;
}

void echo(int n_args, ...)
{
    va_list ap;
    va_start(ap, n_args);

    if (n_args == 1) {
        Serial.println(va_arg(ap, int));
    }
    else {
        String buffer = "";
        for (size_t loop = 0; loop < n_args; ++loop) {

            if (buffer.length() != 0)
                buffer.concat("\t");

            buffer.concat(va_arg(ap, int));
        }

        Serial.println(buffer);
    }

    va_end(ap);
}
