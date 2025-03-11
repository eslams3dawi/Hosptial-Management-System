#include <iostream>
using namespace std;

class Doctor
{
public:
	class NodeDoctor
	{
	public:
		Doctor* DoctorData;
		NodeDoctor* Next;
		NodeDoctor() : DoctorData(NULL) {}

		NodeDoctor(int ID, string Name, string Specialization, int BranchID)
		{
			DoctorData = new Doctor(ID, Name, Specialization, BranchID);
		}
	};

	NodeDoctor* Head;
	int Count = 0;

	int DoctorID;
	string DoctorName;
	string DoctorSpecialization;
	int DoctorBranch;

	Doctor() :
		DoctorID(0), DoctorName("Unkown"), DoctorSpecialization("Unkown"), DoctorBranch(NULL), Head(NULL) {}

	Doctor(int ID, string Name, string Specialization, int BranchID) :
		DoctorID(ID), DoctorName(Name), DoctorSpecialization(Specialization), DoctorBranch(BranchID), Head(NULL) {}

	bool IsEmpty()
	{
		return Head == NULL;
	}

	bool IdIsFound(int ID)
	{
		NodeDoctor* DoctorID = Head;
		while (DoctorID != NULL)
		{
			if (DoctorID->DoctorData->DoctorID == ID)
			{
				return true;
			}
			DoctorID = DoctorID->Next;
		}
		return false;
	}

	Doctor* IsDoctorExist(int DoctorID)
	{
		NodeDoctor* WantedDoctor = Head;
		while (WantedDoctor != NULL)
		{
			if (WantedDoctor->DoctorData->DoctorID == DoctorID)
			{
				return WantedDoctor->DoctorData;
			}
			WantedDoctor = WantedDoctor->Next;
		}
		return NULL;
	}

	void AddNewDoctor(int ID, string Name, string Specialization, int BranchID)
	{
		NodeDoctor* NewDoctor = new NodeDoctor(ID, Name, Specialization, BranchID);
		NewDoctor->Next = NULL;
		if (IsEmpty())
		{
			Head = NewDoctor;
		}
		else
		{
			NodeDoctor* Tail = Head;
			while (Tail->Next != NULL)
			{
				Tail = Tail->Next;
			}
			Tail->Next = NewDoctor;
		}
		cout << "The doctor is added successfully" << endl;
	}

	void RemoveDoctor(int ID)
	{
		if (IsEmpty())
			cout << "The Doctor list is already empty" << endl;

		else
		{
			if (IdIsFound(ID))
			{
				if (Head->DoctorData->DoctorID == ID)
				{
					NodeDoctor* DeleteFirst = Head;
					Head = Head->Next;
					delete DeleteFirst;
				}
				else
				{
					NodeDoctor* PreviousOfDeleted = NULL;
					NodeDoctor* DeletedDoctor = Head;

					while (DeletedDoctor->DoctorData->DoctorID != ID)
					{
						PreviousOfDeleted = DeletedDoctor;
						DeletedDoctor = DeletedDoctor->Next;
					}
					PreviousOfDeleted->Next = DeletedDoctor->Next;
					delete DeletedDoctor;
				}
				cout << "The doctor is removed successfully" << endl;
			}
			else
				cout << "ID : " << ID << " is not in our system, please contact technical support" << endl;
		}
	}

	void DisplayAllDoctors()
	{
		if (IsEmpty())
			cout << "There is no doctors" << endl;
		else
		{
			NodeDoctor* CurrentDoctor = Head;
			while (CurrentDoctor != NULL)
			{
				cout << "Doctor ID : " << CurrentDoctor->DoctorData->DoctorID << endl;
				cout << "Doctor name : " << CurrentDoctor->DoctorData->DoctorName << endl;
				cout << "Doctor specialization : " << CurrentDoctor->DoctorData->DoctorSpecialization << endl;
				cout << "Branch details : " << endl;
				cout << "Branch ID : " << CurrentDoctor->DoctorData->DoctorBranch << endl;
				cout << "------------------------------------" << endl;
				CurrentDoctor = CurrentDoctor->Next;
			}
		}
	}

	int GetNumberOfDoctors()
	{
		Count = 0;
		NodeDoctor* Temp = Head;
		while (Temp != NULL)
		{
			Count++;
			Temp = Temp->Next;
		}
		return Count;
	}

	void RemoveDoctorsByBranch(int BranchID)
	{
		NodeDoctor* CurrentDoctor = Head, * prev = NULL;
		while (CurrentDoctor != NULL)
		{
			if (CurrentDoctor->DoctorData->DoctorBranch == BranchID)
			{
				RemoveDoctor(CurrentDoctor->DoctorData->DoctorID);
			}
			CurrentDoctor = CurrentDoctor->Next;
		}
		cout << "All doctors in branch " << BranchID << " removed successfully!\n";
	}
};

class Branch
{
public:
	class NodeBranch
	{
	public:
		Branch* BranchData;
		NodeBranch* Next;

		NodeBranch() : BranchData(NULL) {}

		NodeBranch(int ID, string Name, string Location)
		{
			BranchData = new Branch(ID, Name, Location); // take instance and intialize it 
		}
	};

	NodeBranch* Head;
	int Count = 0;

	int BranchID;
	string BranchName;
	string BranchLocation;
	Doctor D;

	Branch() :
		BranchID(0), BranchName("Unkown"), BranchLocation("Unkown"), Head(NULL) {}

	Branch(int ID, string Name, string Location) :
		BranchID(ID), BranchName(Name), BranchLocation(Location), Head(NULL) {}

	bool IsEmpty()
	{
		return Head == NULL;
	}

	bool IdIsFound(int ID)
	{
		NodeBranch* BranchID = Head;
		while (BranchID != NULL)
		{
			if (BranchID->BranchData->BranchID == ID)
			{
				return true;
			}
			BranchID = BranchID->Next;
		}
		return false;
	}

	Branch* IsBranchExist(int ID)
	{
		NodeBranch* WantedBranch = Head;
		while (WantedBranch != NULL)
		{
			if (WantedBranch->BranchData->BranchID == ID)
			{
				return WantedBranch->BranchData;
			}
			WantedBranch = WantedBranch->Next;
		}
		return NULL;
	}

	void AddNewBranch(int ID, string Name, string Location)
	{
		NodeBranch* NewBranch = new NodeBranch(ID, Name, Location);
		NewBranch->Next = NULL;

		if (IsEmpty())
		{
			Head = NewBranch;
		}
		else
		{
			NodeBranch* Tail = Head;
			while (Tail->Next != NULL)
			{
				Tail = Tail->Next;
			}
			Tail->Next = NewBranch;
		}
		cout << "The branch is added successfully" << endl;
	}

	void RemoveBranch(int ID)
	{
		if (IsEmpty())
			cout << "The list of branches is already empty ! " << endl;
		else
		{
			if (IdIsFound(ID))
			{
				if (Head->BranchData->BranchID == ID)
				{
					NodeBranch* DeleteFirst = Head;
					Head = Head->Next;
					delete DeleteFirst;
				}
				else
				{
					NodeBranch* PreviousOfDeleted = NULL;
					NodeBranch* DeletedBranch = Head;

					while (DeletedBranch->BranchData->BranchID != ID)
					{
						PreviousOfDeleted = DeletedBranch;
						DeletedBranch = DeletedBranch->Next;
					}
					PreviousOfDeleted->Next = DeletedBranch->Next;
					delete DeletedBranch;
				}
				cout << "The branch is removed successfully" << endl;
			}
			else
				cout << "ID : " << ID << " is not in our system, please contact technical support" << endl;
		}
	}

	void SearchForBranch(int ID)
	{
		if (IsEmpty())
			cout << "There is no branches" << endl;
		else
		{
			if (IdIsFound(ID))
			{
				NodeBranch* WantedBranch = Head; 
				while (WantedBranch->BranchData->BranchID != ID)
				{
					WantedBranch = WantedBranch->Next;
				}
				cout << "Branch ID : " << WantedBranch->BranchData->BranchID << endl;
				cout << "Branch name : " << WantedBranch->BranchData->BranchName << endl;
				cout << "Branch location : " << WantedBranch->BranchData->BranchLocation << endl;
				cout << "-----------------------------------------" << endl;
			}
			else
				cout << "The branch ID : " << ID << " is not in our system, please contact technical support" << endl;
		}
	}

	void DisplayAllBranches()
	{
		if (IsEmpty())
			cout << "There is no branches" << endl;
		else
		{
			NodeBranch* CurrentBranch = Head;
			while (CurrentBranch != NULL)
			{
				cout << "Branch ID : " << CurrentBranch->BranchData->BranchID << endl;
				cout << "Branch mame : " << CurrentBranch->BranchData->BranchName << endl;
				cout << "Branch location : " << CurrentBranch->BranchData->BranchLocation << endl;
				cout << "-----------------------------------------" << endl;
				CurrentBranch = CurrentBranch->Next;
			}
		}
	}

	int GetTheNumberOfBranches()
	{
		Count = 0;
		NodeBranch* Temp = Head;
		while (Temp != NULL)
		{
			Count++;
			Temp = Temp->Next;
		}
		return Count;
	}
};

class Patient
{
public:
	class NodePatient
	{
	public:
		Patient* PatientData;
		NodePatient* Next;

		NodePatient() : PatientData(NULL) {}
		NodePatient(int ID, string Name, string Address)
		{
			PatientData = new Patient(ID, Name, Address);
		}
	};

	NodePatient* Head;
	int Count = 0;

	int PatientID;
	string PatientName;
	string PatientAddress;

	Patient() :
		PatientID(0), PatientName("Unkown"), PatientAddress("Unkown"), Head(NULL) {}

	Patient(int ID, string Name, string Address) :
		PatientID(ID), PatientName(Name), PatientAddress(Address), Head(NULL) {}

	bool IsEmpty()
	{
		return Head == NULL;
	}

	bool IdIsFound(int ID)
	{
		NodePatient* PatientID = Head;
		while (PatientID != NULL)
		{
			if (PatientID->PatientData->PatientID == ID)
			{
				return true;
			}
			PatientID = PatientID->Next;
		}
		return false;
	}

	Patient* IsPatientExist(int PatientID)
	{
		NodePatient* WantedPatient = Head;
		while (WantedPatient != NULL)
		{
			if (WantedPatient->PatientData->PatientID = PatientID)
			{
				return WantedPatient->PatientData;
			}
			WantedPatient = WantedPatient->Next;
		}
		return NULL;
	}

	void AddNewPatient(int ID, string Name, string Address)
	{
		NodePatient* NewPatient = new NodePatient(ID, Name, Address);
		NewPatient->Next = NULL;

		if (IsEmpty())
		{
			Head = NewPatient;
		}
		else
		{
			NodePatient* Tail = Head;
			while (Tail->Next != NULL)
			{
				Tail = Tail->Next;
			}
			Tail->Next = NewPatient;
		}
		cout << "The patient is added successfully" << endl;
	}

	void RemovePatient(int ID)
	{
		if (IsEmpty())
			cout << "There is no patients" << endl;

		else
		{
			if (IdIsFound(ID))
			{
				if (Head->PatientData->PatientID == ID)
				{
					NodePatient* DeleteFirst = Head;
					Head = Head->Next;
					delete DeleteFirst;
				}
				else
				{
					NodePatient* PreviousOfDeleted = NULL;
					NodePatient* DeletedPatient = Head;

					while (DeletedPatient->PatientData->PatientID != ID)
					{
						PreviousOfDeleted = DeletedPatient;
						DeletedPatient = DeletedPatient->Next;
					}
					PreviousOfDeleted->Next = DeletedPatient->Next;
					delete DeletedPatient;
				}
				cout << "The patient is removed successfully" << endl;
			}
			else
				cout << "ID : " << ID << " is not found in our system, please contact technical support" << endl;
		}
	}

	void SearchForPatient(int ID)
	{
		if (IsEmpty())
			cout << "There is no patients" << endl;
		else
		{
			if (IdIsFound(ID))
			{
				NodePatient* WantedPatient = Head;
				while (WantedPatient->PatientData->PatientID != ID)
				{
					WantedPatient = WantedPatient->Next;
				}
				cout << "The patient ID : " << WantedPatient->PatientData->PatientID << endl;
				cout << "The patient name : " << WantedPatient->PatientData->PatientName << endl;
				cout << "The patient address : " << WantedPatient->PatientData->PatientAddress << endl;
				cout << "-----------------------------------------" << endl;
			}
			else
				cout << "The patient ID is not in our system, please contact technical support" << endl;
		}
	}

	void UpdatePatientInformationById(int ID, int UserUpdate)
	{
		if (IdIsFound(ID))
		{
			NodePatient* Temp = Head;
			while (Temp->PatientData->PatientID != ID)
			{
				Temp = Temp->Next;
			}
			if (Temp != NULL && Temp->PatientData != NULL)// check the patient data is not empty after ensuring that it's ID is exist
			{
				int NewID;
				string NewName, NewAddress;

				switch (UserUpdate)
				{
				case 1:
					cout << "Entet the new ID : ";
					cin >> NewID;
					Temp->PatientData->PatientID = NewID;
					break;
				case 2:
					cout << "Enter the new name : ";
					cin >> NewName;
					Temp->PatientData->PatientName = NewName;
					break;
				case 3:
					cout << "Enter the new address : ";
					cin >> NewAddress;
					Temp->PatientData->PatientAddress = NewAddress;
					break;
				default:
					cout << "Invalid option, please write again in a correct way " << endl;
				}
			}
			else
				cout << "Unable to update" << endl;
		}
		else
			cout << "The patient ID " << ID << " is not in our system " << endl;
	}

	int GetTheNumberOfPatients()
	{
		NodePatient* Temp = Head; 
		while (Temp != NULL)
		{
			Count++;
			Temp = Temp->Next;
		}
		return Count;
	}
};

class Appointment
{
public:
	class NodeAppointment
	{
	public:
		Appointment* AppointmentData;
		NodeAppointment* Next;

		NodeAppointment()
			:AppointmentData(NULL) {}

		NodeAppointment(int ID, string Date, Patient* Patient, Doctor* Doctor, Branch* Branch)
		{
			AppointmentData = new Appointment(ID, Date, Patient, Doctor, Branch);
		}
	};

	NodeAppointment* Head;

	int AppointmentID;
	string AppointmentDate;
	Patient* PatientDetails;
	Doctor* DoctorDetails;
	Branch* BranchDetails;

	Appointment() : AppointmentID(0), AppointmentDate("Unkown"), PatientDetails(NULL), DoctorDetails(NULL), BranchDetails(NULL), Head(NULL) {}
	Appointment(int ID, string Date, Patient* Patient, Doctor* Doctor, Branch* Branch) : AppointmentID(ID), AppointmentDate(Date), PatientDetails(Patient), DoctorDetails(Doctor), BranchDetails(Branch), Head(NULL) {}

	bool IsEmptyAppointments()
	{
		return Head == NULL;
	}

	void BookAppointment(int ID, string Date, Patient* Patient, Doctor* Doctor, Branch* Branch)
	{
		NodeAppointment* NewAppointment = new NodeAppointment(ID, Date, Patient, Doctor, Branch);
		NewAppointment->Next = NULL;
		if (IsEmptyAppointments())
			Head = NewAppointment;
		else
		{
			NodeAppointment* Tail = Head;
			while (Tail->Next != NULL)
			{
				Tail = Tail->Next;
			}
			Tail->Next = NewAppointment;
			Tail = NewAppointment;
		}
		cout << "The appointment is booked successfully" << endl;
	}

	void DisplayAppointmentsForBranch(int ID)
	{
		NodeAppointment* WantedAppointment = Head;
		while (WantedAppointment != NULL)
		{
			if (WantedAppointment->AppointmentData->BranchDetails->BranchID == ID)
			{
				cout << "Branch ID : " << WantedAppointment->AppointmentData->BranchDetails->BranchID << endl;
				cout << "Branch name : " << WantedAppointment->AppointmentData->BranchDetails->BranchName << endl;
				cout << "Branch location : " << WantedAppointment->AppointmentData->BranchDetails->BranchLocation << endl;
				cout << "Appointments of branch ID [" << WantedAppointment->AppointmentData->BranchDetails->BranchID << "] : " << endl;
				cout << "	Appointment ID : " << WantedAppointment->AppointmentData->AppointmentID << endl;
				cout << "	Appointment date : " << WantedAppointment->AppointmentData->AppointmentDate << endl;
				cout << "	Patient name : " << WantedAppointment->AppointmentData->PatientDetails->PatientName << endl;
				cout << "	Doctor name : " << WantedAppointment->AppointmentData->DoctorDetails->DoctorName << endl;
			}
			WantedAppointment = WantedAppointment->Next;
		}
	}

	void DisplayAllAppointmentsForDoctor(int ID)
	{
		NodeAppointment* WantedAppointment = Head;
		while (WantedAppointment != NULL)
		{
			if (WantedAppointment->AppointmentData->DoctorDetails->DoctorID == ID)
			{
				cout << "Doctor ID : " << WantedAppointment->AppointmentData->BranchDetails->BranchID << endl;
				cout << "Doctor name : " << WantedAppointment->AppointmentData->BranchDetails->BranchName << endl;
				cout << "Appointments of doctor ID [" << WantedAppointment->AppointmentData->BranchDetails->BranchID << "] : " << endl;
				cout << "	Appointment ID : " << WantedAppointment->AppointmentData->AppointmentID << endl;
				cout << "	Appointment date : " << WantedAppointment->AppointmentData->AppointmentDate << endl;
				cout << "	Patient name : " << WantedAppointment->AppointmentData->PatientDetails->PatientName << endl;
				cout << "	Branch name : " << WantedAppointment->AppointmentData->BranchDetails->BranchName << endl;
			}
			WantedAppointment = WantedAppointment->Next;
		}
	}

	void DisplayAllAppointmentsForPatient(int ID)
	{
		NodeAppointment* WantedAppointment = Head;
		while (WantedAppointment != NULL)
		{
			if (WantedAppointment->AppointmentData->PatientDetails->PatientID == ID)
			{
				cout << "Patient ID : " << WantedAppointment->AppointmentData->BranchDetails->BranchID << endl;
				cout << "Patient name : " << WantedAppointment->AppointmentData->BranchDetails->BranchName << endl;
				cout << "Appointments of patient ID [" << WantedAppointment->AppointmentData->BranchDetails->BranchID << "] : " << endl;
				cout << "	Appointment ID : " << WantedAppointment->AppointmentData->AppointmentID << endl;
				cout << "	Appointment date : " << WantedAppointment->AppointmentData->AppointmentDate << endl;
				cout << "	Doctor name : " << WantedAppointment->AppointmentData->DoctorDetails->DoctorName << endl;
				cout << "	Branch name : " << WantedAppointment->AppointmentData->BranchDetails->BranchName << endl;
			}
			WantedAppointment = WantedAppointment->Next;
		}
	}

	void DisplayAllAppointments()
	{
		NodeAppointment* Current = Head;
		while (Current != NULL)
		{
			cout << "Appointment ID : " << Current->AppointmentData->AppointmentID << endl;
			cout << "Appointment Date : " << Current->AppointmentData->AppointmentDate << endl;

			cout << "	Doctor Name : " << Current->AppointmentData->DoctorDetails->DoctorName << endl;
			cout << "	Patient Name : " << Current->AppointmentData->PatientDetails->PatientName << endl;
			cout << "	Branch Name : " << Current->AppointmentData->BranchDetails->BranchName << endl;
			Current = Current->Next;
		}
	}
};

void Menu()
{
	cout << "[1] Add new branch" << endl;
	cout << "[2] Remove branch" << endl;
	cout << "[3] Display All Branches" << endl;
	cout << "[4] Search for branch (by ID)" << endl;
	cout << "[5] Display all appointments for branch (by ID)" << endl;
	cout << "[6] Show the number of all branches" << endl << endl;

	cout << "[7] Add new doctor" << endl;
	cout << "[8] Remove doctor" << endl;
	cout << "[9] Display all appointments for doctor" << endl;
	cout << "[10] Show all doctors" << endl << endl;

	cout << "[11] Add new patient" << endl;
	cout << "[12] Remove patient" << endl;
	cout << "[13] Book appointment" << endl;
	cout << "[14] Search for patient" << endl;
	cout << "[15] Update patient information (by ID)" << endl;
	cout << "[16] Display all appointments for patient (by ID)" << endl;
	cout << "[17] Display all appointments" << endl << endl;

	cout << "[18][Exit]" << endl;
}

int main()
{
	Branch B;
	Doctor D;
	Patient P;
	Appointment A;

	int BranchID;
	string BranchName;
	string BranchLocation;

	int DoctorID;
	string DoctorName;
	string Specialization;

	int PatientID;
	string PatientName;
	string PatientAddress;

	int AppointmentID;
	string Date;

	string Answer;
	cout << "== Hospital Management System ==" << endl;
	while (true)
	{
		Menu();
		int UserOption;
		cin >> UserOption;
		switch (UserOption)
		{
		case 0:
			return 0;

		case 1:
		{
			cout << "Enter the branch ID : ";
			cin >> BranchID;
			cout << "Enter the branch name : ";
			cin >> BranchName;
			cout << "Enter the branch location : ";
			cin >> BranchLocation;

			B.AddNewBranch(BranchID, BranchName, BranchLocation);
			break;
		}
		case 2:
		{
			cout << "Enter the branch ID : ";
			cin >> BranchID;
			B.RemoveBranch(BranchID);
			break;
		}
		case 3:
		{
			B.DisplayAllBranches();
			break;
		}
		case 4:
		{
			cout << "Enter the branch ID : ";
			cin >> BranchID;
			B.SearchForBranch(BranchID);
			break;
		}
		case 5:
		{
			cout << "Enter the branch ID : ";
			cin >> BranchID;
			A.DisplayAppointmentsForBranch(BranchID); 
			break;
		}
		case 6:
		{
			cout << B.GetTheNumberOfBranches() << endl;
			break;
		}
		case 7:
		{
			cout << "Enter the doctor ID : ";
			cin >> DoctorID;
			cout << "Enter the doctor name : ";
			cin >> DoctorName;
			cout << "Enter the specialization : ";
			cin >> Specialization;
			cout << "Enter the breanch ID : ";
			cin >> BranchID;
			Branch* BranchExist = B.IsBranchExist(BranchID);
			if (BranchExist != NULL)
				D.AddNewDoctor(DoctorID, DoctorName, Specialization, BranchExist->BranchID);
			else
				cout << "The branch not found" << endl;
			break;
		}
		case 8:
		{
			cout << "Enter the doctor ID : ";
			cin >> DoctorID;
			D.RemoveDoctor(DoctorID);
			break;
		}
		case 9:
		{
			cout << "Enter the doctor ID : ";
			cin >> DoctorID;
			A.DisplayAllAppointmentsForDoctor(DoctorID);
			break;
		}
		case 10:
		{
			D.DisplayAllDoctors();
			break;
		}
		case 11:
		{
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			cout << "Enter the patient name : ";
			cin >> PatientName;
			cout << "Enter the patient address : ";
			cin >> PatientAddress;
			P.AddNewPatient(PatientID, PatientName, PatientAddress);
			break;
		}
		case 12:
		{
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			P.RemovePatient(PatientID);
			break;
		}
		case 13:
		{
			cout << "Enter the appointment ID : ";
			cin >> AppointmentID;
			cout << "Enter the date in this format [Year-Month-Day] : ";
			cin >> Date;
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			cout << "Enter the doctor ID : ";
			cin >> DoctorID;
			cout << "Enter the branch ID : ";
			cin >> BranchID;

			Patient* PatientExist = P.IsPatientExist(PatientID);
			Doctor* DoctorExist = D.IsDoctorExist(DoctorID);
			Branch* BranchExist = B.IsBranchExist(BranchID);

			if (PatientExist and DoctorExist and BranchExist)
				A.BookAppointment(AppointmentID, Date, PatientExist, DoctorExist, BranchExist);
			else
				cout << "There are some issues with your input data, please try again with the correct ID or contact the technical support." << endl;
			break;
		}
		case 14:
		{
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			P.SearchForPatient(PatientID);
			break;
		}
		case 15:
		{
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			cout << "[1] Update ID" << endl;
			cout << "[2] Update Name" << endl;
			cout << "[3] Update Address" << endl;
			int UserUpdate;
			cin >> UserUpdate;
			P.UpdatePatientInformationById(PatientID, UserUpdate);
			break;
		}
		case 16:
		{
			cout << "Enter the patient ID : ";
			cin >> PatientID;
			A.DisplayAllAppointmentsForPatient(PatientID);
			break;
		}
		case 17:
		{
			A.DisplayAllAppointments();
			break;
		}
		default:
			cout << "Invalid option, please choose the number of the options as shwon." << endl;
		}
	}
}
