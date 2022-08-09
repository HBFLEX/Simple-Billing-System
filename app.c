#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void readinput(int i);
void writeoutput(int i);

struct  date {
	int year;
	int month;
	int day;
};

struct account {
	char name[80];
	char street[80];
	char city[80];
	char acc_type;
	int acc_no;
	float old_balance;
	float new_balance;
	float payment;
	struct date last_payment;
};

struct account customer[100];

int main(void) {

	int i, n;
	printf("\n\t\t\t\t\tSimple Billing System\n\n");
	printf("How many customers are there? \n");
	scanf("%d", &n);

	for (i = 0; i < n; ++i){
		readinput(i);
		/* determine the account status*/
		if (customer[i].payment > 0)
			customer[i].acc_type = (customer[i].payment < 0.1 * customer[i].old_balance) ? 'O' : 'C';
		else
			customer[i].acc_type = (customer[i].old_balance > 0) ? 'D' : 'C';
		/* adjust the account balance */
		customer[i].new_balance = customer[i].old_balance - customer[i].payment;
	}

	for (i = 0; i < n; i++)
		writeoutput(i);
	return 0;
}


void readinput(int i) {

	printf("\n Customer no: %d\n\n", i + 1);
	printf("name of customer: ");
	scanf("%s", customer[i].name);
	printf("Enter your street: ");
	scanf("%s", customer[i].street);
	printf("Enter your city: ");
	scanf("%s", customer[i].city);
	printf("Enter account no: ");
	scanf("%d", &customer[i].acc_no);
	printf("Enter previous balance: ");
	scanf("%f", &customer[i].old_balance);
	printf("Enter payment: ");
	scanf("%f", &customer[i].payment);
	printf("Enter payment date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &customer[i].last_payment.month,
		&customer[i].last_payment.day,
		&customer[i].last_payment.year);

	return;
}

void writeoutput(int i) {

	printf("\n\n");
	printf("Name: %s", customer[i].name);
	printf("\tAcc_no: %d\n\n", customer[i].acc_no);
	printf("Street: %s\n\n", customer[i].street);
	printf("City: %s\n\n", customer[i].city);
	printf("Old Balance: %.2f", customer[i].old_balance);
	printf("\t Current Payment: %.2f", customer[i].payment);
	printf("\t New Balance: %.2f\n\n", customer[i].new_balance);
	printf("Payment Date: %d/%d/%d\n\n", customer[i].last_payment.month,
		customer[i].last_payment.day, customer[i].last_payment.year);
	printf("Account Status:");

	switch (customer[i].acc_type) {
		case 'C':
			printf("CURRENT\n\n");
			break;
		case 'O':
			printf("OVERDUE\n\n");
			break;
		case 'D':
			printf("DELIQUENT\n\n");
			break;
		default:
			printf("ERROR PROCESSING ACCOUNT TYPE !!\n\n");
	}

	return;
}