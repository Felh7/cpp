#include <iostream>
#include "string"
#include <cstdlib>
#include<fstream>
#include <limits> // для numeric limits
#include<windows.h>
#undef max
using namespace std;

struct Date {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;

};
struct subject {
    string name;
    unsigned short mark;
};
struct Semester {
    subject subject[9];

};
struct struct_student {
    string name;
    Date birth_date;
    Date admission_date;
    string institut;
    string department;
    string group;
    string record_book;
    string sex;
    Semester semester[9];
    unsigned short int numbers_of_semester;
    unsigned short int massive_of_semestersandsubjects[9];
};
struct list {
    struct_student Data;
    struct list* next;
    struct list* previous;
};

struct list* head;
struct list* tail;

unsigned short int count_of_dynamic_items = 0;
void dynamic_add(struct_student Data) {

    struct list* newitem = new list();
    newitem->Data = Data;
    if (count_of_dynamic_items == 0) {
        newitem->next = NULL;
        tail = newitem;
    }
    else
    {
        newitem->next = head;
        newitem->next->previous = newitem;
    }
    newitem->previous = NULL;
    head = newitem;
    count_of_dynamic_items++;
}
void error_numbers(unsigned short int* n) {
    while (true) {
        cin >> *n;
        if (cin.fail()) {
            cout << endl << "неверные данные, поле принимает только числа" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            *n = '\0';
        }
        else {
            break;
        }
    }
}
void enter_date(struct Date* date) {
wrong_day:
    cout << endl << "День: ";
    error_numbers(&date->day);
    if (date->day > 31 or date->day <= 0) {
        cout << "день не может быть больше 31 и меньше 1. Введите корректную дату";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        date->day = '\0';
        goto wrong_day;
    }
wrong_month:
    cout << endl << "Месяц: ";
    error_numbers(&date->month);
    if (date->month > 12 or date->month <= 0) {
        cout << date->month;
        cout << endl << "месяц не может быть больше 12 и меньше 1. Введите корректную дату" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        date->month = '\0';
        goto wrong_month;
    }

    if (not((date->month <= 7 and date->month % 2 == 1) or (date->month > 7 and date->month % 2 == 0)) and date->day == 31) {
        cout << endl << "в введенном месяце нет 31 числа,введите корректную дату" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        date->day = '\0';
        date->month = '\0';
        goto wrong_day;
    }
    if (date->month == 2 and date->day > 28) {
        cout << endl << "в феврале не бельше 28 дней, введите корректную дату" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        date->day = '\0';
        date->month = '\0';
        goto wrong_day;
    }

    cout << endl << "Год: ";
    error_numbers(&date->year);
    if (date->year > 2023) {
        cout << endl << "привет будущее!" << endl;
    }
};

void toomanysymbols(string* str, unsigned short int n) {
    while (true) {
        cin >> *str;
        if (size(*str) > n) {
            cout << endl << "слишком длинное название, допустимая длина - " << n << " символов" << endl;
            *str = '\0';
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

void menu() {

    cout << "введите 1 для записи данных студента в файл" << endl;
    cout << "введите 2 для удаления данных студента в файле" << endl;
    cout << "введите 3 для изменения данных студента в файле" << endl;
    cout << "введите 4 для выведения данных студентов у которых не больше 25 процентов троек с указанныи интервалом даты рождения" << endl;
    cout << "введите 5 для выведения данных всех студентов в файле" << endl;
}

void free_memory(list* current) {
    list* buffer;
    while (current != NULL) {
        if (current->previous != NULL) {
            current->previous->next = current->next;
            buffer = current->previous;
            tail = buffer;
            delete (current);
            current = buffer;
        }
        else {
            delete(current);
            tail = NULL;
            count_of_dynamic_items = 0;

            break;
        }
    }
}

void get_from_file(fstream* file, struct_student* stud, string b, unsigned short int *numbers_of_semester, unsigned short int* massive_of_semestersandsubjects) {
    while (true) {
        b = file->get();
        if (b != "|") {
            stud->name += b;
        }
        else {
            b = " ";
            break;
        }
    }
    *file >> stud->birth_date.day;
    file->get();
    *file >> stud->birth_date.month;
    file->get();
    *file >> stud->birth_date.year;
    file->get();
    *file >> stud->admission_date.day;
    file->get();
    *file >> stud->admission_date.month;
    file->get();
    *file >> stud->admission_date.year;
    file->get();
    while (true) {
        b = file->get();
        if (b != "|") {
            stud->institut += b;
        }
        else {
            b = " ";
            break;
        }
    }

    while (true) {
        b = file->get();
        if (b != "|") {
            stud->department += b;
        }
        else {
            b = " ";
            break;
        }
    }

    while (true) {
        b = file->get();
        if (b != "|") {
            stud->group += b;
        }
        else {
            b = " ";
            break;
        }
    }

    while (true) {
        b = file->get();
        if (b != "|") {
            stud->record_book += b;
        }
        else {
            b = " ";
            break;
        }
    }

    while (true) {
        b = file->get();
        if (b != "|") {
            stud->sex += b;
        }
        else {
            b = " ";
            break;
        }
    }
   
    file->get();
    unsigned short int c;
    c = file->get();
    file->get();
    unsigned short int i = 0;
    unsigned short int j = 0;
   
    while (b != "\n") {
       
        bool flag = true;
        while (flag == true) {
            while (true) {
                b = file->get();
                if (b == "\n") {
                    flag = false;
                    break;
                }
                if (b == "{") {
                    flag = false;
                    *file >> *numbers_of_semester;
                    file->get();
                    break;
                }
                else {
                    while (true) {
                        if (b != "|") {
                            stud->semester[i].subject[j].name += b;
                        }
                        else {
                            b = " ";
                            break;
                        }
                        b = file->get();

                    }
                    *file >> stud->semester[i].subject[j].mark;
                   
                    file->get();
                    j++;

                }
            }
        }
        massive_of_semestersandsubjects[i] = j;
        i++;
        j = 0;
    }

}
void search_with_interval(struct list** tail, unsigned short int a, unsigned short int b, unsigned short int *numbers_of_semester, unsigned short int *massive_of_semestersandsubjects) {
    struct list* current = *tail;
    struct list* buffer;
    int count_of_trois; 
    unsigned short int numbers_of_subjects;
    int j = 0;
    unsigned short int number_of_marks;
    while (current != NULL) {
        count_of_trois = 0;
        number_of_marks = 0;
        for (int i = 0; i < *numbers_of_semester+1; i++) {
           while (j<massive_of_semestersandsubjects[i]) {
                if (current->Data.semester[i].subject[j].mark == 3) {
                    count_of_trois++;
                }
                j++;
            }
           j = 0;
        }
        for (int n = 0; n < *numbers_of_semester+1; n++) {
            for (int k = 0; k < massive_of_semestersandsubjects[n]; k++) {
                number_of_marks++;
            }
        }
        float percent = count_of_trois % number_of_marks;
        if ((percent > 0.25) or (current->Data.birth_date.year < a) or (current->Data.birth_date.year > b)) {
            if (current->previous != NULL) {
                buffer = current->previous;
                buffer->next = current->next;
                delete current;
                current = buffer;
                if (current->next == NULL) {
                    *tail = current;
                }
            }
            else {
                if (current->next == NULL) {
                    *tail = NULL;
                }
                else {
                    current->next->previous = current->previous;
                }
                delete current;

                break;
            }
        }
        else {
            if (current->previous != NULL) {
                current = current->previous;
            }
            else { break; }
        }

    }
}
void print_dynamic(struct list* tail, unsigned short int *numbers_of_semester, unsigned short int *massive_of_semestersandsubjects) {
    struct list* current = tail;
    while (true) {
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl<< "фамилия имя отчество: " << current->Data.name << endl;
        cout << "дата рождения: ";
        cout << current->Data.birth_date.day << " ";
        cout << current->Data.birth_date.month << " ";
        cout << current->Data.birth_date.year << endl;
        cout << "дата поступления: ";
        cout << current->Data.admission_date.day << " ";
        cout << current->Data.admission_date.month << " ";
        cout << current->Data.admission_date.year << endl;
        cout << "институт: " << current->Data.institut << endl;
        cout << "кафедра: " << current->Data.department << endl;
        cout << "группа: " << current->Data.group << endl;
        cout << "зачетная книжка: " << current->Data.record_book << endl;
        cout << "пол: " << current->Data.sex << endl;
        unsigned short int j = 0;
        for (int i = 0; i < *numbers_of_semester+1; i++) {
            cout <<endl<< "семестр " << i + 1 << endl;
            while (j< massive_of_semestersandsubjects[i]) {
                cout << current->Data.semester[i].subject[j].name << "-" << current->Data.semester[i].subject[j].mark << "  ";
                j++;
            }
            cout << endl;
            j = 0;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << endl;
        if (current->previous != NULL) {
            current = current->previous;
        }
        else { break; }
    }
}
void create_dynamic_spis(fstream* file, struct struct_student* stud, string b, unsigned short int * numbers_of_semester, unsigned short int *massive_of_semestersandsubjects) {
    while (true) {

        get_from_file(file, stud, b, numbers_of_semester, massive_of_semestersandsubjects);
        dynamic_add(*stud);
        unsigned short int i = *numbers_of_semester;
        unsigned short int j ;
        //unsigned short int j = numbers_of_subjects - 1;
        stud->name.clear();
        stud->group.clear();
        stud->institut.clear();
        stud->sex.clear();
        stud->record_book.clear();
        stud->department.clear();
        while (true) {
            
            for (j = 0; j < massive_of_semestersandsubjects[i]; j++) {
                stud->semester[i].subject[j].name.clear();
               
            };
            if (i == 0) {
                break;
            }
            i--;          
            //j = numbers_of_subjects - 1;
        }
        file->get();
        if (file->eof()) { break; }
        else { file->seekg(-1, fstream::cur); }
    }
}
bool do_not_enter_numbers(string* str) {
    unsigned short int i = 0;
    
    for (i;i<size(*str);i++ ){
        if (str[i] == "0" or str[i] == "1" or str[i] == "2" or str[i] == "3" or str[i] == "4" or str[i] == "5" or str[i] == "6" or str[i] == "7" or str[i] == "8" or str[i] == "9"  ){
            cout << "поле не принимает цифры" << endl;
            str->clear();
            return false;
            break;
        }
    }
}
bool do_not_enter_special_symbols(string* str) {
    unsigned short int i = 0;

    for (i; i < size(*str); i++) {
        if (str[i] == "~" or str[i] == "`" or str[i] == "!" or str[i] == "@" or str[i] == "$" or str[i] == "%" or str[i] == "^" or str[i] == "&" or str[i] == "*" or str[i] == "(" or str[i] == ")" or str[i] == "_" or str[i] == "+" or str[i] == "=" or str[i] == "{" or str[i] == "}" or str[i] == "[" or str[i] == "]" or str[i] == ":" or str[i] == ";" or str[i] == "." or str[i] == "," or str[i] == "<" or str[i] == ">" or str[i] == "?" or str[i] == "/" or str[i] == "|") {
            cout << "поле не принимает специальные символы кроме (-) " << endl;
            str->clear();
            return false;
            break;
        }
    }
}
void from_dynamic_spis_to_file(fstream *file, struct list* current, unsigned short int* numbers_of_semester) {
    file->open("students.bin", fstream::out | fstream::binary);
    current = tail;
    int j = 0;
    while (current != NULL) {
        *file << current->Data.name << "|" << current->Data.birth_date.day << "|" << current->Data.birth_date.month << "|" << current->Data.birth_date.year << "|" << current->Data.admission_date.day << "|" << current->Data.admission_date.month << "|" << current->Data.admission_date.year << "|" << current->Data.institut << "|" << current->Data.department << "|" << current->Data.group << "|" << current->Data.record_book << "|" << current->Data.sex << "|";
        for (int i = 0; i <*numbers_of_semester; i++) {
            *file << "{" << i << "}";
            while (true) {
                *file << current->Data.semester[i].subject[j].name << "|" << current->Data.semester[i].subject[j].mark << "|";
                j++;
            }
        };
        *file << "\n";
        current = current->previous;
    }
    file->close();
}
void warning(unsigned short int *n, unsigned short int * chose, struct list* current) {
    cout << endl;
    for (int i = 0; i < *n - 1; i++) {
        current = current->previous;
    }
    cout << "вы хотите изменить данные студента " <<current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
    error_numbers(chose);
}
class student {
private:
    string name;
    Date birth_date;
    Date admission_date;
    string institut;
    string department;
    string group;
    string record_book;
    string sex;

    Semester semester[9];
    

    string strbuf;
    unsigned short int intbuf;
public:
    unsigned short int numbers_of_semester;
    unsigned short int massive_of_semestersandsubjects[9];
    student() {
        setData();
    };

    void setData() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "введите Ф.И.О. студента(используйте пробелы для разграничения инициалов)" << endl;
        while (true) {
            getline(cin, this->name);
            if (size(this->name) != 0) {
                if (size(this->name) > 151) {
                    cout << endl << "слишком длинное название, допустимая длина - 150 символов" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->name.clear();
                }
                else {
                    if (do_not_enter_numbers(&this->name) and do_not_enter_special_symbols(&this->name)) {
                        break;
                    }
                }
            }
            
        }
        cout << endl << "введите дату рождения студента" << endl;
        enter_date(&this->birth_date);
        cout << endl << "введите дату поступления студента" << endl;
        enter_date(&this->admission_date);
        cout << endl << "введите институт студента" << endl;
        toomanysymbols(&this->institut, 5);
        cout << endl << "введите кафедру студента" << endl;
        toomanysymbols(&this->department, 5);
        cout << endl << "введите группу студента" << endl;
        toomanysymbols(&this->group, 10);
        cout << endl << "введите номер зачетной книжки студента" << endl;
        toomanysymbols(&this->record_book, 7);
        cout << endl << "введите пол студента" << endl;
        while (true) {
            toomanysymbols(&this->sex, 1);
            if (this->sex != "м" and this->sex != "ж") {
                cout << "поле принимает значение м или ж" << endl;
                this->sex.clear();
            }
            else { break; }
        }
        cout << endl << "введите количество семестров" << endl;
        error_numbers(&numbers_of_semester);
        
        cout << endl << "введите предметы и оценки студента" << endl;
        for (int i = 0; i < numbers_of_semester; i++) {
            cout << "введите количество предметов в семестре номер " << i+1 << endl;
            error_numbers(&massive_of_semestersandsubjects[i]);
            cout << "введите результаты " << i + 1 << " семестра" << endl;
            for (int j = 0; j < massive_of_semestersandsubjects[i]; j++) {
                cout << endl << "введите название предмета:  ";
                while (true) {
                    getline(cin, this->semester[i].subject[j].name);
                    if (size(this->semester[i].subject[j].name) != 0) {
                        if (size(this->semester[i].subject[j].name) > 60) {
                            cout << endl << "слишком длинное название, допустимая длина - 60 символов" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            this->semester[i].subject[j].name.clear();
                        }
                        else {
                            break;
                        }
                    }
                }
                cout << endl << "введите оценку за предмет(цифрой, зачет-1, незачет-0):  ";
                while (true) {
                    cin >> this->semester[i].subject[j].mark;
                    if (cin.fail()) {
                        cout << endl << "ошибка ввода, введите число" << endl;
                        cin.clear();
                        this->semester[i].subject[j].mark = '\0';
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if (this->semester[i].subject[j].mark > 5 or this->semester[i].subject[j].mark < 0) {
                        cout << endl << "ошибка, оценка может принимать значения от 0 до 5" << endl;

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        this->semester[i].subject[j].mark = '\0';
                    }
                    else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                cout << endl;
            }
        }
    };
    void getData() {
        for (int i = 0; i < numbers_of_semester; i++) {
            for (int j = 0; j < massive_of_semestersandsubjects[i]; j++) {
                cout << endl;
                cout << this->semester[i].subject[j].name << endl;
                cout << this->semester[i].subject[j].mark << endl;
            }
        }
    }
    void copy_from_me(struct struct_student* st) {
        st->name = this->name;
        st->group = this->group;
        st->birth_date = this->birth_date;
        st->institut = this->institut;
        st->record_book = this->record_book;
        for (int i = 0; i < numbers_of_semester; i++) {
            st->semester[i] = this->semester[i];
        }
        st->department = this->department;
        st->admission_date = this->admission_date;
        st->sex = this->sex;
    }
};
class dynamic_list {
public:
    struct list* tail;
    struct list* head;
    unsigned short int numbers_of_semester;
    unsigned short int massive_of_semestersandsubjects[9];
    unsigned short int count_of_dynamic_items ;

    dynamic_list() { count_of_dynamic_items = 0; tail = NULL; head = NULL; }
    void dynamic_add(struct_student Data) {

        struct list* newitem = new list();
        newitem->Data = Data;
        if (count_of_dynamic_items == 0) {
            newitem->next = NULL;
            this->tail = newitem;
        }
        else
        {
            newitem->next = this -> head;
            newitem->next->previous = newitem;
        }
        newitem->previous = NULL;
        this->head = newitem;
        count_of_dynamic_items++;
    }
    void free_memory(list* current) {
        list* current = tail;
        list* buffer;
        while (current != NULL) {
            if (current->previous != NULL) {
                current->previous->next = current->next;
                buffer = current->previous;
                this->tail = buffer;
                delete (current);
                current = buffer;
            }
            else {
                delete(current);
                this->tail = NULL;
                count_of_dynamic_items = 0;

                break;
            }
        }
    }
    void create_dynamic_spis(fstream* file, struct struct_student* stud, string b) {
        while (true) {

            get_from_file(file, stud, b, &this->numbers_of_semester, this->massive_of_semestersandsubjects);
            dynamic_add(*stud);
            unsigned short int i = this->numbers_of_semester;
            unsigned short int j;
            stud->name.clear();
            stud->group.clear();
            stud->institut.clear();
            stud->sex.clear();
            stud->record_book.clear();
            stud->department.clear();
            while (true) {

                for (j = 0; j < this->massive_of_semestersandsubjects[i]; j++) {
                    stud->semester[i].subject[j].name.clear();

                };
                if (i == 0) {
                    break;
                }
                i--;
            }
            file->get();
            if (file->eof()) { break; }
            else { file->seekg(-1, fstream::cur); }
        }
    }



};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned short int number;
    unsigned short int kill_app;

    while (true) {
        menu();
        error_numbers(&number);

        switch (number) {
           
        case 0: break;

        case 1:
        {
            class student student;
            struct struct_student stud;
            student.copy_from_me(&stud);
            fstream file;
            file.open("students.bin", fstream::app | fstream::binary);
            if (file.is_open()) {
                file << stud.name << "|" << stud.birth_date.day << "|" << stud.birth_date.month << "|" << stud.birth_date.year << "|" << stud.admission_date.day << "|" << stud.admission_date.month << "|" << stud.admission_date.year << "|" << stud.institut << "|" << stud.department << "|" << stud.group << "|" << stud.record_book << "|" << stud.sex << "|";
                for (int i = 0; i < student.numbers_of_semester; i++) {
                    file << "{" << i << "}";
                    for (int j = 0; j < student.massive_of_semestersandsubjects[i]; j++) {
                        file << stud.semester[i].subject[j].name << "|" << stud.semester[i].subject[j].mark << "|";
                    }
                }
                file << "\n";
                cout << "данные успешно сохранены" << endl;
            }
            else {
                cout << "не удалось открыть файл" << endl;
            }
            file.close();
            break;
        }
       
        case 2:
        {
            struct struct_student stud;
            unsigned short int n;
            class dynamic_list list;
            fstream file;
            file.open("students.bin", fstream::in | fstream::binary);

            if (file.is_open()) {
                string b;
                list.create_dynamic_spis(&file, &stud, b);
            }
            else {
                cout << "не удалось открыть файл" << endl;
            }
            file.close();

            while (true) {
                cout << "Введите номер по счету студента, данные которого вы хотите удалить: ";
                error_numbers(&n);
                if (n > count_of_dynamic_items) {
                    cout << "в фалйе нет столько записей. Количество записей в файле: " << list.count_of_dynamic_items << endl << "Попробуйте снова" << endl;
                }
                else { break; }
            }
            cout << endl;
            struct list* current = tail;
            for (int i = 0; i < n - 1; i++) {
                current = current->previous;
            }

            cout << "вы хотите удалить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
            unsigned short int chose;
            error_numbers(&chose);

            if (chose != 0) {
                list* buffer;
                if (current->previous != NULL) {
                    current->previous->next = current->next;
                }
                if (current->next != NULL) {
                    current->next->previous = current->previous;

                }
                else { tail = current->previous; }

                delete current;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                file.open("students.bin", fstream::out | fstream::binary);
                current = tail;
                int j = 0;
                while (current != NULL) {
                    file << current->Data.name << "|" << current->Data.birth_date.day << "|" << current->Data.birth_date.month << "|" << current->Data.birth_date.year << "|" << current->Data.admission_date.day << "|" << current->Data.admission_date.month << "|" << current->Data.admission_date.year << "|" << current->Data.institut << "|" << current->Data.department << "|" << current->Data.group << "|" << current->Data.record_book << "|" << current->Data.sex << "|";
                    for (int i = 0; i < stud.numbers_of_semester; i++) {
                        file << "{" << i << "}";
                        while (true) {
                            file << current->Data.semester[i].subject[j].name << "|" << current->Data.semester[i].subject[j].mark << "|";
                            j++;
                        }
                    };
                    file << "\n";
                    current = current->previous;
                }
                file.close();
                cout << "Данные успешно удалены" << endl;
                count_of_dynamic_items--;
            }
            current = tail;
            free_memory(current);
            break;
        }

        case 3:
        {
            struct struct_student stud;
            unsigned short int n;

            fstream file;
            file.open("students.bin", fstream::in | fstream::binary);

            if (file.is_open()) {
                string b;
                create_dynamic_spis(&file, &stud, b, &numbers_of_semester, massive_of_semestersandsubjects);
            }
            else {
                cout << "не удалось открыть файл" << endl;
            }
            file.close();

            while (true) {
                cout << "Введите номер по счету студента, данные которого вы хотите изменить: ";
                error_numbers(&n);
                
                if (n > count_of_dynamic_items) {
                    cout << "в файле нет столько записей. Количество записей в файле: " << count_of_dynamic_items << endl << "Попробуйте снова" << endl;
                }
                else if (n <= 0) {
                    cout << "введите число больше нуля" << endl;
                }
                else { break; }
            }
            cout << "выберите что изменить в данных студнета:" << endl << "0-отменить" << endl << "1-изменить все данные студента" << endl << "2-изменить имя студента" << endl << "3-изменить дату рождения студента" << endl;
            cout << "4-изменить дату поступления студента" << endl << "5-изменить институт, кафедру и группу студента " << endl << "6-изменить пол студента " << endl << "7-изменить номер зачетной книжки студента ";
            unsigned short int v;
            error_numbers(&v);

            switch (v) {
            case 0: {
                struct list* current;
                current = tail;
                free_memory(current);
                break;
            }

            case 1: {
                unsigned short int chose;
                struct list* current;
                current = tail;

                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);

                if (chose != 0) {
                    int j = 0;
                    class student student;
                    numbers_of_semester = student.number_of_semester;
                    student.copy_from_me(&stud);
                    current->Data.name = stud.name;
                    current->Data.birth_date = stud.birth_date;
                    current->Data.admission_date = stud.admission_date;
                    current->Data.institut = stud.institut;
                    current->Data.department = stud.department;
                    current->Data.group = stud.group;
                    current->Data.record_book = stud.record_book;
                    current->Data.sex = stud.sex;
                    current->Data.institut = stud.institut;
                    for (int i = 0; i < numbers_of_semester; i++) {
                        for (int j = 0; j < massive_of_semestersandsubjects[i];j++) {
                            current->Data.semester[i].subject[j] = stud.semester[i].subject[j];
                        }
                    }
                    from_dynamic_spis_to_file(&file, current, &numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;
                }
                current = tail;
                free_memory(current);
                break;
            }

            case 2: {
                unsigned short int chose;
                struct list* current;
                current = tail;
                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    string name;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "введите Ф.И.О. студента(используйте пробелы для разграничения инициалов)" << endl;
                    while (true) {
                        getline(cin, name);
                        if (size(name) > 151) {
                            cout << endl << "слишком длинное название, допустимая длина - 150 символов" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            name.clear();
                        }
                        else {
                            break;
                        }
                    }
                    current->Data.name = name;
                    from_dynamic_spis_to_file(&file, current,&numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                break;
            }

            case 3: {
                unsigned short int chose;
                struct list* current;
                current = tail;

                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    struct Date date;
                    cout << endl << "введите дату рождения студента" << endl;
                    enter_date(&date);
                    current->Data.birth_date = date;
                    from_dynamic_spis_to_file(&file, current, &numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                break;
            }

            case 4: {
                unsigned short int chose;
                struct list* current;
                current = tail;
                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    struct Date date;
                    cout << endl << "введите дату поступления студента" << endl;
                    enter_date(&date);
                    current->Data.admission_date = date;
                    from_dynamic_spis_to_file(&file, current,&numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                break;
            }

            case 5: {
                unsigned short int chose;
                struct list* current;
                current = tail;
                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    string inst;
                    string dep;
                    string group;
                    cout << endl << "введите институт студента" << endl;
                    toomanysymbols(&inst, 6);
                    cout << endl << "введите кафедру студента" << endl;
                    toomanysymbols(&dep, 7);
                    cout << endl << "введите группу студента" << endl;
                    toomanysymbols(&group, 12);
                    current->Data.institut = inst;
                    current->Data.department = dep;
                    current->Data.group = group;
                    from_dynamic_spis_to_file(&file, current,&numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                break;
            }

            case 6:
            {
                unsigned short int chose;
                struct list* current;
                current = tail;
                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    string sex;
                    cout << endl << "введите пол студента" << endl;
                    toomanysymbols(&sex, 3);
                    current->Data.sex = sex;
                    from_dynamic_spis_to_file(&file, current, &numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                break;
            }
            case 7: {
                unsigned short int chose;
                struct list* current;
                current = tail;
                cout << endl;
                for (int i = 0; i < n - 1; i++) {
                    current = current->previous;
                }
                cout << "вы хотите изменить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
                error_numbers(&chose);
                if (chose != 0) {
                    string recordbook;
                    cout << endl << "введите номер зачетной книжки студента" << endl;
                    toomanysymbols(&recordbook, 15);
                    current->Data.record_book = recordbook;
                    from_dynamic_spis_to_file(&file, current, &numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;

                }
                current = tail;
                free_memory(current);
                
            }
                  break;
            default: {
                cout << "такой команды нет" << endl;
                list* current = tail;
                free_memory(current);
                break;
            }


            }
            break;
        }
        
        case 4: {

            struct struct_student stud;
            fstream file;

            file.open("students.bin", fstream::in | fstream::binary);
            if (file.is_open()) {
                string b;
                create_dynamic_spis(&file, &stud, b, &numbers_of_semester, massive_of_semestersandsubjects);
            }
            else {
                cout << "не удалось открыть файл" << endl;
                break;
            }
            file.close();
            unsigned short interval_start;
            unsigned short interval_end;
            while (true) {
                cout << "введите интервал даты рождения" << endl;
                cout << "от: ";
                error_numbers(&interval_start);
                cout << endl;
                cout << "до: ";
                error_numbers(&interval_end);
                if (interval_start > interval_end) {
                    cout << "Неправильные данные. Значение поля (от) не должно быть больше значения поля (до)" << endl;
                }
                else { break; }
            }
            search_with_interval(&tail, interval_start, interval_end, &numbers_of_semester, massive_of_semestersandsubjects);
            struct list* current = tail;
            struct list* buffer;

            if (tail == NULL) {
                cout << "студентов, удовлетворяющих условию нет" << endl;
                current = tail;
                free_memory(current);
                break;
            }
            else {
                print_dynamic(current, &numbers_of_semester, massive_of_semestersandsubjects);       
                current = tail;
                free_memory(current);
                break;
            }
        }
        
        case 5: {
            struct struct_student stud;
            fstream file;
            dynamic_list list1;
            list* buffer;
            

            file.open("students.bin", fstream::in | fstream::binary);
            if (file.is_open()) {
                string b;
                create_dynamic_spis(&file, &stud, b, &numbers_of_semester, massive_of_semestersandsubjects);
            }
            else {
                cout << "не удалось открыть файл" << endl;
                break;
            }
            file.close();
            list* current = tail;
            
            print_dynamic(current, &numbers_of_semester,massive_of_semestersandsubjects);
               
            current = tail;
            free_memory(current);
            break;
        }

        default:
            cout << "такой команды нет" << endl;
            list* current = tail;
            free_memory(current);
            break;
        }
        cout << endl <<"введие 0 чтобы закрыть программу или любое число чтобы продолжить" << endl;
        error_numbers(&kill_app);
        if (kill_app == 0) {
            break;
        }
    }
}

