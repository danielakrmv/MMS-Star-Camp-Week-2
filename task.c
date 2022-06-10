#include <stdio.h>
#include <stdarg.h>

void print_template(char* template_str, ...){
    va_list varg_ptr;
    va_start(varg_ptr, template_str);
    for(char* i = template_str; *i != '\0'; i++){
        if(*i == '~'){
            printf("%s", va_arg(varg_ptr, char*));
        }else{
            printf("%c", *i);
        }


    }
    va_end(varg_ptr);
}

void store_template(char* template_str, char* destination_str, ...){
    va_list varg_ptr;
    va_start(varg_ptr, destination_str);
    for(char* i = template_str; *i != '\0'; i++){
        if(*i == '~'){
            destination_str = va_arg(varg_ptr, char*);
            printf("%s", destination_str);
        }else{
            printf("%c", *i);
        }
    }
    va_end(varg_ptr);
}

int main(){
    print_template("Hello i am ~\n", "Ivan");
    print_template("Hello ~, my name is ~\n", "Ivan", "Georgi\n", NULL);
    print_template("~ ~ ~ ~", "A", "B", "C", "D\n", NULL);
    char replaced_str[1000];
    store_template("Hello ~, I AM ~", replaced_str, "IVAN", "Pesho");
}