#include"DeTai_11.h"
using namespace std;
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
	if (str[0] < 48 || str[0]>57)
		return false;
	if (str[str.length() - 1] < 48 || str.length() - 1 >57)
		return false;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '*')
		{
			i++;
			if (str[i] < 48 || str[i]>57)
				return false;
		}
		else if (str[i] < 48 || str[i]>57)
			return false;
	}
	return	true;
}
void input(string& str)
{
	cin.ignore();
	getline(cin, str);
	str=chuanhoachuoi(str);
	while (KTchuoi(str)==false)
	{
		cout << "\nVui long nhap so khong dau: ";
		getline(cin, str);
		str = chuanhoachuoi(str);
	}
}

long tichChuoi(string& str)
{
	str = chuanhoachuoi(str);
	int index = 0;
	long result = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length()-1)
		{
			int number = stoi(str.substr(index, str.length()-1));
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
bool checkBirany(string& str)
{
	str = chuanhoachuoi(str);
	if (str.length() == 0)
		return false;
	if (KTchuoi(str) == false)
		return false;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '*')
		{
			i++;
			if (str[i] < 48 || str[i]>49)
				return false;
		}
		else if (str[i] < 48 || str[i]>49)
			return false;
	}
	return true;
}
void inputBirany(string& str)
{
	cin.ignore();
	getline(cin, str);
	str = chuanhoachuoi(str);
	while (checkBirany(str) == false)
	{
		cout << "\nVui long nhap dung chuoi so nhi phan: ";
		getline(cin, str);
		str = chuanhoachuoi(str);
	}
}
long convertBirayToNumber(string& str)
{
	
	str = chuanhoachuoi(str);
	if (checkBirany(str) == false)
		return -1;
	long resuilt=0;
	int i = 0;
	int  num = stoi(str);
	while (num!=0)
	{
		int numTail = num % 10;
		resuilt += numTail*power(2, i);
		i++;
		num = num / 10;
	}
	return resuilt;
}
long tichchuoinhiphan(string& str)
{
	long resuilt=1;
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
			string binary = str.substr(index,i);
			long number = convertBirayToNumber(binary);
			if (number == -1)
				return -1;
			resuilt *= number;
			index = i + 1;
		}
	}
	return resuilt;
}
void convertToBinary(stack& s, long long num)
{
	creat_stack(s);
	while (num!=0)
	{
		int numTail = num % 2;
		push(s, creatNode(numTail));
		num = num / 2;
	}
	while (s.top!=NULL)
	{
		cout << s.top->data;
		pop(s);
	}
}
void menu()
{
	int luachon = 1;
	string str;
	stack s;
	while (luachon!=0)
	{
		cout << "\n=====================Menu=======================";
		cout << "\n1. Tich so ---->  Nhi phan";
		cout << "\n2. Nhan 2 chuoi nhi phan";
		cout << "\n================================================";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		system("cls");
		switch (luachon)
		{
		case 1:
			cout << "\nnhap mot chuoi so (vd: 100 * 100 * ...) : ";
			input(str);
			convertToBinary(s, tichChuoi(str));
			break;
		case 2:
			cout << "\nhap chuoi binary vd: (10001*11001) chu y chuoi binary toi da 10 ki tu: " << endl;
			inputBirany(str);
			long num = tichchuoinhiphan(str);
			if (num == -1)
				cout << "\nNhap sai chuoi nhi phan";
			else
				convertToBinary(s, num);
			break;

		}
	}
}
int main()
{
	menu();
	/*string str;
	getline(cin,str);
	cout << "\t" << tichchuoinhiphan(str);*/
	return 0;
}