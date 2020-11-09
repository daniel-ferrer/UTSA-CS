#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student_struct {
	int id;
	char name[10];
} Student;

void sortStudents(Student *s, int size);

void print(Student *s, int size);

Student searchStudent(Student *s, int size, int id);

#endif //STUDENT_H
