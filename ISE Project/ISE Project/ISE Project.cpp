/*ISE Project BSSE-2A
Group Members:
Jawad Shahid - 21L5787
Zoya Arif - 21L5832
Romesa Qadeer - 21L5839
Haider Khan - 21L6067
Syed Farhan Jafri - 21L6074*/

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

int inputEmployees();
int inputCustomers();
int inputBilling();
void start();

string empuser[10], emppass[10];
int countEmployees = inputEmployees();
string id[10], cnic[10], name[10], address[10], number[10], custType[10], meterType[10], installDate[10], regUnits[10], peakUnits[10];
int countCustomers = inputCustomers();
string billingID[10], month[10], regReading[10], peakReading[10], entryDate[10], cost[10], tax[10], charges[10], total[10], dueDate[10], status[10], payDate[10];
int countBilling = inputBilling();
char ch;
int location;

string meterInfo[4];
string regInfo[4], peakInfo[4], taxInfo[4], chargeInfo[4];

void menu(int status)
{
	if (status == 0)
	{
		system("cls");
		cout << "\t\t\t\tGoodbye!" << endl;
		exit(0);
	}
	else if (status == 1)
	{
		system("cls");
		cout << "\t\t\t\t\t|LESCO|" << endl;
		cout << "\t\t\t\tWelcome to LESCO Portal!" << endl;
		cout << "\t\t\t\t1. Employee Login" << endl;
		cout << "\t\t\t\t2. Customer Login" << endl;
		cout << "\t\t\t\t3. Exit" << endl;
		cout << "\t\t\t\tChoice: ";
	}
	else if (status == 2)
	{
		system("cls");
		cout << "\t\t\t\t1. CustomerInfo file" << endl;
		cout << "\t\t\t\t2. BillingInfo file" << endl;
		cout << "\t\t\t\t3. Change password" << endl;
		cout << "\t\t\t\t4. Edit Tariffs" << endl;
		cout << "\t\t\t\t5. View Customer Bills" << endl;
		cout << "\t\t\t\t6. Logout" << endl;
		cout << "\t\t\t\tChoice: ";
	}
	else if (status == 3)
	{
		system("cls");
		cout << "\t\t\t\t1. Add new entry" << endl;
		cout << "\t\t\t\t2. Update existing entry" << endl;
		cout << "\t\t\t\t3. Logout" << endl;
		cout << "\t\t\t\tChoice: ";
	}
	if (status == 4)
	{
		system("cls");
		cout << "\t\t\t\tWelcome to LESCO Customer Portal!" << endl;
		cout << "\t\t\t\t1. Check Bill" << endl;
		cout << "\t\t\t\t2. Main Menu" << endl;
		cout << "\t\t\t\tChoice: ";
	}
}

int login()
{
	string user, pass;
	cout << "Please enter username: ";
	cin >> user;
	cout << "Please enter password: ";
	cin >> pass;

	int location = -1;

	for (int i = 0; i < countEmployees; i++)
	{
		if (empuser[i] == user && emppass[i] == pass)
		{
			location = i;
			i = countEmployees;
		}
	}

	return location;
}

int inputEmployees() // inputs all employee usernames and passwords from file
{
	int count = 0;

	ifstream Employees;
	Employees.open("EmployeeData.txt");

	string data = "";
	while (!Employees.eof())
	{
		getline(Employees, empuser[count], ',');
		getline(Employees, emppass[count]);
		count++;
	}
	Employees.close();

	return count;
}

int inputCustomers() // inputs all customer usernames and passwords from file
{
	int count = 0;

	ifstream Customers;
	Customers.open("CustomerInfo.txt");

	while (!Customers.eof())
	{
		getline(Customers, id[count], ',');
		getline(Customers, cnic[count], ',');
		getline(Customers, name[count], ',');
		getline(Customers, address[count], ',');
		getline(Customers, number[count], ',');
		getline(Customers, custType[count], ',');
		getline(Customers, meterType[count], ',');
		getline(Customers, installDate[count], ',');
		getline(Customers, regUnits[count], ',');
		getline(Customers, peakUnits[count]);
		count++;
	}
	Customers.close();

	return count;
}

int inputBilling()
{
	int count = 0;
	ifstream Billing;
	Billing.open("BillingInfo.txt");
	
	while (!Billing.eof())
	{
		getline(Billing, billingID[count], ',');
		getline(Billing, month[count], ',');
		getline(Billing, regReading[count], ',');
		getline(Billing, peakReading[count], ',');
		getline(Billing, entryDate[count], ',');
		getline(Billing, cost[count], ',');
		getline(Billing, tax[count], ',');
		getline(Billing, charges[count], ',');
		getline(Billing, total[count], ',');
		getline(Billing, dueDate[count], ',');
		getline(Billing, status[count], ',');
		getline(Billing, payDate[count]);
		count++;
	}
	
	Billing.close();
	return count;
}

void inputTariff()
{
	ifstream Tariff;
	Tariff.open("TariffTaxInfo.txt");
	for (int i = 0; i < 4; i++)
	{
		getline(Tariff, meterInfo[i], ',');
		getline(Tariff, regInfo[i], ',');
		getline(Tariff, peakInfo[i], ',');
		getline(Tariff, taxInfo[i], ',');
		getline(Tariff, chargeInfo[i]);
	}
	Tariff.close();
}

void writeEmployee()
{
	ofstream Employees;
	Employees.open("EmployeeData.txt", ios::trunc);
	for (int i = 0; i < countEmployees; i++)
	{
		Employees << empuser[i] << "," << emppass[i];
		if (i < countEmployees - 1) { Employees << endl; }
	}
	Employees.close();
}

void writeCustomer()
{
	ofstream Customers;
	Customers.open("CustomerInfo.txt", ios::trunc);
	for (int i = 0; i < countCustomers; i++)
	{
		if (meterType[i] == "1Phase")
		{
			peakUnits[i] = "-";
		}
		Customers << id[i] << "," << cnic[i] << "," << name[i] << "," << address[i] << "," << number[i] << "," << custType[i] << "," << meterType[i] << "," << installDate[i] << "," << regUnits[i] << "," << peakUnits[i] << endl;
		if (i < countCustomers - 1) { Customers << endl; }
	}
	Customers.close();
}

void changePassword()
{
	string newpass;

	int location = login();

	if (location != -1)
	{
		cout << "Please enter new password: ";
		cin >> newpass;
		emppass[location] = newpass;
		writeEmployee();
		cout << "Password has been updated successfully!" << endl;
	}
	else
	{
		cout << "Sorry, incorrect username and password combination, password change unsuccessful" << endl;
	}
}

void updateCustomer()
{
	string user, pass;

	cout << "Please enter ID" << endl;
	cin >> user;
	cout << "Please enter CNIC" << endl;
	cin >> pass;

	int location = -1;

	for (int i = 0; i < countCustomers; i++)
	{
		if (id[i] == user && cnic[i] == pass)
		{
			location = i;
			i = countCustomers;
		}
	}

	if (location != -1)
	{
		cout << "Please enter new readings" << endl;
		cout << "Regular Units: ";
		cin >> regUnits[location];
		cout << "Peak Units: ";
		cin >> peakUnits[location];
		writeCustomer();
		cout << "Readings have been updated successfully" << endl;
	}
	else
	{
		cout << "Sorry, could not find matching ID and CNIC" << endl;
	}
}

int countNumMeters(string CNIC)
{
	int count = 0;
	for (int i = 0; i < countCustomers; i++)
	{
		if (cnic[i] == CNIC)
		{
			count++;
		}
	}
	return count;
}

bool checkValidCNIC(string CNIC)
{
	string buffer;
	ifstream Nadra;
	Nadra.open("NADRADB.txt");
	while (!Nadra.eof()) {
		getline(Nadra, buffer, ',');
		if (buffer == CNIC)
		{
			return true;
		}
		getline(Nadra, buffer);
	}
	return false;
}

void newCustomer()
{
	bool flag = false;
	do
	{
		flag = true;
		cout << "Enter new customer ID (4 digits): ";
		cin >> id[countCustomers];
		if (id[countCustomers].length() > 4)
		{
			cout << "ID cannot be more than 4 digits" << endl;
			flag = false;
		}
		else
		{
			for (int i = 0; i < id[countCustomers].length(); i++)
			{
				if (id[countCustomers][i] < '0' || id[countCustomers][i] > '9')
				{
					cout << "Only digits are allowed for id" << endl;
					flag = false;
				}
			}
		}
	} while (flag == false);

	flag = false;
	do
	{
		flag = true;
		cout << "Enter new CNIC(13 digits): ";
		cin >> cnic[countCustomers];
		if (cnic[countCustomers].length() != 13)
		{
			cout << "CNIC must be exactly 13 digits long" << endl;
			flag = false;
		}
		else if (!(checkValidCNIC(cnic[countCustomers])))
		{
			cout << "CNIC is invalid as it is not registered in NADRA database" << endl;
			flag = false;
		}
		else if (countNumMeters(cnic[countCustomers]) >= 3)
		{
			cout << "Not Allowed! Maximum 3 meters allowed per CNIC" << endl;
			flag = false;
		}
	} while (flag == false);

	cout << "Enter Customer Name: ";
	cin >> name[countCustomers];
	cout << "Enter Address: ";
	cin >> address[countCustomers];
	cout << "Enter Phone Number: ";
	cin >> number[countCustomers];
	cout << "Enter Customer Type (Domestic or Commercial): ";
	cin >> custType[countCustomers];
	while (custType[countCustomers] != "Domestic" && custType[countCustomers] != "domestic" && custType[countCustomers] != "Commercial" && custType[countCustomers] != "commercial")
	{
		cout << "Customer type can only be Domestic or Commercial! Please enter again: ";
		cin >> custType[countCustomers];
	}
	cout << "Enter Meter Type (1Phase or 3Phase): ";
	cin >> meterType[countCustomers];
	while (meterType[countCustomers] != "1Phase" && meterType[countCustomers] != "3Phase")
	{
		cout << "Meter type can only be 1Phase or 3Phase! Please enter again: ";
		cin >> custType[countCustomers];
	}
	cout << "Enter Installation Date: ";
	cin >> installDate[countCustomers];
	regUnits[countCustomers] = peakUnits[countCustomers] = "0";
	countCustomers++;
	writeCustomer();
	cout << "Customer record has been created successfully!" << endl;
}

void writeBillingInfo()
{
	ofstream Billing;
	Billing.open("BillingInfo.txt", ios::trunc);
	for (int i = 0; i < countBilling; i++)
	{
		Billing << billingID[i] << "," << month[i] << "," << regReading[i] << "," << peakReading[i] << "," << entryDate[i] << "," << cost[i] << "," << tax[i] << "," << charges[i] << "," << total[i] << "," << dueDate[i] << "," << status[i] << "," << payDate[i] << endl;
	}
	Billing.close();
}

void addBilling()
{
	string idSearch;
	cout << "Please enter ID for which a bill must be added: ";
	cin >> idSearch;

	int location = -1;

	for (int i = 0; i < countCustomers; i++)
	{
		if (id[i] == idSearch)
		{
			location = i;
			i = countCustomers;
		}
	}

	if (location == -1)
	{
		cout << "ID does not exist in customer database" << endl;
	}

	else
	{
		int regConsumed = 0, peakConsumed = 0;
		billingID[countBilling] = id[location];
		cout << "Enter billing month: ";
		cin >> month[countBilling];
		cout << "Enter current regular meter reading: ";
		cin >> regReading[countBilling];
		regConsumed = stoi(regReading[countBilling]) - stoi(regUnits[location]);
		if (meterType[location] == "3Phase")
		{
			cout << "Enter current peak meter reading: ";
			cin >> peakReading[countBilling];
			peakConsumed = stoi(peakReading[countBilling]) - stoi(peakUnits[location]);
		}
		else
		{
			peakReading[countBilling] = "-";
		}
		cout << "Enter date of reading: ";
		cin >> entryDate[countBilling];
		if (meterType[location] == "1Phase")
		{
			if (custType[location] == "Domestic" || custType[location] == "domestic")
			{
				cost[countBilling] = to_string(stoi(regInfo[0]) * regConsumed);
				tax[countBilling] = taxInfo[0];
				charges[countBilling] = chargeInfo[0];
			}
			else if (custType[location] == "Commercial" || custType[location] == "commercial")
			{
				cost[countBilling] = to_string(stoi(regInfo[1]) * regConsumed);
				tax[countBilling] = taxInfo[1];
				charges[countBilling] = chargeInfo[1];
			}
		}

		else if (meterType[location] == "3Phase")
		{
			if (custType[location] == "Domestic" || custType[location] == "domestic")
			{
				cost[countBilling] = to_string(stoi(regInfo[2]) * regConsumed);
				cost[countBilling] = to_string((stoi(peakInfo[2]) * peakConsumed) + stoi(cost[countBilling]));
				tax[countBilling] = taxInfo[2];
				charges[countBilling] = chargeInfo[2];
			}
			else if (custType[location] == "Commercial" || custType[location] == "commercial")
			{
				cost[countBilling] = to_string(stoi(regInfo[2]) * regConsumed);
				cost[countBilling] = to_string((stoi(peakInfo[2]) * peakConsumed) + stoi(cost[countBilling]));
				tax[countBilling] = taxInfo[2];
				charges[countBilling] = chargeInfo[2];
			}
		}
		int taxAmount = stoi(tax[countBilling]) * stoi(cost[countBilling]) / 100;
		cout << taxAmount;
		total[countBilling] = to_string(stoi(cost[countBilling]) + taxAmount + stoi(charges[countBilling]));
		cout << "Enter Due Date: ";
		cin >> dueDate[countBilling];
		status[countBilling] = "Unpaid";
		payDate[countBilling] = "-";
		countBilling++;
		writeBillingInfo();
		cout << "Bill has been created successfully!" << endl;
	}
}

void updateBill()
{
	string idSearch;
	cout << "Please enter ID for which bill is paid: ";
	cin >> idSearch;

	int location = -1;

	for (int i = 0; i < countBilling; i++)
	{
		if (billingID[i] == idSearch)
		{
			location = i;
			i = countBilling;
		}
	}

	if (location == -1)
	{
		cout << "ID does not exist in Billing Database" << endl;
	}
	else
	{
		status[location] = "Paid";
		cout << "Enter date of payment: " << endl;
		cin >> payDate[location];
		int customerLocation = -1;
		for (int i = 0; i < countCustomers; i++)
		{
			if (id[i] == idSearch)
			{
				customerLocation = i;
				i = countCustomers;
			}
		}
		if (customerLocation != -1)
		{
			regUnits[customerLocation] = regReading[location];
			peakUnits[customerLocation] = peakReading[location];
		}
		writeBillingInfo();
		writeCustomer();
		cout << "Status has been updated successfully & new readings have been entered" << endl;
	}
}

void writeTariff()
{
	ofstream Tariff;
	Tariff.open("TariffTaxInfo.txt", ios::trunc);
	for (int i = 0; i < 4; i++)
	{
		Tariff << meterInfo[i] << "," << regInfo[i] << "," << peakInfo[i] << "," << taxInfo[i] << "," << charges[i] << endl;
	}
}

void editTariff()
{
	string meter, customer;
	cout << "Enter Meter Type (1Phase or 3Phase): ";
	cin >> meter;
	while (meter != "1Phase" && meter != "3Phase")
	{
		cout << "Only enter 1Phase or 3Phase, try again: ";
		cin >> meter;
	}
	cout << "Enter Customer Type (Domestic or Commercial): ";
	cin >> customer;
	while (customer != "domestic" && customer != "Domestic" && customer != "Commercial" && customer != "commercial")
	{
		cout << "Only enter Domestic or Commercial, try again: ";
		cin >> customer;
	}

	if (meter == "1Phase")
	{
		if (customer == "Domestic" || customer == "domestic")
		{
			cout << "Enter Regular Unit Price: ";
			cin >> regInfo[0];
			peakUnits[0] = "";
			cout << "Enter Percentage of Tax: ";
			cin >> taxInfo[0];
			cout << "Enter Fixed Charges: ";
			cin >> charges[0];
		}
		else if (customer == "Commercial" || customer == "commercial")
		{
			cout << "Enter Regular Unit Price: ";
			cin >> regInfo[1];
			peakUnits[1] = "";
			cout << "Enter Percentage of Tax: ";
			cin >> taxInfo[1];
			cout << "Enter Fixed Charges: ";
			cin >> charges[1];
		}
	}
	else if (meter == "3Phase")
	{
		if (customer == "Domestic" || customer == "domestic")
		{
			cout << "Enter Regular Unit Price: ";
			cin >> regInfo[2];
			cout << "Enter Peak Unit Price: ";
			cin >> peakInfo[2];
			cout << "Enter Percentage of Tax: ";
			cin >> taxInfo[2];
			cout << "Enter Fixed Charges: ";
			cin >> charges[2];
		}
		else if (customer == "Commercial" || customer == "commercial")
		{
			cout << "Enter Regular Unit Price: ";
			cin >> regInfo[3];
			cout << "Enter Peak Unit Price: ";
			cin >> peakInfo[3];
			cout << "Enter Percentage of Tax: ";
			cin >> taxInfo[3];
			cout << "Enter Fixed Charges: ";
			cin >> charges[3];
		}
	}
	writeTariff();
	cout << "Tariffs have been edited successfully!" << endl;
}

void printBill(int billingIndex, int customerIndex)
{
	cout << "\t\t\t\tLESCO Bill:" << endl << endl;

	cout << "Billing Month: " << month[billingIndex] << "\t\t\t\t\t\tCustomer ID: " << billingID[billingIndex] << endl;
	cout << "Current Meter Reading Regular: " << regReading[billingIndex] << "\t\t\t\tCustomer Name: " << name[customerIndex] << endl;
	cout << "Current Meter Reading Peak: " << peakReading[billingIndex] << "\t\t\t\t\tCustomer Address: " << address[customerIndex] << endl;
	cout << "Reading Entry Date: " << entryDate[billingIndex] << "\t\t\t\t\tCustomer Phone Number: " << number[customerIndex] << endl;
	cout << "\t\t\t\t\t\t\t        Customer Type: " << custType[customerIndex] << endl;
	cout << "\t\t\t\t\t\t\t        Meter Type: " << meterType[customerIndex] << endl << endl;


	cout << "Costs & Charges Data:\t\t\t\t\t\tTotal Amount Due: " << total[billingIndex] << endl;
	cout << "Cost of Electricity: " << cost[billingIndex] << "\t\t\t\t\tDue Date: " << dueDate[billingIndex] << endl;
	cout << "Sales Tax Amount: " << tax[billingIndex] << endl;
	cout << "Fixed Charges: " << charges[billingIndex] << endl << endl;

	cout << "Tariffs:" << endl;
	cout << "1Phase:" << endl;
	cout << "\tDomestic:" << endl;
	cout << "\t\tRegular Unit: " << regInfo[0] << " rupees" << endl;
	cout << "\tCommercial: " << endl;
	cout << "\t\tRegular Unit: " << regInfo[1] << " rupees" << endl;
	cout << "3Phase:" << endl;
	cout << "\tDomestic:" << endl;
	cout << "\t\tRegular Unit: " << regInfo[2] << " rupees" << endl;
	cout << "\t\tPeak Unit: " << peakInfo[2] << " rupees" << endl;
	cout << "\tCommercial: " << endl;
	cout << "\t\tRegular Unit: " << regInfo[3] << " rupees" << endl;
	cout << "\t\tPeak Unit: " << peakInfo[3] << " rupees" << endl << endl;

	cout << "Bill Status: " << status[billingIndex] << endl;
	if (status[billingIndex] == "Paid")
	{
		cout << "Bill Payment Date: " << payDate[billingIndex] << endl;
	}
}

void viewBillEmployee(string userID)
{
	int billingIndex = -1, customerIndex = -1;
	for (int i = 0; i < countBilling; i++)
	{
		if (billingID[i] == userID)
		{
			billingIndex = i;
			i = countBilling;
		}
	}
	for (int i = 0; i < countCustomers; i++)
	{
		if (id[i] == userID)
		{
			customerIndex = i;
			i = countCustomers;
		}
	}

	if (billingIndex != -1)
	{
		printBill(billingIndex, customerIndex);
	}
	else
	{
		cout << "No existing bill found matching entered user ID" << endl;
	}
}

void startEmployee()
{
	menu(2);
	ch = _getche();
	cout << endl;
	if (ch == '1')
	{
		menu(3);
		ch = _getche();
		if (ch == '1')
		{
			system("cls");
			newCustomer();
			system("pause");
			startEmployee();
		}
		else if (ch == '2')
		{
			system("cls");
			updateCustomer();
			system("pause");
			startEmployee();
		}
		else if (ch == '3')
		{
			start();
		}
	}
	else if (ch == '2')
	{
		menu(3);
		ch = _getche();
		if (ch == '1')
		{
			system("cls");
			addBilling();
			system("pause");
			startEmployee();
		}
		else if (ch == '2')
		{
			system("cls");
			updateBill();
			system("pause");
			startEmployee();
		}
		else if (ch == '3')
		{
			start();
		}

	}
	else if (ch == '3')
	{
		system("cls");
		changePassword();
		system("pause");
		startEmployee();
	}
	else if (ch == '4')
	{
		system("cls");
		editTariff();
		system("pause");
		startEmployee();
	}
	else if (ch == '5')
	{
		string userID;
		system("cls");
		cout << "Please enter customer ID for which you want to view bill: ";
		cin >> userID;
		viewBillEmployee(userID);
		system("pause");
		startEmployee();
	}
	else if (ch == '6')
	{
		start();
	}
}

void startCustomer()
{
	menu(4);
	ch = _getche();
	if (ch == '1')
	{
		system("cls");
		string userID, userCNIC;
		cout << "Please enter user ID: ";
		cin >> userID;
		cout << "Please enter registered CNIC:";
		cin >> userCNIC;

		int customerIndex = -1;

		for (int i = 0; i < countCustomers; i++)
		{
			if (id[i] == userID && cnic[i] == userCNIC)
			{
				customerIndex = i;
				i = countCustomers;
			}
		}

		int billingIndex = -1;

		if (customerIndex != -1)
		{
			for (int i = 0; i < countBilling; i++)
			{
				if (billingID[i] == userID)
				{
					billingIndex = i;
					i = countBilling;
				}
			}

			if (billingIndex != -1)
			{
				printBill(billingIndex, customerIndex);
				system("pause");
				startCustomer();
			}
			else
			{
				cout << "No bill has been generated for this user so far" << endl;
				system("pause");
				startCustomer();
			}
		}
		else
		{
			cout << "User ID and CNIC combination does not exist in database" << endl;
			system("pause");
			startCustomer();
		}
	}
	else if (ch == '2')
	{
		system("cls");
		start();
	}
}

void start()
{
	menu(1);
	ch = _getche();
	if (ch == '1')
	{
		system("cls");
		location = login();
		if (location == -1)
		{
			cout << "Incorrect username and password combination!" << endl;
			system("pause");
		}
		else
		{
			cout << "Login successful!" << endl;
			system("pause");
			startEmployee();
		}
	}
	else if (ch == '2')
	{
		system("cls");
		startCustomer();
	}
	else if (ch == '3')
	{
		menu(0);
	}
}

int main()
{
	while (1)
	{
		inputTariff();
		start();
	}
}