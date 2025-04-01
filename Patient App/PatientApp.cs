using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;

namespace Patient_App
{
	public enum The_TreatmentType
	{
		Surgery,
		Medication,
		Therapy,
		Consolutation
	}

	public class The_Treatment
	{
		public string Name { get; set; }
		public The_TreatmentType Type { get; set; }

		public The_Treatment(string name, The_TreatmentType type)
		{
			Name = name;
			Type = type;
		}

		public override string ToString()
		{
			return Name + " (" + Type + ")";
		}
	}

	public enum The_PatientStatus
	{
		Admitted,
		Discharged,
	}

	public interface The_IHospitalPatient
	{
		void AddTreatment(The_Treatment treatment);
		void RemoveTreatment(The_Treatment treatment);
	}

	public class The_Patient : The_IHospitalPatient
	{
		string ID;
		string Name;
		public The_PatientStatus PatientStatus { get; private set; }

		List<The_Treatment> Treatment = new List<The_Treatment>();

		public The_Patient(string id, string name, The_PatientStatus patientStatus)
		{
			ID = id;
			Name = name;
			PatientStatus = patientStatus;
		}

		public void AddTreatment(The_Treatment treatment)
		{
			Treatment.Add(treatment);
		}
		public void RemoveTreatment(The_Treatment treatment)
		{
			Treatment.Remove(treatment);
		}

		public void FilterEmergencyTreatments()
		{
			foreach (The_Treatment treatment in Treatment)
			{
				if (treatment.Type == The_TreatmentType.Surgery)
				{
					Console.WriteLine(treatment);
				}
			}
		}

		public void ChangeStatus(The_PatientStatus status)
		{
			PatientStatus = status;
		}

		public void DisplayTreatments()
		{
			foreach (var treatment in Treatment)
			{
				Console.WriteLine(treatment);
			}
		}
	}

	public class Patient_App
	{
		public static void Main()
		{
			Console.WriteLine("Creating Patient");
			The_Patient PatientA = new The_Patient("P001", "John Doe", The_PatientStatus.Admitted);

			Console.WriteLine("\n Adding treatments to the patient");
			PatientA.AddTreatment(new The_Treatment("Heart Surgery", The_TreatmentType.Surgery));
			PatientA.AddTreatment(new The_Treatment("Painkiller", The_TreatmentType.Medication));
			PatientA.AddTreatment(new The_Treatment("Physical Therapy", The_TreatmentType.Therapy));

			Console.WriteLine("\nDisplaying all the treatments of the patient");
			PatientA.DisplayTreatments();

			Console.WriteLine("\nFiltering only Emergency treatments");
			PatientA.FilterEmergencyTreatments();

			Console.WriteLine("\nUpdating patient's status to 'Discharged'");
			PatientA.ChangeStatus(The_PatientStatus.Discharged);
			Console.WriteLine($"Patient Status updated: {PatientA.PatientStatus}");

			Console.WriteLine("\nSerializing patient records to patients.json");
			SavePatientRecords(PatientA);

			Console.WriteLine("Patient Records saved to patients.json");
		}

		private static void SavePatientRecords(The_Patient patient)
		{
			var options = new JsonSerializerOptions { WriteIndented = true };
			string jsonString = JsonSerializer.Serialize(patient, options);
			File.WriteAllText("patients.json", jsonString);
		}
	}
}
