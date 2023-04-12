#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define sl 100
struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef Date date;
struct NhanVien
{
    int msnv;
    char ho[20];
    char ten[20];
    date namsinh;
    char noisinh[100];
    char diachi[200];
    float luong;
    date ngayvao;
};
typedef NhanVien nhanvien;
struct DanhSach
{
    nhanvien a[sl];
    int n;
};
typedef DanhSach danhsach;

void nhapngaythang(date &ntn);

nhanvien nhap1nv(nhanvien &x)
{
    printf("Nhap MSNV: ");
    scanf("%d", &x.msnv);
    printf("Nhap ho: ");
    fflush(stdin);
    fgets(x.ho, 20, stdin);
    x.ho[strcspn(x.ho, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
    printf("Nhap ten: ");
    fgets(x.ten, 20, stdin);
    x.ten[strcspn(x.ten, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &x.namsinh.ngay, &x.namsinh.thang, &x.namsinh.nam);
    printf("Nhap noi sinh: ");
    fflush(stdin);
    fgets(x.noisinh, 100, stdin);
    x.noisinh[strcspn(x.noisinh, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
    printf("Nhap dia chi: ");
    fgets(x.diachi, 200, stdin);
    x.diachi[strcspn(x.diachi, "\n")] = '\0'; // Xóa ký tự '\n' cuối chuỗi
    printf("Nhap luong: ");
    scanf("%f", &x.luong);
    printf("Nhap ngay vao lam (dd mm yyyy): ");
    scanf("%d %d %d", &x.ngayvao.ngay, &x.ngayvao.thang, &x.ngayvao.nam);
    return x;
}
void xuat1nv(nhanvien x)
{

    // In đường viền trên cùng
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");

    // In tiêu đề bảng
    printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");

    // In đường viền phân cách giữa tiêu đề và nội dung
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");

    // In thông tin của nhân viên
    printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", x.msnv, strcat(strcat(x.ho, " "), x.ten), x.namsinh.ngay, x.namsinh.thang, x.namsinh.nam, x.noisinh, x.diachi, x.luong);

    // In đường viền cuối cùng
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
}

void xuatngaythang(date ntn);

void xuatdanhsach(danhsach ds)
{
    // In đường viền trên cùng
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");

    // In tiêu đề bảng
    printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");

    // In đường viền phân cách giữa tiêu đề và nội dung
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");

    // In nội dung danh sách nhân viên
    for (int i = 0; i < ds.n; i++)
    {
        printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", ds.a[i].msnv, strcat(strcat(ds.a[i].ho, " "), ds.a[i].ten), ds.a[i].namsinh.ngay, ds.a[i].namsinh.thang, ds.a[i].namsinh.nam, ds.a[i].noisinh, ds.a[i].diachi, ds.a[i].luong);
    }

    // In đường viền cuối cùng
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
}

void nhapdanhsach(danhsach &ds)
{
    // Nhập số lượng nhân viên trong danh sách
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &ds.n);

    // Nhập thông tin của từng nhân viên trong danh sách
    for (int i = 0; i < ds.n; i++)
    {
        printf("Nhap thong tin nhan vien thu %d:\n", i + 1);
        nhap1nv(ds.a[i]);
    }
}

int timten(danhsach ds)
{
    int check = -1;
    nhanvien x;

    // Nhập tên cần tìm từ bàn phím
    printf("Nhap ten cua nhan vien can tim: ");
    char c[19];
    scanf("%19s", c);
    // Xóa ký tự xuống dòng ở cuối chuỗi nếu có
    if (c[strlen(c) - 1] == '\n')
    {
        c[strlen(c) - 1] = '\0';
    }
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
    printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
    // Duyệt danh sách nhân viên và in thông tin của những nhân viên có tên trùng khớp với tên đã nhập
    for (int i = 0; i < ds.n; i++)
    {
        if (strcmp(ds.a[i].ho, c) == 0 || strcmp(ds.a[i].ten, c) == 0)
        {
            x = ds.a[i];
            printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", x.msnv, strcat(strcat(x.ho, " "), x.ten), x.namsinh.ngay, x.namsinh.thang, x.namsinh.nam, x.noisinh, x.diachi, x.luong);
            check = 0;
        }
    }

    // Nếu không tìm thấy nhân viên, in thông báo tương ứng
    if (check == -1)
    {
        printf("|%92s|\n", "Khong tim thay nhan vien.");
    }
    // In đường viền cuối cùng của bảng
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
}
void themnv(danhsach &ds, nhanvien x, int k)
{
    if (ds.n >= k)
    {
        printf("Danh sach da day, khong the them nhan vien!\n");
        return;
    }
    ds.a[ds.n] = x;
    ds.n++;
}

int timMSNV(danhsach ds, int d)
{
    int check = -1;
    nhanvien x;
    printf("Nhap ma so nhan vien can tim: ");
    int manv;
    scanf("%d", &manv);
    for (int i = 0; i < d; i++)
    {
        if (ds.a[i].msnv == manv)
        {
            x = ds.a[i];
            xuat1nv(x);
            break;
        }
    }
    printf("Khong tim thay nhan vien co ma so %d.\n", manv);
}

void xoanv(danhsach ds)
{
    int i, j;
    printf("Moi ban nhap ma nhan vien can xoa: ");
    int d;
    scanf("%d", &d);
    for (i = 0; i < ds.n; i++)
    {
        if (ds.a[i].msnv == d) // Tìm thấy nhân viên cần xóa
        {
            for (j = i; j < ds.n - 1; j++) // Dịch chuyển các phần tử phía sau lên trước
            {
                ds.a[j] = ds.a[j + 1];
            }
            ds.n--; // Giảm số lượng nhân viên trong danh sách đi 1
            printf("Da xoa nhan vien co MSNV %d khoi danh sach.\n", d);
            xuatdanhsach(ds); // In lại danh sách sau khi xóa
            return;
        }
    }
    // Không tìm thấy nhân viên cần xóa
    printf("Khong tim thay nhan vien co MSNV %d trong danh sach.\n", d);
}

// hàm sắp xếp danh sách
// Sắp xếp nổi bọt
void sapxep(danhsach ds)
{
    nhanvien temp;
    int i, j;
    for (i = 0; i < ds.n - 1; i++)
    {
        for (j = 0; j < ds.n - i - 1; j++)
        {
            if (ds.a[j].luong < ds.a[j + 1].luong)
            {
                temp = ds.a[j];
                ds.a[j] = ds.a[j + 1];
                ds.a[j + 1] = temp;
            }
        }
    }
    // In bảng kết quả với danh sách đã sắp xếp
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
    printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
    for (i = 0; i < ds.n; i++)
    {
        printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", ds.a[i].msnv, strcat(strcat(ds.a[i].ho, " "), ds.a[i].ten), ds.a[i].namsinh.ngay, ds.a[i].namsinh.thang, ds.a[i].namsinh.nam, ds.a[i].noisinh, ds.a[i].diachi, ds.a[i].luong);
    }
    printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
}
// Sắp xếp chọn(selection sort)
//  void sapxep(danhsach ds)
//  {
//      nhanvien temp;
//      int i, j, min_idx;
//      for (i = 0; i < ds.n - 1; i++)
//      {
//          min_idx = i;
//          for (j = i + 1; j < ds.n; j++)
//          {
//              if (ds.a[j].luong > ds.a[min_idx].luong)
//              {
//                  min_idx = j;
//              }
//          }
//          temp = ds.a[i];
//          ds.a[i] = ds.a[min_idx];
//          ds.a[min_idx] = temp;
//      }

//     // In bảng kết quả với danh sách đã sắp xếp
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
//     printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
//     for (i = 0; i < ds.n; i++)
//     {
//         printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", ds.a[i].msnv, strcat(strcat(ds.a[i].ho, " "), ds.a[i].ten), ds.a[i].namsinh.ngay, ds.a[i].namsinh.thang, ds.a[i].namsinh.nam, ds.a[i].noisinh, ds.a[i].diachi, ds.a[i].luong);
//     }
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
// }

// Sắp xếp chèn(insertion sort)
//  void sapxep(danhsach ds)
//  {
//      int i, j;
//      nhanvien key;
//      for (i = 1; i < ds.n; i++)
//      {
//          key = ds.a[i];
//          j = i - 1;

//         while (j >= 0 && ds.a[j].luong < key.luong)
//         {
//             ds.a[j+1] = ds.a[j];
//             j = j - 1;
//         }
//         ds.a[j+1] = key;
//     }

//     // In bảng kết quả với danh sách đã sắp xếp
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
//     printf("|       MSNV           |       Ho ten         | Ngay sinh  |       Noi sinh        |             Dia chi            |   Luong    |\n");
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
//     for (i = 0; i < ds.n; i++)
//     {
//         printf("| %20d | %20s | %02d/%02d/%04d | %20s | %-30s | %10.2f |\n", ds.a[i].msnv, strcat(strcat(ds.a[i].ho, " "), ds.a[i].ten), ds.a[i].namsinh.ngay, ds.a[i].namsinh.thang, ds.a[i].namsinh.nam, ds.a[i].noisinh, ds.a[i].diachi, ds.a[i].luong);
//     }
//     printf("+----------------------+----------------------+------------+----------------------+--------------------------------+------------+\n");
// }

int menu()
{

    int choice;
    danhsach ds;
    int d = sizeof(ds), k;
    nhanvien x;
    nhapdanhsach(ds);
    xuatdanhsach(ds);
    while (1)
    {
        printf("\n\t\t-------------------------Menu-------------------------");
        printf("\n\t1.Them vao 1 nhan vien");
        printf("\n\t2.Tim nhan vien theo ma so");
        printf("\n\t3.Tim nhan vien theo ten");
        printf("\n\t4.Bang luong cua nhan vien giam dan");
        printf("\n\t5.Xoa 1 nhan vien");
        printf("\n\t0.Thoat chuong trinh");
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t Chon 1 trong cac chuc nang tren: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Cam on ban da su dung chuong trinh!\n");
            return 0;
        case 1:
            nhap1nv(x);
            themnv(ds, x, k);
            xuatdanhsach(ds);
            break;
        case 2:
            timMSNV(ds, d);
            break;
        case 3:
            timten(ds);
            break;
        case 4:
            sapxep(ds);
            break;
        case 5:
            xoanv(ds);
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
int main()
{
    menu();
    getch();
}
