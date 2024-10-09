#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char customer_id[20];
    char customer_name[50];
    int units_consumed;
    float charge_per_unit, total_bill, surcharge = 0;

    // i. Prompt user to enter Customer ID, Customer Name, and Units Consumed
    printf("Enter Customer ID: ");
    scanf("%s", customer_id);
    printf("Enter Customer Name: ");
    scanf("%s", customer_name);
    printf("Enter Units Consumed: ");
    scanf("%d", &units_consumed);

    // ii. Use if-else to determine the charge per unit and calculate total bill
    if (units_consumed <= 199) {
        charge_per_unit = 1.20;
    } else if (units_consumed >= 200 && units_consumed < 400) {
        charge_per_unit = 1.50;
    } else if (units_consumed >= 400 && units_consumed < 600) {
        charge_per_unit = 1.80;
    } else {
        charge_per_unit = 2.00;
    }

    // Calculate the total bill
    total_bill = units_consumed * charge_per_unit;

    // iv. Apply a 15% surcharge if the bill exceeds Ksh. 400
    if (total_bill > 400) {
        surcharge = total_bill * 0.15;
        total_bill += surcharge;  // Add surcharge to the total bill
    }

    // Output the results
    printf("\nElectricity Bill Summary:\n");
    printf("Customer ID       : %s\n", customer_id);
    printf("Customer Name     : %s\n", customer_name);
    printf("Units Consumed    : %d\n", units_consumed);
    printf("Charge per Unit   : %.2f Ksh\n", charge_per_unit);
    if (surcharge > 0) {
        printf("Surcharge Applied : %.2f Ksh\n", surcharge);
    }
    printf("Total Amount to Pay: %.2f Ksh\n", total_bill);

    return 0;
}