#ifndef PERSON_H
#define PERSON_H
typedef struct 
{
    int year;
    int month;
    int date;
    char *name;
} Person;

Person *Person_construct(int y, int m, int d, char *n);
void Person_destruct(Person *p);
void Person_print(Person *p);
Person *Person_copy(Person *p);
Person *Person_assign(Person *p1, Person *p2);

#endif