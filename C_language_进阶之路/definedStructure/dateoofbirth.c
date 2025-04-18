#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int year;
    int month;
    int date;
} DateOfBirth;

DateOfBirth DateOfBirth_construct(int y, int m, int d)
{
    DateOfBirth dob;
    dob.year = y;
    dob.month = m;
    dob.date = d;
    return dob;
}

void DateOfBirth_print(DateOfBirth d)
{
    printf("Date of Birth: %d/%d/%d\n", d.year, d.month, d.date);
}

typedef struct 
{
    char *name;
    DateOfBirth dob;

} Person;
Person * Person_construct(int y, int m, int d, char *n);
void Person_destruct(Person *p);
Person *Person_copy(Person *p);
Person * Person_assign(Person *p1, Person *p2);
void Person_print(Person *p);
int main(int argc, char* argv[])
{
    Person * p1 = Person_construct(1989, 8, 21, "Amy");
    Person * p2 = Person_construct(1991, 2, 17, "Jennifer");
    Person * p3 = Person_copy(p1);

    Person_print(p1);
    Person_print(p2);
    Person_print(p3);

    p3 = Person_assign(p3, p2);
    Person_print(p3);


    Person_destruct(p1);
    Person_destruct(p2);
    Person_destruct(p3);

    return EXIT_SUCCESS;
}

Person * Person_construct(int y, int m, int d, char *n)
{
    Person * p = NULL;
    p = malloc(sizeof(Person));
    if(p == NULL)
    {
        return NULL;
    }

    p->dob = DateOfBirth_construct(y, m, d);
    p->name = malloc(sizeof(char) * (strlen(n) + 1));
    if(p->name == NULL)
    {
        free(p);
        return NULL;
    }
    strcpy(p->name, n);
    return p;
}

void Person_destruct(Person *p)
{
    free(p->name);
    free(p);
}
void Person_print(Person *p)
{
    printf("Name: %s. ", p->name);
    printf("Data of Birth: %d/%d/%d\n", p->dob.year, p->dob.month, p->dob.date);
}

Person *Person_copy(Person *p)
{
    return Person_construct(p->dob.year, p->dob.month, p->dob.date, p->name);
}
Person *Person_assign(Person *p1, Person *p2)
{
    free(p1->name);
    p1->dob  = p2->dob;
    p1->name = strdup(p2->name);
    return p1;
}


