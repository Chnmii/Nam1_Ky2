#include<stdio.h>
#include<math.h>
#include<string.h>

void ktra(char *a){
	int ktra;
	for(int i=0; i<strlen(a); i++){
		if(a[i]>='0' && a[i]<='9')
			ktra=1;
		else{
			ktra=0;
			break;
		}
	}
	if(ktra==1)
		printf("Xau da nhap la chuoi so\n");
	else
		printf("Xau da nhap khong phai la chuoi so\n");
		
}

int dem_so_tu(char *a){
	int dem=0;
	if(a[0]!=' ')
		dem=1;
	for(int i=0; i<strlen(a)-1; i++)
	{
		if(a[i]==' ' && a[i+1]!=' ')
			dem++;
	}
	return dem;
}

int dem_ki_tu(char *a){
	int count=0;
	while (a[count] != '\0'){
		count++;
	}
	return count;
}

void laytrai(char *a){
	int i,n;
	printf("Nhap so ki tu can lay tu ben trai trong xau :");
	scanf("%d",&n);
	char b[1000];
	strncpy(b,a,n);
	printf("%s\n",b);
}

void layphai(char *a){
	int i,n;
	printf("Nhap so ki tu can lay tu ben phai trong xau : ");
	scanf("%d",&n);
	char b[1000];
	strncpy(b,strrev(a),n);
	printf("%s\n",strrev(b));
	strrev(a);
}

void lay(char *a){
	int i,n,m;
	printf("Nhap so ki tu can lay trong xau : ");
	scanf("%d",&n);
	printf("Bat dau tu vi tri thu : ");
	scanf("%d",&m);
	for(i=m-1;i<m+n-1;i++){
		printf("%c",a[i]);
	}
}

int main(){
	char a[1000];
	printf("Nhap xau ki tu: ");
	fflush(stdin);
	gets(a);
	
	ktra(a);
	printf("So tu trong xau la : %d\n", dem_so_tu(a));
	printf("So ki tu trong xau la : %d\n", dem_ki_tu(a));
	laytrai(a);
	layphai(a);
	lay(a);
	
	return 0;
}

