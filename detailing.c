#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BASE_YEAR 2023
#define SLOT_OFFSET 1
#define MAX_SLOTS 365
#define DATE_LENGTH 20
#define MAX_DATES 365

struct Appointment {
    char date[DATE_LENGTH];
    char clientName[30];
};
struct Appointment detailingSchedule[MAX_SLOTS];
// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return days[month];}
void assignDatesToSlots() {
  int slot = SLOT_OFFSET;

    for (int month = 1; month <= 12; month++) {
        for (int day = 1; day <= daysInMonth(month, 2023); day++) {
            snprintf(detailingSchedule[slot - 1].date, sizeof(detailingSchedule[slot - 1].date), "%02d/%02d/2023", day, month);
            slot++;
        }
    }
}
// Function to display available slots
void displayAvailableSlots() {
    printf("\nAvailable Slots:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (strlen(detailingSchedule[i].date) > 0 && strlen(detailingSchedule[i].clientName) == 0) {
            printf("Slot %d: %s\n", i + SLOT_OFFSET, detailingSchedule[i].date);
        }
    }printf("\n\nBOOK US ON AVAILABLE DATES\n\n");
}kmslmgfdkmvvml <__has_builtin
struct bokAppointment {
    char date[DATE_LENGTH];
    char clientName[30];
};

struct Appointment detailingSchedule[MAX_DATES];

   // Function to check if a date is valid
bool isValidDate(char *date) {
    int day, month, year;

    if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3) {
        if (year == 2023) {
            return false;
        }

        if (month < 1 || month > 12) {
            return false;
        }


        if (day < 1 || day > daysInMonth(month, year)) {
            return false;
        }

        return true; // All checks passed, valid date
        }
        return false;

}


// book appointment by date
void bookAppointment() {
    char date[DATE_LENGTH];
    char clientName[30];

    printf("Enter the date you'd like to book (dd/mm/yyyy): ");
    scanf("%s", date);

    // Validate the date
    if (isValidDate(date)) {
        printf("\n\tInvalid date! Remember to use format dd/mm/yyyy.\n");
        return;
    }

    // Check if the date is within the valid range
    int dateIndex = -1;
    for (int i = 0; i < MAX_DATES; i++) {
        if (strcmp(detailingSchedule[i].date, date) == 0) {
            dateIndex = i;
            break;
        }
    }

     if (dateIndex == -1) {
        printf("\n\tInvalid date or date not available :(\n\t\t Please try again!\n\n");
        return;
    }

    // Check if the date is already booked
    if (strlen(detailingSchedule[dateIndex].clientName) > 0) {
        printf("\n\nThe date is already booked. Please choose another date.\n\t\tThank you!");
        return;
    }

    printf("Enter the client's name: ");
    scanf("%s", clientName);

    strcpy(detailingSchedule[dateIndex].clientName, clientName);

    printf("\n\tslot booked successfully!\n see you on %s, %s  :)\n", date,clientName);
}


// display appointments
void displayAppointments() {
    printf("\n\t\tBOOKED SLOTS:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (strlen(detailingSchedule[i].date) > 0 && strlen(detailingSchedule[i].clientName) > 0) {
            printf("Slot %d (%s): %s\n", i + SLOT_OFFSET, detailingSchedule[i].date, detailingSchedule[i].clientName);
        }
    }
}

// cancel an appointment
void cancelAppointment() {
    int slot;

    printf("Enter the slot number to cancel the appointment: ");
    scanf("%d", &slot);

    if (slot < SLOT_OFFSET || slot > MAX_SLOTS + SLOT_OFFSET - 1 || strlen(detailingSchedule[slot - SLOT_OFFSET].date) == 0) {
        printf("Invalid slot number. Please try again.\n");
        return;
    }

    if (strlen(detailingSchedule[slot - SLOT_OFFSET].clientName) == 0) {
        printf("No appointment booked for slot %d.\n", slot);
        return;
    }

    printf("Appointment canceled for slot %d.\n", slot);
    detailingSchedule[slot - SLOT_OFFSET].clientName[0] = '\0';
}

// search for appointments by date
void searchByDate() {
    char searchDate[11];
    bool found = false;

    printf("Enter the date to search for appointments (dd/mm/yyyy): ");
    scanf("%s", searchDate);

    printf("\nAppointments on %s:\n", searchDate);
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (strlen(detailingSchedule[i].date) > 0 && strcmp(detailingSchedule[i].date, searchDate) == 0) {
            printf("Slot %d: %s\n", i + SLOT_OFFSET, detailingSchedule[i].clientName);
            found = true;
        }
    }

    if (!found) {
        printf("No appointments found for the specified date.\n");
    }
}

int main() {
    assignDatesToSlots();

    int choice;
    do {
        printf("\nAUTO DETAIL BOOKING SYSTEM\n");
        printf("1. Display Available Slots\n");
        printf("2. Book an Appointment\n");
        printf("3. Display Appointments\n");
        printf("4. Cancel an Appointment\n");
        printf("5. Search Appointments by Date\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSlots();
                break;
            case 2:
                bookAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                cancelAppointment();
                break;
            case 5:
                searchByDate();
                break;
            case 6:
                printf("\n\t\tExiting the program. Thank you and Goodbye! :) \n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
