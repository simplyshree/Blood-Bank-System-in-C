#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct donor
{
    char phone[50];
    char name[50];
    char password[50];
    char bloodgroup[50];
   
    int donation_count;
};


int main(){


struct donor usr,usr1;
int opt,choice;
FILE *fp;
char filename[50],phone[50],pword[50];
char cont ='y';


int donation;


printf("  Welcome to our Blood Donation Management System!!!\n");


printf("\nWhat do you want to do?\n");
printf("\n1. Register as Donor\n");
printf("\n2. Access My Donor Profile");


printf("\n\nYour Choice: ");
scanf("%d",&opt);


if(opt ==1){
   
    printf("Enter your Name: \t");
    scanf("%s",usr.name);


    printf("\nEnter your phone number: \t");
    scanf("%s",usr.phone);


    printf("\nEnter your new password: \t");
    scanf("%s",usr.password);


    printf("\nEnter your Blood Group: \t");
    scanf("%s",usr.bloodgroup);


    usr.donation_count =0;
    strcpy(filename,usr.phone);
    strcat(filename, ".dat");


    fp =fopen(filename,"w");
    fwrite(&usr,sizeof(struct donor),1,fp);


    if(fwrite != 0){
        printf("\n\n Donor Profile Successfully registered");


    }
    else{


        printf("\n\nSomething went wrong try again");
    }


fclose(fp);


}


if(opt ==2){




    printf("\nLogin to your Donor Profile\n");
    printf("\nPhone NUmber: \t");
    scanf("%s",phone);
    printf("\nPassword: \t");
    scanf("%s",pword);
   
    strcpy(filename,phone);
    strcat(filename,".dat");
   
    fp = fopen(filename,"r");


    if(fp == NULL){
        printf("\n Donor Profile Not Found.\nThank you for supporting the cause.");
        return 1;
    }


    else{


        fread(&usr,sizeof(struct donor),1,fp);


        fclose(fp);


        if(!strcmp(pword,usr.password)){
            while(cont == 'y'){
                printf("\nPress 1 to View Total Donations\n");
                printf("\nPress 2 to Record a New Donation\n");
                printf("\nPress 3 to View Donor Information\n");
                printf("\nPress 4 to delete Donor Profile\n");
                printf("\nPress 5 for password change\n");
                printf("\nPress 6 to exit the program");
                printf("\nYour Choice:");
                scanf(" %d",&choice);


                switch(choice){


                case 1:
                    printf("\n You have donated %d time(s).\n", usr.donation_count);
                   
                    break;
                case 2:
                printf("\nEnter the number of units donated: ");
                scanf("%d", &donation);
                usr.donation_count += donation;
       
                    fp =fopen(filename,"w");
                    fwrite(&usr,sizeof(struct donor),1,fp);
       
                    if(fwrite != NULL)
                        printf("\nSuccessfully  Deposited");
                   
                    fclose(fp);
                    break;


                case 3:
                printf("\nDonor Info:\n");
                printf("\nName: %s", usr.name);
                printf("\nPhone: %s", usr.phone);
                printf("\nBlood Group: %s", usr.bloodgroup);
                printf("\nTotal Donations: %d\n", usr.donation_count);
                break;


                case 4:
            remove(filename);
            printf("\n Donor Profile Deleted Successfully.");
            return 0;


                   




                case 5:
                printf("\nPlease enter your new password: ");
                scanf("%s",pword);
                fp =fopen(filename,"w");
                strcpy(usr.password,pword);
                fwrite(&usr,sizeof(struct donor),1,fp);
                if(fwrite != NULL){
                printf("\nPassword Successfully Chnaged");
                printf("\n");


                    }
                    fclose(fp);
                    break;




                case 6:
                printf("Thank you for saving Lives");
                return 0;




                }


                printf("\nDo you want to continue[y/n]");
                scanf("%s",&cont);


            }




        }
        else{
            printf("\nInvalid Password");        }
    }




    }




   
return 0;
}
