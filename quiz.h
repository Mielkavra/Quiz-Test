#ifndef QUIZ_H // if not defined, define the functions for quiz.c to handle
#define QUIZ_H

#define MAX_QUESTIONS 50
#define MAX_LINE_LENGTH 512

typedef struct { // typedef to not repeatedly type struct before Question;
    char question_text[256]; //256 array size, question's content
    char options[4][64]; //2D array, line in Linear Algebra. 4 rows of choices, 64 columns of text as answers
    int correct_option; // (0-3) adresses for 4 choices
} Question; // struct's name, requires one big letter at the start (e.g. Question; question; will count as an error)

int load_questions_from_file(const char *filename, Question questions[], int max_questions); //catches the filenames fed into it

#endif // end of #ifndef