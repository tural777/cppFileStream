#pragma once


void write_txt_file() {
	// // default  ios::out moddadir.
	// ofstream fout("myFile.txt");

	// ofstream fout("myFile.txt", ios::out);
	ofstream fout("myFile.txt", ios::app);

	if (!fout) throw "file can not created";


	if (fout.is_open()) {
		fout << "8 Mart Qadinlar bayraminiz mubarek\n";
	}
	else {
		throw "file can not opened";
	}


	fout.close();
}


void read_txt_file() {
	//ifstream fin("myFile.txt", ios::in);

	ifstream fin("myFile.txt");

	if (fin.is_open()) {
		string value;

		// fin >> value;
		// getline(fin, value);

		while (!fin.eof())
		{
			getline(fin, value);
			cout << value << endl;
		}

		fin.close();
	}
}


void writeAndReadModesTogetherInTxt() {
	fstream file("file.txt", ios::out | ios::in | ios::trunc);
	file << "WriteAndRead";

	file.seekg(0);

	string value;
	file >> value;

	cout << value << endl;

	file.close();
}


void write_binary_file() {
	ofstream file("arr.bin", ios_base::binary);

	int arr[] = { 1, 2, 3, 4, 8 };

	if (file.is_open())
		file.write((char*)arr, sizeof arr);

	file.close();
}


void read_binary_file() {
	ifstream file("arr.bin", ios_base::binary);

	int arr[5]{};

	if (file.is_open())
		file.read((char*)arr, sizeof arr);

	for (size_t i = 0; i < 5; i++)
		cout << arr[i] << ' ';

	cout << endl;

	file.close();
}


void writeAndReadModesTogetherInBinary() {
	fstream file("arrWriteAndRead.bin", ios::binary | ios::out | ios::in | ios::trunc);

	int arrWrite[]{ 5, 4, 3, 2, 1 };
	file.write(reinterpret_cast<char*>(arrWrite), sizeof arrWrite);


	file.seekg(0);


	int arrRead[5];
	file.read(reinterpret_cast<char*>(arrRead), sizeof arrRead);

	for (size_t i = 0; i < 5; i++)
	{
		cout << arrRead[i] << ' ';
	}
	cout << endl;



	file.close();
}


void write_complex_type() {
	Student st("Aga", 15);

	ofstream file("student.txt", ios::app);

	file << st._name << ' ' << st._age << endl;

	file.close();
}


void read_complex_type() {
	Student st;
	ifstream file("student.txt");

	while (!file.eof())
	{
		file >> st._name;
		file >> st._age;

		st.whoAreYou();
	}

	file.close();
}