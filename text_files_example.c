#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*
* Пример чтения структур из текстового файла
*/

/*
* Функция для выделения указателей на указатели на структуры студентов
* Под капотом позволяет выделить память под каждого отдельного из *n* студентов
*/
Student **allocate_students(int n) {
    Student **all = (Student **) malloc(n * sizeof(Student *));
    // NOTE: на самом деле необходимо проверять указатель на NULL,
    // т.к. могут быть утечки памяти
    for (int i = 0; i < n; i++) {
        all[i] = allocate_student();
    }
    return all;
}

/*
* Функция для выделения указателей на структуры студентов
*/
Student *allocate_student() {
    return (Student *) malloc(sizeof(Student));
}

/*
* Функция для чтения *n* студентов из файла *file*
*/
void read_students(FILE *file, Student **students, int n) {
    for (int i = 0; i < n && !feof(file); i++) {
        // ВАЖНО: fscanf ограничен форматной строкой, обсуждали на семинаре.
        // Вспомнить, до какого момента читается %s
        fscanf(file, "%d %s", &(students[i]->id), students[i]->name);
    }
}

/*
* Функция для печати *n* студентов на консоль
*/
void print_students(Student **students, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", students[i]->id, students[i]->name);
    }
}

/*
* Функция освобождения памяти из-под студентов
*/
void clear_students(Student **students, int n) {
    for (int i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);
}

int main(int argc, char **argv) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла!\n");
        exit(1);
    }
    Student **students = allocate_students(DEFAULT_COUNT);
    read_students(f, students, DEFAULT_COUNT);
    print_students(students, DEFAULT_COUNT);
    clear_students(students, DEFAULT_COUNT);

    int rc = fclose(f);
    if (rc != 0) {
        printf("Ошибка закрытия файла!\n");
        exit(1);
    }
    return 0;
}
