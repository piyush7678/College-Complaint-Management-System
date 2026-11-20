#include <stdio.h>
#include <string.h>

// Structure to store one complaint record
struct complaint{
    int id, sid;                                   // Complaint ID and Student ID
    char name[50], cat[30], des[200], status[20];  // Name, category, description, status
};

struct complaint c[100];   // Array to store up to 100 complaints
int n = 0;                 // Number of complaints currently stored

// Load saved complaints from the file when the program starts
void load(){
    FILE *f;
    f = fopen("complaints.dat", "rb");
    if (f != NULL){
        n = fread(c, sizeof(struct complaint), 100, f);
        fclose(f);
    }
}

// Save all complaints to the file
void save(){
    FILE *f;
    f = fopen("complaints.dat", "wb");
    if (f != NULL){
        fwrite(c, sizeof(struct complaint), n, f);
        fclose(f);
    }
}

// Register a new complaint
void reg(){
    int a, i;

    // Stop if the array is full
    if (n >= 100){
        printf("\nStorage is full!\n");
        return;
    }

    printf("\nEnter Complaint ID: ");
    scanf("%d", &a);

    // Check that the Complaint ID is not already used
    for (i = 0; i < n; i++){
        if (c[i].id == a){
            printf("\nComplaint ID already exists!\n");
            return;
        }
    }

    // Take the remaining details from the user
    c[n].id = a;
    printf("Enter Student ID: ");
    scanf("%d", &c[n].sid);
    printf("Enter Student Name: ");
    scanf(" %49[^\n]", c[n].name);
    printf("Enter Complaint Category: ");
    scanf(" %29[^\n]", c[n].cat);
    printf("Enter Complaint Description: ");
    scanf(" %199[^\n]", c[n].des);

    // New complaints always start as Pending
    strcpy(c[n].status, "Pending");
    n++;
    save();
    printf("\nComplaint Registered Successfully!\n");
}

// Display all complaints
void view(){
    int i;

    if (n == 0){
        printf("\nNo complaints found!\n");
        return;
    }

    // Print every complaint one by one
    for (i = 0; i < n; i++){
        printf("\n-------------------------");
        printf("\nComplaint ID: %d", c[i].id);
        printf("\nStudent ID: %d", c[i].sid);
        printf("\nStudent Name: %s", c[i].name);
        printf("\nCategory: %s", c[i].cat);
        printf("\nDescription: %s", c[i].des);
        printf("\nStatus: %s\n", c[i].status);
    }
}

// Search a complaint using its Complaint ID
void search(){
    int a, i, found = 0;

    printf("\nEnter Complaint ID: ");
    scanf("%d", &a);

    for (i = 0; i < n; i++){
        if (c[i].id == a){
            printf("\nComplaint Found!");
            printf("\nStudent Name: %s", c[i].name);
            printf("\nCategory: %s", c[i].cat);
            printf("\nDescription: %s", c[i].des);
            printf("\nStatus: %s\n", c[i].status);
            found = 1;
            break;   // Stop searching once found
        }
    }

    if (found == 0){
        printf("\nComplaint Not Found!\n");
    }
}

// Update the status of a complaint
void update(){
    int a, i, b, found = 0;
    struct complaint *p;   // Pointer to the complaint being updated

    printf("\nEnter Complaint ID: ");
    scanf("%d", &a);

    for (i = 0; i < n; i++){
        if (c[i].id == a){
            p = &c[i];   // Point to the matching complaint

            printf("\n1. Pending");
            printf("\n2. In Progress");
            printf("\n3. Resolved");
            printf("\nEnter New Status: ");
            scanf("%d", &b);

            // Set the new status according to the choice
            switch (b){
                case 1:
                    strcpy(p->status, "Pending");
                    break;
                case 2:
                    strcpy(p->status, "In Progress");
                    break;
                case 3:
                    strcpy(p->status, "Resolved");
                    break;
                default:
                    printf("\nInvalid Choice!\n");
                    return;
            }

            save();
            printf("\nStatus Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0){
        printf("\nComplaint Not Found!\n");
    }
}

// Show the total number of complaints and the count for each status
void summary(){
    int a = 0, b = 0, d = 0, i;   // a = Pending, b = In Progress, d = Resolved

    // Count complaints by status
    for (i = 0; i < n; i++){
        if (strcmp(c[i].status, "Pending") == 0)
            a++;
        else if (strcmp(c[i].status, "In Progress") == 0)
            b++;
        else if (strcmp(c[i].status, "Resolved") == 0)
            d++;
    }

    printf("\n------ COMPLAINT SUMMARY ------");
    printf("\nTotal Complaints: %d", n);
    printf("\nPending: %d", a);
    printf("\nIn Progress: %d", b);
    printf("\nResolved: %d\n", d);
}

int main(){
    int a;   // Menu choice

    load();  // Load old complaints from the file

    // Keep showing the menu until the user chooses Exit
    do{
        printf("\n\n===== COLLEGE COMPLAINT MANAGEMENT SYSTEM =====");
        printf("\n1. Register Complaint");
        printf("\n2. View Complaints");
        printf("\n3. Search Complaint");
        printf("\n4. Update Complaint Status");
        printf("\n5. Complaint Summary");
        printf("\n6. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &a);

        // Call the function for the chosen option
        switch (a){
            case 1:
                reg();
                break;
            case 2:
                view();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                summary();
                break;
            case 6:
                save();   // Save before exiting
                printf("\nThank You!\n");
                break;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    } while (a != 6);

    return 0;
}