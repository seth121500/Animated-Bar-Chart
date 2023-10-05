// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <iterator>
//#include <unistd.h>
//#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
#include <windows.h>

using namespace std;



//
// BarChartAnimate
//
class BarChartAnimate {
private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title; 
    string xlabel;
    string source;
    int color;
    int valueint;


    void data(ifstream& file, BarChart& temp)
    {
        string rec, year, name, value, category, chars;
        getline(file, rec);
        string::iterator it;
        int holder = 0;
        for (it = rec.begin(); it < rec.end(); it++)
        {
            if (*it != ',')
            {
                chars = chars + *it;
            }
            if (*it != ',' || it == rec.end() - 1)
            {
                if (holder == 4)
                {
                    category = chars;
                }
                else
                    if (holder == 3)
                    {
                        value = chars;
                    }
                    else
                        if (holder == 1)
                        {
                            name = chars;
                        }
                        else
                            if (holder == 0)
                            {
                                year = chars;
                            }
                chars = "";
                holder += 1;
            }
        }

        if (colorMap.count(category) != 1)
        {
            if (color == 7)
            {
                color = 0;
            }
            colorMap[category] = COLORS[color];
            color++;
        }

        valueint = stoi(value);
        temp.setFrame(year);
        temp.addBar(name, valueint, category);
    }

    void usleep(__int64 usec)
    {
        HANDLE timer;
        LARGE_INTEGER ft;

        ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

        timer = CreateWaitableTimer(NULL, TRUE, NULL);
        SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
        WaitForSingleObject(timer, INFINITE);
        CloseHandle(timer);
    }



public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) 
    {
        capacity = 4;
        barcharts = new BarChart[capacity];
        size = 0;
        //colorMap = NULL;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        int color  = 0;
        int valueint = 0;

        // TO DO:  Write this constructor.

    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() 
    {
        //if (size != 0 || capacity != 0)
        //{
            delete[] barcharts;
        //}
        // TO DO:  Write this destructor.
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream& file) 
    {
        string emptyline;
        string grouprecords;
        int rec = 0;
        getline(file, emptyline);
        getline(file, grouprecords);
        if (file.good()) 
        {

            if (size == capacity)
            {
                int newcapacity = capacity * 2;
                capacity = newcapacity;
                BarChart* newA = new BarChart[newcapacity];

                for (int i = 0; i < size; i++)
                {
                    newA[i] = barcharts[i];
                }
                delete[] barcharts;
                barcharts = newA;
            }
            int rec = stoi(grouprecords);
            BarChart temp(rec);
            for (int i = 0; i < rec; i++)
            {
                data(file, temp);
            }

            barcharts[size] = temp;
            size++;

        }
        // TO DO:  Write this constructor.

    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
    void animate(ostream& output, int top, int endIter) {
        unsigned int microsecond = 50000;

        if (endIter == -1)
        {
            endIter = getSize();
        }

            for (int i = 0; i < endIter; i++)
            {
                usleep(3 * microsecond);
                output << CLEARCONSOLE;
                output << WHITE << title << "\n" << WHITE << source << endl;
                barcharts[i].graph(output, colorMap, top);
                output << WHITE << xlabel << "\n" << WHITE << "Frame: " << barcharts[i].getFrame() << endl;
            }
            // TO DO:  Write this function.
    }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() {

        return size;  // TO DO:  update this, it is only here so code compiles.

    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i) {
        BarChart bc;

        if (i >= size || i < 0)
        {
            throw out_of_range("BarChartAnimate: i out of bounds");
        }
        else
        {
            //b.getName();
            //b.getValue();
            //b.getCategory();
            return barcharts[i];
        }

        //return bc; // TO DO:  update this, it is only here so code compiles.
    }
};