#include <stdio.h>
#include <string.h>

struct medicine {
    char name[50];  // medicine name
    float price;
    char date[11];   // string function for date (dd/mm/yyyy)
};

struct user {
    char user_name[50]; // user name
    char mobile_number[11]; // mobile number (as a string)
};
float bill1(struct medicine medicines[], int num_medicines) {
    float total = 0;
    printf("\nMedicine Name\tPrice\n");
    printf("=========================================\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%s\t\tRs. %.2f\n", medicines[i].name, medicines[i].price);
        total += medicines[i].price;
    }
    printf("=========================================\n");
    float gst = 0.18 * total; // calculate GST at 18%
    float bill = total + gst; // add GST to the total
    printf("Total\t\tRs. %.2f\n", total);
    printf("GST (18%)\tRs. %.2f\n", gst);
    printf("=========================================\n");
    printf("Grand Total\tRs. %.2f\n", bill);
    return bill;
}


int main() {
    char response = 'N';
    int num_users = 0;
    int num_medicines = 0;

    struct user users[50];
    struct medicine medicines[50]; // arrays to store up to 50 users and medicines

    printf("====================================================\n");
    printf("|            PHARMACY MANAGEMENT SYSTEM            |\n");
    printf("====================================================\n");

    while (response != 'Y') {
        printf("\nChoose an option:\n");
        printf("1. Add new customer data\n");
        printf("2. Add new medicine\n");
        printf("3. Buy medicine\n");
        printf("4. Exit\n");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: // add new customer data
                if (num_users >= 50) {
                    printf("You have reached maximum user limit.\n");
                } else {
                    struct user u;
                    printf("\nEnter your name: ");
                    scanf("%49s", &u.user_name);
                    printf("Enter your mobile number: ");
                    scanf("%11s", &u.mobile_number);
                    users[num_users] = u;
                    num_users++;
                    printf("\nNew customer added successfully.\n");
                }
                break;

            case 2: // add new medicine
                if (num_medicines >= 50) {
                    printf("You have reached maximum medicine limit.\n");
                } else {
                    struct medicine m;
                    printf("\n");
                    printf("====================================================\n");
                    printf("|                ADD NEW MEDICINE                  |\n");
                    printf("====================================================\n");
                    printf("Name of medicine: ");
                    scanf("%49s", &m.name);
                    printf("Price of the medicine: ");
                    scanf("%f", &m.price);
                    printf("Expiry date of medicine (dd/mm/yyyy): ");
                    scanf("%10s", &m.date);
                    medicines[num_medicines] = m;
                    num_medicines++;
                    printf("\nNew medicine added successfully.\n");
                }
                break;
case 3:
    // User selection part
    if(num_users==0){
        printf("No user data found.\n");
    }
    else{
        int choice;
        printf("Choose a user: \n");
        for(int i=0;i<num_users;i++){
            printf("%d. %s\n",i+1,users[i].user_name);
        }
        scanf("%d",&choice);
        if(choice<1 || choice>num_users){
            printf("Invalid choice.\n");
            break;
        }
        else{
            struct user u= users[choice-1];
            printf("Selected user: %s, %s\n",u.user_name,u.mobile_number);
        }
    }
    // Medicine buying part
    if (num_medicines == 0) {
        printf("No medicines found.\n");
    } else {
        int num_choices = 0;
        int choices[50];
        printf("Choose medicine(s) to buy (enter 0 to finish):\n");
        for (int i = 0; i < num_medicines; i++) {
            printf("%d. %s - Rs. %.2f\n", i+1, medicines[i].name, medicines[i].price);
        }
        int choice;
        while (scanf("%d", &choice) == 1 && choice != 0) {
            if (choice < 1 || choice > num_medicines) {
                printf("Invalid choice. Try again.\n");
            } else {
                choices[num_choices++] = choice - 1;
            }
        }
        if (num_choices == 0) {
            printf("No medicines selected.\n");
        } else {
            struct medicine selected_medicines[num_choices];
            for (int i = 0; i < num_choices; i++) {
                selected_medicines[i] = medicines[choices[i]];
            }
            float total = 0;
            printf("\n\n");
            printf("====================================================\n");
            printf("|                       BILL                       |\n");
            printf("====================================================\n");
            printf("|%-25s|%-15s|%-15s|\n", "Medicine Name", "Price", "Expiry Date");
            printf("====================================================\n");
            for (int i = 0; i < num_choices; i++) {
                printf("|%-25s|%-15.2f|%-15s|\n", selected_medicines[i].name, selected_medicines[i].price, selected_medicines[i].date);
                total += selected_medicines[i].price;
            }
            float gst = 0.18 * total; // calculate GST at 18%
            float bill = total + gst; // add GST to the total
            printf("====================================================\n");
            printf("|%-40s|%-15.2f|\n", "Total (excluding GST)", total);
            printf("|%-40s|%-15.2f|\n", "GST (18%)", gst);
            printf("|%-40s|%-15.2f|\n", "Total (including GST)", bill);
            printf("====================================================\n");
        }
    }
    break;


            case 4:
            response = 'Y';
            break;
            default:
            printf("Invalid option.\n");
            break;
        }
    }
    return 0;
}
