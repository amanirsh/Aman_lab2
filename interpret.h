/*
This File contains the funcionality of interpretor which is to parse a file and execute it line by line.
And if there is an error, raise the syntax error.
*/
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
int checkflag = 0;
int cot = 0;
float final_res = 0;
int no_of_sym = 0;
int no_of_var = 0;


template <class A_Type, class B_Type> class Variable
{
public:
	A_Type name;
	B_Type value;
	void setter(A_Type x, B_Type y);
	A_Type get_name();
	B_Type get_val();
};
template <class A_Type, class B_Type> void Variable<A_Type, B_Type>::setter(A_Type x, B_Type y)
{
	name = x;
	value = y;
	//cout << "name : "<< name << "\n";
	//cout << "value : "<<value << "\n";
}
template <class A_Type, class B_Type> A_Type Variable<A_Type, B_Type>::get_name()
{
	return name;
}
template <class A_Type, class B_Type> B_Type Variable<A_Type, B_Type>::get_val()
{
	return value;
}
void SytaxErrorCheck(string s);
void PresentCheck(string s);
int interpretor(string tm);
void Operation(int x, int y, string op);
void CheckingLength(char  *s[], int x2);
int objnum(std::string s);
void anotherCheck(std::string s);
float getval(std::string s);
void checkpreced(string st);

Variable <string, int> obj[10];

char * sym[100];
char * svar[100];

void SytaxErrorCheck(string s)
{
	char s2[100];
	char s23[100];
	char *str3[100];
	char * pch1;
	const char * cs;
	int x = 0;
	cs = s.c_str();
	strcpy(s2, cs);
	pch1 = strtok(s2, "  ;");
	str3[x] = pch1;
	//const char * a;
	x++;
	while (pch1 != NULL)
	{
		pch1 = strtok(NULL, "  ;");
		str3[x] = pch1;
		x++;
	} // end of while


	char str[] = " ";

	for (int i = 0; i < x - 1; i++)
	{


		if (strcmp(str3[i], "=") == 0)
		{
			str3[i - 1]; //should be a variable name
			strcpy(s23, str3[i - 1]);
			if (isdigit(s23[0]))
			{
				std::cout << "Syntax error\n";
				checkflag = 1;
			}

			if (str3[i + 1] == NULL)
			{
				std::cout << "Syntax error\n";
				checkflag = 1;
			}

		}

	}


}
void PresentCheck(string s)
{
	int temp_var = 0;
	const char* csm1;
	const char* csm;
	char st[100];
	char str21[100];
	char *str4[100];
	int valueFound = 0;
	csm = s.c_str();
	strcpy(str21, csm);

	for (int j = 0; j < cot; j++) // find the object and get its value
	{

		string temp1 = obj[j].get_name();
		//convert string to char[]
		csm1 = temp1.c_str();
		strcpy(st, csm1);

		if ((strcmp(st, str21) == 0))
		{
			//cout << "st " << st<<"\n";
			valueFound = 1;
			break;

		}

	}// end of for
	if (valueFound == 0)
	{
		std::cout << "\nSyntax Error\n";
		checkflag = 1;
	}
	if (valueFound > 1)
	{
		checkflag = 1;
		std::cout << "Syntax Error\n";
	}

}
void Operation(int x, int y, string op){

	if (op == "+")
	{
		final_res = x + y;

	}
	if (op == "-")
	{
		final_res = x - y;

	}
	if (op == "/")
	{
		if (y == 0)
		{
			std::cout << "can not divide by zero\n";
		}
		else{
			final_res = x / y;

		}
	}
	if (op == "*")
	{
		final_res = x * y;

	}

}
void CheckingLength(char*s[], int x2){


	int k = 0;
	int l = 0;
	for (int i = 0; i < x2; i++)
	{
		if ((strcmp(s[i], "+") == 0) || (strcmp(s[i], "-") == 0) || (strcmp(s[i], "/") == 0) || (strcmp(s[i], "*") == 0))
		{
			no_of_sym++;
			sym[k] = s[i];
			k++;

		}
		else
		{
			no_of_var++;
			svar[l] = s[i];
			l++;
		}
	}

	if (no_of_sym == no_of_var - 1)
	{

	}
	else
	{
		std::cout << "syntax error\n";
		checkflag = 1;
	}

}
float getval(std::string s){

	char s2[100];
	char s23[100];
	char *str3[100];
	const char* csm1;
	char st[100];

	const char* cs = s.c_str();
	strcpy(s2, cs);

	if (isdigit(s2[0])){


		return stof(s); // converting string to int

	}
	else
	{

		PresentCheck(s);
		if (checkflag == 1)
		{
			getchar();
			getchar();
			return 0;

		}
		for (int j = 0; j < cot; j++)
		{
			string temp1 = obj[j].get_name();
			csm1 = temp1.c_str();
			strcpy(st, csm1);


			if ((strcmp(st, s2) == 0))
			{

				return (float(obj[j].get_val()));


			}
		}
	}
}
int objnum(std::string s){

	int temp_var = 0;
	const char* csm1;
	const char* csm;
	char st[100];
	char str21[100];
	char *str4[100];
	int valueFound = 0;
	csm = s.c_str();
	strcpy(str21, csm);

	for (int j = 0; j < cot; j++) // find the object and get its value
	{

		string temp1 = obj[j].get_name();
		//convert string to char[]
		csm1 = temp1.c_str();
		strcpy(st, csm1);

		if ((strcmp(st, str21) == 0))
		{
			
			return j;
			valueFound = 1;
			break;

		}

	}// end of for

}
void anotherCheck(string s){

	int temp_var = 0;
	const char* csm1;
	const char* csm;
	char st[100];
	char str21[100];
	char *str4[100];
	int valueFound = 0;
	csm = s.c_str();
	strcpy(str21, csm);

	for (int j = 0; j < cot; j++)
	{

		string temp1 = obj[j].get_name();
		csm1 = temp1.c_str();
		strcpy(st, csm1);

		if ((strcmp(st, str21) == 0))
		{

			checkflag = 1;
			cout << "Syntax Error\n";
			break;

		}

	}// end of for


}
int interpretor(string tm)
{

	int var;

	ifstream file(tm);
	char str2[100];
	char str21[100];
	char st[100];
	char st1[100];
	char st2[100];
	char s1[100];
	char s2[100];
	char *str3[100];
	char *str4[100];
	char *str5[100];
	string str;
	const char * cs;
	const char * csm;
	const char * csm1;
	const char* cs1;
	const char* cs2;
	const char* c1;
	const char* c2;
	char * pch1;
	int checkval = 0;
	char * pch;
	char * pchm;
	int x;
	int x1 = 0;
	string nme;
	float val = 0;
	int flag1 = 0;
	int flag2 = 0;
	string opr;
	string rest;
	string rest1;

	while (getline(file, str)) // reading file line by line
	{

		cout << str << "\n";
		SytaxErrorCheck(str);
		if (checkflag == 1)
		{
			getchar();
			getchar();
			return 0;
		}
		if (checkflag == 0)
		{

			x = 0;
			cs = str.c_str();
			strcpy(str2, cs);
			pch = strtok(str2, "  ;");
			str3[x] = pch;
			x++;
			while (pch != NULL)
			{
				pch = strtok(NULL, "  ;");
				str3[x] = pch;
				x++;
			} // end of while
			if (strcmp(str3[0], "Let") == 0){
				for (int i = 0; i < x - 1; i++)
				{
					//std::cout << str3[i] << "\n";
					if (flag1 == 0)
					{
						if (strcmp(str3[i], "=") == 0)
						{

							nme = str3[i - 1];

							val = atof(str3[i + 1]);

							//if (checkval >= 1)
							//{

							anotherCheck(nme);
							if (checkflag == 1)
							{
								getchar();
								getchar();
								return 0;

							}
							//}
							obj[cot].setter(nme, val);
							cot++;
							flag1 = 1;
						}
					}
				}

			} //end of if


			else if (strcmp(str3[0], "Print") == 0){

				int temp_var = 0;
				for (int i = 0; i < x - 1; i++)
				{

					if (strcmp(str3[i], "[") == 0)
					{
						rest1 = str3[i + 1];
						for (int j = 0; j < cot; j++)
						{
							string temp1 = obj[j].get_name();

							cs1 = temp1.c_str();
							cs2 = rest1.c_str();


							strcpy(st1, cs1);
							strcpy(st2, cs2);
							if ((strcmp(st1, st2) == 0))
							{
								temp_var = obj[j].get_val();
								std::cout << "Value of " << temp1 << " is : " << temp_var;

							}
						}

					}
				}
			} //end of if

			else{
				int lop = 0;

				int x2 = 0;
				int name_of_var = 0;
				csm = str.c_str();
				strcpy(str21, csm);
				pchm = strtok(str21, " =;");
				str5[0] = pchm;
				PresentCheck(str5[0]);
				if (checkflag == 1)
				{
					getchar();
					getchar();
					return 0;

				}
				while (pchm != NULL)
				{
					pchm = strtok(NULL, " =;");
					str4[x2] = pchm;
					x2++;
				} // end of while

				CheckingLength(str4, x2 - 1);
				int co = 2;
				int co1 = 1;
				int firstTime = 0;
				for (int k = 0; k < no_of_sym; k++)
				{
					float var1 = 0;
					float var2 = 0;
					string op;
					if (firstTime == 0)
					{
						//check if svar[0] and svar[1] is a digit or a variable. If var, fetch its value;
						var1 = getval(svar[0]);
						var2 = getval(svar[1]);
						op = sym[0];
						Operation(var1, var2, op);
						firstTime++;
					}
					else
					{
						int var3 = getval(svar[co]);
						op = sym[co1];
						Operation(final_res, var3, op);
						co++;
						co1++;

					}

				}

				std::cout << "final res " << final_res;
				std::cout << "\n";
				int z = objnum(str5[0]);
				obj[z].setter(str5[0], final_res);



			}
			flag1 = 0;
			//flag2 = 0;

		}//end of while
		checkval++;
	}

	getchar();
	getchar();
	return 0;
}
void checkpreced(string st){

}