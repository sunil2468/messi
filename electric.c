#include <stdio.h>
#include<conio.h>
void calculate_charges(char name[], int units) {
    // Rates
    float rate1 = 0.80;  // for the first 200 units
    float rate2 = 0.90;  // for the next 100 units
    float rate3 = 1.00;  // beyond 300 units
    float meter_charge = 100.00;  // minimum meter charge
    float charges = 0.0;
    float total_amount = 0.0;

    // Calculate charges
    if (units <= 200) {
        charges = units * rate1;
    } else if (units <= 300) {
        charges = (200 * rate1) + ((units - 200) * rate2);
    } else {
        charges = (200 * rate1) + (100 * rate2) + ((units - 300) * rate3);
    }

    // Add meter charge
    total_amount = charges + meter_charge;

    // Apply surcharge if total amount exceeds Rs 400
    if (total_amount > 400) {
        total_amount += total_amount * 0.15;
    }

    // Print the result
    printf("Name: %s\n", name);
    printf("Units Consumed: %d\n", units);
    printf("Total Charges: Rs %.2f\n", total_amount);
}

int main() {
    char name[50];
    int units;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    calculate_charges(name, units);

    return 0;
}
