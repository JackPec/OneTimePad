/*

One Time Pad Lib Header File


*/
#pragma once
#include <vector>
#include <string>
#include <fstream>
//#include <cctype>


#include <ctime>


class EncryptDoc
{
    std::vector<std::string> rowOfText;
    std::vector<int> keys;
    size_t defaultwidth;


public:
    EncryptDoc(size_t defaultwidthIn = 76)
        :
        rowOfText(),
        keys()
        //defaultwidth(defaultwidthIn)
    {
        //seeds the random
        if(set_width(defaultwidthIn))
        {
            //handles the case if defaultwidth is zero
        }
        else
        {
            set_width(76);
        }
        srand(static_cast<unsigned>(time(nullptr)));

    }

    EncryptDoc(const EncryptDoc & a)
        :
        rowOfText(a.rowOfText),
        keys(), //does not copy key for security reasons
        defaultwidth(a.defaultwidth)
    {
        //seeds the random

        //set_width(a.defaultwidth);
        srand(static_cast<unsigned>(time(nullptr)));

    }

    //default copying
    EncryptDoc & operator=(const EncryptDoc & a) = default;


    friend std::istream & operator>>(std::istream & in,
                                     EncryptDoc & r)
    {
        std::string a;
        //in >> a;
        // r.val = a;

        //takes care of reading in whitespace
        // if (in.peek() == '\n')
        // {
        //    in.ignore();
        // }

        std::getline(in,a);

        //std::cout << a;


        while(a.size()> r.defaultwidth)
        {
            std::string b = a.substr(0,r.defaultwidth);
            std::string c = a.substr(r.defaultwidth, a.size());

            r.rowOfText.push_back(b);

            a.erase(0,r.defaultwidth);

        }



        a.resize(r.defaultwidth,' ');
        r.rowOfText.push_back(a);

        return in;

    }

    friend std::ostream & operator<<(std::ostream & out,
                                     const EncryptDoc & r)
    {
        // out << r.val;

        for(size_t i = 0; i < r.rowOfText.size(); i++)
        {
            out << r.rowOfText[i] << "\n";

        }

        return out;

    }

    //setters and getters

    size_t get_width() const
    {
        return defaultwidth;
    }

    size_t get_length() const
    {
        return rowOfText.size();
    }

    bool set_width(size_t new_width)
    {
        bool okay = false;
        if (new_width >= 1)
        {
            defaultwidth = new_width;
            okay = true;
        }
        return okay;
    }

    //main functions
    //encrypting text and saving it to this object
    void encrypt(std::string fname);
    void encrypt(std::istream & in);
    //decrypting text in this object
    void decrypt(std::string fname, std::string kname);
    void decrypt(std::istream & dataIn, std::istream & keyIn);
    void resetRandSeed();
    void getkeyfile();
    void getkeyfile(std::string kname);
    void getCurrentfile();
    std::ostream & getCurrentfile(std::ostream & out);
    void test();
    //output file helper functions
    std::ofstream openOutputfile(std::string prompt);
    void closeOutputFile(std::ofstream & file);

};
