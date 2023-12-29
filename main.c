#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 10

typedef enum {
    EMPTY = 1,
    OCCUPIED = 0
} state;

typedef struct {
    int spot;
    char vehicle_no[9];
    state available;
} parking_spot;

parking_spot parking_space[CAPACITY];
int total_parked = 0;
void park();
void get_car();
void leave_parking();
void display_all();
void exit_program();
void print_details(parking_spot* car);

int main() {
    int choice;

    do {
        printf("\nWelcome to the Parking System\n");
        printf("1. Park Car\n");
        printf("2. Leave Parking\n");
        printf("3. Display All Parked Vehicles\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                park();
                break;
            case 2:
                get_car();
                break;
            case 3:
                display_all();
                break;
            case 4:
                exit_program();
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void park() {
    if (total_parked >= CAPACITY) {
        printf("Parking is full. Cannot park more cars!\n");
        return;
    }

    char car_no[9];
    printf("Enter Your Car Number: ");
    scanf("%s", car_no);

    strcpy(parking_space[total_parked].vehicle_no, car_no);
    parking_space[total_parked].available = OCCUPIED;
    parking_space[total_parked].spot = total_parked + 1;

    total_parked++;
    printf("Car Parked! Your Token is %d\n", parking_space[total_parked - 1].spot);
}

void get_car() {
    int token;
    while (1) {
        printf("Please ENTER your Token: ");
        scanf("%d", &token);
        if (token >= 1 && token <= total_parked) {
            break;
        }
        printf("-------Invalid Token Please Try Again-------\n");
    }

    for (int i = 0; i < total_parked; i++) {
        if (parking_space[i].spot == token && parking_space[i].available == OCCUPIED) {
            print_details(&parking_space[i]);
            parking_space[i].available = EMPTY;
            printf("Thank You for Choosing Us! :)\n\n");
            return;
        }
    }

    printf("No Vehicle Here! Sorry\n");
}

void leave_parking() {
    int token;
    while (1) {
        printf("Please ENTER your Token to leave parking: ");
        scanf("%d", &token);
        if (token >= 1 && token <= total_parked) {
            break;
        }
        printf("-------Invalid Token Please Try Again-------\n");
    }

    for (int i = 0; i < total_parked; i++) {
        if (parking_space[i].spot == token && parking_space[i].available == OCCUPIED) {
            parking_space[i].available = EMPTY;
            printf("Car successfully left parking\n");
            return;
        }
    }

    printf("No Vehicle Here! Sorry\n");
}

void display_all() {
    if (total_parked == 0) {
        printf("No vehicles parked.\n");
        return;
    }

    printf("\nList of Parked Vehicles:\n");
    for (int i = 0; i < total_parked; i++) {
        print_details(&parking_space[i]);
    }
}

void exit_program() {
    printf("Exiting...\n");
}

void print_details(parking_spot* car) {
    printf("\nPlate Number: %s", car->vehicle_no);
    printf("\nSpot: %d\n", car->spot);
}
