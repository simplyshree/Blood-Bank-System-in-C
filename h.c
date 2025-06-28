#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct donor {
    char phone[50];
    char name[50];
    char password[50];
    char bloodgroup[50];
    int donation_count;
};

void print_certificate(struct donor usr) {
    printf("\n-------------------------------\n");
    printf("   BLOOD DONATION CERTIFICATE   \n");
    printf("-------------------------------\n");
    printf("Name          : %s\n", usr.name);
    printf("Phone         : %s\n", usr.phone);
    printf("Blood Group   : %s\n", usr.bloodgroup);
    printf("Donations Made: %d\n", usr.donation_count);
    printf("-------------------------------\n");
    printf(" Thank you for saving lives!   \n");
    printf("-------------------------------\n");
}

void quiz() {
    int score = 0, ans;
    printf("\n--- Blood Donation Quiz ---\n");

    printf("\nQ1: How often can you donate whole blood?\n");
    printf("1. Every 30 days\n2. Every 56 days\n3. Every 90 days\n4. Once a year\n");
    printf("Your Answer: ");
    scanf("%d", &ans);
    if(ans == 2) score++;

    printf("\nQ2: Which component of blood carries oxygen?\n");
    printf("1. White cells\n2. Plasma\n3. Red cells\n4. Platelets\n");
    printf("Your Answer: ");
    scanf("%d", &ans);
    if(ans == 3) score++;

    printf("\nQ3: What benefit does blood donation provide to donors?\n");
    printf("1. Helps burn calories\n2. Helps reduce iron overload\n3. Free health checkup\n4. All of the above\n");
    printf("Your Answer: ");
    scanf("%d", &ans);
    if(ans == 4) score++;

    printf("\nQ4: Who cannot donate blood?\n");
    printf("1. People over 18\n2. Those with cold/flu\n3. Vegetarians\n4. Healthy athletes\n");
    printf("Your Answer: ");
    scanf("%d", &ans);
    if(ans == 2) score++;

    printf("\nQ5: How long does a blood donation take?\n");
    printf("1. 5 minutes\n2. 10 hours\n3. 8-10 minutes\n4. 1 hour\n");
    printf("Your Answer: ");
    scanf("%d", &ans);
    if(ans == 3) score++;

    printf("\nYou scored %d out of 5!\n", score);
    if(score == 5)
        printf("🏆 Excellent! You're a Blood Donation Champ!\n");
    else if(score >= 3)
        printf("🎉 Good job! You're pretty knowledgeable.\n");
    else
        printf("🧠 Keep learning—thank you for playing!\n");
}


void export_report(struct donor usr) {
    FILE *rep;
    char reportfile[100];
    strcpy(reportfile, usr.phone);
    strcat(reportfile, "_report.txt");

    rep = fopen(reportfile, "w");
    fprintf(rep, "Donor Report\n\n");
    fprintf(rep, "Name          : %s\n", usr.name);
    fprintf(rep, "Phone         : %s\n", usr.phone);
    fprintf(rep, "Blood Group   : %s\n", usr.bloodgroup);
    fprintf(rep, "Total Donations: %d\n", usr.donation_count);
    fclose(rep);

    printf("\nReport exported to %s\n", reportfile);
}

void doctor_consultation() {
    int docopt;
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        printf("\n--- Doctor Consultation Menu ---\n");
        printf("1. Iron Deficiency\n");
        printf("2. Vitamin B12 Deficiency\n");
        printf("3. Vitamin D Deficiency\n");
        printf("4. Calcium Deficiency\n");
        printf("5. General Mineral Deficiency\n");
        printf("6. Exit Consultation\n");
        printf("Enter your choice: ");
        scanf("%d", &docopt);

        switch (docopt) {
            case 1:
                printf("\nSymptoms: Fatigue, pale skin, dizziness.\n");
                printf("Advice: Eat spinach, lentils, red meat.\n");
                break;
            case 2:
                printf("\nSymptoms: Numbness, weakness, memory problems.\n");
                printf("Advice: Eggs, dairy, meat; take B12 supplements.\n");
                break;
            case 3:
                printf("\nSymptoms: Bone pain, mood swings, fatigue.\n");
                printf("Advice: Sunlight, fatty fish, fortified dairy.\n");
                break;
            case 4:
                printf("\nSymptoms: Weak nails, cramps, brittle bones.\n");
                printf("Advice: Dairy, leafy greens, calcium tablets.\n");
                break;
            case 5:
                printf("\nAdvice: Stay hydrated. Eat a balanced diet of grains, nuts, and fruits.\n");
                break;
            case 6:
                printf("Exiting doctor consultation...\n");
                cont = 'n';
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

        if (docopt != 6) {
            printf("\nDo you want to consult again? (y/n): ");
            scanf(" %c", &cont);
        }
    }
}

int main() {
    struct donor usr, usr1;
    int opt, choice;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    char cont = 'y';
    int donation;
    char playQuiz;


    printf("==============================================\n");
    printf(" Welcome to our Blood Donation Management System!\n");
    printf("==============================================\n");

    printf("\nWhat do you want to do?\n");
    printf("1. Register as Donor\n");
    printf("2. Access My Donor Profile\n");
    printf("\nYour Choice: ");
    scanf("%d", &opt);

    if (opt == 1) {
        printf("\nEnter your Name: ");
        scanf("%s", usr.name);
        printf("Enter your Phone Number: ");
        scanf("%s", usr.phone);
        printf("Enter your new Password: ");
        scanf("%s", usr.password);
        printf("Enter your Blood Group: ");
        scanf("%s", usr.bloodgroup);

        usr.donation_count = 0;
        strcpy(filename, usr.phone);
        strcat(filename, ".dat");

        fp = fopen(filename, "w");
        fwrite(&usr, sizeof(struct donor), 1, fp);

        if (fwrite != 0)
            printf("\nDonor Profile Registered Successfully.\n");
        else
            printf("\nError in Registration.\n");

        fclose(fp);
    }

    if (opt == 2) {
        printf("\nLogin to your Donor Profile\n");
        printf("Phone Number: ");
        scanf("%s", phone);
        printf("Password: ");
        scanf("%s", pword);

        strcpy(filename, phone);
        strcat(filename, ".dat");
        fp = fopen(filename, "r");

        if (fp == NULL) {
            printf("\nDonor Profile Not Found.\n");
            return 1;
        }

        fread(&usr, sizeof(struct donor), 1, fp);
        fclose(fp);

        if (!strcmp(pword, usr.password)) {
            while (cont == 'y' || cont == 'Y') {
                printf("\n------ Donor Dashboard ------\n");
                printf("1. View Total Donations\n");
                printf("2. Record New Donation\n");
                printf("3. View Donor Information\n");
                printf("4. Delete Donor Profile\n");
                printf("5. Change Password\n");
                printf("6. Update Donor Info\n");
                printf("7. Export Report to File\n");
                printf("8. Doctor Consultation\n");
                printf("9. Print Donation Certificate\n");
                printf("10. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("\nTotal Donations: %d\n", usr.donation_count);
                        break;

                    case 2:
                        printf("\nEnter number of units donated: ");
                        scanf("%d", &donation);
                        usr.donation_count += donation;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct donor), 1, fp);
                        fclose(fp);
                        printf("Donation Recorded Successfully.\n");
                        break;

                    case 3:
                        printf("\n--- Donor Information ---\n");
                        printf("Name         : %s\n", usr.name);
                        printf("Phone        : %s\n", usr.phone);
                        printf("Blood Group  : %s\n", usr.bloodgroup);
                        printf("Donations    : %d\n", usr.donation_count);
                        break;

                    case 4:
                        remove(filename);
                        printf("Donor Profile Deleted Successfully.\n");
                        return 0;

                    case 5:
                        printf("\nEnter New Password: ");
                        scanf("%s", pword);
                        strcpy(usr.password, pword);
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct donor), 1, fp);
                        fclose(fp);
                        printf("Password Changed Successfully.\n");
                        break;

                    case 6:
                        printf("\nUpdate Info\n");
                        printf("Enter New Name: ");
                        scanf("%s", usr.name);
                        printf("Enter New Blood Group: ");
                        scanf("%s", usr.bloodgroup);
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct donor), 1, fp);
                        fclose(fp);
                        printf("Donor Info Updated.\n");
                        break;

                    case 7:
                        export_report(usr);
                        break;

                    case 8:
                        doctor_consultation();
                        break;

                    case 9:
                        print_certificate(usr);
                        break;

                    case 10:
                        printf("\nThank you for supporting the cause!\n");
                        return 0;

                    default:
                        printf("Invalid option. Try again.\n");
                }

                printf("\nDo you want to continue? (y/n): ");
                scanf(" %c", &cont);
            }
        } else {
            printf("\nInvalid Password.\n");
        }
    }

    printf("\nBefore you go, would you like to play a short quiz about blood donation? (y/n): ");
    scanf(" %c", &playQuiz);

    if(playQuiz == 'y' || playQuiz == 'Y') {
        quiz();
    } else {
        printf("\nNo worries! Stay healthy and thank you again!\n");
    }


    return 0;
}
