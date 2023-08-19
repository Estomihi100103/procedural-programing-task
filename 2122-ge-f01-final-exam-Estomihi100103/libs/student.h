#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

struct student_t
{
    char id[20];
    char name[50];
    char year[10];
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);
void print_student(struct student_t *_student, int count);
void print_student_detail(struct student_t *_student, int count);
void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name);
void student_leave(struct student_t *_student,struct dorm_t *_dorm);

#endif








/*
Expected:
12S21001|Dhino Turnip|2021|male|Antiokia
12S21002|Marudut Tampubolon|2021|male|Antiokia
12S21003|Jusas Tampubolon|2021|male|Kapernaum
12S21004|Estomihi pangaribuan|2021|male|Antiokia
12S21006|Weny Sitinjak|2021|female|unassigned
12S21007|Dame Sitinjak|2021|female|Pniel
12S21008|Tuani Manurung|2021|male|Kapernaum
12S21001|Dhino Turnip|2021|male|left
12S21002|Marudut Tampubolon|2021|male|left
12S21003|Jusas Tampubolon|2021|male|Kapernaum
12S21004|Estomihi pangaribuan|2021|male|left
12S21006|Weny Sitinjak|2021|female|unassigned
12S21007|Dame Sitinjak|2021|female|left
12S21008|Tuani Manurung|2021|male|Kapernaum


0AActual:
12S21001|Dhino Turnip|2021|male|Antiokia
12S21002|Marudut Tampubolon|2021|male|Antiokia
12S21003|Jusas Tampubolon|2021|male|Kapernaum
12S21004|Estomihi pangaribuan|2021|male|Antiokia
12S21006|Weny Sitinjak|2021|female|left
12S21007|Dame Sitinjak|2021|female|Pniel
12S21008|Tuani Manurung|2021|male|Kapernaum
12S21001|Dhino Turnip|2021|male|left
12S21002|Marudut Tampubolon|2021|male|left
12S21003|Jusas Tampubolon|2021|male|Kapernaum
12S21004|Estomihi pangaribuan|2021|male|left
12S21006|Weny Sitinjak|2021|female|left
12S21007|Dame Sitinjak|2021|female|left
12S21008|Tuani Manurung|2021|male|Kapernaum



student-add#12S21001#Dhino Turnip#2021#male
student-add#12S21002#Marudut Tampubolon#2021#male
student-add#12S21003#Jusas Tampubolon#2021#male
student-add#12S21004#Estomihi pangaribuan#2021#male
student-add#12S21006#Weny Sitinjak#2021#female
student-add#12S21007#Dame Sitinjak#2021#female
student-add#12S21008#Tuani Manurung#2021#male
dorm-add#Antiokia#5#male
dorm-add#Pniel#5#female
dorm-add#Kapernaum#5#male
assign-student#12S21001#Antiokia
assign-student#12S21002#Antiokia
assign-student#12S21003#Kapernaum
assign-student#12S21004#Antiokia
assign-student#12S21006#Kapernaum
assign-student#12S21007#Pniel
assign-student#12S21008#Kapernaum
student-print-all-detail
student-leave#12S21007
student-leave#12S21004
student-leave#12S21001
student-leave#12S21002
student-print-all-detail
*/