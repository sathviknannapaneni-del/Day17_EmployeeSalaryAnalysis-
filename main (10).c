#include <stdio.h>

int main() {
    char name[50], regNo[20], section[10];
    int n, choice;
    float salary[10], total = 0, avg, temp;
    int i, j;
    
    printf("========= Employee Salary Analysis System =========\n");

    
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter Registration Number: ");
    fgets(regNo, sizeof(regNo), stdin);
    printf("Enter Section: ");
    fgets(section, sizeof(section), stdin);

   
    for (i = 0; name[i] != '\0'; i++) if (name[i] == '\n') name[i] = '\0';
    for (i = 0; regNo[i] != '\0'; i++) if (regNo[i] == '\n') regNo[i] = '\0';
    for (i = 0; section[i] != '\0'; i++) if (section[i] == '\n') section[i] = '\0';

    
    printf("Enter number of employees (<=10): ");
    scanf("%d", &n);

    if (n > 10 || n <= 0) {
        printf("Invalid number of employees. Exiting...\n");
        return 0;
    }
 
    printf("Enter salaries:\n");
    for (i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%f", &salary[i]);
        total += salary[i];
    }

    avg = total / n; 

    do {
        printf("\n========= Menu =========\n");
        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Employees Above and Below Average\n");
        printf("5. Display Sorted Salaries (Ascending)\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        if (choice == 1) {
            printf("All Salaries:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f\n", salary[i]);
            }
        } 
        else if (choice == 2) {
            printf("Total Salary = %.2f\n", total);
            printf("Average Salary = %.2f\n", avg);
        } 
        else if (choice == 3) {
            float highest = salary[0], lowest = salary[0];
            for (i = 1; i < n; i++) {
                if (salary[i] > highest) highest = salary[i];
                if (salary[i] < lowest) lowest = salary[i];
            }
            printf("Highest Salary = %.2f\n", highest);
            printf("Lowest Salary = %.2f\n", lowest);
        } 
        else if (choice == 4) {
            int above = 0, below = 0;
            for (i = 0; i < n; i++) {
                if (salary[i] > avg)
                    above++;
                else if (salary[i] < avg)
                    below++;
            }
            printf("Average Salary = %.2f\n", avg);
            printf("Employees Above Average = %d\n", above);
            printf("Employees Below Average = %d\n", below);
        } 
        else if (choice == 5) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (salary[j] > salary[j + 1]) {
                        temp = salary[j];
                        salary[j] = salary[j + 1];
                        salary[j + 1] = temp;
                    }
                }
            }
            printf("Salaries in Ascending Order:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f\n", salary[i]);
            }
        } 
        else if (choice == 6) {
            printf("Exiting program...\n");
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }

        if (choice >= 1 && choice <= 5) {
            printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, regNo, section);
            printf("Challenge Day 17 – Code2Grow Program\n");
        }

    } while (choice != 6);

    return 0;
}
