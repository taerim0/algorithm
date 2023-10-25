#include <stdio.h>
#include <string.h>

int main() {
	char str[1000000];
	char alp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num[27] = {0};
	int max = 0, cnt = 0;
	char result;
	char ch;
	
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		ch = str[i];
		if (ch >= 'a' && ch <= 'z')
			str[i] = ch - 32;
		for (int j = 0; j < 26; j++) {
			if (str[i] == alp[j])
				num[j]++;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		if (max < num[i])
			max = num[i];
	}
	
	for (int i = 0; i < 26; i++) {
		if (max == num[i]) {
			result = alp[i];
			cnt++;
		}
		if (cnt == 2) {
			result = '?';
			break;
		}
	}
	
	printf("%c", result);
	
	return 0;
}