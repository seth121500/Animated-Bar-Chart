// barchart.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <algorithm>
#include <map>
//#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.

const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals

const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
//const string RESET("\033[0m");
const vector<string> COLORS = { CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE };



//
// BarChart
//
class BarChart {
private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;

public:

    // default constructor:
    BarChart() {
        capacity = 0;
        size = 0;
        frame = "";
        //bars = &bars[0];
        // TO DO:  Write this constructor.

    }

    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) 
    {
        bars = new Bar[n];
        size = 0;
        capacity = n;
        // TO DO:  Write this constructor.
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) 
    {
        this -> bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        // TO DO:  Write this constructor.
        for (int i = 0; i < size; i++)
        {
            this->bars[i] = other.bars[i];
        }
        this->frame = other.frame;
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        BarChart bc;

        if (this == &other)
        {
            return *this;
        }
        else
        {
            
            this->bars = new Bar[other.capacity];
            this->size = other.size;
            this->capacity = other.capacity;

            for (int i = 0; i < size; i++)
            {
                this->bars[i] = other.bars[i];
            }
            this->frame = other.frame;
            return *this;
        }
        // TO DO:  Write this operator.
        // TO DO:  update this, it is only here so code compiles.
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        capacity = 0;
        size = 0;
        delete[] bars;
        // TO DO:  Write this operator.

    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() 
    {
        if (size != 0 || capacity != 0)
        {
            delete[] bars;
        }
        // TO DO:  Write this destructor.

    }

    // setFrame
    void setFrame(string frame) 
    {
        this->frame = frame;
        // TO DO:  Write this destructor.

    }

    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {

        // TO DO:  Write this function.
        //this->frame = frame;

        return frame; // TO DO:  update this, it is only here so code compiles.
        //return this->frame;
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category)
    {
        if (capacity <= size)
        {
            return false;
        }
        else
        {
            Bar bar(name, value, category);
            bars[size] = bar;
            size += 1;
            return true;
        }
        // TO DO:  Write this function.
    }

    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() 
    {
        return size;
        // TO DO:  Write this function.
        // TO DO:  update this, it is only here so code compiles.
    }

    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        Bar b;

        if (i >= size || i < 0)
        {
            throw out_of_range("BarChart: i out of bounds");
        }
        else
        {
            //bars[i] = b;
            //b.getName();
            //b.getValue();
            //b.getCategory();
            return bars[i];
        }
        // TO DO:  Write this function.
        
        //return b;  // TO DO:  update this, it is only here so code compiles.
    }

    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream& output) 
    {

        sort(bars, &bars[size], greater<Bar>());
        
        output << "frame: " << getFrame() << endl;
        for (int i = 0; i < size; i++)
        {
            output << bars[i].getName() << " " << bars[i].getValue() << " " << bars[i].getCategory() << endl;
        }

        // TO DO:  Write this function.

    }

    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)

    
    void graph(ostream& output, map<string, string>& colorMap, int top) {
        int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        sort(bars, &bars[size], greater<Bar>());

        string barstr = "";
        for (int j = 0; j < lenMax; j++)
        {
            barstr += BOX;
        }
        string color = "\033[1; 37m";
        output << color << barstr << " " << bars[0].getName() << " " << bars[0].getValue() << endl;
        double num = 0.0;
        int num1 = 0;
        int topval = bars[0].getValue();

        for (int i = 0; i < top-1; i++)
        {
            num = (bars[i+1].getValue() * 1.0) / topval;
            num = num * 60;
            num1 = num;
            for (int j = 0; j < num1; j++)
            {
                barstr += BOX;
            }
            if (colorMap.count(bars[i + 1].getCategory()) != 1)
            {
                color = "\033[1;37m";
            }
            else
            {
                color = colorMap[bars[i + 1].getCategory()];
            }
            output << color << barstr << " " << bars[i + 1].getName() << " " << bars[i + 1].getValue() << endl;
            barstr = "";
            color = "";
        }



        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        //string color = "\033[1;36m";  // you should get this from colorMap
        //string barstr = "";
        //for (int i = 0; i < lenMax; i++) {
        //    barstr += BOX;
        //}
        //output << color << barstr << endl;

        // TO DO:  Write this function.

    }
    
};
