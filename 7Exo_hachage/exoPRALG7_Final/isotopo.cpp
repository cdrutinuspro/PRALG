#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

#include "town.h"

using namespace std;

/// Study French isotoponyms
int main(int argc, char* argv[]) {
    string townFile = argc>1? argv[1]: srcPath "/villes.txt";
    /////
    ///// Read town file
    /////
    // Create an empty list of towns
    vector<Town> towns;
    // Read file
    cout << "Reading town file: " << townFile << endl;
    clock_t time1 = clock();
    int nb_towns = Town::read_file(townFile, towns);
    clock_t time2 = clock();
    // Sanity check
    if (nb_towns < 0) {
        cout << "Error while reading file" << endl;
        return 2;
    }
    if (nb_towns == 0) {
        cout << "No town found" << endl;
        return 1;
    }
    // Say how many towns have been read
    cout << "File read in: "
         << ((float)(time2-time1)/CLOCKS_PER_SEC) << " s" << endl;
    cout << "Number of towns in file: "
         << towns.size() /* same as nb_towns */ << endl;

    /////
    ///// Count repeated names or coordinates
    /////
    map<string,int> nbTownsByName;
    map<Point2D,int> nbTownsByCoord;
    int maxNbTownsByName = 0;
    int maxNbTownsByCoord = 0;
    for(vector<Town>::iterator it = towns.begin(); it != towns.end(); it++) {
        if (++nbTownsByName[it->name()] > maxNbTownsByName)
            maxNbTownsByName = nbTownsByName[it->name()];
        if (++nbTownsByCoord[it->point()] > maxNbTownsByCoord)
            maxNbTownsByCoord = nbTownsByCoord[it->point()];
    }

    // Compute histogram of towns with same name
    vector<int> histTownsByName(maxNbTownsByName+1);
    for(map<string,int>::iterator it = nbTownsByName.begin();
        it != nbTownsByName.end(); it++)
        histTownsByName[it->second]++;
    // Display histogram of towns with same name
    cout << "Q1. Histogram of towns with same name:" << endl;
    for (unsigned int i = 0; i < histTownsByName.size(); i++)
        if (histTownsByName[i] != 0)
            cout << i << ": " << histTownsByName[i] << endl;

    // Compute histogram of towns with same coordinates
    vector<int> histTownsByCoord(maxNbTownsByCoord+1);
    for(map<Point2D,int>::iterator it = nbTownsByCoord.begin();
        it != nbTownsByCoord.end(); it++)
        histTownsByCoord[it->second]++;
    // Display histogram of towns with same coordinates
    cout << "Q2. Histogram of towns with same coord:" << endl;
    for (unsigned int i = 0; i < histTownsByCoord.size(); i++)
        if (histTownsByCoord[i] != 0)
            cout << i << ": " << histTownsByCoord[i] << endl;

    /////
    ///// Set of towns that share the same name/coordinates with at
    ///// least one other town
    /////
    set<Town> townsByName;
    set<Town> townsByCoord;
    // Construct the sets of towns sharing the same name (resp. same
    // coordinates) as at least one other town
    for(vector<Town>::iterator it = towns.begin(); it != towns.end(); it++) {
        if (nbTownsByName[it->name()] >= 2)
            townsByName.insert(*it);
        if (nbTownsByCoord[it->point()] >= 2)
            townsByCoord.insert(*it);
    }
    cout << "Q3. |N|=" << townsByName.size() << " (Towns sharing name), "
         << "|C|=" << townsByCoord.size()  << " (Towns sharing coords), ";

    // Make intersection
    vector<Town> townsByNameCoord(min(townsByName.size(), townsByCoord.size()));
    vector<Town>::iterator end =
        set_intersection(townsByName.begin(), townsByName.end(),
                         townsByCoord.begin(), townsByCoord.end(),
                         townsByNameCoord.begin());
    townsByNameCoord.resize(end-townsByNameCoord.begin());
    cout << "|NC|=" << townsByNameCoord.size() << endl;

    /////
    ///// Isotoponyms:
    ///// towns t1 such that there are t2, t3, t4 such that
    /////   coord(t1)=coord(t2), name(t1)=name(t3),
    /////   coord(t3)=coord(t4), name(t2)=name(t4)
    /////
    ///// Efficient variant
    ///// 
    time1 = clock();
    map<string,vector<Town> > townsOfName;
    map<Point2D,vector<Town> > townsOfCoord;
    for(vector<Town>::iterator it = towns.begin(); it != towns.end(); it++) {
        townsOfName[it->name()].push_back(*it);
        townsOfCoord[it->point()].push_back(*it);
    }
    set<Town> ambig;
    for(vector<Town>::iterator it1 = townsByNameCoord.begin();
        it1 != townsByNameCoord.end(); it1++) {
        string n1 = it1->name();
        Point2D c1 = it1->point();
        for (vector<Town>::iterator it2 = townsOfCoord[c1].begin();
             it2 != townsOfCoord[c1].end(); it2++)
            if (*it2 != *it1)
                for (vector<Town>::iterator it3 = townsOfName[n1].begin();
                     it3 != townsOfName[n1].end(); it3++)
                    if (*it3 != *it1) {
                        Point2D c3 = it3->point();
                        for (vector<Town>::iterator it4 =
                                 townsOfCoord[c3].begin();
                             it4 != townsOfCoord[c3].end(); it4++)
                            if (*it4 != *it2 && it4->name() == it2->name()) {
                                ambig.insert(*it1);
                                ambig.insert(*it2);
                                ambig.insert(*it3);
                                ambig.insert(*it4);
                            }
                    }
    }
    time2 = clock();
    cout << "Q4. Isotoponyms (efficient): " << ambig.size();
    for(set<Town>::iterator it = ambig.begin(); it != ambig.end(); it++)
        cout << "  " << *it;
    cout << "... found in " << float(time2-time1)/CLOCKS_PER_SEC << 's' << endl;

    /////
    ///// Ambiguous names of towns that are very close to another town.
    ///// Inefficient variant.
    ///// 
    ambig.clear();
    time1 = clock();
    for(vector<Town>::iterator it1 = towns.begin();
        it1 != towns.end(); it1++) {
        string n1 = it1->name();
        Point2D c1 = it1->point();
        for (vector<Town>::iterator it2 = towns.begin();
             it2 != towns.end(); it2++) {
            if (it2 != it1 && it2->point() == c1) {
                string n2 = it2->name();
                for (vector<Town>::iterator it3 = towns.begin();
                     it3 != towns.end(); it3++)
                    if (it3 != it1 && it3->name() == n1) {
                        Point2D c3 = it3->point();
                        for (vector<Town>::iterator it4 = towns.begin();
                             it4 != towns.end(); it4++)
                            if (it4 != it2 && it4->name() == n2 &&
                                it4 != it3 && it4->point() == c3) {
                                ambig.insert(*it1);
                                ambig.insert(*it2);
                                ambig.insert(*it3);
                                ambig.insert(*it4);
                            }
                    }
            }
        }
    }
    time2 = clock();
    cout << "Q5. Isotoponyms (inefficient): " << ambig.size();
    for(set<Town>::iterator it = ambig.begin(); it != ambig.end(); it++)
        cout << "  " << *it;
    cout << "... found in " << float(time2-time1)/CLOCKS_PER_SEC << 's' << endl;

    // That's all folks
    return 0;
}
