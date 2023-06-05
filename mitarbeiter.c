#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define NAME_MAX 20

typedef enum {
    DEP_HR,
    DEP_MARKETING,
    DEP_MANAGEMENT,
} department_t;

typedef struct {
    char first_name[NAME_MAX+1];
    char last_name[NAME_MAX+1];
    float salary;
    department_t department;
} employee_t;

typedef struct __node_t__ {
    employee_t employee;
    struct __node_t__* left;
    struct __node_t__* right;
} node_t;

const char* get_department_str(department_t department){
    switch(department){
        case DEP_HR: return "Human resources";
        case DEP_MANAGEMENT: return "Marketing";
        case DEP_MARKETING: return "Management";
        default: return "unknown";
    }
}

void printemp(const employee_t* employee){
    printf("Name: %s %s \n", employee->first_name, employee->last_name);
    printf(        "Salary: %.2f Euronen\n", employee->salary);
    printf(    "department %s\n\n", get_department_str(employee->department));
}

void adjust_salary(employee_t* employee, float new_salary){
    printf("Before:");
    printemp(employee);
    employee->salary= new_salary;
    printf("After:");
    printemp(employee);
}

void transfer_employee(employee_t* employee, department_t new_department){
    printf("Before transfer:");
    printemp(employee);
    if (employee->department == new_department){
        printf("%s is already in %s\n", employee->first_name, get_department_str(employee->department));
    }else{
        employee->department=new_department;
    }
    printf("After transfer:");
    printemp(employee);
    return;
}

int adjust_last_name(employee_t* employee, const char* new_last_name){
    printf("Beforename change:");
    printemp(employee);
    if(strlen(new_last_name)> NAME_MAX){
        printf("New last name is too long");
        return 0;
    }
    strcpy(employee->last_name, new_last_name);
    printf("After name change:");
    printemp(employee);
}

void print_employees(const employee_t* employees, unsigned int count){
    for(unsigned int i =0; i<count; i++){
        printemp(&employees[i]);
    }
}

// i)
void remove_employee(employee_t* employees, unsigned int* count, unsigned int idx){
    //Validate the index
    if(idx>= *count){
        return;
    }

    //do not use memcpy(), because areas overlap
    *count -=1;
    memmove(&employees[idx], &employees[idx+1], (*count - idx)*sizeof(employee_t));
}

// i) alternative
void remove_employee_swap(employee_t* employees, unsigned int* count, unsigned int idx){
    //Validate the index
    if(idx>= *count){
        return;
    }

    //do not use memcpy(), because areas overlap
    *count -=1;
    employees[idx]= employees[*count];
}

// j)
node_t* alloc_node(const employee_t* employee){
    node_t* node = malloc(sizeof(node_t));

    if(!node){
        printf("Failed to allocate memory");
        exit(-1);
    }
    *node = (node_t){
        .employee = *employee,
        .left = NULL,
        .right = NULL
    };
    return node;
}

// j)
void insert_into_tree(node_t** root, const employee_t* employee){
    if (!*root){
        *root = alloc_node(employee);
    }else if (employee->salary <= (*root)->employee.salary){
        insert_into_tree(&(*root)->left, employee);
    }else{
        insert_into_tree(&(*root)->right, employee);
    }
}

// j)
void insert_into_tree_rdm_salary(
    node_t** root, 
    const char* first_name,
    const char* last_name, 
    department_t department
){
    if((strlen(first_name) > NAME_MAX) || (strlen(last_name)>NAME_MAX)){
        return ;
    }

    employee_t employee;
    strcpy(employee.first_name, first_name);
    strcpy(employee.last_name, last_name);
    employee.salary = (rand()% 1000000)/100.0;
    employee.department = department;

    insert_into_tree(root, &employee);
}

// k)
void print_tree_sorted(const node_t* root){
    if(!root){
        return;
    }
    print_tree_sorted(root->left);
    printemp(&root->employee);
    print_tree_sorted(root->right);
}

// k)
void free_tree(node_t* root){
    if(!root){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

//14a)
void checked_write(FILE* f, const void* ptr, size_t len){
    if(fwrite(ptr, len, 1, f) != 1){
        printf("Failed to write");
        exit(EXIT_FAILURE);
    }
}

void checked_write_string(FILE* f, const char* str){
    size_t len = strlen(str);

    if(len > __UINT8_MAX__){
        printf("String too long\n");
        exit(EXIT_FAILURE);
    };
    __UINT8_TYPE__ len_u8 = (__UINT8_TYPE__)len;

    checked_write(f, &len_u8, sizeof(__UINT8_TYPE__));
    checked_write(f, str, len);
}

void store_employees(const employee_t* employees, size_t count, const char* file_path){
    //create file
    FILE* f =fopen(file_path, "wb"); //opens an empty binary file for writing
    if(!f){
        printf("failed to create file\n");
        exit(EXIT_FAILURE);
    }

    //write the number of employees as u32
    if(count > __UINT32_MAX__){
        printf("Too many employees\n");
        exit(EXIT_FAILURE);
    }
    __UINT32_TYPE__ count_u32 = (__UINT32_TYPE__)count;
    checked_write(f, &count_u32, sizeof(__UINT32_TYPE__));

    for(size_t i=0; i<count;i++){
        const employee_t* employee = &employees[i];
        checked_write_string(f, employee->first_name);
        checked_write_string(f, employee->last_name);

        checked_write(f, &employee->salary, sizeof(float));

        __UINT8_TYPE__ department_u8 = (__UINT8_TYPE__)employee->department;
        checked_write(f, &department_u8, sizeof(__UINT8_TYPE__));
    }

    fclose(f);


}

void store_load_employees(const employee_t* employees, size_t count){
    store_employees(employees, count, "employees.bin");

    employee_t* loaded_employees;
    size_t loaded_count;

    load_employees(&loaded_employees, loaded_count);

    print_employees(loaded_employees);
}


/*
*
*
*
*/
int main(void){
    srand(time(NULL));
    employee_t max = {
        .first_name = "Max",
        .last_name = "Mustermax",
        .salary = 4500.59,
        .department = DEP_HR
    };

    employee_t employees[] = {
        {
            .first_name= "Harry",
            .last_name= "Potter",
            .salary= 6200.38,
            .department= DEP_MARKETING,
        },
         {
            .first_name= "Draco",
            .last_name= "Malfoy",
            .salary= 3300.20,
            .department= DEP_HR,
        },
         {
            .first_name= "Ron",
            .last_name= "Weasley",
            .salary= 5900.24,
            .department= DEP_MARKETING,
        },
         {
            .first_name= "Hermiioioioone",
            .last_name= "Granger",
            .salary= 60200.38,
            .department= DEP_MANAGEMENT,
        }
    };
    unsigned int count = 4;

    /*printemp(&max);

    adjust_salary(&max, 4600.50);
    transfer_employee(&max, DEP_HR);
    adjust_last_name(&max, "Musterer");
    print_employees(employees, count);

    printf("Initial:\n");
    print_employees (employees, count);

    printf("After Remove\n\n");
    remove_employee(employees, &count, 1);
    print_employees (employees, count);

    printf("After swap remove\n\n");
    remove_employee_swap(employees, &count, 0);
    print_employees (employees, count); */

    node_t* root = NULL;
    insert_into_tree_rdm_salary(&root, "Lily", "Potter", DEP_HR);
    insert_into_tree_rdm_salary(&root, "James", "Potter", DEP_HR);
    insert_into_tree_rdm_salary(&root, "Sirius", "Black", DEP_HR);
    insert_into_tree_rdm_salary(&root, "Peter", "Pettigrew", DEP_MARKETING);
    insert_into_tree_rdm_salary(&root, "Molly", "Weasley", DEP_MANAGEMENT);
    insert_into_tree_rdm_salary(&root, "Arthur", "Weasley", DEP_HR);
    insert_into_tree_rdm_salary(&root, "Albus", "Dumbledore", DEP_MANAGEMENT);

    printf("=========\n");
    print_tree_sorted(root);
    free_tree(root);


    //new c
    employee_t io_employees[]= {
        {
            .first_name = "wetg",
            .last_name = "rrj",
            .salary = 12,
            .department = DEP_MARKETING
        },
         {
            .first_name = "werw",
            .last_name = "zkn",
            .salary = 324,
            .department = DEP_HR
        },
         {
            .first_name = "rtbtb",
            .last_name = "mz",
            .salary = 25,
            .department = DEP_HR
        },
         {
            .first_name = "wrtv",
            .last_name = "mzgrg",
            .salary = 4534,
            .department = DEP_MANAGEMENT
        }
    };

    return 0;

}
