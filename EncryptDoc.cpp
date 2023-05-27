/*

Encrypted Document Lib Impl File


*/
#include "EncryptDoc.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // files
#include <cctype> //char stuff
#include <cstdio> //for removing files

#include <ctime> // for randomness from time

using namespace std;

//main functions

//encrypting text and saving it to this object
void EncryptDoc::encrypt(std::string fname)
{
    std::ifstream data_file;
    // std::string fname = "";

    //std::cout << "what's the name of input file?  ";
    //std::cin >> fname;
    // }
    data_file.open(fname);

    while (!data_file)
    {
        data_file.close();
        data_file.clear();
        std::cerr << "\n\aCould not open file '" << fname << "'!\n\n";
        std::cout << "what's the name of input file?  ";
        std::getline(std::cin, fname);
        data_file.open(fname);
    }

    data_file >> std::ws;

    while(!data_file.eof())
    {
        data_file >> *this;

    }

    //closeOutputFile(outputfile);
    data_file.clear();
    data_file.close();


    //getting random keys


    for(size_t i = 0; i < rowOfText.size(); i++)
    {


        for(size_t j = 0; j < defaultwidth; j++)
        {
            // can use any rand function as needed for true randomness
            int k = rand() % 26;

            char temp = rowOfText[i][j];

            char tempOG = temp;

            if(isupper(temp))
            {
                temp = ((temp - 'A') + k)% 26 + 'A'; //derived from web


            }
            else if(islower(temp))
            {
                temp = ((temp - 'a') + k)% 26 + 'a'; //derived from web

            }
            else if(isdigit(temp))
            {
                temp = ((temp - '0') + k)% 10 + '0'; //derived from web
            }

            //shows the ascii shift
            /*
            std::cout << tempOG  << " becomes "
                      << temp << " :" << temp - tempOG << "\n";

            */

            rowOfText[i][j] = temp;

            keys.push_back(tempOG - temp);

        }


    }
    std::cout << "\nFile encrypted\n\n";

}

//For Encryption with without user input
/*
void EncryptDoc::encrypt(std::istream & in)
{

    in >> std::ws;

    while(!in.eof())
    {
        in >> *this;

    }

    //getting random keys


    for(size_t i = 0; i < rowOfText.size(); i++)
    {


        for(size_t j = 0; j < defaultwidth; j++)
        {
            int k = rand() % 26;

            char temp = rowOfText[i][j];

            char tempOG = temp;

            if(isupper(temp))
            {
                temp = static_cast<char>(((temp - static_cast<int>('A')) + k)% 26 + static_cast<int>('A')); //derived from web


            }
            else if(islower(temp))
            {
                temp = static_cast<char>(((temp - static_cast<int>('a')) + k)% 26 + static_cast<int>('a')); //derived from web

            }
            else if(isdigit(temp))
            {
                temp = static_cast<char>(((temp - static_cast<int>('0')) + k)% 10 + static_cast<int>('0')); //derived from web
            }

            //shows the ascii shift


            std::cout << tempOG  << " becomes "
                      << temp << " :" << temp - tempOG << "\n";



            rowOfText[i][j] = temp;

            keys.push_back(tempOG - temp);

        }


    }

    std::cout << "\nFile encrypted\n\n";

}
*/


//decrypting text in this object
void EncryptDoc::decrypt(std::string fname, std::string kname)
{


    if(rowOfText.size() > 0)
    {

        size_t keypos = 0;

        for(size_t i = 0; i < rowOfText.size(); i++)
        {


            for(size_t j = 0; j < defaultwidth; j++)
            {

                char temp = rowOfText[i][j];

                // char tempOG = temp;
                temp =  temp + static_cast<char>(keys[keypos])  ;


                rowOfText[i][j] = temp;

                keypos++;
            }
        }

        for(size_t i = 0; i < rowOfText.size(); i++)
        {
            std::cout << rowOfText[i] << "\n";



        }

        //for deleting key automaticly if needed
        //commented out for demo purposes

        /*

        std::cout << "## Text is now decrypted, deleting internal key"
                  "and key in file folder" << "\n";

        keys.clear();

        std::cout << "keys length: " << keys.size() << "\n";

        //deleting key file used
        std::remove(kname.c_str());
        */


    }
    else
    {

        std::ifstream data_file;
        // std::string fname = "";

        //std::cout << "what's the name of input file?  ";
        //std::cin >> fname;
        // }
        data_file.open(fname);

        while (!data_file)
        {
            data_file.close();
            data_file.clear();
            std::cerr << "\n\aCould not open file '" << fname << "'!\n\n";
            std::cout << "Name of input file?:  ";
            std::getline(std::cin, fname);
            data_file.open(fname);
        }

        data_file >> std::ws;

        while(!data_file.eof())
        {
            data_file >> *this;

        }

        //closeOutputFile(outputfile);
        data_file.clear();
        data_file.close();

        //////////for key

        std::ifstream key_file;
        //std::string kname = "";

        //std::cout << "what's the name of key file?  ";
        //std::cin >> kname;
        // }
        key_file.open(kname);

        while (!key_file)
        {
            key_file.close();
            key_file.clear();
            std::cerr << "\n\aCould not open file '" << fname << "'!\n\n";
            std::cout << "Name of key file?:  ";
            std::getline(std::cin, fname);
            key_file.open(fname);
        }

        key_file >> std::ws;

        while(!key_file.eof())
        {
            int temp = 0;

            key_file >> temp;

            keys.push_back(temp);

        }

        //closeOutputFile(outputfile);
        key_file.clear();
        key_file.close();





        decrypt(fname,kname);
    }



    std::cout <<"\n\nFile now decrypted, reprint file to get decrypted file printed\n\n";



}

//For decryption with without user input
/*
void EncryptDoc::decrypt(std::istream & dataIn, std::istream & keyIn)
{


    if(rowOfText.size() > 0)
    {

        size_t keypos = 0;

        for(size_t i = 0; i < rowOfText.size(); i++)
        {


            for(size_t j = 0; j < defaultwidth; j++)
            {

                char temp = rowOfText[i][j];

                // char tempOG = temp;
                temp =  temp + static_cast<char>(keys[keypos])  ;


                rowOfText[i][j] = temp;

                keypos++;
            }
        }

        for(size_t i = 0; i < rowOfText.size(); i++)
        {
            std::cout << rowOfText[i] << "\n";

        }


        //deleting key

        std::cout << "## Text is now decrypted, deleting internal key"
                  "and key in file folder" << "\n";

        keys.clear();

        std::cout << "Keys length: " << keys.size() << "\n";

        //deleting key stream will be
        //up to code outside this lib



    }
    else
    {

        dataIn >> std::ws;

        while(!dataIn.eof())
        {
            dataIn >> *this;

        }


        //////////for key



        keyIn >> std::ws;

        while(!keyIn.eof())
        {
            int temp = 0;

            keyIn >> temp;

            keys.push_back(temp);

        }


        decrypt(dataIn,keyIn);

    }





}

*/

void EncryptDoc::resetRandSeed()
{
    srand(static_cast<unsigned int>(time(0)));
}

void EncryptDoc::getkeyfile()
{
    std::ofstream keyfile;
    keyfile = openOutputfile("Key file name?: ");

    for(size_t i = 0; i < keys.size(); i++)
    {
        keyfile << keys[i] << " ";

    }


    closeOutputFile(keyfile);
}

void EncryptDoc::getkeyfile(std::string kname)
{
    std::ofstream keyfile;
    // keyfile = openOutputfile("What should the Key file name be?  ");

    keyfile.open(kname);


    while (!keyfile)
    {
        keyfile.close();
        keyfile.clear();
        std::cout << "\nCannot write to '" << kname
                  << "'!!\a\n\nPlease choose "
                  "another name (and/or location):  ";
        //getline(cin, fname);
        std::cin >> kname;
        keyfile.open(kname);
    }

    for(size_t i = 0; i < keys.size(); i++)
    {
        keyfile << keys[i] << " ";

    }


    closeOutputFile(keyfile);
}

void EncryptDoc::getCurrentfile()
{
    std::ofstream outputfile;
    outputfile = openOutputfile("File name?:  ");

    for(size_t i = 0; i < rowOfText.size(); i++)
    {
        //std::cout << rowOfText[i] << "\n";
        outputfile << rowOfText[i] << "\n";

    }

    closeOutputFile(outputfile);

}

std::ostream & EncryptDoc::getCurrentfile(std::ostream & out)
{

        for(size_t i = 0; i < (*this).rowOfText.size(); i++)
        {
            //std::cout << rowOfText[i] << "\n";
            out << (*this).rowOfText[i] << "\n";

        }

        return out;

}



/*
void EncryptDoc::test()
{

    std::ofstream outputfile;
    std::ofstream keyfile;

    outputfile = openOutputfile("What should the Output file name be?  ");

    keyfile = openOutputfile("What should the Key file name be?  ");



    for(size_t i = 0; i < rowOfText.size(); i++)
    {
        std::cout << rowOfText[i] << "\n";
        outputfile << rowOfText[i] << "\n";

    }

    for(size_t i = 0; i < keys.size(); i++)
    {
        keyfile << keys[i] << " ";

    }

    closeOutputFile(outputfile);

    closeOutputFile(keyfile);


}
*/

//output file helper functions
std::ofstream EncryptDoc::openOutputfile(std::string prompt)
{
    std::ofstream file;
    std::string fname;
    std::cout << prompt; //"What should the Output file name be?  ";
    //getline(cin, fname);
    std::cin >> fname;
    file.open(fname);


    while (!file)
    {
        file.close();
        file.clear();
        std::cout << "\nCannot write to '" << fname
                  << "'!!\a\n\nPlease choose "
                  "another name (and/or location):  ";
        //getline(cin, fname);
        std::cin >> fname;
        file.open(fname);
    }

    return file;


}

void EncryptDoc::closeOutputFile(std::ofstream & file)
{
    file.close();
    file.clear();

}


