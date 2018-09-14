/*
 * This program computes the user's Body Mass Index (BMI). He or she can decide which unit system to use, then input
 * his or her height and weight, and the program will indicate him or her his or her BMI category.
 *
 * Author: Gerardo González Becerril.
 * Date: September 13th, 2018.
 * E-mail: a01411981@itesm.mx
 */

 // Library needed.
#include <stdio.h>

// This function takes a person's height and weight and prints their BMI category.
int calculateBMI(double height, double weight) {

    // The BMI is calculated from dividing the height by the weight squared.
    double bmi = weight / height / height;

    // If statement to determine the category in which the user's BMI fit.
    if (bmi < 18.5) {
        printf("You are underweight.");
    } else if (bmi < 25) {
        printf("You are normal.");
    } else if (bmi < 30) {
        printf("You are overweight.");
    } else {
        printf("You suffer from obesity.");
    }

    return 0;

}

// This function takers the user's height in feet and inches and returns it in meters.
double convertHeight(double feet, double inches) {
    // Meters are calculated by adding the product of the feet multiplied by 0.3048 (1 feet in meters) and the
    // the product of the inches multiplied by 0.0254 (1 inch in meters).
    double meters = feet * 0.3048 + inches * 0.0254;
    return meters;
}

// This function takes the user's weight in pounds and returns it in kilograms.
double convertWeight(double pounds) {
    double kg = pounds * 0.4535; // Kilograms are calculated by multiplying the pounds by 0.4535 (1 pound in kilograms).
    return kg;
}

// Main function.
int main() {

    // Variables.
    char unitSystem; // String to detect the user's desired unit system.
    double feet; // Variable for storing the height in feet.
    double inches; // Variable for storing the height in inches.
    double weight; // Variable for storing the weight in either pounds or kilograms.
    double height; // Variable for storing the height in meters.

    // Welcomes the user and asking him for his desired unit system.
    printf("Welcome to the BMI Calculator!\n");
    printf("Which unit system would you like to use?\n");
    printf("Press 'm' for meters and kilograms.\n");
    printf("Or press 'i' for feet, inches and pounds.\n");
    scanf(" %c", &unitSystem); // Scans the user's input.

    // Switch statement to check the user's input.
    switch(unitSystem) {
        case 'i':
            // Asks the user for his height.
            printf("Please input your height in feet and inches (first feet, then press enter, then inches).\n");
            scanf("%lf%lf", &feet, &inches); // Scans the user's input.

            // Asks the user for his weight.
            printf("Please input your weight in pounds.\n");
            scanf("%lf", &weight); // Scans the user's input.

            height = convertHeight(feet, inches); // Uses a function to turn the user's height into meters.
            weight = convertWeight(weight); // Uses a function to turn the user's weight into kilograms.

            calculateBMI(height, weight); // Uses a function to print the user's BMI category.

            break;
        case 'm':
            // Asks the user for his height.
            printf("Please input your height in meters.\n");
            scanf("%lf", &height);

            // Asks the user for his weight.
            printf("Please input your weight in kilograms.\n");
            scanf("%lf", &weight); // Scans the user's input.

            calculateBMI(height, weight); // Uses a function to print the user's BMI category.

            break;
        default:
            // Informs the user he's selected a non-existent unit system.
            printf("%c is not a valid unit system.", unitSystem);
    }

    return 0; // Terminates the program.

}