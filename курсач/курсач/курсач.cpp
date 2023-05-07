#include <iostream>
#include "string"
#include <cstdlib>
#include<fstream>
#include <limits> // для numeric limits
#include<windows.h>
#include <time.h>
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
    Semester semester[10];
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
    while (true) {
        error_numbers(&date->year);
        if (date->year > 2100 or date->year < 1900) { cout << "поле даты не должно быть меньше 1900 и больше 2100" << endl; }
        else { break; }
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
    cout << "введите 6 для шифрования файла" << endl;
    cout << "введите 7 для дешифрования файла" << endl;
}
void print_date(unsigned short int day, unsigned short int month, unsigned short int year, unsigned short int width) {
    cout << "|" ;
    cout << left;
    if (day > 9) {
        cout << day << ".";
    }
    else {
        cout << 0 << day << ".";
    }
    if (month > 9) {
        cout << month << ".";
<<<<<<< HEAD
    }
    else {
        cout << 0 << month << ".";
    }
=======
    }
    else {
        cout << 0 << month << ".";
    }
>>>>>>> баг фикс 3 кейса
    cout << year; cout.width(width);cout << " " << "|";
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
   
    while (b!="\n") {
        bool flag = true;
        while (flag == true) {
            while (true) {
                b = file->get();
                if (b == "\r") {
                    b = file->get();
                    flag = false;
                    break;
                }
                if (b == "\n") {
                    flag = false;
                    break;
                }
                if (b == "{") {
                    flag = false;
                    file->get();
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
                   
                    b = file->get();
                    
                    j++;

                }
            }
        }
        massive_of_semestersandsubjects[i] = j;
        i++;
        j = 0;
        
    }
    *numbers_of_semester=i;
    for (int i = 0; i < *numbers_of_semester; i++) {
        stud->massive_of_semestersandsubjects[i] = massive_of_semestersandsubjects[i];
    }
    stud->numbers_of_semester = *numbers_of_semester;

}
void search_with_interval(struct list** tail, unsigned short int a, unsigned short int b) {
    struct list* current = *tail;
    struct list* buffer;
    float count_of_trois;
    unsigned short int numbers_of_semester;
    int j = 0;
    unsigned short int number_of_marks;
    while (current != NULL) {
        count_of_trois = 0;
        number_of_marks = 0;
        numbers_of_semester = current->Data.numbers_of_semester;
        for (int i = 0; i < numbers_of_semester; i++) {
           while (j<current->Data.massive_of_semestersandsubjects[i]) {
                if (current->Data.semester[i].subject[j].mark == 3) {
                    count_of_trois++;
                }
                j++;
            }
           j = 0;
        }
        for (int n = 0; n < numbers_of_semester; n++) {
            for (int k = 0; k < current->Data.massive_of_semestersandsubjects[n]; k++) {
                number_of_marks++;
            }
        }
        float percent = count_of_trois / number_of_marks;
        if ((percent > 0.25) or (current->Data.birth_date.year < a) or (current->Data.birth_date.year > b)) {
            if (current->previous != NULL) {
                buffer = current->previous;
                buffer->next = current->next;
                if (buffer->next != NULL) {
                    buffer->next->previous = buffer;
                }
                else { *tail = buffer; }
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
bool do_not_enter_numbers(string* str) {
    if (str->find("0") != string::npos or str->find("1") != string::npos or str->find("2") != string::npos or str->find("3") != string::npos or str->find("4") != string::npos or str->find("5") != string::npos or str->find("6") != string::npos or str->find("7") != string::npos or str->find("8") != string::npos or str->find("9") != string::npos){
        str->clear();
        return true; 
     }
    else { return false; }
}
bool do_not_enter_special_symbols(string* str) {
   
<<<<<<< HEAD
   if (str->find("~") != string::npos or str->find("`") != string::npos or str->find("!") != string::npos or str->find("@") != string::npos or str->find("$") != string::npos or str->find("%") != string::npos or str->find("^") != string::npos or str->find("&") != string::npos or str->find("*") != string::npos or str->find("(") != string::npos or str->find(")") != string::npos or str->find("_") != string::npos or str->find("+") != string::npos or str->find("=") != string::npos or str->find("{") != string::npos or str->find("}") != string::npos or str->find("[") != string::npos or str->find("]") != string::npos or str->find(":") != string::npos or str->find(";") != string::npos or str->find(".") != string::npos or str->find(",") != string::npos or str->find("<") != string::npos  or str->find(">") != string::npos or str->find("?") != string::npos or str->find("/") != string::npos or str->find("|") != string::npos or str->find("\\") != string::npos) {
=======
   if (str->find("~") != string::npos or str->find("`") != string::npos or str->find("!") != string::npos or str->find("@") != string::npos or str->find("$") != string::npos or str->find("%") != string::npos or str->find("^") != string::npos or str->find("&") != string::npos or str->find("*") != string::npos or str->find("(") != string::npos or str->find(")") != string::npos or str->find("_") != string::npos or str->find("+") != string::npos or str->find("=") != string::npos or str->find("{") != string::npos or str->find("}") != string::npos or str->find("[") != string::npos or str->find("]") != string::npos or str->find(":") != string::npos or str->find(";") != string::npos or str->find(".") != string::npos or str->find(",") != string::npos or str->find("<") != string::npos  or str->find(">") != string::npos or str->find("?") != string::npos or str->find("/") != string::npos or str->find("|") != string::npos or str->find("\\") != string::npos or str->find("№") != string::npos or str->find("'") != string::npos) {
>>>>>>> баг фикс 3 кейса
        str->clear();
        return true;    
    }
   else { return false; }
}
void from_dynamic_spis_to_file(fstream *file, struct list** tail, unsigned short int* numbers_of_semester) {
    file->open("students.bin", fstream::out | fstream::binary);
    struct list* current = *tail;
<<<<<<< HEAD
    int j = 0;
=======
>>>>>>> баг фикс 3 кейса
    while (current != NULL) {
        *file << current->Data.name << "|" << current->Data.birth_date.day << "|" << current->Data.birth_date.month << "|" << current->Data.birth_date.year << "|" << current->Data.admission_date.day << "|" << current->Data.admission_date.month << "|" << current->Data.admission_date.year << "|" << current->Data.institut << "|" << current->Data.department << "|" << current->Data.group << "|" << current->Data.record_book << "|" << current->Data.sex << "|";
        for (int i = 0; i <*numbers_of_semester; i++) {
            *file << "{" << i << "}";
            for (unsigned short int j = 0; j < current->Data.massive_of_semestersandsubjects[i];j++) {
                *file << current->Data.semester[i].subject[j].name << "|" << current->Data.semester[i].subject[j].mark << "|";
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

    Semester semester[10];
    

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
                if (size(this->name) > 100) {
                    cout << endl << "слишком длинное название, допустимая длина - 100 символов" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    this->name.clear();
                }
                else {
                    if (do_not_enter_numbers(&this->name)) { cout << "поле не принимает цифры " << endl;cin.clear();  }
                    else if (do_not_enter_special_symbols(&this->name)) {
                        cout << "поле не принимает специальные символы кроме (-) " << endl;
                        cin.clear();
                    }
                    else{
                        break;
                    }
                }
            }
            
        }
        cout << endl << "введите дату рождения студента" << endl;
        enter_date(&this->birth_date);
        cout << endl << "введите дату поступления студента" << endl;
        enter_date(&this->admission_date);
        while (true) {
            cout << endl << "введите институт студента" << endl;
            toomanysymbols(&this->institut, 5);
            if (do_not_enter_numbers(&this->institut)) { cout << "поле не принимает цифры " << endl; cin.clear(); }
            else if (do_not_enter_special_symbols(&this->institut)) {
                cout << "поле не принимает специальные символы кроме (-) " << endl;
                cin.clear();
            }
            else {
                break;
            }
        }
        while (true) {
            cout << endl << "введите кафедру студента" << endl;
            toomanysymbols(&this->department, 5);
            if (do_not_enter_special_symbols(&this->department)) {
                cout << "поле не принимает специальные символы кроме (-) " << endl;
                cin.clear();
            }
            else {
                break;
            }
        }
        while (true) {
            cout << endl << "введите группу студента" << endl;
            toomanysymbols(&this->group, 10);
            if (do_not_enter_special_symbols(&this->group)) {
                cout << "поле не принимает специальные символы кроме (-) " << endl;
                cin.clear();
            }
            else {
                break;
            }  
        }
        while (true) {
            cout << endl << "введите номер зачетной книжки студента" << endl;
            toomanysymbols(&this->record_book, 7);
            if (do_not_enter_special_symbols(&this->record_book)) {
                cout << "поле не принимает специальные символы кроме (-) " << endl;
                cin.clear();
            }
            else {
                break;
            }
        }
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
        while (true) {
            error_numbers(&numbers_of_semester);
<<<<<<< HEAD
            if (numbers_of_semester > 10) { cout << "максимальное количсетво семестров-10"; }
=======
            if (numbers_of_semester > 10) { cout << "максимальное количсетво семестров-10" << endl; }
>>>>>>> баг фикс 3 кейса
            else { break; }
        }
        cout << endl << "введите предметы и оценки студента" << endl;
        for (int i = 0; i < numbers_of_semester; i++) {
            cout << "введите количество предметов в семестре номер " << i+1 << endl;
            while (true) {
                error_numbers(&massive_of_semestersandsubjects[i]);
<<<<<<< HEAD
                if (massive_of_semestersandsubjects[i] > 9) { cout << "максимальное количсетво семестров-9";  }
=======
                if (massive_of_semestersandsubjects[i] > 9) { cout << "максимальное количсетво семестров-9" << endl;  }
>>>>>>> баг фикс 3 кейса
                else { break; }
            }
            cout << "введите результаты " << i + 1 << " семестра" << endl;
            for (int j = 0; j < massive_of_semestersandsubjects[i]; j++) {
                cout << endl << "введите название предмета:  ";
                while (true) {
                    getline(cin, this->semester[i].subject[j].name);
                    if (size(this->semester[i].subject[j].name) != 0) {
                        if (size(this->semester[i].subject[j].name) > 30) {
                            cout << endl << "слишком длинное название, допустимая длина - 30 символов" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            this->semester[i].subject[j].name.clear();
                        }
                        else if (do_not_enter_numbers(&this->semester[i].subject[j].name) or do_not_enter_special_symbols(&this->semester[i].subject[j].name)) {
                            if (do_not_enter_numbers(&this->semester[i].subject[j].name)) {
                                cout << "поле не принимает цифры " << endl; 
                                cin.clear();
                            }
                            else {
                                cout << "поле не принимает специальные символы кроме (-) " << endl;
                                cin.clear();
                            }
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
    unsigned short int massive_of_semestersandsubjects[10];
    unsigned short int count_of_dynamic_items =0;

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
    void free_memory() {
        list* current = this->tail;
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
    void print_dynamic() {
        struct list* current = this->tail;
        while (true) {
            cout << endl;
            cout << "|-----------------------------------------------------------------------------------------------------------------------|" <<endl;
            cout << "|"; cout.width(22);  cout.fill(' '); cout << left << " Фамилия имя отчество" << "|";  cout.width(96); cout << current->Data.name; cout << "|" << endl;
            cout << "|"; cout.width(22); cout <<left << " Дата рождения";
            print_date(current->Data.birth_date.day, current->Data.birth_date.month, current->Data.birth_date.year, 86); cout << endl;
            cout << "|"; cout.width(22); cout << left << "Дата поступления";
            print_date(current->Data.admission_date.day, current->Data.admission_date.month, current->Data.admission_date.year, 86); cout << endl;
            cout << "|"; cout.width(22); cout << left << "Институт " << "|"; cout.width(96); cout << current->Data.institut; cout << "|" << endl;
            cout << "|"; cout.width(22); cout << left << "Кафедра" << "|"; cout.width(96); cout << current->Data.department; cout << "|" << endl;
            cout << "|"; cout.width(22); cout << left << "Группа" << "|"; cout.width(96); cout << current->Data.group; cout << "|" << endl;
            cout << "|"; cout.width(22); cout << left << "Зачетная книжка" << "|"; cout.width(96); cout << current->Data.record_book; cout << "|" << endl;
            cout << "|"; cout.width(22); cout << left << "Пол" << "|"; cout.width(96); cout << current->Data.sex; cout << "|" << endl;
            unsigned short int j = 0;
            for (int i = 0; i < current->Data.numbers_of_semester; i++) {
                cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                  Семестр " << i + 1 << "                                                            |" << endl;
                cout << "|-----------------------------------------------------------------------------------------------------------------------|"<<endl;
                cout << "|         Предмет           |О|         Предмет           |О|         Предмет           |О|         Предмет           |О|" << endl;
                cout << "|-----------------------------------------------------------------------------------------------------------------------|";
                cout << endl; cout << "|";
                while (j < current->Data.massive_of_semestersandsubjects[i]) {             
                    cout.width(27); cout << current->Data.semester[i].subject[j].name << "|"; cout.width(1); cout << current->Data.semester[i].subject[j].mark << "|";
                    j++;
                    if (j == 4 or j == 8) { cout << endl << "|"; };
                    if ((j == current->Data.massive_of_semestersandsubjects[i] and current->Data.massive_of_semestersandsubjects[i]<4) or (j == current->Data.massive_of_semestersandsubjects[i] and current->Data.massive_of_semestersandsubjects[i] > 4 and current->Data.massive_of_semestersandsubjects[i] < 8) or (j == current->Data.massive_of_semestersandsubjects[i] and current->Data.massive_of_semestersandsubjects[i] > 8)) {
                        if (current->Data.massive_of_semestersandsubjects[i] < 4) {
                            unsigned short int k = j;
                            for (j; k < 4; k++) {
                                cout.width(29); cout << " " << "|";
                            };                           
                        }
                        else if (current->Data.massive_of_semestersandsubjects[i] < 8) {
                            unsigned short int k = j;
                            for (j; k < 8; k++) {
                                cout.width(29); cout << " " << "|";
                            };
                        }
                        else {
                            unsigned short int k = j;
                            for (j; k < 12; k++) {
                                cout.width(29); cout << " " << "|";
                            }
                        }
                    };                   
                }
                cout << endl;
                j = 0;
            }
            cout << "|-----------------------------------------------------------------------------------------------------------------------|";
            cout <<endl<< "|Примечание: зачет-1; незачет-0; О-оценка                                                                               |";
            cout << endl << "|-----------------------------------------------------------------------------------------------------------------------|";
            cout << endl<<endl;
            if (current->previous != NULL) {
                current = current->previous;
            }
            else { break; }
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
            for (int k = 0; k < 9; k++) {
                stud->massive_of_semestersandsubjects[k] = '\0';
            }
            stud->numbers_of_semester = 0;
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

void Crypt() {
    srand(time(NULL));
    char* pass = new char[64];
    for (int i = 0; i < 64; ++i) {
        switch (rand() % 3) {
        case 0:
            pass[i] = rand() % 10 + '0';
            break;
        case 1:
            pass[i] = rand() % 26 + 'A';
            break;
        case 2:
            pass[i] = rand() % 26 + 'a';
            break;
        }
    }
    pass[64] = '\0';
    string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in students.bin -out students.bin.enc -pass pass:";
    command += pass;
    system(command.c_str());
    if (remove("students.bin") != 0) {
        cout << "[ERROR] - deleting file failed" << endl;
    }
    ofstream file;
    file.open("key.txt", ios::binary);
<<<<<<< HEAD
    file.write(pass, 65);
=======
    file.write(pass, 64);
>>>>>>> баг фикс 3 кейса
    file.close();
    
    command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
    system(command.c_str());
    if (remove("key.txt") != 0) {
        cout << "[ERROR] - deleting file failed" << endl;
    }
    else { cout << endl<< "данные успешно зашифрованы" << endl; }

    
}

void Decrypt() {
    string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
    system(command.c_str());
    if (remove("key.txt.enc") != 0) {
        cout << "[ERROR] - deleting file failed" << endl;
    }

    char* pass = new char[64];
    ifstream file;
    file.open("key.txt", ios::binary);
    file >> pass;
    file.close();
    if (remove("key.txt") != 0) {
        cout << "[ERROR] - deleting file failed" << endl;
    }
    
    command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in students.bin.enc -out students.bin -pass pass:";
    command += pass;
    system(command.c_str());
    if (remove("students.bin.enc") != 0) {
        cout << "[ERROR] - deleting file failed" << endl;
    }
    else { cout << endl << "данные успешно расшифрованы"<<endl; }
    

}
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
            class dynamic_list list;
            fstream file;
            string number_of_record_book;
            file.open("students.bin", fstream::in | fstream::binary);
            if (file.peek() == EOF) { cout << "в файле нет записей" << endl; break; }

            else if (file.is_open()) {
                string b;
                list.create_dynamic_spis(&file, &stud, b);
            }
            else {
                cout << "не удалось открыть файл" << endl;
            }
            file.close();

            cout << "Введите номер зачетной книжки студента, данные которого вы хотите удалить: " ;
            toomanysymbols(&number_of_record_book, 7);
            
            cout << endl;
            unsigned short int chose;
            struct list* current = list.tail;
            bool fl = true;
            while (true) {
                if (current->Data.record_book == number_of_record_book) {
                    cout << "вы хотите удалить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;                 
                    error_numbers(&chose);
                    break;
                }
                else { current = current->previous; }
                if (current == NULL) { cout << "студента с введенным номером зачетной книжки нет" << endl; fl = false;  break; }
            }
            if (fl != false) {
                if (chose != 0) {            
                    if (current->previous != NULL) {
                        current->previous->next = current->next;
                    }
                    if (current->next != NULL) {
                        current->next->previous = current->previous;

                    }
                    else { list.tail = current->previous; }

                    delete current;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    file.open("students.bin", fstream::out | fstream::binary);
                    current = list.tail;
                    while (current != NULL) {
                        file << current->Data.name << "|" << current->Data.birth_date.day << "|" << current->Data.birth_date.month << "|" << current->Data.birth_date.year << "|" << current->Data.admission_date.day << "|" << current->Data.admission_date.month << "|" << current->Data.admission_date.year << "|" << current->Data.institut << "|" << current->Data.department << "|" << current->Data.group << "|" << current->Data.record_book << "|" << current->Data.sex << "|";
                        for (int i = 0; i < current->Data.numbers_of_semester; i++) {
                            file << "{" << i << "}";
                            for (int j = 0; j < current->Data.massive_of_semestersandsubjects[i];j++) {
                                file << current->Data.semester[i].subject[j].name << "|" << current->Data.semester[i].subject[j].mark << "|";
                            }
                        };
                        file << "\n";
                        current = current->previous;
                    }
                    file.close();
                    cout << "Данные успешно удалены" << endl;
                    list.count_of_dynamic_items--;
                }
            }
            current = list.tail;
            list.free_memory();
            break;
        }

        case 3:
        {
            struct struct_student stud;
            class dynamic_list list;
            string number_of_record_book;
            unsigned short int chose;
            fstream file;
            file.open("students.bin", fstream::in | fstream::binary);
            if (file.peek() == EOF) { cout << "в файле нет записей" << endl; break; }
            else if (file.is_open()) {
                string b;
                list.create_dynamic_spis(&file, &stud, b);
            }
            else {
                cout << "не удалось открыть файл" << endl;
            }
            file.close();

<<<<<<< HEAD
            cout << "Введите номер зачетной книжки студента, данные которого вы хотите удалить: ";
            toomanysymbols(&number_of_record_book, 7);
            cout << "выберите что изменить в данных студнета:" << endl << "0-отменить" << endl << "1-изменить все данные студента" << endl << "2-изменить имя студента" << endl << "3-изменить дату рождения студента" << endl;
            cout << "4-изменить дату поступления студента" << endl << "5-изменить институт, кафедру и группу студента " << endl << "6-изменить пол студента " << endl << "7-изменить номер зачетной книжки студента ";
=======
            cout << "Введите номер зачетной книжки студента, данные которого вы хотите изменть: ";
            toomanysymbols(&number_of_record_book, 7);
            cout << "выберите что изменить в данных студнета:" << endl << "0-отменить" << endl << "1-изменить все данные студента" << endl << "2-изменить имя студента" << endl << "3-изменить дату рождения студента" << endl;
            cout << "4-изменить дату поступления студента" << endl << "5-изменить институт, кафедру и группу студента " << endl << "6-изменить пол студента " << endl << "7-изменить номер зачетной книжки студента " << endl;
>>>>>>> баг фикс 3 кейса
            cout << "8-изменить данные предмета выбранного семестра" << endl;
            unsigned short int v;
            error_numbers(&v);
            struct list* current = list.tail;
            bool fl = true;
            while (true) {
                if (current->Data.record_book == number_of_record_book) {
<<<<<<< HEAD
                    cout << "вы хотите удалить данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
=======
                    cout << "вы хотите изменть данные студента " << current->Data.name << endl << "введите  0, чтобы отменить и любое число чтобы продолжить " << endl;
>>>>>>> баг фикс 3 кейса
                    error_numbers(&chose);
                    break;
                }
                else { current = current->previous; }
                if (current == NULL) { cout << "студента с введенным номером зачетной книжки нет" << endl; fl = false;  break; }
            }
<<<<<<< HEAD
            if (fl ==false) { v = 0; }
=======
            if (fl ==false or chose == 0) { v = 0; }
>>>>>>> баг фикс 3 кейса

            switch (v) {
            case 0: {
                struct list* current;
                current = list.tail;
                list.free_memory();
                break;
            }

            case 1: {
             cout << endl;
             int j = 0;
             class student student;
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
             for (int i = 0; i < current->Data.numbers_of_semester; i++) {
                 for (int j = 0; j < current->Data.massive_of_semestersandsubjects[i];j++) {
                     current->Data.semester[i].subject[j] = stud.semester[i].subject[j];
                 }
             }
             from_dynamic_spis_to_file(&file, &list.tail , & current->Data.numbers_of_semester);
             cout << "Данные успешно изменены" << endl;
               
             current = list.tail;
             list.free_memory();
             break;
            }

            case 2: {              
             cout << endl;            
                
             string name;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "введите Ф.И.О. студента(используйте пробелы для разграничения инициалов)" << endl;
            while (true) {

                getline(cin,name);
                if (size(name) != 0) {
                    if (size(name) > 100) {
                        cout << endl << "слишком длинное название, допустимая длина - 100 символов" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        name.clear();
                    }
                    else {
                        if (do_not_enter_numbers(&name)) { cout << "поле не принимает цифры " << endl; cin.clear(); }
                        else if (do_not_enter_special_symbols(&name)) {
                            cout << "поле не принимает специальные символы кроме (-) " << endl;
                            cin.clear();
                        }
                        else {
                            break;
                        }
                    }
                }

            }
             current->Data.name = name;
             from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
             cout << "Данные успешно изменены" << endl;
             current = list.tail;
             list.free_memory();
             break;
            }

            case 3: {
                cout << endl;              
                struct Date date;
                cout << endl << "введите дату рождения студента" << endl;
                enter_date(&date);
                current->Data.birth_date = date;
                from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
                cout << "Данные успешно изменены" << endl;
             
                current = list.tail;
                list.free_memory();
                break;
            }

            case 4: {
                cout << endl;
                struct Date date;
                cout << endl << "введите дату поступления студента" << endl;
                enter_date(&date);
                current->Data.admission_date = date;
                from_dynamic_spis_to_file(&file, &list.tail,&current->Data.numbers_of_semester);
                cout << "Данные успешно изменены" << endl;

                current = list.tail;
                list.free_memory();
                break;
            }

            case 5: {
                string inst;
                string dep;
                string group;
                while (true) {
                    cout << endl << "введите институт студента" << endl;
                    toomanysymbols(&inst, 5);
                    if (do_not_enter_numbers(&inst)) { cout << "поле не принимает цифры " << endl; cin.clear(); }
                    else if (do_not_enter_special_symbols(&inst)) {
                        cout << "поле не принимает специальные символы кроме (-) " << endl;
                        cin.clear();
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    cout << endl << "введите кафедру студента" << endl;
                    toomanysymbols(&dep, 5);
                    if (do_not_enter_special_symbols(&dep)) {
                        cout << "поле не принимает специальные символы кроме (-) " << endl;
                        cin.clear();
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    cout << endl << "введите группу студента" << endl;
                    toomanysymbols(&group, 10);
                    if (do_not_enter_special_symbols(&group)) {
                        cout << "поле не принимает специальные символы кроме (-) " << endl;
                        cin.clear();
                    }
                    else {
                        break;
                    }
                }
                current->Data.institut = inst;
                current->Data.department = dep;
                current->Data.group = group;
                from_dynamic_spis_to_file(&file, &list.tail,&current->Data.numbers_of_semester);
                cout << "Данные успешно изменены" << endl;
                current = list.tail;
                list.free_memory();
                break;
            }

            case 6:
            {
                string sex;
                while (true) {
                    toomanysymbols(&sex, 1);
                    if (sex != "м" and sex != "ж") {
                        cout << "поле принимает значение м или ж" << endl;
                        sex.clear();
                    }
                    else { break; }
                }
                current->Data.sex = sex;
                from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
                cout << "Данные успешно изменены" << endl;
                current = list.tail;
                list.free_memory();
                break;
            }
            case 7: {
                string recordbook;
                cout << endl << "введите номер зачетной книжки студента" << endl;
                while (true) {
<<<<<<< HEAD
                    cout << endl << "введите номер зачетной книжки студента" << endl;
=======
>>>>>>> баг фикс 3 кейса
                    toomanysymbols(&recordbook, 7);
                    if (do_not_enter_special_symbols(&recordbook)) {
                        cout << "поле не принимает специальные символы кроме (-) " << endl;
                        cin.clear();
                    }
                    else {
                        break;
                    }
                }
                current->Data.record_book = recordbook;
                from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
                cout << "Данные успешно изменены" << endl;
                current = list.tail;
                list.free_memory();
                break;
            }
            case 8: {
                unsigned short int semestr_number;
                string name;
                unsigned short mark;
                bool flag = true;
                int j = 0;
                while (true) {
                    cout << "введите номер семестра, предмет которого вы хотите изменить:";
                    error_numbers(&semestr_number);
                    if (semestr_number > current->Data.numbers_of_semester or semestr_number <= 0) {
                        cout << "у студента " << current->Data.name << " нет такого количества семестров. Допустимое количество семестров: " << current->Data.numbers_of_semester << endl;
                    }
                    else { break; }
                }
<<<<<<< HEAD

                while (flag == true) {
                    cout << "данные о предметах в семестре номер " << semestr_number << ":" << endl;
                    for (int j = 0; j < current->Data.massive_of_semestersandsubjects[semestr_number - 1]; j++) {
                        cout << "предмет: " << current->Data.semester[semestr_number - 1].subject[j].name << " оценка: ";
                        cout << current->Data.semester[semestr_number - 1].subject[j].mark << endl;
                    }
                    cout << "введите название предмета, данные которого вы хотите изменить" << endl;
                    cout << endl << "введите название предмета:  ";
                    while (true) {
                        getline(cin,name);
                        if (size(name) != 0) {
                            if (size(name) > 30) {
                                cout << endl << "слишком длинное название, допустимая длина - 30 символов" << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                name.clear();
                            }
                            else if (do_not_enter_numbers(&name) or do_not_enter_special_symbols(&name)) {
                                if (do_not_enter_numbers(&name)) {
                                    cout << "поле не принимает цифры " << endl;
                                    cin.clear();
                                }
                                else {
                                    cout << "поле не принимает специальные символы кроме (-) " << endl;
                                    cin.clear();
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                    
                    for ( j = 0; j < current->Data.massive_of_semestersandsubjects[semestr_number - 1]; j++) {
                        if (name == current->Data.semester[semestr_number - 1].subject[j].name) { fl = false; break; }
                        else { cout << "введенного вами предмета нет" << endl; }
                    }
                    if (fl == false) {break; }
                    cout << "введите новые дынные о предмете"<< endl;
                    cout << endl << "введите название предмета:  ";
                    while (true) {
                        getline(cin, name);
                        if (size(name) != 0) {
                            if (size(name) > 30) {
                                cout << endl << "слишком длинное название, допустимая длина - 30 символов" << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                name.clear();
                            }
                            else if (do_not_enter_numbers(&name) or do_not_enter_special_symbols(&name)) {
                                if (do_not_enter_numbers(&name)) {
                                    cout << "поле не принимает цифры " << endl;
                                    cin.clear();
                                }
                                else {
                                    cout << "поле не принимает специальные символы кроме (-) " << endl;
                                    cin.clear();
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                    cout << endl << "введите оценку за предмет(цифрой, зачет-1, незачет-0):  ";
                    while (true) {
                        cin >> mark;
                        if (cin.fail()) {
                            cout << endl << "ошибка ввода, введите число" << endl;
                            cin.clear();
                            mark = '\0';
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (mark > 5 or mark < 0) {
                            cout << endl << "ошибка, оценка может принимать значения от 0 до 5" << endl;

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            mark = '\0';
                        }
                        else {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                    }
                    current->Data.semester[semestr_number - 1].subject[j].name = name;
                    current->Data.semester[semestr_number - 1].subject[j].mark = mark;
                    from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;
                    current = list.tail;
                    list.free_memory();
                }
=======

                
                    cout << "данные о предметах в семестре номер " << semestr_number << ":" << endl;
                    for (int j = 0; j < current->Data.massive_of_semestersandsubjects[semestr_number - 1]; j++) {
                        cout << "предмет: " << current->Data.semester[semestr_number - 1].subject[j].name << " оценка: ";
                        cout << current->Data.semester[semestr_number - 1].subject[j].mark << endl;
                    }
                    cout << "введите название предмета, данные которого вы хотите изменить" << endl;
                    cout << endl << "введите название предмета:  ";
                    while (true) {
                        getline(cin,name);
                        if (size(name) != 0) {
                            if (size(name) > 30) {
                                cout << endl << "слишком длинное название, допустимая длина - 30 символов" << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                name.clear();
                            }
                            else if (do_not_enter_numbers(&name) or do_not_enter_special_symbols(&name)) {
                                if (do_not_enter_numbers(&name)) {
                                    cout << "поле не принимает цифры " << endl;
                                    cin.clear();
                                }
                                else {
                                    cout << "поле не принимает специальные символы кроме (-) " << endl;
                                    cin.clear();
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                    
                    for ( j = 0; j < current->Data.massive_of_semestersandsubjects[semestr_number - 1]; j++) {
                        if (name == current->Data.semester[semestr_number - 1].subject[j].name) { fl = false; break; }                      
                    }
                    if (fl == true) {cout << "введенного вами предмета нет" << endl; break; }
                else {
                    cout << "введите новые дынные о предмете" << endl;
                    cout << endl << "введите название предмета:  ";
                    while (true) {
                        getline(cin, name);
                        if (size(name) != 0) {
                            if (size(name) > 30) {
                                cout << endl << "слишком длинное название, допустимая длина - 30 символов" << endl;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                name.clear();
                            }
                            else if (do_not_enter_numbers(&name) or do_not_enter_special_symbols(&name)) {
                                if (do_not_enter_numbers(&name)) {
                                    cout << "поле не принимает цифры " << endl;
                                    cin.clear();
                                }
                                else {
                                    cout << "поле не принимает специальные символы кроме (-) " << endl;
                                    cin.clear();
                                }
                            }
                            else {
                                break;
                            }
                        }
                    }
                    cout << endl << "введите оценку за предмет(цифрой, зачет-1, незачет-0):  ";
                    while (true) {
                        cin >> mark;
                        if (cin.fail()) {
                            cout << endl << "ошибка ввода, введите число" << endl;
                            cin.clear();
                            mark = '\0';
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (mark > 5 or mark < 0) {
                            cout << endl << "ошибка, оценка может принимать значения от 0 до 5" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            mark = '\0';
                        }
                        else {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                    }
                    current->Data.semester[semestr_number - 1].subject[j].name = name;
                    current->Data.semester[semestr_number - 1].subject[j].mark = mark;
                    from_dynamic_spis_to_file(&file, &list.tail, &current->Data.numbers_of_semester);
                    cout << "Данные успешно изменены" << endl;
                }
                current = list.tail;
                list.free_memory();
                    
                
>>>>>>> баг фикс 3 кейса
                break;
                
            }
            default: {
                cout << "такой команды нет" << endl;
                struct list* current = list.tail;
                list.free_memory();
                break;
            }

            }
            break;
        }
        
        case 4: {

            struct struct_student stud;
            fstream file;
            class dynamic_list list;

            file.open("students.bin", fstream::in | fstream::binary);
            if (file.peek() == EOF) { cout << "в файле нет записей" << endl; break; }
            else if (file.is_open()) {
                string b;
                list.create_dynamic_spis(&file, &stud, b);
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
            search_with_interval(&list.tail, interval_start, interval_end);
            struct list* current = list.tail;
            if (list.tail == NULL) {
                cout << "студентов, удовлетворяющих условию нет" << endl;
                current = list.tail;
                list.free_memory();
                break;
            }
            else {
                list.print_dynamic();
                current = list.tail;
                list.free_memory();
                break;
            }
        }
        
        case 5: {
            struct struct_student stud;
            class dynamic_list list;
            fstream file;
            dynamic_list list1;
            file.open("students.bin", fstream::in | fstream::binary);
            if (file.peek() == EOF) { cout << "в файле нет записей" << endl; break; }
            else if (file.is_open()) {
                string b;
                list.create_dynamic_spis(&file, &stud, b);
            }
            else {
                cout << "не удалось открыть файл" << endl;
                break;
            }
            file.close();
            struct list* current = list.tail;
            
            list.print_dynamic();

            list.free_memory();
            break;
        }
           
        case 6: {
            Crypt();  
            break;
            
        }
        case 7:{
            Decrypt();
            break;
        }
        default:       
            cout << "такой команды нет" << endl;
            break;
        }
        cout << endl <<"введие 0 чтобы закрыть программу или любое число чтобы продолжить" << endl;
        error_numbers(&kill_app);
        if (kill_app == 0) {
            break;
        }
    }
}

