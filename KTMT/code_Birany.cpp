
#include "DeTai_11.h"
#include "thietke.h"
string chuanhoachuoi(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		while (str[i] == ' ')
		{
			str.erase(str.begin() + i);
		}
	}
	return str;
}
bool KTchuoi(string str)
{
	if (str[0] < 48 || str[0] > 57)
		return false;
	if (str[str.length() - 1] < 48 || str[str.length() - 1] > 57)
		return false;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '*')
		{
			i++;
			if (str[i] < 48 || str[i] > 57)
				return false;
		}
		else if (str[i] < 48 || str[i] > 57)
			return false;
	}
	return true;
}
void input(string &str, int &tdy)
{
	gotoXY(Tuong_phai + 1, ++tdy);
	getline(cin, str);
	str = chuanhoachuoi(str);
	while (KTchuoi(str) == false)
	{
		if (tdy >= Tuong_duoi - 4)
		{
			cls_sreen_left();
			tdy = Tuong_tren + 4;
		}
		out_toando(Tuong_phai + 1, ++tdy, "Vui long nhap so khong dau: \n");
		gotoXY(Tuong_phai + 1, ++tdy);

		getline(cin, str);
		str = chuanhoachuoi(str);
	}
}

long tichChuoi(string &str)
{
	str = chuanhoachuoi(str);
	int index = 0;
	long result = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1)
		{
			int number = stoi(str.substr(index, str.length()));
			result *= number;
			break;
		}
		else if (str.at(i) == '*')
		{
			int number = stoi(str.substr(index, i));
			result *= number;
			index = i + 1;
		}
	}
	return result;
}
bool checkBirany(string &str)
{
	str = chuanhoachuoi(str);
	if (str.length() == 0)
		return false;
	if (KTchuoi(str) == false)
		return false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*')
		{
			i++;
			if (str[i] < 48 || str[i] > 49)
				return false;
		}
		else if (str[i] < 48 || str[i] > 49)
			return false;
	}
	return true;
}
void inputBirany(string &str, int &tdy)
{
	gotoXY(Tuong_Giua_sreen + 1, ++tdy);
	getline(cin, str);
	str = chuanhoachuoi(str);
	while (checkBirany(str) == false)
	{
		if (tdy >= Tuong_duoi - 4)
		{
			cls_sreen_right();
			tdy = Tuong_tren + 4;
		}
		out_toando(Tuong_Giua_sreen + 1, ++tdy, "Nhap dung chuoi nhi phan: \n");
		gotoXY(Tuong_Giua_sreen + 1, ++tdy);
		getline(cin, str);
		str = chuanhoachuoi(str);
	}
}
long convertBirayToNumber(string &str)
{

	str = chuanhoachuoi(str);
	if (checkBirany(str) == false)
		return -1;
	long resuilt = 0;
	int i = 0;
	long num = stoi(str);
	while (num != 0)
	{
		long numTail = num % 10;
		resuilt += numTail * power(2, i);
		i++;
		num = num / 10;
	}
	return resuilt;
}
long tichchuoinhiphan(string &str)
{
	long resuilt = 1;
	str = chuanhoachuoi(str);
	int index = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1)
		{
			string binary = str.substr(index, str.length());
			long number = convertBirayToNumber(binary);
			if (number == -1)
				return -1;
			resuilt *= number;
			break;
		}
		else if (str.at(i) == '*')
		{
			string binary = str.substr(index, i);
			long number = convertBirayToNumber(binary);
			if (number == -1)
				return -1;
			resuilt *= number;
			index = i + 1;
		}
	}
	return resuilt;
}
void convertToBinary(stack &s, long long num, int &toadox, int &toadoy)
{
	creat_stack(s);
	while (num != 0)
	{
		int numTail = num % 2;
		push(s, creatNode(numTail));
		num = num / 2;
	}
	while (s.top != NULL)
	{
		gotoXY(++toadox, toadoy);
		cout << s.top->data;
		pop(s);
	}
}
void menu()
{
	int luachon = 1;
	string str;
	stack s;
	toado t;
	t.x = Tuong_Trai + 2;
	t.y = Tuong_Giua+4;
	KhungGioiThieu();
	khungtrai();
	
	KhungInfo();
	Khunghuongdan();
	while (luachon != 0)
	{
        ShowCur(0);
		VeKhung();
		out_toando(++t.x, ++t.y, "1. Tich so ---->  Nhi phan");
		out_toando(t.x, ++t.y, "2. Nhan 2 chuoi nhi phan");
		luachon = batsukien(++t.y);
		switch (luachon)
		{
		case 1:
		{
			out_toando((Tuong_phai + Tuong_Giua_sreen) / 2 - 8, (Tuong_tren + Tuong_Duoi_Header) / 2, "Tich so nhi phan");
			setTextColor(15);
			int tdy = Tuong_tren + 4;
			int tdx = Tuong_phai + 1;
			out_toando(tdx, tdy, "Nhap phep tinh so nguyen: ");
			input(str, tdy);
			convertToBinary(s, tichChuoi(str), tdx, ++tdy);
			tdy = Tuong_tren + 5;
			tdx = Tuong_phai + 1;
			_getch();
			cls_sreen_left();
			setTextColor(8);
			out_toando((Tuong_phai + Tuong_Giua_sreen) / 2 - 8, (Tuong_tren + Tuong_Duoi_Header) / 2, "Tich so nhi phan");
			setTextColor(11);
			break;
		}
		case 2:
		{
			out_toando((Tuong_Giua_sreen + Bien_Ben) / 2 - 10, (Tuong_tren + Tuong_Duoi_Header) / 2, "Nhan 2 chuoi nhi phan");
			setTextColor(15);
			int tdy = Tuong_tren + 4;
			int tdx = Tuong_Giua_sreen + 1;
			out_toando(tdx, tdy, "Nhap phep tinh 2 chuoi nhi phan: ");
			inputBirany(str, tdy);
			long num = tichchuoinhiphan(str);
			if (num == -1)
				out_toando(tdx, ++tdy, "Nhap sai chuoi nhi phan");

			else
				convertToBinary(s, num, tdx, ++tdy);
			tdy = Tuong_tren + 4;
			tdx = Tuong_Giua_sreen + 1;
			_getch();
			setTextColor(8);
			out_toando((Tuong_Giua_sreen + Bien_Ben) / 2 - 10, (Tuong_tren + Tuong_Duoi_Header) / 2, "Nhan 2 chuoi nhi phan");
			setTextColor(11);
			cls_sreen_right();
			break;
		}
		}
		t.x = Tuong_Trai + 2;
		t.y = Tuong_Giua + 4;
	}
}
int main()
{
	menu();
	getch();
	return 0;
}