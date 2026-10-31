#include <stdio.h>
#include <ctype.h> // Required for toupper() so 'a' and 'A' both work
#include "quiz.h"

int main() {
    // 1. Create the question array
    Question my_questions[MAX_QUESTIONS];

    // 2. Load questions from your text file
    int loaded_count = load_questions_from_file("QUIZqusetions_and_answers.txt", my_questions, MAX_QUESTIONS);

    if (loaded_count <= 0) {
        printf("Error: Could not load any questions from the file!\n");
        return 1;
    }

    int score = 0;

    printf("=== WELCOME TO THE C QUIZ! ===\n\n");

    // 3. Loop through every loaded question
    for (int i = 0; i < loaded_count; i++) {
        // Print the question text
        printf("Question %d: %s\n", i + 1, my_questions[i].question_text);

        // Print the 4 options formatted as A, B, C, D using ASCII math
        for (int j = 0; j < 4; j++) {
            printf("  %c) %s\n", 'A' + j, my_questions[i].options[j]); // the letter A has a value in ASCII like all symbols, so adding 1, 2, 3 make it B, C D
        }

        // 4. Wait for the user's answer
        printf("Your answer (A, B, C, D): ");
        char choice;
        scanf(" %c", &choice); // Note the space before %c to clear any leftover whitespace/newlines

        // Convert lowercase input (a, b, c, d) to uppercase (A, B, C, D)
        choice = toupper(choice);

        // Convert the letter back to an index (0 to 3)
        int user_index = choice - 'A';

        // 5. Check if the answer matches the correct option index
        if (user_index == my_questions[i].correct_option) {
            printf(" Correct!\n\n");
            score++;
        } else {
            printf(" Incorrect. The correct answer was %c.\n\n", 'A' + my_questions[i].correct_option);
        }
    }

    // 6. Show final results
    printf("=== QUIZ FINISHED ===\n");
    printf("Your Score: %d out of %d\n", score, loaded_count);

    return 0;
}