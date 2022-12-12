#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char **argv) {
    FILE *f = fopen("students.dat", "wb");
    if (f == NULL) {
        printf("Ошибка открытия файла!\n");
        exit(1);
    }

    Student students[DEFAULT_COUNT] = {
        { .id = 42, .name = "Binary Ivanov" },
        { 43, "Binary Petrov long name" },
        { 44, "Студентка 1 Иванова"},
        { 45, "Если прочитал(а) этот текст, то ты почти справился(лась)" },
        { 46, "Что еще можно поместить в файл?" }
    }; // создаем массив структур на стеке (пример(!!!))
    for (int i = 0; i < DEFAULT_COUNT; i++) {
        fwrite(students + i, sizeof(Student), 1, f); // пишем по одному студенту в файл
    }

    int rc = fclose(f);
    if (rc != 0) {
        printf("Ошибка закрытия файла!\n");
        exit(1);
    }
    return 0;
}
