#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include<string>
using namespace std;

struct Status {
    int love;
    int health;
    int mask;
    int money;
    int week;
    int event;
};

struct Person {
    int id;
    string name;
    int age;
    char gender;
};

struct Backup {
    string date, time;
    Status s;
    Person p;
    Person l;
};

struct Node {
    Backup record;
    Node * next;
};

#endif /* end of include guard: DATA_STRUCTURE_H*/
