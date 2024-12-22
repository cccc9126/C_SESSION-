#include <stdio.h>
#include <string.h>

struct SinhVien{
    char name[50];
    int age;
    char phoneNumber[20];
};
void printStruct(struct SinhVien*user,int *n);
void addItem(struct SinhVien*user,int *n);
void repairItem(struct SinhVien*user,int *n);
void dltItem(struct SinhVien*user,int *n);
void search(struct SinhVien*user,int *n);
void sort(struct SinhVien*user,int *n);
int main(int argc, const char * argv[]) {
    int choice;
    int n=4;
    struct SinhVien user[10]={
        {"BBBB",18,"0936757745"},
        {"AAAA",22,"0132745184"},
        {"DDDD",29,"0813641344"},
        {"EEEE",20,"0817354843"},
        {"CCCC",19,"0987135432"}
    };
    do {
        printf("\tMENU\n");
        printf("1. Hiển thị danh sách sinh viên\n");
        printf("2. Thêm sinh viên\n");
        printf("3. Sửa thông tin sinh viên\n");
        printf("4. Xóa sinh viên\n");
        printf("5. Tìm kiếm sinh viên\n");
        printf("6. Sắp xếp danh sách sinh viên\n");
        printf("7. Thoát\n");
        printf("Hãy nhập lựa chọn của bạn :");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printStruct(user,&n);
                break;
            case 2:
                addItem(user,&n);
                break;
            case 3:
                repairItem(user,&n);
                break;
            case 4:
                dltItem(user,&n);
                break;
            case 5:
                search(user,&n);
                break;
            case 6:
                sort(user,&n);
            default:
                break;
        }
    } while (choice!=7);
    
    return 0;
}
void printStruct(struct SinhVien*user,int *n){
    printf("\n");
    for(int i=0;i<=*n;i++){
        printf("ID : %d\n",i+1);
        printf("NAME : %s\n",user[i].name);
        printf("AGE : %d\n",user[i].age);
        printf("PHONE NUMBER : %s\n",user[i].phoneNumber);
        printf("\n----------------\n");
    }
}
void addItem(struct SinhVien*user,int *n){
    char nameSinhVien[50];
    int ageSinhVien;
    char phoneSinhVien[50];
    getchar();
    printf("Hãy nhập tên cho sinh viên : ");
    fgets(nameSinhVien, 50, stdin);
    strcpy(user[*n+1].name, nameSinhVien);
    user[*n+1].name[strcspn(user[*n+1].name, "\n")]='\0';
    printf("Hãy nhập tuổi cho sinh viên : ");
    scanf("%d",&ageSinhVien);
    user[*n+1].age=ageSinhVien;
    fflush(stdin);
    printf("Hãy nhập số điện thoại cho sinh viên :");
    fgets(phoneSinhVien, 50, stdin);
    strcpy(user[*n+1].phoneNumber, phoneSinhVien);
    user[*n+1].phoneNumber[strcspn(user[*n+1].phoneNumber, "\n")]='\0';
    fflush(stdin);
    *n+=1;
}
void repairItem(struct SinhVien*user,int *n){
    printf("Hãy nhập id để sửa : ");
    int id;
    scanf("%d",&id);
    fflush(stdin);
    id-=1;
    printf("Hãy nhập tên mới cho sinh viên :");
    char name[50];
    fgets(name, 50, stdin);
    strcpy(user[id].name, name);
    user[id].name[strcspn(user[id].name, "\n")]='\0';
    printf("Hãy nhập tuổi mới cho sinh viên : ");
    int age;
    scanf("%d",&age);
    user[id].age=age;
    fflush(stdin);
    printf("Hãy nhập số điện thoại mới cho sinh viên : ");
    char phone[20];
    fgets(phone,20,stdin);
    strcpy(user[id].phoneNumber, phone);
    user[id].phoneNumber[strcspn(user[id].phoneNumber, "\n")]='\0';
}
void dltItem(struct SinhVien*user,int *n){
    getchar();
    printf("Hãy nhập ID bạn muốn xóa : ");
    int id;
    scanf("%d",&id);
    id-=1;
    for(int i=id;i<*n;i++ ){
        struct SinhVien temp = user[i];
        user[i]=user[i+1];
        user[i+1]=temp;
    }
    *n-=1;
}
void search(struct SinhVien*user,int *n){
    printf("Hãy nhập ID bạn muốn tìm : ");
    int id;
    scanf("%d",&id);
    fflush(stdin);

    printf("\nID : %d\n",id);
    printf("NAME : %s\n",user[id].name);
    printf("AGE : %d\n",user[id].age);
    printf("PHONE NUMBER : %s\n\n",user[id].phoneNumber);
}
void sort(struct SinhVien*user,int *n){
    for(int i = 0;i<*n-1;i++){
        for(int j =0;j<*n-1-i;j++){
            if(strcmp(user[j].name, user[j+1].name)>0){
                struct SinhVien temp = user[j];
                user[j]=user[j+1];
                user[j+1]=temp;
            }
        }
    }
}
