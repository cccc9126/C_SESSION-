#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct SinhVien{
    char name[50];
    int age;
    char phoneNumber[50];
};
void sort(struct SinhVien *student);
int main(int argc, const char * argv[]) {
    struct SinhVien student[5]={
        {"bbb", 18, "0145764325"},
        {"dddd", 22, "0765324325"},
        {"AAA", 20, "0455766753"},
        {"tttt", 21, "0913455325"},
        {"ccc", 23, "0736513953"}
    };
    sort(&student);
    for(int ii=0;ii<5;ii++){
        printf("ID : %d\n",ii+1);
        printf("Name : %s\n",student[ii].name);
        printf("Age : %d\n",student[ii].age);
        printf("Phone Nmber : %s\n",student[ii].phoneNumber);
        printf("\n");
        
    }
    return 0;
}
void sort(struct SinhVien *student){
    for(int i = 0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(strcmp(student[i].name, student[i+1].name)>0){
                struct SinhVien temp = student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
}
