#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

template<typename T>
void printLatticeToFile(std::vector<T> & lattice, const size_t sweep){
    // generate file name
    std::string filename = "Confs/config_" + std::to_string(sweep) + ".lat";

    // declare file stream
    std::fstream fs;

    // open file for out put. If it exists remove its content
    fs.open(filename, std::ios::out | std::ios::trunc);

    if (fs.is_open()){
        // write into the file in the format
        // site value
        for(size_t site = 0; site < lattice.size(); ++site){
            fs << site << " " << lattice[site] << "\n";
        }
    } else {
        std::cerr << "Couldn't open file: " << filename << "\n";
    }

    // close file
    fs.close();
}

template<typename T>
void readLatticeFromFile(std::vector<T> & lattice, const size_t sweep){
    // generate file name
    std::string filename = "Confs/config_" + std::to_string(sweep) + ".lat";

    // declare file stream
    std::fstream fs;

    // open file for out put. If it exists remove its content
    fs.open(filename, std::ios::in);


    if(fs.is_open()){
        size_t site;
        T value;
        while(!fs.eof()){
            fs >> site;
            fs >> value;
            lattice[site] = value;
        }
    }  else {
        std::cerr << "Couldn't open file: " << filename << "\n";
    }

    // close file
    fs.close();
}

#endif //FILEIO_H
