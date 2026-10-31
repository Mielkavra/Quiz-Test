#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h" // Links your header file so C recognizes the Question struct

// Implement the function declared in quiz.h
int load_questions_from_file(const char *filename, Question questions[], int max_questions) { //* or pointers point to addresses to not repeatedly type "QUIZqusetions_and_answers.txt" and not waste memory
    FILE *file = fopen(filename, "r"); //Open the file in read mode ("r") //FILE interacts with files whether to open, close or edit.
    if (file == NULL) {
        return -1;         // Return -1 if the file couldn't be found or opened
    }

    char buffer[MAX_LINE_LENGTH];
    int count = 0;

    //Read the file line by line until the end of the file or max capacity is reached
    while (fgets(buffer, sizeof(buffer), file) != NULL && count < max_questions) {
        //Strip out newline or carriage return characters at the end of the line
        buffer[strcspn(buffer, "\r\n")] = 0;

        // Skip completely blank lines
        if (strlen(buffer) == 0) continue;

        //Parse the line using sscanf (String Scan Formatted) reads direct data instead of relying on keyboard like scanf
        //Format expected: questiontext|option0|option1|option2|option3|correct_index
        int parsed = sscanf(buffer, "%255[^|]|%63[^|]|%63[^|]|%63[^|]|%63[^|]|%d", //0-255 means 256 characters and and ends reading before \0 to prevent errors
                            questions[count].question_text,
                            questions[count].options[0],
                            questions[count].options[1],
                            questions[count].options[2],
                            questions[count].options[3],
                            &questions[count].correct_option);

        if (parsed == 6) { //why 6? it needs the (1)question (2-5)choices (6)correct asnwer from QUIZqusetions_and_answers.txt
            count++;
        }
    }

    fclose(file); // close files always to prevent memory leaks

    return count;
}