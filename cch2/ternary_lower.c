#include<stdio.h>
#define END_CHAR '\0'


void lower(char chs[]);

int main(){
	char t1[] = "hAkApeSzi MAKI ha KAP ESZI!!!!!";
	char t2[] = "";
	lower(t1);
	lower(t2);
	printf("%s\n", t1);	 
	printf("%s\n", t2);
	return 0;
}


void lower(char chs[]) {
	/*converts the letters(if they're present) in the character string
	**to lower case*/
	int i, conversion;
	conversion = 'A' - 'a';
	for (i = 0; chs[i] != END_CHAR; ++i) {
		chs[i] = (chs[i] >= 'A' && chs[i] <= 'Z') ? chs[i] - conversion : chs[i];
	}
}
	
