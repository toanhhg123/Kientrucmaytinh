
#pragma once
#include "DeTai_11.h"
void VeKhung()
{
    setTextColor(11);
    for (int i = Tuong_Trai; i < Bien_Ben; i++)
    {
        gotoXY(i, 0);
        cout << (char)220;
    }
    for (int i = Tuong_tren; i < Tuong_duoi; i++)
    {
        gotoXY(Bien_Ben - 1, i);
        cout << (char)222;
    }
    for (int i = Bien_Ben - 1; i >= Tuong_Trai; i--)
    {
        gotoXY(i, Tuong_duoi - 1);
        cout << (char)223;
    }
    for (int i = Tuong_duoi - 2; i >= Tuong_tren; i--)
    {
        gotoXY(Tuong_Trai, i);
        cout << (char)221;
    }
    for (int i = Tuong_tren; i < Tuong_duoi - 1; i++)
    {
        gotoXY(Tuong_phai - 1, i);
        cout << (char)222;
    }
}
void KhungGioiThieu()
{

    setTextColor(6);
    out_toando(Tuong_Trai + 3, (Tuong_tren + Tuong_Giua) / 2 - 1, "NHOM_3");
    out_toando((Tuong_phai + Tuong_Trai) / 2 + 6, (Tuong_tren + Tuong_Giua) / 2 - 1, "De_Tai_11");
    out_toando((Tuong_phai + Tuong_Trai) / 2 - 11, (Tuong_tren + Tuong_Giua) / 2 + 1.5, "MON: Kien_Truc_May_Tinh");
    setTextColor(11);
    for (int i = Tuong_Trai + 1; i < Tuong_phai - 1; i++)
    {
        gotoXY(i, Tuong_Giua);
        cout << (char)223;
    }
}
void KhungInfo()
{
    for (int i = Tuong_Trai + 1; i < Tuong_phai - 1; i++)
    {
        gotoXY(i, Tuong_Tren_Ifo);
        cout << (char)223;
    }
    setTextColor(6);
    out_toando(Tuong_Trai + 5, Tuong_Tren_Ifo + 1, "Le Huu Toan - 2001206939");
    out_toando(Tuong_Trai + 5, Tuong_Tren_Ifo + 2, "Chu Huy Khanh - 2001207017");
    out_toando(Tuong_Trai + 5, Tuong_Tren_Ifo + 3, "Nguyen Bao Sanh - 2001207211");
    out_toando(Tuong_Trai + 5, Tuong_Tren_Ifo + 4, "Van Bon - 2001207289");
    setTextColor(11);
}
void Khunghuongdan()
{
    for (int i = Tuong_Trai + 1; i < Tuong_phai - 1; i++)
    {
        gotoXY(i, Tuong_Tren_Huong_Dan);
        cout << (char)223;
    }
    setTextColor(12);
    out_toando((Tuong_phai + Tuong_Trai) / 2 - 5, (Tuong_Tren_Huong_Dan + Tuong_Tren_Ifo) / 2 - 1, "Huong_dan");
    out_toando(Tuong_Trai + 2, (Tuong_Tren_Huong_Dan + Tuong_Tren_Ifo) / 2, "Dung phim mui ten de chon");
    out_toando(Tuong_Trai + 2, (Tuong_Tren_Huong_Dan + Tuong_Tren_Ifo) / 2 + 1, "Enter: Chon");
    out_toando((Tuong_phai + Tuong_Trai) / 2 + 3, (Tuong_Tren_Huong_Dan + Tuong_Tren_Ifo) / 2 + 1, "ESC: Ket_Thuc");
    setTextColor(11);
}
int batsukien(int &bien)
{
    setTextColor(4);
    toado T;
    T.x = Tuong_Trai + 1;
    T.y = Tuong_Giua + 5;
    out_toando(T.x, T.y, "->");
    while (true)
    {
        ShowCur(0);
        toado cu = T;
        char key = _getch();
        if (key == 13)
        {
            out_toando(cu.x, cu.y, "  ");
            return T.y - Tuong_Giua - 4;
        }
        else if (key == 27)
        {
            system("cls");
            cout << "\n\tChuong trinh ket thuc";
            return 0;
        }
        else if (key == -32)
            key = _getch();
        switch (key)
        {
        case 80:
            T.y++;
            if (T.y == bien)
                T.y = Tuong_Giua + 5;
            out_toando(cu.x, cu.y, "  ");
            out_toando(T.x, T.y, "->");
            break;
        case 72:
            T.y--;
            if (T.y == Tuong_Giua)
                T.y = bien - 1;
            out_toando(cu.x, cu.y, "  ");
            out_toando(T.x, T.y, "->");
            break;
        }
    }
}
void header_khungtrai()
{
    for (int i = Tuong_phai; i < Bien_Ben - 1; i++)
    {
        gotoXY(i, Tuong_Duoi_Header);
        cout << (char)223;
    }
    setTextColor(8);
    out_toando((Tuong_phai + Tuong_Giua_sreen) / 2 - 8, (Tuong_tren + Tuong_Duoi_Header) / 2, "Tich so nhi phan");
    out_toando((Tuong_Giua_sreen + Bien_Ben) / 2 - 10, (Tuong_tren + Tuong_Duoi_Header) / 2, "Nhan 2 chuoi nhi phan");
    setTextColor(11);
}

void khungtrai()
{
    header_khungtrai();
    for (int i = Tuong_tren; i < Tuong_duoi - 1; i++)
    {
        gotoXY(Tuong_Giua_sreen, i);
        cout << (char)222;
    }
}
void cls_sreen()
{
    for (int i = Tuong_tren + 1; i < Tuong_duoi - 1; i++)
    {
        for (int j = Tuong_phai + 1; j < Bien_Ben - 1; j++)
            out_toando(j, i, " ");
    }
}
void cls_sreen_left()
{
    for (int i = Tuong_Duoi_Header + 1; i < Tuong_duoi - 1; i++)
    {
        for (int j = Tuong_phai + 1; j < Tuong_Giua_sreen - 1; j++)
            out_toando(j, i, " ");
    }
}
void cls_sreen_right()
{
    for (int i = Tuong_Duoi_Header + 1; i < Tuong_duoi - 1; i++)
    {
        for (int j = Tuong_Giua_sreen + 1; j < Bien_Ben - 1; j++)
            out_toando(j, i, " ");
    }
}