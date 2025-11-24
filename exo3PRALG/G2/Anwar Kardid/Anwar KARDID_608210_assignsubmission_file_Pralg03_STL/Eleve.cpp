#include "Eleve.h"

/**
 * @brief Compares students' names in ascending alphabetical order
 * @param a First student to compare
 * @param b Second student to compare
 * @return true if student a's name comes before student b's name
 */
bool CompareNom::operator()(const Eleve& a, const Eleve& b) const
{
    ++(*ptr_);  // Increment comparison counter
    return a.nom_ < b.nom_;
}

/**
 * @brief Compares students' grades in descending order
 * @param a First student to compare
 * @param b Second student to compare
 * @return true if student a's grade is higher than student b's grade
 */
bool CompareNote::operator()(const Eleve& a, const Eleve& b) const
{
    ++(*ptr_);  // Increment comparison counter
    return a.note_ > b.note_;
}