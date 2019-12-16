void introductionDisplay(void){
    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
    printf("\u2551CMSC11 STUDENT REGISTRATION SYSTEM (SRS)\u2551\n");
    printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}

void adminStudentRecordsMenu(void){
    printf("\n\nSTUDENT RECORDS\n");
    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
    printf("\u25510. Back                                            \u2551\n");
    printf("\u25511. Create a student record through keyboard input. \u2551\n");
    printf("\u25512. Import student record/s from .txt or .csv file. \u2551\n");
    printf("\u25513. Update a student's records.                     \u2551\n");
    printf("\u25514. Delete a student's records.                     \u2551\n");
    printf("\u25515. Enrol a student to a subject.                   \u2551\n");
    printf("\u25516. Drop a student's subject.                       \u2551\n");
    printf("\u25517. Display all student records.                    \u2551\n");
    printf("\u25518. Display specific student's records.             \u2551\n");
    printf("\u25519. Output student records as .csv file             \u2551\n");
    printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}

void adminSubjectsRecordsMenu(void){
    printf("\n\nSUBJECT RECORDS\n");
    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
    printf("\u25510. Back                                            \u2551\n");
    printf("\u25511. Create a subject record through keyboard input. \u2551\n");
    printf("\u25512. Import subject record/s from .txt or .csv file. \u2551\n");
    printf("\u25513. Update a subject's record.                      \u2551\n");
    printf("\u25514. Delete a subject's record.                      \u2551\n");
    printf("\u25515. Display all subject records.                    \u2551\n");
    printf("\u25516. Search subject.                                 \u2551\n");
    printf("\u25517. Output subject records as .csv file.            \u2551\n");
    printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}

void studentMenu(void){
    printf("0. Back\n");
    printf("1. Enrol to a subject.\n");
    printf("2. Drop a subject.\n");
    printf("3. Display student info.\n");
}

void stringCopy(char src[], char dest[]){
    int count;
    for(count = 0; src[count] != '\0'; count++){
        dest[count] = src[count];
    }   
}

int power(int p, int n){
    int result = 1;
    for (n=n; n>0; n--){
        result = result * p;
    }
    return result;
}


double squareRoot(int number){
    float temp, sqrt;
    sqrt = number / 2;
    temp = 0;

    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;
}

