#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::pair<int, bool> riff_chunk;

riff_chunk _read_riff_chunk(std::ifstream& fid)
{
    bool is_big_endian;
    int file_size;
    char str1[4];
    fid.read(str1, 4);
    if (strcmp(str1, "RIFF")) {
        is_big_endian = false;
    } else if (strcmp(str1, "RIFX")) {
        is_big_endian = true;
    } else {
        throw std::invalid_argument("File format " + std::string(str1) + "... not understood.");
    }
    fid.read((char*)&file_size, 4);
    file_size += 8;
    return std::make_pair(file_size, is_big_endian);
}


int main(int argc, char const* argv[])
{
    std::ifstream file("OSR_us_000_0010_8k.wav", std::ios::in | std::ios::binary);
    
    riff_chunk rc = _read_riff_chunk(file);
    
    std::cout << rc.first << "," << rc.second << std::endl;



    while(file.tellg() < rc.first){
        char chunk_id[4];
        file.read(chunk_id, 4);
        if(chunk_id == nullptr)
            throw std::runtime_error("Unexpected end of file.");
        else if (sizeof(chunk_id) !=4)
            throw std::runtime_error("Incomplete wav chunk.");
        
        std::cout << chunk_id << std::endl;
        break;
    }
    return 0;
}
