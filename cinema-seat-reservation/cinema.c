#include<stdio.h>

int availableSeats(int seats[], int count) {
    int total = 0;

    for(int i = 0; i < count; i++) {
        if(!seats[i]) total++;
    }

    return total;
}

void displaySeats(int seats[], int count) {
    for(int i = 0; i < count; i++) {
        printf("Seat %d: ", i+1);
        if(seats[i]) printf("reserved\n");
        else printf("available\n");
    }

    printf("There are %d seats available.\n", availableSeats(seats, count));

}

void checkValidSeat(int seats[], int count, int input) {
    if(input < 1 || input > count) {
        printf("Invalid seat position\n");
    }

    if(seats[input-1] == 1) {
        printf("Seat already taken.\n");
    }

    if(seats[input-1] == 0) {
        printf("Seat is available. You have successfully reserved this seat.\n");
        seats[input-1] = 1;
    }
}

int main() {
    int seats[12] = {
        0, 1, 0, 0, 1, 1,
        0, 0, 1, 0, 0, 0
    };

    int count = sizeof(seats) / sizeof(seats[0]);

    displaySeats(seats, count);

    printf("Which seat do you want to reserve? (1-12): ");
    int input; scanf("%d", &input);
    checkValidSeat(seats, count, input);
    displaySeats(seats, count);

    return 0;
}