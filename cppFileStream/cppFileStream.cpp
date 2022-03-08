#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "notes.h"
#include "models.h"
#include "write_and_read.h"


int main() {
	Applier* cv1 = new Applier("Ceyhun", 18, "IT", "Empty1");
	Applier* cv2 = new Applier("Sebine", 17, "Designer", "Empty2");


	Company company;
	// company.hireUp(cv1);
	// company.hireUp(cv2);
	// 
	// company.writeToFile("company.txt");
	
	
	company.readToFile("company.txt");
	company.showAllCV();

}



// int main()
// {
// 	// write_txt_file();
// 	// read_txt_file();
// 
// 	// writeAndReadModesTogetherInTxt();
// 
// 	// write_binary_file();
// 	// read_binary_file();
// 
// 	// writeAndReadModesTogetherInBinary();
// 
// 
// 	// write_complex_type();
// 	// read_complex_type();
// 
// 	system("pause");
// }