#include <stdio.h>
#include <string.h>

// Function to get charge per unit based on units consumed
float get_charge_per_unit(int units_consumed) {
    if (units_consumed <= 199) {
        return 1.20;
    } else if (units_consumed >= 200 && units_consumed < 400) {
        return 1.50;
    } else if (units_consumed >= 400 && units_consumed < 600) {
        return 1.80;
    } else {
        return 2.00;
    }
}

// Function to calculate the total bill
float calculate_total_bill(int units_consumed) {
    float charge_per_unit = get_charge_per_unit(units_consumed);
    float total_bill = units_consumed * charge_per_unit;
    
    // Add 15% surcharge if the total bill exceeds Ksh. 400
    if (total_bill > 400) {
        total_bill += total_bill * 0.15;  // Apply 15% surcharge
    }

    return total_bill;
}

int main() {
    // Declare variables
    char customer_id[20];
    char customer_name[50];
    int units_consumed;
    float charge_per_unit, total_amount_to_pay;

    // i. Prompt user to enter Customer ID, Customer Name, and Units Consumed
    printf("Enter Customer ID: ");
    scanf("%s", customer_id);
    printf("Enter Customer Name: ");
    scanf("%s", customer_name);
    printf("Enter Units Consumed: ");
    scanf("%d", &units_consumed);

    // ii. Calculate the total bill and iii. calculate surcharge if necessary
    total_amount_to_pay = calculate_total_bill(units_consumed);
    charge_per_unit = get_charge_per_unit(units_consumed);
    
    // Output: Display the results
    printf("\nElectricity Bill Summary:\n");
    printf("Customer ID       : %s\n", customer_id);
    printf("Customer Name     : %s\n", customer_name);
    printf("Units Consumed    : %d\n", units_consumed);
    printf("Charge per Unit   : %.2f Ksh\n", charge_per_unit);
    printf("Total Amount to Pay: %.2f Ksh\n", total_amount_to_pay);

    return 0;
}