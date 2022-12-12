#ifndef __STUDENT_H__
#define __STUDENT_H__

#define DEFAULT_COUNT 5
#define NAME_SIZE 100

struct Student {
    int id;
    char name[NAME_SIZE];
};

typedef struct Student Student;


Student *allocate_student();
Student **allocate_students(int n);
void read_students(FILE *file, Student **students, int n);
void print_students(Student **students, int n);

#endif
