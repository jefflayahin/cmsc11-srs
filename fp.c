#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "srs.h"

const int password = 1;

#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

struct subject{
    int subID;
    char subCode[50];
    char subTitle[100];
}temp = {0, "none", " "},temp2 = {0, "none", " "},temp3 = {0, "none", " "}, temp1 = {0, " ", " "};

struct student{
    int studentID;
    char lastName[20];
    char firstName[20];
    char section[5];
    int exam1;
    int exam2;
    int exam3;
    struct subject *sub1;
    struct subject *sub2;
    struct subject *sub3;
    int hex;
    char grade[3];
}tempo, tempor = {0, " ", " ", " ", 0, 0, 0, &temp1, &temp1, &temp1, 0, " "};

struct stat{
    int low;
    int high;
    float ave;
    float sd;
}studentStats[4];

//Struct for exam statistics
struct stat statsEx1(struct stat st);
struct stat statsEx2(struct stat st);
struct stat statsEx3(struct stat st);
struct stat statsHex(struct stat st);

struct student studentInputKeyboard(struct student inputStudent);
struct student updateStudentRecordsKeyboard(struct student inputStudent);
struct subject updateSubjectKeyboard(struct subject *inputSub);
struct subject addSubjectKeyboard(struct subject *inputSub, char a[]);

struct student scoreGrade(struct student iS);
void cmscEnrol(struct student *s);
void studentNameSearch(char a[15]);
void studentSort(int n);
void displayStudent(int num);
void displaySubject(struct subject *inputSubPtr);
void inputSubjectData(char file[15]);
void inputStudentData(char file[15]);
void studentEnrolSubject(int idNum, char code[20]);
void displayAllStudents(int s);
void writeStudentRecordsToFile(char file[15]);
void writeSubjectRecordsToFile(char file[15]);
void inputStudentMasterData(char file[15]);
void deleteStudent(int n);
void emptyStudentChecker(void);
void deleteSubject(char a[]);
void updateGrades(void);
void drop(int n);
void dequeuSubject(void);
int findSub(char a[10]);
int stringCompare(char s1[], char s2[]);
int checkSubjectFile(char file[15]);
int checkStudentFile(char file[15]);
int checkMasterStudentFile(char file[15]);
char toLower(char ch);

// Variable that keeps track of the tail of the cs11(students) array.
int cS = 0;

// Variable that keeps track of the tail of the subjects array.
int cSub = 1;


struct student cs11[70];
struct subject sub[21];

int main(void){

    int admin = 1;
    int empty = 2;
    int n;

    // Initialize student's subject to empty or none. Refer to line 21 for struct values of temp.
    for(int i = 0; i < 70; i++){
        cs11[i].sub1 = &temp;
        cs11[i].sub2 = &temp;
        cs11[i].sub3 = &temp;
    }

    // Initialize index 0 of struct subject array as CS11.
    sub[0] = (struct subject){11, "CMSC11", "Introduction to Computer Science"};

    introductionDisplay();


    while(admin == 1 || admin == 2){
    int record = 1;
    printf("\n\n\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
    printf("\u2551Would you like to enter as:\u2551\n");
    printf("\u25511. Admin.                  \u2551\n");
    printf("\u25512. Student.                \u2551\n");
    printf("\u2551Any other number to exit.  \u2551\n");
    printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
    printf(">>> ");
    scanf("%d", &admin);
    printf("\n");
    system("clear");
    switch (admin){
    int pass;
    char a[15];
    
    // User enters as admin.
    case 1:
        printf("Enter admin password: ");
        scanf("%d", &pass);
        printf("\n");
        system("clear");
        if(pass == password){
            printf("\nWelcome admin user.\n\n");
        if(cSub == 1){
        if(checkSubjectFile("subject_masterlist.csv") == -1){
            printf("Subject masterlist is empty. No subject records exist.\n");
        }else if(checkSubjectFile("subject_masterlist.csv") == 0){
            printf("Subject masterlist file not found.\n");
        }else if(cSub == 1){
            inputSubjectData("subject_masterlist.csv");
        }
        }

        if(cS == 0){
        if(checkMasterStudentFile("student_masterlist.csv") == -1){
            printf("Student masterlist is empty. No student records exist.\n");
        }else if(checkMasterStudentFile("student_masterlist.csv") == 0){
            printf("Student masterlist not found.\n");
        }else{
            inputStudentMasterData("student_masterlist.csv");
            emptyStudentChecker();
        }
        }
            while(record >= 1 && record <= 2){
            int choice = 1;
            printf("\n\n\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n");
            printf("\u25510. Back                          \u2551\n");
            printf("\u25511. Manage Student Records.       \u2551\n");
            printf("\u25512. Manage Subject Records        \u2551\n");
            printf("\u2551Any other number to exit program.\u2551\n");
            printf("\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
            printf(">>> ");
            scanf("%d", &record);
            printf("\n");
            system("clear");
            
            if (record == 1){
                while(choice >= 0 && choice <= 9){
                    adminStudentRecordsMenu();
                    printf("\n>>> ");
                    scanf("%d", &choice);
                    printf("\n");
                    if(choice == 0){
                        choice = -1;
                        admin = 1;
                    }else if(choice < 0 || choice > 2){
                        admin = 3;
                    }
                    system("clear");
                    switch(choice){
                        case 1:
                            cs11[cS] = studentInputKeyboard(cs11[cS]);
                            cmscEnrol(&cs11[cS]);
                            ++cS;
                            break;
                        char a[15];
                        case 2:
                            printf("Type filename of student's records with file extension .txt/.csv: ");
                            scanf(" %14[^\n]s", a);
                            printf("\n");
                            if(checkStudentFile(a) == -1){
                                printf("File is empty.\n");
                            }else if(checkStudentFile(a) == -0){
                                printf("File not found.\n");
                            }else{
                                inputStudentData(a);
                                emptyStudentChecker();
                            }

                            break;
                        case 3:
                            printf("Enter student ID number to be updated: ");
                            scanf("%d", &n);
                            int i;
                            for(i = 0; cs11[i].studentID != n; i++);
                            n = i;
                            cs11[n] = updateStudentRecordsKeyboard(cs11[n]);
                            break;
                        case 4:
                            printf("Enter student ID number to be deleted: ");
                            scanf("%d", &n);
                            deleteStudent(n);
                            break;
                        case 5:
                            printf("Enter Student ID number: ");
                            scanf("%d", &n);
                            printf("\nAvailable subjects:");
                            printf("\n\nID number\tSubject Code\tSubject Title\n");
                            for (int i = 0; i < cSub; i++){
                                if(stringCompare(sub[i].subCode, "none") != 0){
                                    displaySubject(&sub[i]);
                                }
                            }
                            printf("\nEnter Subject code: ");
                            scanf("%s",a);
                            printf("\n");
                            studentEnrolSubject(n, a);
                            break;
                        case 6:
                            printf("Enter Student ID number: ");
                            scanf("%d", &n);
                            drop(n);

                            break;
                        case 7:
                            if(cS == 0){
                                printf("No student records.\n");
                            }else{
                                updateGrades();
                                displayAllStudents(cS);
                            }
                            
                            break;
                        case 8:
                            printf("Input student's last name: ");
                            scanf("%s", a);
                            printf("\n");
                            studentNameSearch(a);
                            break;
                        case 9:
                            writeStudentRecordsToFile("student_masterlist.csv");
                            writeSubjectRecordsToFile("subject_masterlist.csv");
                        default:
                            break;
                        
                    }
                    if(cS != 0){
                        updateGrades();
                    }
                        
                }
            }else if (record == 2){
                while(choice >= 0 && choice <= 7){
                    adminSubjectsRecordsMenu();
                    printf(">>> ");
                    scanf("%d", &choice);
                    printf("\n");
                    system("clear");
                    if(choice == 0){
                        choice = -1;
                        admin = 1;
                    }else if(choice < 0 && choice > 5){
                        admin = 3;
                    }
                    switch(choice){    
                        case 1:
                            sub[cSub] = updateSubjectKeyboard(&sub[cSub]);
                            ++cSub;
                            break;
                        case 2:
                            printf("Type filename of subject's records with file extension .txt/.csv: ");
                            scanf(" %19[^\n]s", a);
                            printf("\n");
                            if(checkSubjectFile(a) == -1){
                                printf("File is empty.\n");
                            }else if(checkSubjectFile(a) == 0){
                                printf("File not found.\n");
                            }else{
                                inputSubjectData(a);
                            }

                            break;
                        int found = 0;
                        case 3:
                            printf("Enter Subject code: ");
                            scanf("%s", a);
                            printf("\n");
                            for (n = 0; n < cSub; n++){
                                if(stringCompare(sub[n].subCode, a) == 0){
                                    found = 1;
                                    break;
                                }
                            }
                        if(found == 1){
                            updateSubjectKeyboard(&sub[n]);
                        }else{
                            printf("No records found");
                        }
                            break;
                        case 4:
                            printf("Available subjects to be deleted:");
                            printf("\n\nID number\tSubject Code\tSubject Title\n");
                            for (int x = 1; x < cSub; x++){
                                if(stringCompare(sub[x].subCode, "none") != 0){
                                    displaySubject(&sub[x]);
                                }
                            }
                            printf("Enter subject code to be deleted: ");
                            scanf("%s", a);
                            system("clear");
                            deleteSubject(a);
                            break;
                        case 5:
                            dequeuSubject();
                            printf("\n\nID number\tSubject Code\tSubject Title\n");
                            for (int i = 0; i < cSub; i++){
                                if(stringCompare(sub[i].subCode, "none") != 0){
                                    displaySubject(&sub[i]);
                                }
                            }
                            break;
                        case 6:
                            printf("Enter subject code to search: ");
                            scanf("%s", a);
                            if (findSub(a) == -1){
                                printf("Subject does not exists.\n");
                                printf("Would you like to create suject record?.\n");
                                printf("1 for yes, 0 for no: ");
                                scanf("%d", &n);
                                if(n == 1){
                                    sub[cSub] = addSubjectKeyboard(&sub[cSub],a);
                                    ++cSub;
                                }
                            }else{
                                system("clear");
                                printf("\n\nID number\tSubject Code\tSubject Title\n");
                                displaySubject(&sub[findSub(a)]);
                            }
                        break;

                        case 7:
                            dequeuSubject();
                            writeSubjectRecordsToFile("subject_masterlist.csv");
                            break;
                        default:
                            break;
                    }
                }
            }
            dequeuSubject();
        }
        }else{
            printf("Entered wrong password.\n");
        }
        break;
    
    // User enters as student.
    case 2:
    if(cSub == 1){
        if(checkSubjectFile("subject_masterlist.csv") == -1){
        printf("Subject masterlist is empty.\n");
    }else if(checkSubjectFile("subject_masterlist.csv") == 0){
        printf("File not found\n");
    }else{
        inputSubjectData("subject_masterlist.csv");
    }
    }
    if(cS == 0){
    if(checkMasterStudentFile("student_masterlist.csv") == -1){
        printf("Student masterlist is empty.\n");
    }else if(checkMasterStudentFile("student_masterlist.csv") == 0){
        printf("File not found\n");
    }
    else{
        inputStudentMasterData("student_masterlist.csv");
    }
    }

    // User can only enter as student if there exists student data in masterlist.
    if(cS != 0){
        int choice = 1, studentFound = 0;
        int idN = 0;
        char fam[10];
        int i;
        printf("Username: ");
        scanf("%d", &idN);
        for(i = 0; i < cS; i++){
            if(cs11[i].studentID == idN){
                studentFound = 1;
                break;
            }
        }
        if(studentFound == 0){
            printf("Student ID number does not exist.\n");
        }else{
            int passW = 0;
            printf("Password: ");
            scanf("%s", fam);
            for (int x = 0; x < cS; x++){
                if(stringCompare(fam,cs11[x].lastName) == 0 && idN == cs11[x].studentID){
                    passW = 1;
                    break;
                }
            }
            
            if(passW == 1){
            printf("\n\nYour student records:\n");
            displayStudent(i);
            while(choice >= 0 && choice <=3){
                printf("\n");
                studentMenu();
                printf("\n>>> : ");
                scanf("%d", &choice);
                if(choice == 0){
                    choice = -1;
                    admin = 2;
                }
                switch (choice){
                char a[20];
                case 1:
                    printf("Available subjects:");
                    printf("\n\nID number\tSubject Code\tSubject Title\n");
                    for (int x = 0; x < cSub; x++){
                        if(stringCompare(sub[x].subCode, "none") != 0){
                            displaySubject(&sub[x]);
                        }
                    }
                    printf("\n\nEnroll to: ");
                    scanf("%s",a);
                    printf("\n");
                    studentEnrolSubject(idN, a);
                    break;
                
                case 2:
                    drop(idN);
                case 3:
                    displayStudent(i);
                default:
                    break;
                }
            }
            }else{
                printf("Wrong password.\n");
            }
        }
        
    }


    default:
        break;
    }
    }
}


// Create student record through keyboard input.
struct student studentInputKeyboard(struct student inputStudent){
    char a[10];
    int lo = 1;

    while(lo == 1){
        int hold, cnt = 0;
        reEnterID:
        printf("Enter a unique student 3 digit ID number: ");
        scanf("%d", &hold);
        if(hold > 999 || hold < 100){
            system("clear");
            printf("Please enter 3 digit number.\n");
            goto reEnterID;
        }
        for(int i = 0; i < cS + 1; i++){
            if (cs11[i].studentID == hold)
            {   
                system("clear");
                printf("ID number is used. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == cS + 1){
            inputStudent.studentID = hold;
            lo = 0;
            break;
        }
    }
    printf("Enter last name of student: ");
    scanf(" %14[^\n]s", inputStudent.lastName);
    printf("Enter first name of student: ");
    scanf(" %14[^\n]s", inputStudent.firstName);
    printf("Enter lecture section of student: ");
    scanf(" %4[^\n]s", inputStudent.section);
    printf("Enter Hands-On Exam 1 Score: ");
    scanf("%d", &inputStudent.exam1);
    printf("Enter Hands-On Exam 2 Score: ");
    scanf("%d", &inputStudent.exam2);
    printf("Enter Hands-On Exam 3 Score: ");
    scanf("%d", &inputStudent.exam3);
    printf("\nChoose from available subjects, otherwise type none:\n");
    for(int i = 1; i < cSub; i++){
        printf("%s ", sub[i].subCode);
    }

    reEnterCode2:
    printf("\n\nEnter Subject Code: ");
    scanf(" %9[^\n]s", a);
    if(stringCompare(a, "none")==0){
        inputStudent.sub2 = &temp;
    }else if((findSub(a) == -1)){
        printf("\n%s subject code not found.\n\n", a);
        goto reEnterCode2;
    }else{
        inputStudent.sub2 =& sub[findSub(a)];
    }
    reEnterCode3:
    printf("Enter Subject Code: ");
    scanf(" %9[^\n]s", a);
    if(stringCompare(a, "none")==0){
        inputStudent.sub3 = &temp;
    }else if((findSub(a) == -1)){
        printf("\n%s subject code not found.\n\n", a);
        goto reEnterCode3;
    }else if(stringCompare(inputStudent.sub2->subCode,a) == 0){
        printf("\nStudent already enrolled in that subject.\n");
        goto reEnterCode3;
    }else{
        inputStudent.sub3 =&sub[findSub(a)];
    }

    printf("\n");
    return inputStudent;
}

// Checks if subject exists.
int findSub(char a[10]){
    int n, found = -1;
    for (n = 0; n <= cSub; n++){
    if(stringCompare(sub[n].subCode, a) == 0){
        found = 1;
        break;
        }
    }
    if(found == -1){
        return -1;
    }else{
        return n;
    }
}

// Checks if .txt/.csv exists or if empty.
int checkStudentFile(char file[15]){
    int test;
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        return 0;
    }else{
        int d = fscanf(data, "%d", &test);
        return d;
    }

}
int checkMasterStudentFile(char file[15]){
    int test;
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        return 0;
    }else{
        int d = fscanf(data, "%d", &test);  
        return d;
    }

}
int checkSubjectFile(char file[15]){
    FILE * data;
    data = fopen(file, "r");
        if ((data = fopen(file, "r")) == NULL){
        return 0;
    }else{
        int d = fscanf(data, "%d, %[^,], %[^\n]", &sub[19].subID, sub[19].subCode, sub[19].subTitle);  
        return d;
    }
}

// Creates student records from .txt/.csv file. 
void inputStudentData(char file[15]){

    char a[50], b[50], c[50], lName[20], fName[20]; int at, max, idNum;
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        printf("File could not be opened\n");
    }else{
        while(!feof(data)){
            int same = 0;

            fscanf(data, "%d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^\n]", &cs11[cS].studentID, cs11[cS].lastName, cs11[cS].firstName, cs11[cS].section, &cs11[cS].exam1, &cs11[cS].exam2, &cs11[cS].exam3, a, b, c);
            /*
            This function makes sure that there will be no duplicates for student ID number.
            
            Checks if current student ID number read from file exists in student records. 
            If it already exists, find the largest ID number and assign student with the
            largest + 1. 
            */
            for(int x = 0; x < cS; x++){
                if((cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) != 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) != 0)||(cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) == 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) != 0)||(cs11[x].studentID == cs11[cS].studentID && stringCompare(cs11[x].firstName, cs11[cS].firstName) != 0 && stringCompare(cs11[x].lastName, cs11[cS].lastName) == 0)){
                    max = cs11[0].studentID;
                    for(int y = 0; y < cS; y++){
                        if(cs11[y].studentID > max){
                            max = cs11[y].studentID;
                        }
                    }
                    cs11[cS].studentID = max + 1;
                    break;
                }
            }
            if(stringCompare(sub[0].subCode, a) == 0 && stringCompare(sub[0].subCode, b) == 0 && stringCompare(sub[0].subCode, c) == 0){
                cs11[cS].sub1 = &sub[0];
                cs11[cS].sub2 = &temp;
                cs11[cS].sub3 = &temp;
            }
            if(stringCompare(sub[0].subCode, a) != 0 && stringCompare(sub[0].subCode, b) != 0 && stringCompare(sub[0].subCode, c) != 0){
                cs11[cS].sub1 = &sub[0];
            }else{
                if(stringCompare(a, "none") == 0){
                    cs11[cS].sub1 = &temp;
                }else if(findSub(a) == -1){
                    printf("%s subject code not found.\n", a);
                    printf("Create %s subject record? 1 for yes, 0 for no: ", a);
                    scanf("%d", &at);
                    if(at == 1){
                        sub[cSub] = addSubjectKeyboard(&sub[cSub],a);
                        cs11[cS].sub1 = &sub[findSub(a)];
                        ++cSub;
                    }
                }else{
                    cs11[cS].sub1 = &sub[findSub(a)];
                }
            }
            if(stringCompare(b, "none")  == 0 || stringCompare(b, cs11[cS].sub1->subCode) == 0){
                cs11[cS].sub2 = &temp;
            }else if(findSub(b) == -1){
                printf("%s subject code not found.\n", b);
                printf("Create %s subject record? 1 for yes, 0 for no: ", b);
                scanf("%d", &at);
                if(at == 1){
                    sub[cSub] = addSubjectKeyboard(&sub[cSub],b);
                    cs11[cS].sub2 = &sub[findSub(b)];
                    ++cSub;
                }
            }else{
                cs11[cS].sub2 = &sub[findSub(b)];
            }
            if(stringCompare(c, "none") == 0 || stringCompare(c, cs11[cS].sub2->subCode) == 0 || stringCompare(c, cs11[cS].sub1->subCode) == 0){
                cs11[cS].sub3 = &temp;
            }else if(findSub(c) == -1){
                printf("%s subject code not found.\n", c);
                printf("Create %s subject record? 1 for yes, 0 for no: ", c);
                scanf("%d", &at);
                if(at == 1){
                    sub[cSub] = addSubjectKeyboard(&sub[cSub],c);
                    cs11[cS].sub3 = &sub[findSub(c)];
                    ++cSub;
                }
            }else{
                cs11[cS].sub3 = &sub[findSub(c)];
            }
            for(int x = 0; x < cS; x++){
                if(stringCompare(cs11[cS].lastName, cs11[x].lastName) == 0 && stringCompare(cs11[cS].firstName, cs11[x].firstName) == 0){
                    printf("Student %s %s already exists in student records.\n", cs11[cS].firstName, cs11[cS].lastName);
                    same = 1;
                    break;
                }
            }
            if(same == 0){
                cS++;
            }
            printf("\n");
        }
        printf("\nSuccessfully imported file.\n");
    }
}

// Import student records from subject_masterlist.csv file.
void inputStudentMasterData(char file[15]){
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        printf("File could not be opened\n");
    }else{
        while(!feof(data)){
        char a[50], b[50], c[50]; int at;    
        fscanf(data, "%d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^,], %d, %[^\n]", &cs11[cS].studentID, cs11[cS].firstName, cs11[cS].lastName, cs11[cS].section, &cs11[cS].exam1, &cs11[cS].exam2, &cs11[cS].exam3, a, b, c, &cs11[cS].hex, cs11[cS].grade);

        if(stringCompare(a, "none") == 0){
            cs11[cS].sub1 = &temp;
        }else{
            cs11[cS].sub1 = &sub[findSub(a)];
        }
        if(stringCompare(b, "none") == 0){
            cs11[cS].sub2 = &temp2;
        }else{
            cs11[cS].sub2 = &sub[findSub(b)];
        }
        if(stringCompare(c, "none") == 0){
            cs11[cS].sub3 = &temp3;
        }else{
            cs11[cS].sub3 = &sub[findSub(c)];
        }
        cS++;
        }
    printf("Successfully imported student masterlist records.\n");
    }
}

// Creates subject records from .txt/.csv file. 
void inputSubjectData(char file[15]){
    FILE * data;

    data = fopen(file, "r");

    if ((data = fopen(file, "r")) == NULL){
        printf("File could not be opened\n");
    }else{
        while(!feof(data)){
        int same = 0, max;
        
        fscanf(data, "%d, %[^,], %[^\n]", &sub[cSub].subID, sub[cSub].subCode, sub[cSub].subTitle);
        /*
        Checks if current subject code read from file exists in subject records.

        If it already exists, current array index will be assigned to temp(refer to sub struct initialization)
        and will be overwriten by next creation/import of subject record.
        */
        for(int x = 0; x < cSub; x++){
            if(sub[x].subID == sub[cSub].subID){
                max = sub[0].subID;
                for(int y = 0; y < cSub; y++){
                    if(sub[y].subID > max){
                        max = sub[y].subID;
                    }
                }
                sub[cSub].subID = max + 1;
                break;
            }
        }
        for(int i = 0; i < cSub; i++){
            if(stringCompare(sub[i].subCode,sub[cSub].subCode) == 0){
                sub[cSub] = temp; // Untested 
                same = 1;
                break;
            }
        }
        if(same == 0){
            cSub++;
        }
        }
        printf("Successfully imported file.\n");
    }
}

// Update student records through keyboard input.
struct student updateStudentRecordsKeyboard(struct student inputStudent){

    printf("Enter a unique student ID number.");
    scanf(" %d", &inputStudent.studentID);
    printf("Enter last name of student: ");
    scanf(" %14[^\n]s", inputStudent.lastName);
    printf("Enter first name of student: ");
    scanf(" %14[^\n]s", inputStudent.firstName);
    printf("Enter lecture section of student: ");
    scanf(" %4[^\n]s", inputStudent.section);
    printf("Enter Hands-On Exam 1 Score: ");
    scanf("%d", &inputStudent.exam1);
    printf("Enter Hands-On Exam 2 Score: ");
    scanf("%d", &inputStudent.exam2);
    printf("Enter Hands-On Exam 3 Score: ");
    scanf("%d", &inputStudent.exam3);    
    return inputStudent;
}

// Drops a specific student's subjects.
void drop(int idNum){
    int i;
    char a[50];
    for(i = 0; cs11[i].studentID != idNum; i++);
    if(stringCompare(cs11[i].sub1->subCode, "none") == 0 && stringCompare(cs11[i].sub2->subCode, "none") == 0 && stringCompare(cs11[i].sub3->subCode, "none") == 0){
        printf("Student is not enrolled in any subjects.\n");
    }else{
        printf("\nSubjects of student: %s, %s, %s\n\n", cs11[i].sub1->subCode, cs11[i].sub2->subCode, cs11[i].sub3->subCode);
        printf("Enter code of subject to be dropped: ");
        scanf(" %s", a);
        printf("\n");
        if(stringCompare(a, sub[0].subCode) == 0){
            printf("Subject cannot be dropped.\n");
        }else if(stringCompare(cs11[i].sub2->subCode, a) == 0){
            printf("%s is dropped.\n", cs11[i].sub2->subCode);
            cs11[i].sub2 = cs11[i].sub3;
            cs11[i].sub3 = &temp;
        }else if(stringCompare(cs11[i].sub3->subCode, a) == 0){
            printf("%s is dropped.\n", cs11[i].sub3->subCode);
            cs11[i].sub3 = &temp;
        }else{
            printf("Subject code is not found.\n");
        }
    }
}

// Enrol student to a subject.
void studentEnrolSubject(int idNum, char code[20]){
    int found = 0;
    int find = 0;
    for(int i = 0; i <= cS; i++){
        if(cs11[i].studentID == idNum){
            found = 1;
            if(stringCompare(code, cs11[i].sub1->subCode) == 0 || stringCompare(code, cs11[i].sub2->subCode) == 0 || stringCompare(code, cs11[i].sub3->subCode) == 0){
                printf("Student is already enrolled in this subject.\n");
                break;
            }
            for(int j = 1; j <= cSub; j++){
                if(stringCompare(code, sub[j].subCode) == 0){
                    if(cs11[i].sub2->subID == 0){
                        cs11[i].sub2 = &sub[j];
                        find = 1;
                        printf("Successfully Enrolled.\n");
                        break;
                    }else if (cs11[i].sub3->subID == 0){
                        cs11[i].sub3 = &sub[j];
                        find = 1;
                        printf("Successfully Enrolled.\n");
                        break;
                    }else{
                        printf("Student is already enrolled to 3 subjects.\n");
                        find = 1;
                        break;
                    }

                }
            }
            if(find == 0){printf("Subject code not found\n");}

            break;
        }
    }if(found == 0){printf("Student ID number not found\n");}
}

// Update/create subject records through keyboard input.
struct subject updateSubjectKeyboard(struct subject *inputSub){
    int lo = 1, cnt = 0;
    while(lo == 1){
        int hold;
        reEnterSub:
        printf("Enter Subject ID number: ");
        scanf("%d", &hold);
        if(hold > 100 || hold < 10){
            system("clear");
            printf("Enter a 2 digit number.\n");
            goto reEnterSub;
        }
        for(int i = 0; i < 20; i++){
            if (sub[i].subID == hold)
            {
                system("clear");
                printf("ID number is used. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == 20){
            inputSub->subID = hold;
            lo = 0;
        }
    }
    printf("Enter Subject Code: ");
    scanf(" %9[^\n]s", inputSub->subCode);
    printf("Enter Subject Title: ");
    scanf(" %49[^\n]s", inputSub->subTitle);
    return *inputSub;
}

// Create subject record if not found during import .txt/.csv file.
struct subject addSubjectKeyboard(struct subject *inputSub, char a[]){
    printf("\nCreate Subject Code: %s\n", a);
    stringCopy(a,inputSub->subCode);
    int lo = 1;
    while(lo == 1){
        int hold, cnt = 0;
        reEnterSub:
        printf("Enter Subject ID number: ");
        scanf("%d", &hold);
        if(hold > 100 || hold < 10){
            system("clear");
            printf("Enter a 2 digit number.\n");
            goto reEnterSub;
        }
        for(int i = 0; i < 20; i++){
            if (sub[i].subID == hold)
            {
                system("clear");
                printf("ID number is used. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == 20){
            inputSub->subID = hold;
            lo = 0;
        }
    }
    printf("Enter Subject Title: ");
    scanf(" %49[^\n]s", inputSub->subTitle);
    return *inputSub;
}

// Compares 2 strings, returns 0 if both are same, else returns -1 or 1;
int stringCompare(char s1[], char s2[]){
    int num, i = 0;
    while (toLower(s1[i]) == toLower(s2[i]) && s1[i] != '\0' && s2[i] != '\0'){
        ++i;
    }
    if(toLower(s1[i]) < toLower(s2[i])){
        return -1;
    }else if(toLower(s1[i]) > toLower(s2[i])){
        return 1;
    }else{return 0;}
}

// Converts char to lowecase.
char toLower(char ch){
        if(ch >= 'a' && ch<= 'z'){
        return ch;
    }else{
        return(ch + 32);
    }
}

// Display specific subject's records
void displaySubject(struct subject *inputSubPtr){
    if(inputSubPtr->subID != 0){
    printf("%d\t\t", inputSubPtr->subID);
    printf("%s\t\t", inputSubPtr->subCode);
    printf("%s\n", inputSubPtr->subTitle);
    }
}

// Displays all student's records with statistics(lowest, highest and standard deviation)
void displayAllStudents(int s){
    printf(BLUE"\nCOUNT\tID\tLAST NAME\tFIRST NAME\tSECTION\t\tSUBJECT\t\t\t\tHEX 1\tHEX 2\tHEX 3\tTOTAL\tGRADE\n"RESET);
    for (int i = 0; i < s; i++)
    {
        printf("%d\t%d\t%s\t\t%s\t\t%s\t\t%s, %s, %s\t\t%d\t%d\t%d\t%d\t%s\n",i + 1,cs11[i].studentID, cs11[i].lastName, cs11[i].firstName, cs11[i].section, cs11[i].sub1->subCode, cs11[i].sub2->subCode, cs11[i].sub3->subCode, cs11[i].exam1, cs11[i].exam2, cs11[i].exam3,cs11[i].hex,cs11[i].grade);
    }
    printf(RED"\n\t\t\t\t\t\t\t\t\t\t\tLowest: %d\t%d\t%d\t%d\n" RESET,studentStats[0].low, studentStats[1].low ,studentStats[2].low,studentStats[3].low);
    printf(RED"\t\t\t\t\t\t\t\t\t\t       Highest: %d\t%d\t%d\t%d\n" RESET,studentStats[0].high, studentStats[1].high ,studentStats[2].high,studentStats[3].high);
    printf(RED"\t\t\t\t\t\t\t\t\t\t       Average: %.3f\t%.3f\t%.3f\t%.3f\n" RESET,studentStats[0].ave, studentStats[1].ave ,studentStats[2].ave,studentStats[3].ave);
    printf(RED"\t\t\t\t\t\t\t\t\t\t     Std. Dev.: %.3f\t%.3f\t%.3f\t%.3f\n" RESET,studentStats[0].sd, studentStats[1].sd ,studentStats[2].sd,studentStats[3].sd);
    printf("\n");   
}

// Determines student's grade from exam scores.
struct student scoreGrade(struct student iS){
    iS.hex = iS.exam1 + iS.exam2 + iS.exam3;
    if(iS.hex >= 135){
        strcpy (iS.grade, "HD");    
    }else if (iS.hex >= 120)
    {
        strcpy (iS.grade, "D");
    }else if (iS.hex >= 100)
    {
        strcpy (iS.grade, "P");
    }else if (iS.hex >= 75)
    {
        strcpy (iS.grade, "C");
    }else{
        strcpy (iS.grade, "F"); 
    }

    return iS;
}
// Statistics for Exam 1
struct stat statsEx1(struct stat st){
    int scores[cS];
    int min = cs11[0].exam1;
    int max = cs11[0].exam1;
    float ave = 0,stD = 0;
    
    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam1;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;
    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += power(cs11[i].exam1 - ave, 2);
    }
    st.sd = squareRoot(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
//Statistics for Exam 2
struct stat statsEx2(struct stat st){
    int scores[cS];
    int min = cs11[0].exam2;
    int max = cs11[0].exam2;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam2;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += power(cs11[i].exam2 - ave, 2);
    }
    st.sd = squareRoot(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
// Statistics for Exam 3
struct stat statsEx3(struct stat st){
    int scores[cS];
    int min = cs11[0].exam3;
    int max = cs11[0].exam3;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].exam3;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += power(cs11[i].exam3 - ave, 2);
    }
    st.sd = squareRoot(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}
// Statistics for total scores
struct stat statsHex(struct stat st){
    int scores[cS];
    int min = cs11[0].hex;
    int max = cs11[0].hex;
    float ave = 0,stD = 0;

    // Lowest and highest
    for (int i = 0; i < cS; i++){
        scores[i] = cs11[i].hex;
        ave += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    ave /= cS;

    // Standard deviation
    for (int i = 0; i < cS; i++){
        stD += power(cs11[i].hex - ave, 2);
    }
    st.sd = squareRoot(stD/cS);
    st.ave = ave;
    st.high = max;
    st.low = min;
    return st;
}

// Bubble sort student's last names alphabetically. (medj hugaw pa siya)
void studentSort(int n){
for (int i = 0; i < n - 1; i++){
    for (int c = i; c < n - 1; c++){
        if (stringCompare(cs11[c].lastName,cs11[c+1].lastName) == 1){
            tempo = cs11[c + 1];
            cs11[c + 1] = cs11[c];
            cs11[c] = tempo;
        }
    }
}
}

// Display a student's records by searching student's family name.
void studentNameSearch(char a[15]){
    int cnt = 0;
    for(int i = 0; i < cS; i++){
        if(stringCompare(cs11[i].lastName,a) == 0){
            displayStudent(i);
        }else{
            ++cnt;
        }
        if(cnt == cS){
            printf("Student not found.\n\n");
        }
    }
}

// Display a student's records by struct cs11 array index number.
void displayStudent(int cs11IndexNum){
    printf("Student ID number: %d\n", cs11[cs11IndexNum].studentID);
    printf("Last Name: %s\n", cs11[cs11IndexNum].lastName); 
    printf("First Name: %s\n", cs11[cs11IndexNum].firstName); 
    printf("Lecture Section: %s\n", cs11[cs11IndexNum].section);
    printf("Exam 1 Score: %d\n", cs11[cs11IndexNum].exam1);
    printf("Exam 2 Score: %d\n", cs11[cs11IndexNum].exam2);
    printf("Exam 3 Score: %d\n", cs11[cs11IndexNum].exam3);
    printf("Subject 1: %s\n",cs11[cs11IndexNum].sub1->subCode);
    printf("Subject 2: %s\n",cs11[cs11IndexNum].sub2->subCode);
    printf("Subject 3: %s\n",cs11[cs11IndexNum].sub3->subCode);
    printf("Total Hex Score: %d\n", cs11[cs11IndexNum].hex);
    printf("Grade: %s\n", cs11[cs11IndexNum].grade);
    printf("\n");
}

// Enrolls student to CMSC11.
void cmscEnrol(struct student *cs11Student){
    cs11Student->sub1 = &sub[0];
}

// Export student records in struct array cs11  o a csv file.
void writeStudentRecordsToFile(char file[15]){
    FILE * data;
    data = fopen(file, "w");
    for (int i = 0; i < cS; i++){
        fprintf(data, "%d, %s, %s, %s, %d, %d, %d, %s, %s, %s, %d, %s\n", cs11[i].studentID, cs11[i].firstName, cs11[i].lastName, cs11[i].section, cs11[i].exam1, cs11[i].exam2, cs11[i].exam3, cs11[i].sub1->subCode, cs11[i].sub2->subCode, cs11[i].sub3->subCode, cs11[i].hex, cs11[i].grade);
    }
    fclose(data);
    printf("Successfully exported student data.\n");
}

// Export subject records in struct array sub to a csv file.
void writeSubjectRecordsToFile(char file[15]){
    FILE * data;
    data = fopen(file, "w");
    for (int i = 0; i < cSub; i++){
        fprintf(data, "%d, %s, %s\n", sub[i].subID, sub[i].subCode, sub[i].subTitle);
    }
    fclose(data);
    printf("Successfully exported subject data.\n");
}

// Delete a subject's records.
void deleteSubject(char a[]){
    int i;
    if(stringCompare(sub[0].subCode,a) == 0){
        printf("Subject cannot be deleted.\n");
    }else{
    for(i = 1; i <= cSub; i++){
        if (stringCompare(sub[i].subCode, a)==0){
            sub[cSub] = temp;
            printf("Subject deleted successfully.\n");
            --cSub;
            break;
        }
    }
    }
}

void dequeuSubject(void){
    int i;
    for(i = 1; i < cSub; i++){
        if (sub[i].subID == 0){
            for (int x = i; x <= cSub; x++){
                sub[x] = sub[x + 1];
            }
            cSub -= 1;
            break;
        }
    }
}

// Delete a student's record by dequeuing. 
void deleteStudent(int n){
    int i;
    for(i = 0; i <= cS; i++){
        if (cs11[i].studentID == n){
            break;
        }
    }
    for(int x = i; x < cS; x++){
        cs11[x] = cs11[x + 1];
    }
    --cS;
}

// Function that updates student's grades and score statistics.
void updateGrades(void){
    for (int i = 0; i <= cS; i++)
    {
        cs11[i] = scoreGrade(cs11[i]);
    }
    studentSort(cS);
    //Exam Statistcs
    studentStats[0] = statsEx1(studentStats[0]);
    studentStats[1] = statsEx2(studentStats[1]);
    studentStats[2] = statsEx3(studentStats[2]);
    studentStats[3] = statsHex(studentStats[3]);
}

// Checks if cs11 element is empty and then dequeues it. 
void emptyStudentChecker(void){
    for(int x = 0; x < cS; x++){
        if(cs11[x].studentID == 0){
                int i;
        for(i = 0; i <= cS; i++){
            if(cs11[i].studentID == 0){
                break;
            }
        }
        for(int x = i; x < cS; x++){
            cs11[x] = cs11[x + 1];
        }
        --cS;
        }
    }
}


