  
#include <string.h>
#include <stdio.h>

struct SinhVien{
    char name[50];
    int age;
    char phoneNumber[50];
};
struct Class {
    struct SinhVien student[5];
    
};
void dltItem(int id,struct Class *study);
int main(int argc, const char * argv[]) {
    struct SinhVien user01={"AAAA", 18,"0145764325"};
    struct SinhVien user02={"BBBB", 22,"0765324325"};
    struct SinhVien user03={"CCCC", 20,"0455766753"};
    struct SinhVien user04={"DDDD", 21,"0913455325"};
    struct SinhVien user05={"EEEE", 23,"0736513953"};
    struct Class study={
        .student={user01,user02,user03,user04,user05}
    };
    for(int i=0;i<5;i++){
        printf("ID : %d\n",i+1);
        printf("Name : %s\n",study.student[i].name);
        printf("Age : %d\n",study.student[i].age);
        printf("Phone Nmber : %s\n",study.student[i].phoneNumber);
        printf("\n");
    }
    int id;
    printf("Input the index to delete : ");
    scanf("%d",&id);
    dltItem(id, &study);
    for(int i=0;i<4;i++){
        printf("ID : %d\n",i+1);
        printf("Name : %s\n",study.student[i].name);
        printf("Age : %d\n",study.student[i].age);
        printf("Phone Nmber : %s\n",study.student[i].phoneNumber);
        printf("\n");
    }
    return 0;
}
void dltItem(int id,struct Class *study){
    if(id>0&&id<5){
        for(int i=id-1;i<5;i++){
            strcpy(study->student[i].name,study->student[i+1].name);
            strcpy(study->student[i].phoneNumber,study->student[i+1].phoneNumber);
            study->student[i].age=study->student[i+1].age;
        }
    }
}
