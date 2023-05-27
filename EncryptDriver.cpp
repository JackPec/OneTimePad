#include <iostream>
#include "EncryptDoc.h"

using namespace std;

int main(void)
{

    EncryptDoc a;

    bool valid = true;

    do{
        std::cout << "\n\n  Jack P's One-Time Pad\n\n" << std::endl;

        std::cout << "1) Encrypt a File" << std::endl;
        std::cout << "2) Decrypt a File"<< std::endl;
        std::cout << "3) Print Key File from current encryption object"<< std::endl;
        std::cout << "4) Print current File from current encryption object"<< std::endl;
        std::cout << "5) Quit"<< std::endl;

        char menuChoice;

        std::cin >> menuChoice;
        std::cin.ignore();

        if(menuChoice == '1'){
            //cityInput(vec);
           // EncryptDoc a;
            string fileName;
            std::cout << "File Name of source:" << std::endl;

            std::getline(std::cin,fileName);


            a.encrypt(fileName);


        }
        else if(menuChoice == '2'){
            //distanceTwoCities(vec);

            string fileName;

            string keyName;

            if(a.get_length() > 0)
            {
                std::cout << "File Name:" << std::endl;
                std::getline(std::cin,fileName);

                std::cout << "Key Name:" << std::endl;

                std::getline(std::cin,keyName);

            }
            else
            {
                std::cout << "File Name to decrypt:" << std::endl;
                std::getline(std::cin,fileName);

                std::cout << "Key Name to decrypt:" << std::endl;

                std::getline(std::cin,keyName);

            }




            a.decrypt(fileName,keyName);

        }
        else if(menuChoice == '3'){
                std::cout << "New key to be created/printed in current folder, \n";
                a.getkeyfile();


        }
        else if(menuChoice == '4'){
                std::cout << "New file to be created/printed in current folder, \n";
                a.getCurrentfile();



        }
        else if(menuChoice == '5'){
            valid = false;

        }

    }
    while(valid);





    return 0;
}















