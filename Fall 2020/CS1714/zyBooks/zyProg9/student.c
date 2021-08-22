#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "student.h"


void sSwap(Student *s1, Student *s2)
{
	int temp = s1->id;
	s1->id = s2->id;
	s2->id = temp;

	char sName[10];
	strcpy(sName, s1->name);
	strcpy(s1->name, s2->name);
	strcpy(s2->name, sName);
}

void sortStudents(Student *s, int size)
{
	for(int i =0; i < size-1; i++)
	{
		int minIdx = i;
		for(int j = i+1; j < size; j++)
		{
			if(s[j].id < s[minIdx].id)
			{
				minIdx = j;
			}
		}
		if(minIdx != i)
		{
			sSwap(&s[minIdx], &s[i]);
		}
	}
}

void print(Student *s, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		printf("(%d,%s) -> ", s[i].id, s[i].name);
	}
	printf("(%d,%s) -> \n", s[size-1].id, s[size-1].name);
}

Student searchStudent(Student *s, int size, int id)
{
	for(int i = 0; i < size; i++)
	{
		if(s[i].id == id)
		{
			return s[i];
		}
	}
	return s[0];
}