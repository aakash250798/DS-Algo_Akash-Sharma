#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void oct_to_hex(int a)
{
    char b[100];int c=0,s=0,z,i;
    int n=a;
	while(n>0)
	{
		s=s+pow(8,c)*(n%10);
		n=n/10;
		c++;
	}i=s;c=0;

	while(i>0)
	{	z=i%16;
	if(z>9)
	{
		b[c++]='A'+z-10;
	}
	else b[c++]=(char)(z+48);
	i=i/16;
}
	for(i=strlen(b)-1;i>=0;i--)
	{
		cout<<b[i];
}
}

void hex_to_oct(char a[])
{
    int c=0,s=0,z,i;
	for(int i=strlen(a)-1;i>=0;i--)
	{
		if(a[i]<='F'&&a[i]>='A')
		{z=(int)(a[i]-55);
			s=s+(pow(16,c))*z;
		}
		else if(a[i]<='9'&&a[i]>='0')
		{z=(int)(a[i]-48);
			s=s+(pow(16,c))*z;
		}
		c++;
	}
		i=s;
	s=0;c=0;
	while(i>0)
	{	s=s*10+(i%8);
		i=i/8;
	}i=s;
	s=0;
	while(i>0)
	{s=s*10+(i%10) ;   i=i/10;
	};
	cout<<s;

}

void hex_to_bin(char a[])
{
    for(int i=0;i<strlen(a);i++)
	{switch(a[i])
		{case '0':
			cout<<"0000";
			break;
			case '1':
			cout<<"0001";
			break;
			case '2':
			cout<<"0010";
			break;
			case '3':
			cout<<"0011";
			break;
			case '4':
			cout<<"0100";
			break;
			case '5':
			cout<<"0101";
			break;
			case '6':
			cout<<"0110";
			break;
			case '7':
			cout<<"0111";
			break;
			case '8':
			cout<<"1000";
			break;
			case '9':
			cout<<"1001";
			break;
			case 'A':
			cout<<"1010";
			break;
			case 'B':
			cout<<"1011";
			break;
			case 'C':
			cout<<"1100";
			break;
			case 'D':
			cout<<"1101";
			break;
			case 'E':
			cout<<"1110";
			break;
			case 'F':
			cout<<"1111";
			break;
			}
	}
}
void oct_to_bin(int a)
{
    int b[100],c=0,d=0,i=0,s=0;
    while(a>0)
	{
		d=a%10;
		a=a/10;
		s=s+pow(8,c)*d;
		c++;
	}
        while(s>0)
		{
			c=s%2;
			b[i]=c;
			s=s/2;
			i++;
		}
	for(int j=i-1;j>=0;j--)
	{
		cout<<b[j];
	}
}

void bin_to_hexa(char a[])
{
    char b[100];
    int z;
    int n=strlen(a);
	int i=n-1,c=0,s=0;
	while(i>=0)
	{
	if(a[i]=='1')
		s=s+pow(2,c);
	c++;
	i--;
	}
	i=s;
	s=0;c=0;
	while(i>0)
	{	z=i%16;
	if(z>9)
	{
		b[c++]='A'+z-10;
	}
	else b[c++]=(char)(z+48);
	i=i/16;
}
	for(i=strlen(b)-2;i>=0;i--)
	{
		cout<<b[i];
 }
}

void bin_to_oct(char a[])
{
    int n=strlen(a);
	int i=n-1,c=0,s=0;
	while(i>=0)
	{
	if(a[i]=='1')
		s=s+pow(2,c);
	c++;
	i--;
	}
	i=s;
	s=0;c=0;
	while(i>0)
	{	s=s*10+(i%8);
		i=i/8;
	}i=s;
	s=0;
	while(i>0)
	{
		s=s*10+(i%10);
		i=i/10;
	};
	cout<<s<<endl;

}

void hex_to_dec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int res = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (hex[i]>='0' && hex[i]<='9')
        {
            res += (hex[i] - 48)*base;
            base = base * 16;
        }
        else if (hex[i]>='A' && hex[i]<='F')
        {
            res += (hex[i] - 55)*base;
            base = base*16;
        }
    }
    cout<<res<<endl;
}

int binoct_to_dec(int n, int base)
{
    int num = n;
    int temp = num;
    int res = 0;
    int pos = 1;

    while (temp) {
        int ldig = temp % 10;
        temp = temp / 10;

        res += ldig * pos;

        pos = pos * base;
    }
    return res;
}

void dec_to_any(int n, int base)
{
    char arr[100];
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % base;
        if(temp < 10)
        {
            arr[i] = temp + 48;
            i++;
        }
        else
        {
            arr[i] = temp + 55;
            i++;
        }
        n = n/base;
    }
    for(int j=i-1; j>=0; j--)
        cout << arr[j];

}

int main()
{
    cout<<"**************NUMBER SYSTEM CONVERTER*****************"<<endl;
    cout<<endl;
    cout<<"      Choose from the following:      "<<endl;
    cout<<"        1. Decimal to Binary "<<endl;
    cout<<"        2. Decimal to Octal  "<<endl;
    cout<<"        3. Decimal to hexadecimal "<<endl;
    cout<<"        4. Binary to Octal   "<<endl;
    cout<<"        5. Binary to hexadeciaml"<<endl;
    cout<<"        6. Binary to decimal "<<endl;
    cout<<"        7. Octal to Decimal  "<<endl;
    cout<<"        8. Octal to Binary   "<<endl;
    cout<<"        9. Octal to hexadecimal "<<endl;
    cout<<"       10. Hexadecimal to Binary"<<endl;
    cout<<"       11. Hexadecimal to octal  "<<endl;
    cout<<"       12. Hexadecimal to Decimal "<<endl;
    int option;
    char c = 'a';
    while(c!='@')
    {
    cout<<"Enter the option from above list:";
    cin>>option;
    int iter =1;
    while(iter!=-1){
    if(option==1)
    {

        int num;
        cout<<"Enter the number in decimal:";
        cin>>num;
        dec_to_any(num,2);
    }
    else if (option ==2)
    {
        int num;
        cout<<"Enter the number in decimal:";
        cin>>num;
        dec_to_any(num,8);
    }
    else if (option ==3)
    {
        int num;
        cout<<"Enter the number in decimal:";
        cin>>num;
        dec_to_any(num,16);
    }
    else if (option ==4)
    {
        char num[10];
        cout<<"Enter the number in binary:";
        cin>>num;
        bin_to_oct(num);

    }
    else if (option ==5)
    {
        char num[10];
        cout<<"Enter the number in binary:";
        cin>>num;
        bin_to_hexa(num);
    }
    else if (option ==6)
    {
        int num;
        cout<<"Enter the number in binary:";
        cin>>num;
        int res=binoct_to_dec(num,2);
        cout<<res<<"\n";
    }
    else if (option ==7)
    {
        int num;
        cout<<"Enter the number in octal:";
        cin>>num;
        int res = binoct_to_dec(num,8);
        cout<<res<<"\n";
    }
    else if (option ==8)
    {
        int num;
        cout<<"Enter the number in octal:";
        cin>>num;
        oct_to_bin(num);
    }
    else if (option ==9)
    {
        int num;
        cout<<"Enter the number in octal:";
        cin>>num;
        oct_to_hex(num);
    }
    else if (option ==10)
    {
        char num[50];
        cout<<"Enter the number in hexadecimal:";
        cin>>num;
        hex_to_bin(num);
    }
    else if (option ==11)
    {
        char num[50];
        cout<<"Enter the number in hexadecimal:";
        cin>>num;
        hex_to_oct(num);
    }
    else if (option ==12)
    {
        char num[10];
        cout<<"Enter the number in hexadecimal:";
        cin>>num;
        hex_to_dec(num);
    }
    cout<<"\nDo you want to continue doing the same conversion? For No: type (-1) for yes: type (1) :: ";
    cin>>iter;
    if(iter!=-1)
        continue;
    else
        break;
}
    cout<<"\nIf you don't want to continue press '@' else press any other alphabet:";
    cin>>c;
}

}
