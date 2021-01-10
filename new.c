#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankCustomer {
   char name[100];
   unsigned long long int   ID,
                            accountNo, 
                            currentBalance, 
                            phoneNo;
};

// takes in details of customers from stdin
void Input(FILE *fptr, int n, struct BankCustomer customers[]) {
    for(int i=0; i<n; i++) {
        printf("\nDetails of cutomer %d: \n", i+1);
        printf("Customer Name: ");
        scanf("%s", customers[i].name);

        printf("ID: ");
        scanf("%llu", &customers[i].ID);

        printf("account No: ");
        scanf("%llu", &customers[i].accountNo);

        printf("current Balance: ");
        scanf("%llu", &customers[i].currentBalance);

        printf("phone No: ");
        scanf("%llu", &customers[i].phoneNo);
    }
}

// print details of single customer 
void printDetails(struct BankCustomer customer) {
    printf("Customer ID: %llu\t Customer Name: %s\t account No: %llu\t current Balance: %llu\t phone No: %llu\n", customer.ID, customer.name, 
        customer.accountNo, customer.currentBalance, customer.phoneNo);
}

// writes all the customers data to file
void WriteFile (FILE *fptr, int n, struct BankCustomer customers[]) {
    for(int i=0; i<n; i++) {
        fwrite(&customers[i], sizeof(struct BankCustomer), 1, fptr);
    }
    printf("\nWrite to file done\n\n");
}

// read the file data 
void ReadFile(FILE *fptr, int n) {
    struct BankCustomer customer;

    for(int i=0; i<n; i++) {
        fread(&customer, sizeof(struct BankCustomer), 1, fptr); 
        printDetails(customer);
    }
    printf("\n\nRead from file done\n\n");
}

void searchByID(struct BankCustomer customers[], int n) {
    int id, i;
    printf("Enter ID:  ");
    scanf("%d", &id);
    
    // search
    for(i=0; i<n; i++) {
        if(customers[i].ID == id) {
            printf("\nCustomer Found!\n");
            printDetails(customers[i]);
            break;
        }
    }
    if(i == n) {
        printf("No Customer Found!\n");
    }
}

void searchByName(struct BankCustomer customers[], int n) {
    char name[100];
    int i;
    printf("Enter Name:  ");
    scanf("%s", name);
    
    // search
    for(i=0; i<n; i++) {
        if(strcmp(customers[i].name, name) == 0) {
            printf("\nCustomer Found!\n");
            printDetails(customers[i]);
            break;
        }
    }
    if(i == n) {
        printf("No Customer Found!\n");
    }
    printf("\n");
}

void searchByAccNo(struct BankCustomer customers[], int n) {
    int accNo, i;
    printf("Enter Account No:  ");
    scanf("%d", &accNo);
    
    // search
    for(i=0; i<n; i++) {
        if(customers[i].accountNo == accNo) {
            printf("\nCustomer Found!\n");
            printDetails(customers[i]);
            break;
        }
    }
    if(i == n) {
        printf("No Customer Found!\n");
    }
}


int searchMenu(struct BankCustomer customers[], int n) {
    printf("Choose the search scheme: ");
    printf("\n1. Search by ID");
    printf("\n2. Search by Name");
    printf("\n3. Search by Account Number");
    printf("\n4. Exit\n");
    printf("\nChoice: ");
    
    int response;
    scanf("%d", &response);
    
    if(response == 1) {
        searchByID(customers, n);
    } else if(response == 2) {
        searchByName(customers, n);
    } else if(response == 3) {
        searchByAccNo(customers, n);
    } else {
        printf("Exiting...\n");
        exit(1);
    }
}


int main() {
    FILE *fptr;

    // open for write and read both
    if ((fptr = fopen("bank_customer_details.bin","rwb")) == NULL){
        printf("Oops! Some error in file");
        exit(1);
    }

    int n;
    printf("Enter the number of customers: ");
    scanf("%d", &n);
    
    // array of objects each holding details of a cutomer 
    struct BankCustomer customers[n];

    Input(fptr, n, customers);

    WriteFile(fptr, n, customers);

    ReadFile(fptr, n);

    fclose(fptr); 

    // press ctrl+z to stop or press 4 to exit  
    while(1) {
        searchMenu(customers, n);
    }
    
    return 0;
}