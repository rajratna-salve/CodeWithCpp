#include<iostream>
#include<fstream>
using namespace std;

class Patient
{
	public:
		int PatientId,age;
		string PatientName,Disease,DoctorName;
		float HospitalCharges;
	void input()
	{
		cout<<"Enter Patient Id : "<<endl;
		cin>>PatientId;
		cout<<"Enter Patinet Name : " <<endl;
		cin>>PatientName;
		cout<<"Enter Patient Age: "<<endl;
		cin>>age;
		cout<<"Disease: "<<endl;
		cin>>Disease;
		cout<<"Enter Doctor Name: "<<endl;
		cin>>DoctorName;
		cout<<"Enter Hospital Charges: "<<endl;
		cin>>HospitalCharges;
	}
	void display()
	{
		cout<<"Patient Id: "<<PatientId<<endl;
		cout<<"Patient Name: "<<PatientName<<endl;
		cout<<"Patient Age: "<<age<<endl;
		cout<<"PAtient Disease: "<<Disease<<endl;
		cout<<"Doctor Name: "<<DoctorName<<endl;
		cout<<"Hospital Charges: "<<HospitalCharges<<endl;		
	}
	int getId()
	{
		return PatientId;
	}
	void update()
    {
        cout << "Patient Name: ";
        cin >> PatientName;
        cout << "Age: ";
        cin >> age;
        cout << "Disease: ";
        cin >> Disease;
        cout << "Doctor Name: ";
        cin >> DoctorName;
        cout << "Hospital Charges: ";
        cin >> HospitalCharges;
    }
};
	void addPatient()
	{
    	Patient p;
   		ofstream fout("patient.dat", ios::binary | ios::app);

    	p.input();
    	fout.write((char*)&p, sizeof(p));

    	fout.close();
    	cout << "\nPatient added successfully.";
	}

	void displayAll()
	{
   		Patient p;
   		ifstream fin("patient.dat", ios::binary);

   		while (fin.read((char*)&p, sizeof(p)))
        p.display();

    	fin.close();
}
	void searchPatient()
	{
    	Patient p;
    	int id;
    	bool found = false;

    	cout << "\nEnter Patient ID: ";
    	cin >> id;

    	ifstream fin("patient.dat", ios::binary);

    	while (fin.read((char*)&p, sizeof(p)))
    	{
        	if (p.getId() == id)
        	{
           	 	p.display();
            	found = true;
            	break;
        	}
    	}

    	fin.close();

    	if (!found)
        	cout << "\nPatient not found.";
	}
	void updatePatient()
	{
    	Patient p;
    	int id;
    	bool found = false;

    	cout << "\nEnter Patient ID: ";
    	cin >> id;

    	fstream file("patient.dat", ios::binary | ios::in | ios::out);

    	while (file.read((char*)&p, sizeof(p)))
   	 	{
        	if (p.getId() == id)
        	{
            	p.update();

            	file.seekp(-sizeof(p), ios::cur);
            	file.write((char*)&p, sizeof(p));

            	found = true;
            	cout << "\nPatient updated successfully.";
            	break;
        	}
    	}

    	file.close();

    	if (!found)
        	cout << "\nPatient not found.";
}

	void deletePatient()
	{
   	 	Patient p;
    	int id;
    	bool found = false;

    	cout << "\nEnter Patient ID: ";
    	cin >> id;

    	ifstream fin("patient.dat", ios::binary);
    	ofstream fout("temp.dat", ios::binary);

    	while (fin.read((char*)&p, sizeof(p)))
    	{
        	if (p.getId() == id)
            	found = true;
        	else
            	fout.write((char*)&p, sizeof(p));
   	 	}

    	fin.close();
    	fout.close();

    	remove("patient.dat");
    	rename("temp.dat", "patient.dat");

    	if (found)
        	cout << "\nPatient deleted successfully.";
    	else
        	cout << "\nPatient not found.";
	}

main()
{
	int choice;
	do
	{	
		cout<<"\n<=============Hospital Raj===============>"<<endl;
		cout<<"1. Add New Patient."<<endl;
		cout<<"2. Display Patient."<<endl;
		cout<<"3. Search for Patient."<<endl;
		cout<<"4. Update Patient Info."<<endl;
		cout<<"5. Delete Patient Record."<<endl;
		cout<<"6. Exit."<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				addPatient();
				break;
			case 2:
				displayAll();
				break;
			case 3:
				searchPatient();
				break;
			case 4:
				updatePatient();
				break;
			case 5:
				deletePatient();
				break;
			case 6:
				cout<<"\n Thank you For Visiting Hospital Raj!"<<endl;
			
		}
	}
	while(choice!=6);
}

/*Create class patient 
patient Id
patient name
age
Disease
doctor name
Hospital Charges

provide following operation
add new patient
display all patient
serach for patient by patient id
update patient info
delete patient
store all records permanently in file
*/
