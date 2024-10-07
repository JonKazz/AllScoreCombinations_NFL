#include <stdio.h>

float celsiusconverter(float temp, int scale) // Converts to Celsius
{
    if (scale == 1) // Returns celcius value
    {
        return temp;
    }

    if (scale == 2) // Converting Fahrenheit to Celsius
    {
        return (5.0 / 9.0) * (temp - 32);
    }

    if (scale == 3) // Converting Kelvin to Celsius
    {
        return temp - 273.15;
    }
}

float fahrenheitconverter(float temp, int scale) // Converts to Fahrenheit
{
    if (scale == 1) // Converting Celcius to Fahrenheit
    {
        return (9.0 / 5.0) * temp + 32;
    }
    if (scale == 3) // Converting Kelvin to Fahrenheit
    {
        return (9.0 / 5.0) * (temp - 273.15) + 32;
    }
}

float kelvinconverter(float temp, int scale) // Converts to Kelvin
{
    if (scale == 1) // Celcius to Kelvin
    {
        return temp + 273.15;
    }
    if (scale == 2) // Fahrenheit to Kelvin
    {
        return (5.0 / 9.0) * (temp - 32) + 273.15;
    }
}

void categorize_temperature(float celsius) // Prints temperature category and weather advisory
{
    if (celsius < 0) // If freezing
    {
        printf("Temperature category: Freezing\n");
        printf("Bundle up!");
    }
    else if (celsius <= 10.0) // If cold
    {
        printf("Temperature category: Cold\n");
        printf("Wear a jacket.");
    }
    else if (celsius <= 25.0) // If comfortable
    {
        printf("Temperature category: Comfortable\n");
        printf("You should be comfortable.");
    }
    else if (celsius <= 35.0) // If hot
    {
        printf("Temperature category: Hot\n");
        printf("Wear sunscreen and stay hydrated.");
    }
    else // If extreme heat
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Stay indoors.");
    }
}

int main()
{
    while (1)
    {
        float temperature;
        int scale; // First input (measurement of temperature)
        int conversion; // Second input (measurement we are converting too)

        printf("\nEnter the temperature: ");
        scanf("%f", &temperature);

        // Loop for getting scale choice
        while (1)
        {
            printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &scale);
            if (scale != 1 && scale != 2 && scale != 3) // If scale is not valid input (1,2,3)
            {
                printf("You must enter a number between 1 and 3.\n");
            }
            else if (scale == 3 && temperature < 0) // If scale is Kelvin and is negative
            {
                printf("Invalid value. Kelvin cannot be negative.\n");
            }
            else // If no errors, break from loop
            {
                break;
            }
        }

        // Loop for getting conversion choice
        while (1)
        {
            printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            scanf("%d", &conversion);
            if (conversion != 1 && conversion != 2 && conversion != 3) // If conversion is not valid input (1,2,3)
            {
                printf("You must enter a number between 1 and 3.\n");
            }
            else if (conversion == scale) // If conversion and scale are the same measurement
            {
                printf("Invalid conversion. Please choose another measurement.\n");
            }
            else // If no errors, break from loop
            {
                break;
            }
        }


        printf("\n");
        float convertedtemp;

        if (conversion == 1) // If converting to Celcius
        {
            convertedtemp = celsiusconverter(temperature, scale);
            printf("Converted temperature: %.2f°C\n", convertedtemp);
        }
        if (conversion == 2) // If converting to Fahrenheit
        {
            convertedtemp = fahrenheitconverter(temperature, scale);
            printf("Converted temperature: %.2f°F\n", convertedtemp);
        }
        if (conversion == 3) // If converting to Kelvin
        {
            convertedtemp = kelvinconverter(temperature, scale);
            printf("Converted temperature: %.2fK\n", convertedtemp);
        }

        float celciustemp = celsiusconverter(temperature, scale); // Converts temperature to celcius for categorization
        categorize_temperature(celciustemp); // Categorizes temperature
        printf("\n");
    }
}