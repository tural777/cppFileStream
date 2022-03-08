#pragma once


class Student {
public:
	string _name;
	int _age;

	Student()
	{
		_name = "noname";
		_age = 0;
	}

	Student(string name, int age)
	{
		_name = name;
		_age = age;
	}

	void whoAreYou() {
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
	}
};





class Applier {
public:

	string _name = "";
	int _age = 0;
	string _speciality = "";
	string _text = "";

	Applier() = default;

	Applier(string name, int age, string speciality, string text) {
		_name = name;
		_age = age;
		_speciality = speciality;
		_text = text;
	};

	void print() {
		cout << "======= Applier =======" << endl;
		cout << "Name: " << _name << endl;
		cout << "Age: " << _age << endl;
		cout << "Speciality: " << _speciality << endl;
		cout << "Text: " << _text << endl << endl;
	}
};


class Company {
	vector<Applier*> appliers;

public:
	void hireUp(Applier* cv) { appliers.push_back(cv); }

	void showAllCV() {
		for (size_t i = 0; i < appliers.size(); i++)
			appliers[i]->print();
	}


	void writeToFile(string filename) {
		ofstream file(filename);

		if (file.is_open()) {
			for (size_t i = 0; i < appliers.size(); i++)
			{
				file << appliers[i]->_name << '\n'
					<< appliers[i]->_age << '\n'
					<< appliers[i]->_speciality << '\n'
					<< appliers[i]->_text << '\n';
			}

			file.close();
		}
	}


	void readToFile(string filename) {
		ifstream file(filename);
		Applier* temp;
		string age;

		if (file.is_open()) {

			while (!file.eof())
			{
				if (file.peek() == -1) break;

				temp = new Applier;

				getline(file, temp->_name);
				getline(file, age);
				getline(file, temp->_speciality);
				getline(file, temp->_text);

				temp->_age = stoi(age);

				appliers.push_back(temp);
			}

			file.close();
		}

	}
};