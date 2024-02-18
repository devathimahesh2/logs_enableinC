#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[]) {

    // Get the file name as input
      std::string fileName = argv[1];

    // Open the input file for reading
    std::ifstream inFile(fileName);

    // Open a temporary file for writing the modified content
    std::ofstream tempFile("temp.txt");

    // Check if both files are opened successfully
    if (!inFile || !tempFile) {
        std::cerr << "Failed to open files!" << std::endl;
        return 1;
    }

    std::string line;
    tempFile <<  "#include <utils/Log.h>" << std::endl;
    // Read each line from the file
    while (std::getline(inFile, line)) {
        // Check if the line contains '$'
        size_t found1 = line.find('{');
        size_t found2 = line.find('}');

        if (found1 != std::string::npos) {
            // If found, append " present" to the line
        tempFile << line << std::endl;
        tempFile << " ALOGE(\"Mahesh: %s, %s: %d\", __FILE__, __FUNCTION__, __LINE__);" << std::endl;
        }
        else if (found2 != std::string::npos){
        tempFile << " ALOGE(\"Mahesh: %s, %s: %d\", __FILE__, __FUNCTION__, __LINE__);" << std::endl;
        tempFile << line << std::endl;
        }
        else
        {tempFile << line << std::endl;}

        // Write the line to the temporary file
    }

    // Close both files
    inFile.close();
    tempFile.close();

    // Rename the temporary file to the original file
    if (std::rename("temp.txt", fileName.c_str()) != 0) {
        std::cerr << "Error renaming file!" << std::endl;
        return 1;
    }

    std::cout << "Lines modified successfully!" << std::endl;

    return 0;
}
