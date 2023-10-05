/*
#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool Tframe()
{
    BarChart A(1);
        if (A.getFrame() != "")
        {
            cout << A.getFrame() << " get Frame" << endl;
            cout << " Tframe : getFrame() failed" << endl;
            return false;
        }
    cout << "Tframe : getFrame() passed" << endl;
    return true;
}

bool testBarChart()
{
    BarChart b(8);
    if (b.addBar("Illinois", 10000, "US"))
    {
        cout << "added Bar" << endl;
    }
    if (b.addBar("Delaware", 154895, "America"))
    {
        cout << "added Bar" << endl;
    }
    if (b.addBar("Peru", 6565700, "South America"))
    {
        cout << "added Bar" << endl;
    }
    else
    {
        cout << "testBarChart : addbar() failed" << endl;
        return false;
    }
    cout << "testBarChart : addbar() passed" << endl;
    return true;
}

bool clearCheckSize()
{
    BarChart bc(8);
    if (bc.addBar("Illinois", 10000, "US"))
    {
        cout << "added Bar" << endl;
    }
    if (bc.addBar("Delaware", 154895, "America"))
    {
        cout << "added Bar" << endl;
    }
    if (bc.addBar("Peru", 6565700, "South America"))
    {
        cout << "added Bar" << endl;
    }
    int n = bc.getSize();
    cout << "Current size of bc before clear(): " <<  n << endl;
    bc.clear();
    n = bc.getSize();
    if (n == 0)
    {
        cout << "clearCheckSize: getSize() passed" << endl;
        return true;
    }
    else 
    {
        cout << "clearCheckSize: getSize() failed" << endl;
        return false;
    }
}

bool clearCheckDump()
{
        BarChart bc(8);
        if (bc.addBar("Illinois", 10000, "US"))
        {
            cout << "added Bar" << endl;
        }
        if (bc.addBar("Delaware", 154895, "America"))
        {
            cout << "added Bar" << endl;
        }
        if (bc.addBar("Peru", 6565700, "South America"))
        {
            cout << "added Bar" << endl;
        }
        stringstream ss("");
        bc.dump(ss);
        cout << ss.str();
        //cout << bc.dump(ss);
        //string test = bc.getName();
        //cout << "1. " << test <<  endl;
        return true;
        
}

bool checkGraph()
{
    BarChart bc(8);
    if (bc.addBar("Illinois", 58, "US"))
    {
        cout << "added Bar" << endl;
    }
    if (bc.addBar("Delaware", 34, "America"))
    {
        cout << "added Bar" << endl;
    }
    if (bc.addBar("Peru", 46, "South America"))
    {
        cout << "added Bar" << endl;
    }
    cout << endl << endl;
    string red("\033[1;31m");
    string blue("\033[1;34m");
    string cyan("\033[1;36m");
    map<string, string> colorMap;
    colorMap["US"] = red;
    colorMap["South America"] = blue;
    colorMap["America"] = cyan;
    bc.graph(cout, colorMap, 3);
    return true;
}

bool checkGraphNoColor()
{
    BarChart bc(8);
    bc.addBar("Illinois", 58, "US");
    bc.addBar("Delaware", 34, "America");
    bc.addBar("Peru", 46, "South America");
    bc.addBar("North Pole", 100, "Antartica");

    cout << endl << endl;
    string red("\033[1;31m");
    string blue("\033[1;34m");
    string cyan("\033[1;36m");
    map<string, string> colorMap;
    colorMap["US"] = red;
    colorMap["South America"] = blue;
    colorMap["America"] = cyan;
    bc.graph(cout, colorMap, 4);
    return true;
}


bool BarOperatorTest()
{
    BarChart bc(8);
    bc.addBar("Illinois", 58, "US");
    bc.addBar("Delaware", 34, "America");
    bc.addBar("Peru", 46, "South America");
    bc.addBar("North Pole", 100, "Antartica");
    int n = bc.getSize();
    for (int i = 0; i < n; i++) {
        cout << bc[i].getName() << " ";
        cout << bc[i].getValue() << " ";
        cout << bc[i].getCategory();
        cout << endl;
    }
    return true;
}



int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();

    cout << "Tframe() test:" << endl;
    Tframe();
    cout << "testBarChart() test:" << endl;
    testBarChart();
    cout << "clearCheckSize() test:" << endl;
    clearCheckSize();
    cout << "clearCheckDump() test:" << endl;
    clearCheckDump();
    cout << "BarOperatorTest() test:" << endl;
    BarOperatorTest();






    cout << endl << endl;
    cout << "checkGraph() test:" << endl;
    checkGraph();
    cout << endl << endl;
    cout << "checkGraphNoColor() test:" << endl;
    checkGraphNoColor();

    return 0;
}
/*