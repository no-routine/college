#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 100
#define MAX_STORED_PASSWORDS 5
#define MAX_APPS 5
#define HASH_SIZE 64

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char hashed_password[HASH_SIZE];
    struct {
        char app[MAX_APPS][MAX_PASSWORD_LENGTH];
        char password[MAX_APPS][MAX_PASSWORD_LENGTH];
        int count;
    } stored_passwords;
};

struct User users[MAX_USERS];
int user_count = 0;

unsigned long djb2_hash(const char *str) {
    unsigned long hash = 5381;

    while (*str != '\0') {
        hash = ((hash << 5) + hash) + (*str);
        str++;
    }

    return hash;
}

void saveUserToFile(struct User *user) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %s\n", user->username, user->hashed_password);

    fclose(file);
}

void loadUserFromFile(struct User *user) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", user->username, user->hashed_password) == 2) {
        // Assuming each user has a unique username
        if (strcmp(user->username, users[user_count].username) == 0) {
            break;
        }
    }

    fclose(file);
}

void addPassword(struct User *user) {
if (user->stored_passwords.count < MAX_APPS) {
        printf("Enter the app or website name: ");
        scanf("%s", user->stored_passwords.app[user->stored_passwords.count]);

        // Clear the input buffer
        while (getchar() != '\n');

        printf("Enter the password: ");
        scanf("%s", user->stored_passwords.password[user->stored_passwords.count]);

        // Clear the input buffer
        while (getchar() != '\n');

        user->stored_passwords.count++;
        printf("Password added successfully!\n");
    } else {
        printf("Maximum number of stored passwords reached.\n");
    }
}

void deletePassword(struct User *user) {
    if (user->stored_passwords.count > 0) {
        printf("Enter the app or website name to delete: ");
        char app[MAX_PASSWORD_LENGTH];
        scanf("%s", app);

        int index = -1;
        for (int i = 0; i < user->stored_passwords.count; i++) {
            if (strcmp(app, user->stored_passwords.app[i]) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            // Move the last element to the deleted position to maintain order
            user->stored_passwords.count--;
            strcpy(user->stored_passwords.app[index], user->stored_passwords.app[user->stored_passwords.count]);
            strcpy(user->stored_passwords.password[index], user->stored_passwords.password[user->stored_passwords.count]);
            printf("Password deleted successfully!\n");
        } else {
            printf("App or website not found.\n");
        }
    } else {
        printf("No stored passwords to delete.\n");
    }
}

void displayPasswords(struct User *user) {
    printf("Stored passwords:\n");
    for (int i = 0; i < user->stored_passwords.count; i++) {
        printf("- App/Website: %s, Password: %s\n",
               user->stored_passwords.app[i],
               user->stored_passwords.password[i]);
    }
}

void authenticatedMenu(struct User *user) {
    int authChoice;

    do {
        printf("\nPassword Manager Menu (Authenticated):\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Display Passwords\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &authChoice);

        switch (authChoice) {
            case 1:
                addPassword(user);
                break;
            case 2:
                deletePassword(user);
                break;
            case 3:
                displayPasswords(user);
                break;
            case 4:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (authChoice != 4);
}

void authenticateUser() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    unsigned long hash = djb2_hash(password);
    snprintf(password, HASH_SIZE, "%lu", hash);

    // Load user information from file
    loadUserFromFile(&users[user_count]);

    if (strcmp(username, users[user_count].username) == 0 && strcmp(password, users[user_count].hashed_password) == 0) {
        printf("Authentication successful!\n");

        // Additional feature: Allow user to store multiple passwords
        authenticatedMenu(&users[user_count]);
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }
}

void registerUser() {
    if (user_count < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", users[user_count].username);

        printf("Enter password: ");
        scanf("%s", users[user_count].hashed_password);

        // Hash the password before storing it
        unsigned long hash = djb2_hash(users[user_count].hashed_password);
        snprintf(users[user_count].hashed_password, HASH_SIZE, "%lu", hash);

        // Save user information to file
        saveUserToFile(&users[user_count]);

        printf("User registered successfully!\n");
        user_count++;
    } else {
        printf("Maximum number of users reached.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager Menu:\n");
        printf("1. Register User\n");
        printf("2. Authenticate User\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
