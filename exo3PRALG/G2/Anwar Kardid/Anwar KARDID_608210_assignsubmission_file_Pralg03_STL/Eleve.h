#pragma once 
#include <string>

using namespace std;

/**
 * @brief Class representing a student with name and grade
 */
class Eleve
{
public:
    string nom_;
    int note_;

    /**
     * @brief Constructor for Eleve
     * @param nom Student's name
     * @param note Student's grade
     */
    Eleve(string nom, int note) : nom_(nom), note_(note) {};
};

/**
 * @brief Functor for name-based comparison in ascending order
 */
class CompareNom
{   
    int *ptr_;
public:
    /**
     * @brief Constructor initializing the counter pointer
     * @param ptr Pointer to integer counter for comparisons
     */
    CompareNom(int *ptr) : ptr_(ptr){};
    
    /**
     * @brief Comparison operator for alphabetical sorting
     * @param a First student to compare
     * @param b Second student to compare
     * @return true if a's name comes before b's name alphabetically
     */
    bool operator()(const Eleve& a, const Eleve& b) const;
};

/**
 * @brief Functor for grade-based comparison in descending order
 */
class CompareNote
{   
    int *ptr_;
public:
    /**
     * @brief Constructor initializing the counter pointer
     * @param ptr Pointer to integer counter for comparisons
     */
    CompareNote(int *ptr) : ptr_(ptr){};
    
    /**
     * @brief Comparison operator for grade sorting (descending)
     * @param a First student to compare
     * @param b Second student to compare
     * @return true if a's grade is higher than b's grade
     */
    bool operator()(const Eleve& a, const Eleve& b) const;
};