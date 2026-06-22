#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== STRUCTS ======
typedef struct
{
    char username[30];
    char password[30];
    char role[20]; // admin, doctor, patient
    char securityQ[100];
    char securityAns[100];
} Account;

// ====== FUNCTION DECLARATIONS ======
int login(char *role, int *patientID);
int forgotPassword();
void adminMenu();
void doctorMenu(const char *username);
void patientMenu(int patientID);

// ====== LOGIN SYSTEM ======
int login(char *role, int *patientID)
{
    FILE *fp = fopen("accounts.txt", "r");
    if (!fp)
    {
        printf("\n[ERROR] Could not open accounts.txt\n");
        return 0;
    }

    char inputUser[30], inputPass[30];
    Account acc;

    printf("\nUsername: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);

    while (fscanf(fp, "%s %s %s %[^|]|%[\n]", acc.username, acc.password, acc.role, acc.securityQ, acc.securityAns) != EOF)
    {
        if (strcmp(acc.username, inputUser) == 0 && strcmp(acc.password, inputPass) == 0)
        {
            strcpy(role, acc.role);
            if (strncmp(role, "patient", 7) == 0)
            {
                *patientID = atoi(acc.username + 7); // Extract ID
            }
            fclose(fp);
            printf("\n[LOGIN SUCCESSFUL] Logged in as %s\n", acc.role);
            return 1;
        }
    }

    fclose(fp);
    printf("\n[LOGIN FAILED] Invalid credentials\n");
    return 0;
}

int forgotPassword()
{
    FILE *fp = fopen("accounts.txt", "r+");
    if (!fp)
    {
        printf("\n[ERROR] Could not open accounts.txt\n");
        return 0;
    }

    char username[30];
    printf("\nEnter your username: ");
    scanf("%s", username);

    Account acc;
    long pos;
    while ((pos = ftell(fp)) >= 0 && fscanf(fp, "%s %s %s %[^|]|%[\n]", acc.username, acc.password, acc.role, acc.securityQ, acc.securityAns) != EOF)
    {
        if (strcmp(acc.username, username) == 0)
        {
            char ans[100];
            printf("Security Question: %s\nAnswer: ", acc.securityQ);
            scanf(" %[^\n]", ans);
            if (strcmp(ans, acc.securityAns) == 0)
            {
                printf("Enter new password: ");
                scanf("%s", acc.password);
                fseek(fp, pos, SEEK_SET);
                fprintf(fp, "%s %s %s %s|%s\n", acc.username, acc.password, acc.role, acc.securityQ, acc.securityAns);
                fclose(fp);
                printf("[SUCCESS] Password updated!\n");
                return 1;
            }
            else
            {
                printf("[ERROR] Incorrect answer.\n");
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);
    printf("[ERROR] Username not found.\n");
    return 0;
}

// ====== MENUS (Placeholder) ======
void adminMenu()
{
    printf("\n[Admin Menu Placeholder]\n");
}

void doctorMenu(const char *username)
{
    printf("\n[Doctor Menu Placeholder for %s]\n", username);
}

void patientMenu(int patientID)
{
    printf("\n[Patient Menu Placeholder for ID: %d]\n", patientID);
}

// ====== MAIN ======
int main()
{
    char choice;
    char role[20];
    int patientID = 0;

    printf("Welcome to Hospital Management System\n");
    printf("1. Login\n2. Forgot Password\nEnter choice: ");
    scanf(" %c", &choice);

    if (choice == '1')
    {
        if (!login(role, &patientID))
            return 0;
    }
    else if (choice == '2')
    {
        forgotPassword();
        return 0;
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }

    if (strcmp(role, "admin") == 0)
        adminMenu();
    else if (strcmp(role, "doctor") == 0)
        doctorMenu("doctor");
    else if (strncmp(role, "patient", 7) == 0)
        patientMenu(patientID);
    else
        printf("\n[ERROR] Unknown role\n");

    return 0;
}
